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



    void HBconsTimeoutInc(int index);
    void HBconsTimeoutDec(int index);
    void HBprodTimeInc(int index);
    void HBprodTimeDec(int index);


    void getHBprodTime(int index);
    void setHBprodTime(int index);
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
