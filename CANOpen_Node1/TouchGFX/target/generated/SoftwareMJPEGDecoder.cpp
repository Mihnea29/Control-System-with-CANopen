/**
  ******************************************************************************
  * File Name          : SoftwareMJPEGDecoder.cpp
  ******************************************************************************
  * This file is generated by TouchGFX Generator 4.25.0. Please, do not edit!
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include <jinclude.h>
#include <jpeglib.h>
#include <string.h>
#include <SoftwareMJPEGDecoder.hpp>

#define RGB565 0
#define RGB888 1
#define ARGB8888 2
#define VIDEO_DECODE_FORMAT RGB565
namespace
{
struct JPEG_RGB
{
    uint8_t B;
    uint8_t G;
    uint8_t R;
};
} // namespace

SoftwareMJPEGDecoder::SoftwareMJPEGDecoder(uint8_t* buffer)
    : frameNumber(0), currentMovieOffset(0), indexOffset(0), firstFrameOffset(0), lastFrameEnd(0), movieLength(0), movieData(0),
      reader(0), lineBuffer(buffer), aviBuffer(0), aviBufferLength(0), aviBufferStartOffset(0), lastError(AVI_NO_ERROR)
{
    // Clear video info
    videoInfo.frame_height = 0;
    videoInfo.frame_width = 0;
    videoInfo.ms_between_frames = 0;
    videoInfo.number_of_frames = 0;
}

int SoftwareMJPEGDecoder::compare(const uint32_t offset, const char* str, uint32_t num)
{
    const char* src;
    if (reader != 0)
    {
        // Assuming data is in buffer!
        src = reinterpret_cast<const char*>(aviBuffer + (offset - aviBufferStartOffset));
    }
    else
    {
        src = (const char*)movieData + offset;
    }
    return strncmp(src, str, num);
}

inline uint32_t SoftwareMJPEGDecoder::getU32(const uint32_t offset)
{
    if (reader != 0)
    {
        // Assuming data is in buffer!
        const uint32_t index = offset - aviBufferStartOffset;
        return aviBuffer[index + 0] | (aviBuffer[index + 1] << 8) | (aviBuffer[index + 2] << 16) | (aviBuffer[index + 3] << 24);
    }
    else
    {
        const uint8_t* const d = movieData + offset;
        return d[0] | (d[1] << 8) | (d[2] << 16) | (d[3] << 24);
    }
}

inline uint32_t SoftwareMJPEGDecoder::getU16(const uint32_t offset)
{
    if (reader != 0)
    {
        // Assuming data is in buffer!
        const uint32_t index = offset - aviBufferStartOffset;
        return aviBuffer[index + 0] | (aviBuffer[index + 1] << 8);
    }
    else
    {
        const uint8_t* const d = movieData + offset;
        return d[0] | (d[1] << 8);
    }
}

const uint8_t* SoftwareMJPEGDecoder::readData(uint32_t offset, uint32_t length)
{
    if (reader != 0)
    {
        if (length > aviBufferLength)
        {
            lastError = AVI_ERROR_FILE_BUFFER_TO_SMALL;
            assert(!"Buffer to small");
        }

        reader->seek(offset);
        if (!reader->readData(aviBuffer, length))
        {
            lastError = AVI_ERROR_EOF_REACHED;
        }

        aviBufferStartOffset = offset;
        return aviBuffer;
    }

    return movieData + offset;
}

bool SoftwareMJPEGDecoder::decodeNextFrame(uint8_t* buffer, uint16_t buffer_width, uint16_t buffer_height, uint32_t buffer_stride)
{
    assert((frameNumber > 0) && "SoftwareMJPEGDecoder decoding without frame data!");

    //find next frame and decode it
    readData(currentMovieOffset, 8);
    uint32_t streamNo = getU16(currentMovieOffset);
    uint32_t chunkType = getU16(currentMovieOffset + 2);
    uint32_t chunkSize = getU32(currentMovieOffset + 4);
    const uint16_t STREAM0 = 0x3030;
    const uint16_t TYPEDC = 0x6364;

    bool isCurrentFrameLast;
    //play frame if we have it all
    if (currentMovieOffset + 8 + chunkSize < movieLength)
    {
        if (streamNo == STREAM0 && chunkType == TYPEDC && chunkSize > 0)
        {
            currentMovieOffset += 8;
            //decode frame
            const uint8_t* chunk = readData(currentMovieOffset, chunkSize);
            decodeMJPEGFrame(chunk, chunkSize, buffer, buffer_width, buffer_height, buffer_stride);
            frameNumber++;
        }

        isCurrentFrameLast = false;

        // Advance to next frame
        currentMovieOffset += chunkSize;
        if (chunkSize == 0) // Empty frame - Skip
        {
            currentMovieOffset += 8;
        }
        currentMovieOffset = (currentMovieOffset + 1) & 0xFFFFFFFE; //pad to next word

        if (currentMovieOffset == lastFrameEnd)
        {
            frameNumber = 1;
            currentMovieOffset = firstFrameOffset; //start over
            isCurrentFrameLast = true;
        }
    }
    else
    {
        frameNumber = 1;
        currentMovieOffset = firstFrameOffset; //start over
        isCurrentFrameLast = true;
    }
    return !isCurrentFrameLast;
}

bool SoftwareMJPEGDecoder::gotoNextFrame()
{
    assert((frameNumber > 0) && "SoftwareMJPEGDecoder decoding without frame data!");

    readData(currentMovieOffset, 8);
    uint32_t chunkSize = getU32(currentMovieOffset + 4);

    //increment until next video frame
    while (currentMovieOffset + 8 + chunkSize < movieLength)
    {
        //increment one frame
        currentMovieOffset += chunkSize + 8;
        currentMovieOffset = (currentMovieOffset + 1) & 0xFFFFFFFE; //pad to next word
        frameNumber++;

        //next chunk
        readData(currentMovieOffset, 8);
        //check it is a video frame
        uint32_t streamNo = getU16(currentMovieOffset);
        uint32_t chunkType = getU16(currentMovieOffset + 2);
        chunkSize = getU32(currentMovieOffset + 4);
        const uint16_t STREAM0 = 0x3030;
        const uint16_t TYPEDC = 0x6364;

        if (streamNo == STREAM0 && chunkType == TYPEDC && chunkSize > 0)
        {
            // Found next frame
            return true;
        }
    }

    //skip back to first frame
    frameNumber = 1;
    currentMovieOffset = firstFrameOffset; //start over
    return false;
}

void SoftwareMJPEGDecoder::setVideoData(const uint8_t* movie, const uint32_t length)
{
    movieData = movie;
    movieLength = length;
    reader = 0; //not using reader

    readVideoHeader();
}

void SoftwareMJPEGDecoder::setVideoData(touchgfx::VideoDataReader& reader)
{
    this->reader = &reader;
    movieData = 0;
    movieLength = reader.getDataLength();

    readVideoHeader();
}

bool SoftwareMJPEGDecoder::hasVideo()
{
    return (reader != 0) || (movieData != 0);
}

void SoftwareMJPEGDecoder::readVideoHeader()
{
    // Start from the start
    currentMovieOffset = 0;
    lastError = AVI_NO_ERROR;

    // Make header available in buffer
    readData(0, 72);

    // Decode the movie header to find first frame
    // Must be RIFF file
    if (compare(currentMovieOffset, "RIFF", 4))
    {
        lastError = AVI_ERROR_NOT_RIFF;
        assert(!"RIFF header not found");
    }

    //skip fourcc and length
    currentMovieOffset += 8;
    if (compare(currentMovieOffset, "AVI ", 4))
    {
        lastError = AVI_ERROR_AVI_HEADER_NOT_FOUND;
        assert(!"AVI header not found");
    }

    currentMovieOffset += 4;
    if (compare(currentMovieOffset, "LIST", 4))
    {
        lastError = AVI_ERROR_AVI_LIST_NOT_FOUND;
        assert(!"AVI LIST not found");
    }

    //save AVI List info
    const uint32_t aviListSize = getU32(currentMovieOffset + 4);
    const uint32_t aviListOffset = currentMovieOffset;
    assert(aviListSize);

    //look into header to find frame rate
    bool foundFrame = true;
    uint32_t offset = currentMovieOffset + 8;
    if (compare(offset, "hdrl", 4))
    {
        lastError = AVI_ERROR_AVI_HDRL_NOT_FOUND;
        foundFrame = false;
    }

    offset += 4;
    if (compare(offset, "avih", 4))
    {
        lastError = AVI_ERROR_AVI_AVIH_NOT_FOUND;
        foundFrame = false;
    }

    if (foundFrame)
    {
        offset += 8; //skip fourcc and cb in AVIMAINHEADER
        videoInfo.ms_between_frames = getU32(offset) / 1000;
        videoInfo.number_of_frames = getU32(offset + 16);
        videoInfo.frame_width = getU32(offset + 32);
        videoInfo.frame_height = getU32(offset + 36);
    }
    //skip rest of AVI header, start from end of AVI List

    //look for list with 'movi' header
    uint32_t listOffset = aviListOffset + aviListSize + 8;
    readData(listOffset, 12);
    while (compare(listOffset + 8, "movi", 4) && (lastError == AVI_NO_ERROR) && listOffset < movieLength)
    {
        const uint32_t listSize = getU32(listOffset + 4) + 8;
        listOffset += listSize;
        readData(listOffset, 12);
    }

    if (lastError != AVI_NO_ERROR)
    {
        lastError = AVI_ERROR_MOVI_NOT_FOUND;
        return;
    }

    //save first frame and end of last frame
    currentMovieOffset = listOffset + 8 + 4; //skip LIST and 'movi'
    lastFrameEnd = listOffset + 8 + getU32(listOffset + 4);

    //find idx
    const uint32_t listSize = getU32(listOffset + 4) + 8;
    listOffset += listSize;
    readData(listOffset, 4);
    if (!compare(listOffset, "idx1", 4))
    {
        indexOffset = listOffset;
    }
    else
    {
        lastError = AVI_ERROR_IDX1_NOT_FOUND;
        return;
    }

    //start on first frame
    frameNumber = 1; //next frame number is 1
    firstFrameOffset = currentMovieOffset;
}

#if VIDEO_DECODE_FORMAT == RGB565 || VIDEO_DECODE_FORMAT == RGB888 || VIDEO_DECODE_FORMAT == ARGB8888
void SoftwareMJPEGDecoder::decodeMJPEGFrame(const uint8_t* const mjpgdata, const uint32_t length, uint8_t* outputBuffer, uint16_t bufferWidth, uint16_t bufferHeight, uint32_t bufferStride)
{
    if (length == 0)
    {
        return;
    }

    if (outputBuffer && lineBuffer) //only decode if buffers are assigned.
    {
        /* This struct contains the JPEG decompression parameters */
        struct jpeg_decompress_struct cinfo;
        /* This struct represents a JPEG error handler */
        struct jpeg_error_mgr jerr;

        JSAMPROW lines[2] = { lineBuffer, 0 }; /* Output row buffer */

        /* Step 1: allocate and initialize JPEG decompression object */
        cinfo.err = jpeg_std_error(&jerr);

        /* Initialize the JPEG decompression object */
        jpeg_create_decompress(&cinfo);

        //jpeg_stdio_src (&cinfo, file);
        jpeg_mem_src(&cinfo, const_cast<uint8_t*>(mjpgdata), length);

        /* Step 3: read image parameters with jpeg_read_header() */
        jpeg_read_header(&cinfo, TRUE);

        /* Step 4: set parameters for decompression */
        cinfo.dct_method = JDCT_FLOAT;

        /* Step 5: start decompressor */
        jpeg_start_decompress(&cinfo);

        //restrict to minimum of movie and output buffer size
        const uint32_t width = MIN(bufferWidth, cinfo.image_width);
        const uint32_t height = MIN(bufferHeight, cinfo.output_height);

