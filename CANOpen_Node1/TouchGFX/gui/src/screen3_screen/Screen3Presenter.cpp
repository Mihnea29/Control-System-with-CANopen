#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}

void Screen3Presenter::updateCANID(uint8_t CAN_ID)
{
	view.updateCANID(CAN_ID);
}


void Screen3Presenter::setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate)
{
	view.setNodeInfo(index, CAN_ID, HBstate, NMTstate);
}


void Screen3Presenter::setHBconsumerTimeout( int index, uint16_t timeoutTime)
{
	view.setHBconsumerTimeout(index, timeoutTime);
}

void Screen3Presenter::updateHBprodTime(int index, uint16_t HBprodTime)
{
	view.updateHBprodTime(index, HBprodTime);
}

void Screen3Presenter::buttonNodeXHBTinc(int index)
{
	model->HBconsTimeoutInc(index);
}

void Screen3Presenter::buttonNodeXHBTdec(int index)
{
	model->HBconsTimeoutDec(index);
}

void Screen3Presenter::getHBprodTime(int index)
{
	model->getHBprodTime(index);
}

void Screen3Presenter::setHBprodTime(int index)
{
	model->setHBprodTime(index);
}

void Screen3Presenter::HBprodTimeInc(int index)
{
	model->HBprodTimeInc(index);
}

void Screen3Presenter::HBprodTimeDec(int index)
{
	model->HBprodTimeDec(index);
}
