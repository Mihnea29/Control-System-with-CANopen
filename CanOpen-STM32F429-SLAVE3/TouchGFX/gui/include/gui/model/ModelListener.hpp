#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void changeScreen(int ecran)
    {
    }

    virtual void updateTime(uint8_t Hours, uint8_t Minutes, uint8_t Seconds)
    {}   // dummy implementation, not implemented in Screen1 and Screen3
    virtual void updateData(uint8_t WeekDay, uint8_t Date, uint8_t Month, uint8_t Year)
    {}

    virtual void updateHeartbeatTime(uint8_t CAN_ID, CO_NMT_internalState_t NMTstate, uint32_t HeartbeatTime)
    {}   // dummy implementation, not implemented in Screen1 and Screen2

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
