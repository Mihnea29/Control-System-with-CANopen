#ifndef MODEL_HPP
#define MODEL_HPP

extern "C" {
#include "CANopen.h"
}

class ModelListener;

#define HB_CONS_NODES 8

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    //SCREEN3
//    uint16_t HBconsTimeout[HB_CONS_NODES];
    uint16_t HBprodTime[HB_CONS_NODES];
    bool HBprodTimeValid[HB_CONS_NODES];

    void getTimeDate();
    void getNodeInfoDetail(int index);

    void HBconsTimeoutInc(int index);
    void HBconsTimeoutDec(int index);
    void HBprodTimeInc(int index);
    void HBprodTimeDec(int index);

    void getHBprodTime(int index);
    void setHBprodTime(int index);

    //SCREEN4
    void toggleButton(int index);
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
