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

    virtual void updateTime(uint8_t Hours, uint8_t Minutes, uint8_t Seconds) {};
    virtual void updateData(uint8_t WeekDay, uint8_t Date, uint8_t Month, uint8_t Year) {};
    virtual void setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
