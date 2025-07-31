#ifndef MODEL_HPP
#define MODEL_HPP

extern "C" {
#include "CANopen.h"
}

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void getTimeDate();

    void getNodeInfo();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