#if VIDEO_DECODE_FORMAT == RGB565
        uint16_t* lineptr = reinterpret_cast<uint16_t*>(outputBuffer);
        lineptr += bufferWidth * (width - 1);
#elif VIDEO_DECODE_FORMAT == RGB888
        uint8_t* lineptr = outputBuffer;
        lineptr += bufferWidth * (width - 1) * 3;
#else
        uint32_t* lineptr = reinterpret_cast<uint32_t*>(outputBuffer);
        lineptr += bufferWidth * (width - 1);
#endif
        while (cinfo.output_scanline < height)
        {
            (void)jpeg_read_scanlines(&cinfo, lines, 1);
#if VIDEO_DECODE_FORMAT == RGB565
            JPEG_RGB* RGB_matrix = (JPEG_RGB*)lineBuffer;
            JPEG_RGB* const RGB_end = RGB_matrix + width;
            while (RGB_matrix < RGB_end)
            {
                const uint16_t pix = ((RGB_matrix->R & 0xF8) << 8) | ((RGB_matrix->G & 0xFC) << 3) | ((RGB_matrix->B & 0xF8) >> 3);
                *lineptr = pix;
                lineptr -= bufferWidth;
                RGB_matrix++;
            }
            lineptr += 1 + bufferWidth * width; //move to next line
#elif VIDEO_DECODE_FORMAT == RGB888
            JPEG_RGB* RGB_matrix = (JPEG_RGB*)lineBuffer;
            JPEG_RGB* const RGB_end = RGB_matrix + width;
            while (RGB_matrix < RGB_end)
            {
                *lineptr = RGB_matrix->B;
                *(lineptr + 1) = RGB_matrix->G;
                *(lineptr + 2) = RGB_matrix->R;
                lineptr -= bufferWidth * 3;
                RGB_matrix++;
            }
            lineptr += 3 + bufferWidth * width * 3; //move to next line
#else
            JPEG_RGB* RGB_matrix = (JPEG_RGB*)lineBuffer;
            JPEG_RGB* const RGB_end = RGB_matrix + width;
            while (RGB_matrix < RGB_end)
            {
                const uint32_t pix = (0xFF << 24) | (RGB_matrix->R << 16) | (RGB_matrix->G << 8) | (RGB_matrix->B);
                *lineptr = pix;
                lineptr -= bufferWidth;
                RGB_matrix++;
            }
            lineptr += 1 + bufferWidth * width; //move to next line
#endif
        }

