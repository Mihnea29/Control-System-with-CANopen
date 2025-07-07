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

void Screen3Presenter::setCANID(uint8_t CAN_ID, CO_NMT_internalState_t NMTstate)
{
	view.setCANID(CAN_ID, NMTstate);
}


void Screen3Presenter::setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate)
{
	view.setNodeInfo(index, CAN_ID, HBstate, NMTstate);
}


void Screen3Presenter::setNodeInfoDetail( int index, uint8_t CANID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate,
		uint16_t timeoutTime, uint16_t HBprodTime, bool HBprodTimeValid )
{
	view.setNodeInfoDetail(index, CANID, HBstate, NMTstate, timeoutTime, HBprodTime, HBprodTimeValid );
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

void Screen3Presenter::getNodeInfoDetail(int index)
{
	model->getNodeInfoDetail(index);
}

