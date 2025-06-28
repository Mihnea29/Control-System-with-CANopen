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

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