#ifdef SIMULATOR
        cinfo.output_scanline = cinfo.output_height;
#endif
        /* Step 6: Finish decompression */
        jpeg_finish_decompress(&cinfo);

        /* Step 7: Release JPEG decompression object */
        jpeg_destroy_decompress(&cinfo);
    }
}

bool SoftwareMJPEGDecoder::decodeFrame(const touchgfx::Rect& area, uint8_t* frameBuffer, uint32_t framebuffer_width)
{
    // Assuming that chunk is available and streamNo and chunkType is correct.
    // Check by gotoNextFrame

    readData(currentMovieOffset, 8);
    const uint32_t length = getU32(currentMovieOffset + 4);

    // Ensure whole frame is read
    const uint8_t* mjpgdata = readData(currentMovieOffset + 8, length);

    assert(lineBuffer && "LineBuffer must be assigned prior to decoding directly to framebuffer");

    /* This struct contains the JPEG decompression parameters */
    struct jpeg_decompress_struct cinfo;
    /* This struct represents a JPEG error handler */
    struct jpeg_error_mgr jerr;

    JSAMPROW lines[2] = { lineBuffer, 0 }; /* Output row buffer */

    /* Step 1: allocate and initialize JPEG decompression object */
    cinfo.err = jpeg_std_error(&jerr);

    /* Initialize the JPEG decompression object */
    jpeg_create_decompress(&cinfo);

    //jpeg_stdio_src (&cinfo, file);
    jpeg_mem_src(&cinfo, const_cast<uint8_t*>(mjpgdata), length);

    /* Step 3: read image parameters with jpeg_read_header() */
    jpeg_read_header(&cinfo, TRUE);

    /* Step 4: set parameters for decompression */
    cinfo.dct_method = JDCT_FLOAT;

    /* Step 5: start decompressor */
    jpeg_start_decompress(&cinfo);

    //restrict to minimum of movie and output buffer size
    const uint32_t startY = area.y;

    //scan down to startY
    while (cinfo.output_scanline < startY)
    {
        (void)jpeg_read_scanlines(&cinfo, lines, 1);
    }

    const uint32_t startX = area.x;
    const uint32_t endX = MIN((uint32_t)area.right(), cinfo.image_width);

#if VIDEO_DECODE_FORMAT == RGB565
    uint16_t* lineptr = reinterpret_cast<uint16_t*>(frameBuffer);
    lineptr += framebuffer_width * (cinfo.image_width - 1);
    lineptr += startY;
#elif VIDEO_DECODE_FORMAT == RGB888
    uint8_t* lineptr = frameBuffer;
    lineptr += framebuffer_width * (cinfo.image_width - 1) * 3;
    lineptr += startY * 3;
#else
    uint32_t* lineptr = reinterpret_cast<uint32_t*>(frameBuffer);
    lineptr += framebuffer_width * (cinfo.image_width - 1);
    lineptr += startY;
#endif
    const uint32_t endY = MIN((uint32_t)area.bottom(), cinfo.output_height);

    //scan relevant part
    while (cinfo.output_scanline < endY)
    {
        (void)jpeg_read_scanlines(&cinfo, lines, 1);
#if VIDEO_DECODE_FORMAT == RGB565
        JPEG_RGB* RGB_matrix = (JPEG_RGB*)lineBuffer;
        //loop row RGB888->RGB565 for required line part
        for (uint32_t counter = startX; counter < endX; counter++)
        {
            const uint16_t pix = ((RGB_matrix[counter].R & 0xF8) << 8) | ((RGB_matrix[counter].G & 0xFC) << 3) | ((RGB_matrix[counter].B & 0xF8) >> 3);
            *(lineptr - counter * framebuffer_width) = pix;
        }
        lineptr++; //move to next line
#elif VIDEO_DECODE_FORMAT == RGB888
        JPEG_RGB* RGB_matrix = (JPEG_RGB*)lineBuffer;
        //loop row RGB888->RGB888 for required line part
        for (uint32_t counter = startX; counter < endX; counter++)
        {
            *(lineptr - counter * framebuffer_width * 3) = RGB_matrix[counter].B;
            *(lineptr - counter * framebuffer_width * 3 + 1) = RGB_matrix[counter].G;
            *(lineptr - counter * framebuffer_width * 3 + 2) = RGB_matrix[counter].R;
        }
        lineptr += 3; //move to next line
#else
        JPEG_RGB* RGB_matrix = (JPEG_RGB*)lineBuffer;
        //loop row RGB888->ARGB8888 for required line part
        for (uint32_t counter = startX; counter < endX; counter++)
        {
            const uint32_t pix = (0xFF << 24) | (RGB_matrix[counter].R << 16) | (RGB_matrix[counter].G << 8) | RGB_matrix[counter].B;
            *(lineptr - counter * framebuffer_width) = pix;
        }
        lineptr++; //move to next line
#endif
    }

#ifdef SIMULATOR
    cinfo.output_scanline = cinfo.output_height;
#endif

    /* Step 6: Finish decompression */
    jpeg_finish_decompress(&cinfo);

    /* Step 7: Release JPEG decompression object */
    jpeg_destroy_decompress(&cinfo);

    return true;
}
#else
void SoftwareMJPEGDecoder::decodeMJPEGFrame(const uint8_t* const, const uint32_t, uint8_t*, uint16_t, uint16_t, uint32_t)
{
}
bool SoftwareMJPEGDecoder::decodeFrame(const touchgfx::Rect&, uint8_t*, uint32_t)
{
    return true;
}
#endif // VIDEO_DECODE_FORMAT == RGB565 || VIDEO_DECODE_FORMAT == RGB888 || VIDEO_DECODE_FORMAT == ARGB888

