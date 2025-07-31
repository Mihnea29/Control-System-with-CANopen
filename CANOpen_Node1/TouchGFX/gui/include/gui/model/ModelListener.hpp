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

    //Screen2 - CLOCK & TIMESTAMP
    virtual void updateTime(uint8_t Hours, uint8_t Minutes, uint8_t Seconds) {};
    virtual void updateData(uint8_t WeekDay, uint8_t Date, uint8_t Month, uint8_t Year) {};

	//Screen3 - HEARTBEAT
    virtual void setCANID(uint8_t CAN_ID, CO_NMT_internalState_t NMTstate){};
    virtual void setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate) {}
    virtual void setNodeInfoDetail( int index, uint8_t CANID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate,
    		uint16_t timeoutTime, uint16_t HBprodTime, bool HBprodTimeValid ) {}

    //Screen4 - AUTO

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
