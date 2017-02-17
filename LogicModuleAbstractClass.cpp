#include "LogicModuleAbstractClass.h"
#include "TR4A_if.h"


Appilication::Power::LogicModuleAbstractClass::LogicModuleAbstractClass(QObject *parent)
{
     parent = parent;
     this->m_batteryController.reset();;
}

Appilication::Power::LogicModuleAbstractClass::~LogicModuleAbstractClass()
{

}

/*
 * @brief set battery controller
*/
void Appilication::Power::LogicModuleAbstractClass::setBatteryController(QSharedPointer<Appilication::Power::BatteryControllerClass> controller)
{
    this->m_batteryController = controller;
}

/*
 * @brief set charger controller
*/
void Appilication::Power::LogicModuleAbstractClass::setChargerController(QSharedPointer<Appilication::Power::ChargerControllerClass> controller)
{
    this->m_chargercontroller = controller;
}

/*
 * @brief set switch controller
*/
void Appilication::Power::LogicModuleAbstractClass::setSwitcherController(QSharedPointer<Appilication::Power::SwitchControllerClass> controller)
{
    this->m_switchController = controller;
}

void Appilication::Power::LogicModuleAbstractClass::registerCallback()
{
    /*
     * @ 1#
    */
    this->m_logicCallbackMap["918ECAA2-1AE55394-3F03440B-07D10E73"] = &Appilication::Power::LogicModuleAbstractClass::performStartChargeLogicCheck;

    /*
     * @ 2#
    */
    this->m_logicCallbackMap["A4A46F4E-F6D144B2-EE099B44-7DF588C1"] = &Appilication::Power::LogicModuleAbstractClass::performStartChargeLogicCheck;
    return ;
}

/*
 * @brief data initialize module
*/
void Appilication::Power::LogicModuleAbstractClass::initializeLogicModule()
{

}

void Appilication::Power::LogicModuleAbstractClass::setDataService(Platform::Middleware::DataService *dataService)
{
    this->m_dataService.reset(dataService);
}

void Appilication::Power::LogicModuleAbstractClass::setCtrlService(Platform::Middleware::CtrlService *ctrlService)
{
    this->m_ctrlService.reset(ctrlService);
}


NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::checkSatfyBeforePowerBattery(QSharedPointer<ChargerClass> charger,
                                                                                       QSharedPointer<BatteryClass> battery,
                                                                                       QSharedPointer<SwitchClass> switcher,
                                                                                       const QString & ctrlMode)
{
    TR4A_FuncEntry(__FUNCTION__,"null");
    NIO_UINT16 errorCode = 0;
    if(charger.isNull() || battery.isNull()|| switcher.isNull() || ctrlMode.isNull())
    {
        errorCode = APP_PARAMETER_ERROR;
    }

    TR4A_FuncExit(__FUNCTION__,"null",errorCode);
    return errorCode;
}

NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::checkSatfyBeforeStopPower(QSharedPointer<ChargerClass> charger,
                                                                                    QSharedPointer<BatteryClass> battery,
                                                                                    QSharedPointer<SwitchClass> switcher)
{
    TR4A_FuncEntry(__FUNCTION__,"null");
    NIO_UINT16 errorCode = 0;
    if(charger.isNull() || battery.isNull()|| switcher.isNull())
    {
         errorCode = APP_PARAMETER_ERROR;
    }
    TR4A_FuncExit(__FUNCTION__,"null",errorCode);
    return errorCode;
}

NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::checkSatfyBeforeSetting(QSharedPointer<BatteryClass> battery)
{
    TR4A_FuncEntry(__FUNCTION__,"null");
    NIO_UINT16 errorCode = 0;
    if(battery.isNull())
    {
         errorCode = APP_PARAMETER_ERROR;
    }
    TR4A_FuncExit(__FUNCTION__,"null",errorCode);
    return errorCode;
}

NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::performSwitchStateLogicCheck(const GUID & guid,
                                                                                       const QVariant & value)
{
   TR4A_FuncEntry(__FUNCTION__,QString("guid[%1]").arg(guid));
    NIO_UINT16 errorCode = 0;
    if(value.toInt() == 0)
    {

    }
    if(guid.isNull()) return APP_PARAMETER_ERROR;
    TR4A_FuncExit(__FUNCTION__,"null",errorCode);
    return errorCode;
}

NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::performResetPowerBoardLogicCheck(const GUID & guid,
                                                                                           const QVariant & value)
{
    TR4A_FuncEntry(__FUNCTION__,QString("guid[%1]").arg(guid));
    NIO_UINT16 errorCode = 0;
    if(value.toInt() == 0)
    {

    }
    if(guid.isNull()) return APP_PARAMETER_ERROR;
    return errorCode;
}

/*
 * @brief switch ctrl logic check
*/
NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::performSwitchCtrlLogicCheck(const QString &guid,
                                                                                      const QVariant &value)
{
    TR4A_FuncEntry(__FUNCTION__,QString("guid[%1]").arg(guid));
    NIO_UINT16 errorCode = 0;
    if(value.toInt() == 0)
    {

    }
    if(guid.isNull()) return APP_PARAMETER_ERROR;
    return errorCode;
}

/*
 * @brief start charge logic check
*/
NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::performStartChargeLogicCheck(const QString &guid, const QVariant &value)
{
    TR4A_FuncEntry(__FUNCTION__,QString("guid[%1]-value[%2]").arg(guid).arg(value.toInt()));
    NIO_UINT16 errorCode = 0;
    int action = 3;
    enum{startAction = 1,stopAction = 2,otherAction = 3};
    bool convert_OK = false;

    /*
     * @brief get 1# or 2# battery
    */
    QSharedPointer<BatteryClass> battery = this->m_batteryController->getModelByGuid(guid);
    if(NULL == battery)
    {
        errorCode = CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
        return errorCode;
    }

    /*
     * @brief get 1# or 2# charger
    */
    QSharedPointer<ChargerClass> charger = this->m_chargercontroller->getModelByGuid(guid);
    if(NULL == charger)
    {
         errorCode = CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
         return errorCode;
    }

    /*
     * @brief get 1# or 2# switch
    */
    QSharedPointer<SwitchClass> switcher = this->m_switchController->getModelByGuid(guid);
    if(NULL == switcher)
    {
        errorCode = CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
        return errorCode;
    }

    /*
     * @brief value convertion
    */
    if(0 == errorCode)
    {
        action = value.toInt(&convert_OK);
        if(!convert_OK)
        {
            errorCode = CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
        }
    }

    /*
     * @brief perform action
    */
    if(0 == errorCode)
    {
        if(action == startAction)
        {
            errorCode = this->checkSatfyBeforePowerBattery(charger,battery,switcher,guid);
        }
        else if(action == stopAction)
        {
            errorCode = this->checkSatfyBeforeStopPower(charger,battery,switcher);
        }
    }
    TR4A_FuncExit(__FUNCTION__,"null",errorCode);
    return errorCode;
}


NIO_UINT16 Appilication::Power::LogicModuleAbstractClass::performSettingLogicCheck(const QList<GUID>  & guid,
                                                                                   const QVariant &value)
{
    NIO_UINT16 errorCode = 0;
    if(value.toInt() == 0)
    {

    }
    if(guid.empty()) return APP_PARAMETER_ERROR;
    return errorCode;
}

/*
 * @brief logic check slot
 * @
*/
void Appilication::Power::LogicModuleAbstractClass::reset()
{
    this->m_ctrlService.reset();
    this->m_dataService.reset();
    this->m_batteryController.reset();
    this->m_chargercontroller.reset();
    this->m_switchController.reset();
}

/*
 * @brief logic check slot
 * @
*/
void Appilication::Power::LogicModuleAbstractClass::peroformLogicCheck(const QString &guid, QVariant &value)
{
    TR4A_FuncEntry(__FUNCTION__,QString("guid[%1]-value[%2]").arg(guid).arg(value.toInt()));
    NIO_UINT16 errorCode = 0;
    std::map<GUID,callback>::iterator ite = this->m_logicCallbackMap.find(guid);
    if(ite != this->m_logicCallbackMap.end())
    {
        errorCode = (this->*(ite->second))(guid,value);
    }
    else
    {
        errorCode = 0x01;
        qDebug() << "Guid[" << guid << "] no callback function find!";
    }
    TR4A_FuncExit(__FUNCTION__,"null",errorCode);
    emit set_ctrl_callback_signal(guid,value,errorCode);
}