bool SoftwareMJPEGDecoder::decodeThumbnail(uint32_t frameno, uint8_t* buffer, uint16_t width, uint16_t height)
{
    assert(0);
    return false;
}

void SoftwareMJPEGDecoder::gotoFrame(uint32_t frameNumber)
{
    if (frameNumber == 0)
    {
        frameNumber = 1;
    }

    if (frameNumber > getNumberOfFrames())
    {
        frameNumber = getNumberOfFrames();
    }

    uint32_t offset = indexOffset + 8 + (frameNumber - 1) * 16;

    readData(offset, 16);

    currentMovieOffset = getU32(offset + 8) + firstFrameOffset - 4;
    this->frameNumber = frameNumber;
}

uint32_t SoftwareMJPEGDecoder::getNumberOfFrames()
{
    return videoInfo.number_of_frames;
}

void SoftwareMJPEGDecoder::getVideoInfo(touchgfx::VideoInformation* data)
{
    *data = videoInfo;
    // For unsupported decode formats, set video dimension to 0x0, to avoid drawing anything
#if VIDEO_DECODE_FORMAT == RGB565 || VIDEO_DECODE_FORMAT == RGB888 || VIDEO_DECODE_FORMAT == ARGB8888
#else
    data->frame_width = 0;
    data->frame_height = 0;
#endif
}

//#ifndef SIMULATOR
//link libjpeg file operation to fileinput namespace
extern "C" {
    size_t jpeg_read_file(FILE* file, uint8_t* buf, uint32_t sizeofbuf)
    {
        assert(!"jpeg_read_file called with no implementation");
        return 0;
    }
}
//#endif
