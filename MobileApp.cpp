#include "MobileApp.h"
#include "TR4A_if.h"
#include "ExceptionClass.h"
using namespace Platform::Middleware;
namespace Appilication
{
    namespace Power
    {

        MobileAppClass::MobileAppClass()
        {

        }

        MobileAppClass::~MobileAppClass()
        {

        }

        /*
         * @brief check power conditions ready
         * @QSharedPointer<ChargerClass> charger : Charge system
         * @QSharedPointer<BatteryClass> battery : battery status
         * @QSharedPointer<SwitchClass> switcher : switch status
        */
        NIO_UINT16 MobileAppClass::checkSatfyBeforePowerBattery(QSharedPointer<ChargerClass> charger,
                                                                QSharedPointer<BatteryClass> battery,
                                                                QSharedPointer<SwitchClass> switcher,
                                                                const QString &ctrlMode)
        {
            const char * funcName = "MobileAppClass::checkSatfyBeforePowerBattery";
            TR4A_FuncEntry(funcName,"null");
            NIO_UINT16 errorCode = 0;
            if(charger.isNull() || battery.isNull() || switcher.isNull())
            {
                TR4A_FuncExit(funcName,"parameter error ...!",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }
            //check board connect state
            TR4A_FuncTrace(funcName,"check board connect state ...");
            if(!this->isBoardConnected(this->m_dataService,charger))
            {
                TR4A_FuncExit(funcName,"Board is disconnect error",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }
            TR4A_FuncTrace(funcName,"check board connect state ...DONE");

            //check board connect state
            TR4A_FuncTrace(funcName,"check charger is healthy ...");
            if(!this->isChargerHealth(this->m_dataService,charger))
            {
                TR4A_FuncExit(funcName,"Charger system is not healthy ...",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }
            TR4A_FuncTrace(funcName,"check charger is healthy ...DONE");

            //check board connect state
            TR4A_FuncTrace(funcName,"check charger is free to be charged ...");
            if(!this->isChargerIdle(this->m_dataService,charger))
            {
                TR4A_FuncExit(funcName,"Charger current is not free ...",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }
            TR4A_FuncTrace(funcName,"check charger is free to be charged ...DONE");

            if(!this->isBatteryHealth(this->m_dataService,battery))
            {
                TR4A_FuncExit(funcName,"Battery is not healthy ...",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }

            if(!this->isBatteryIdle(this->m_dataService,battery))
            {
                TR4A_FuncExit(funcName,"Battery current is not free",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }

            if(!this->isBatteryAllowTocharge(this->m_dataService,battery))
            {
                TR4A_FuncExit(funcName,"Battery is not allow to charge now ...",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }

            if(!this->isBatteryEnableTocharge(this->m_dataService,battery))
            {
                TR4A_FuncExit(funcName,"Battery is disabled ...",CTRL_OUTPUT_OPER_FAILED_COMM_ERROR);
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }

            try
            {
                this->m_switchController->checkSwitchLogicStateValid(this->m_dataService,ctrlMode);
            }
            catch(ExceptionClass & e)
            {
                errorCode = e.getErrorCode();
                TR4A_FuncTrace(funcName,"Switch state is now correct ...");
            }

            TR4A_FuncExit(funcName,"null",errorCode);
            return errorCode;
        }

        /* @brief check STOP power conditions ready
         * @QSharedPointer<ChargerClass> charger : Charge system
         * @QSharedPointer<BatteryClass> battery : battery status
         * @QSharedPointer<SwitchClass> switcher : switch status
        */
        NIO_UINT16 MobileAppClass::checkSatfyBeforeStopPower(QSharedPointer<ChargerClass> charger,
                                                             QSharedPointer<BatteryClass> battery,
                                                             QSharedPointer<SwitchClass> switcher)
        {
            NIO_UINT16 errorCode = 0;
            if(charger.isNull() || battery.isNull() || switcher.isNull())
            {
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }
            //check board connect state
            if(!this->isBoardConnected(this->m_dataService,charger))
            {
                return CTRL_OUTPUT_OPER_FAILED_COMM_ERROR;
            }
            return errorCode;
        }

        /*
         * @brief ctrl service instance
         * @QSharedPointer<BatteryClass> battery : battery status
        */
        NIO_UINT16 MobileAppClass::checkSatfyBeforeSetting(QSharedPointer<BatteryClass> battery)
        {
            if(NULL != battery)
            {

            }
            return 0;
        }

        /*
         * @brief check board connected state
         * @QSharedPointer<ChargerClass> charger : Charge system
         * @QSharedPointer<ChargerClass> charger : charger status
        */
        bool MobileAppClass::isBoardConnected(QSharedPointer<Platform::Middleware::DataService> dataService,
                                              QSharedPointer<ChargerClass> charger)
        {
            const char * funcName = "MobileAppClass::isBoardConnected";
            TR4A_FuncEntry(funcName,"null");
            bool result = false;
            if(NULL != charger && NULL != dataService)
            {
                TR4A_FuncTrace(funcName,"dispatch data id ...");
                QSharedPointer<DataConfigClass> dataCfg;
                dataCfg = charger->getConnectStateData();
                if(dataCfg == NULL)
                {
                    return false;
                }
                QString connect = dataCfg->getGuid();
                TR4A_FuncTrace(funcName,QString("data_id = %1").arg(connect));
                DataPoint* data = NULL;

                Service::ServiceStatus status = dataService->readData(connect,data);
                if(Service::SERVICE_OK == status)
                {
                    int value = 0;
                    unsigned int length = sizeof(int);
                    bool ok = data->getValue((void *)&value,length);
                    if(ok)
                    {
                        int CONNECTED = 0;
                        result = value == CONNECTED ? true : false;
                    }
                }
                TR4A_FuncTrace(funcName,QString("get data[%1]-[%2] from data service ").arg(result));
            }
            TR4A_FuncExit(funcName,QString("result[%1]").arg(result),0);
            return result;
        }

        /*
         * @brief check charge is free
         * @QSharedPointer<ChargerClass> charger : Charge system
         * @QSharedPointer<ChargerClass> charger : charger status
        */
        bool MobileAppClass::isChargerIdle(QSharedPointer<DataService> dataService,
                                           QSharedPointer<ChargerClass> charger)
        {
            bool result = false;
            if(NULL != charger && NULL != dataService)
            {
                QString idle = charger->getConnectStateData()->getGuid();
                DataPoint* data = NULL;
                Service::ServiceStatus status = dataService->readData(idle,data);
                if(Service::SERVICE_OK == status)
                {
                    int value = 0;
                    unsigned int length = sizeof(int);
                    bool ok = data->getValue((void *)&value,length);
                    if(ok)
                    {
                        int FREE = 0;
                        result = value == FREE ? true : false;
                    }
                }
            }
            return result;
        }

        /*
         * @brief check charge is healthy
         * @QSharedPointer<ChargerClass> charger : Charge system
         * @QSharedPointer<ChargerClass> charger : charger status
        */
        bool MobileAppClass::isChargerHealth(QSharedPointer<DataService> dataService,
                                             QSharedPointer<ChargerClass> charger)
        {
            bool result = false;
            if(NULL != charger && NULL != dataService)
            {
                QString healthy = charger->getConnectStateData()->getGuid();
                DataPoint* data = NULL;
                Service::ServiceStatus status = dataService->readData(healthy,data);
                if(Service::SERVICE_OK == status)
                {
                    int Value = 0;
                    unsigned int length = sizeof(int);
                    bool ok = data->getValue((void *)&Value,length);
                    if(ok == true)
                    {
                        int HEALTHY = 0;
                        result = Value == HEALTHY ? true : false;
                    }
                }
            }
            return result;
        }

        /*
         * @brief check charge is healthy
         * @QSharedPointer<Platform::Middleware::DataService> dataService
         * @QSharedPointer<BatteryClass> charger : battery
        */
        bool MobileAppClass::isBatteryIdle(QSharedPointer<DataService> dataService,
                                           QSharedPointer<BatteryClass> battery)
        {
            bool result = false;
            if(NULL != battery && NULL != dataService)
            {
                QString idle = battery->getBatteryStateData()->getGuid();
                DataPoint* data = NULL;
                Service::ServiceStatus status = dataService->readData(idle,data);
                if(Service::SERVICE_OK == status)
                {
                    int value = 0;
                    unsigned int length = sizeof(int);
                    bool ok = data->getValue((void *)&value,length);
                    if(ok)
                    {
                        int FREE = 0;
                        result = value == FREE ? true : false;
                    }
                }
            }
            return result;
        }

        /*
         * @brief check battery is healthy
         * @QSharedPointer<Platform::Middleware::DataService> dataService
         * @QSharedPointer<BatteryClass> charger : battery
        */
        bool MobileAppClass::isBatteryHealth(QSharedPointer<DataService> dataService,
                                             QSharedPointer<BatteryClass> battery)
        {
            bool result = false;
            if(NULL != battery && NULL != dataService)
            {
                QString healthy = battery->getWorkStatusData()->getGuid();
                DataPoint* data = NULL;
                Service::ServiceStatus status = dataService->readData(healthy,data);
                if(Service::SERVICE_OK == status)
                {
                    int Value = 0;
                    unsigned int length = sizeof(int);
                    bool ok = data->getValue((void *)&Value,length);
                    if(ok)
                    {
                        int HEALTHY = 0;
                        result = Value == HEALTHY ? true : false;
                    }
                }
            }
            return result;
        }

        /*
         * @brief check battery is allow to charge
         * @QSharedPointer<Platform::Middleware::DataService> dataService
         * @QSharedPointer<BatteryClass> charger : battery
        */
        bool MobileAppClass::isBatteryAllowTocharge(QSharedPointer<DataService> dataService,
                                                    QSharedPointer<BatteryClass> battery)
        {
            bool result = false;
            if(NULL != battery && NULL != dataService)
            {
                QString allow = battery->getChargeAllowData()->getGuid();
                DataPoint* data = NULL;
                Service::ServiceStatus status = dataService->readData(allow,data);
                if(Service::SERVICE_OK == status)
                {
                    bool value = false;
                    unsigned int length = sizeof(bool);
                    bool ok = data->getValue((void *)&value,length);
                    if(ok)
                    {
                        result = value;
                    }
                }
            }
            return result;
        }

        /*
         * @brief check battery is enable to charge
         * @QSharedPointer<Platform::Middleware::DataService> dataService
         * @QSharedPointer<BatteryClass> charger : battery
        */
        bool MobileAppClass::isBatteryEnableTocharge(QSharedPointer<DataService> dataService,
                                                     QSharedPointer<BatteryClass> battery)
        {
            bool result = false;
            if(dataService.isNull() || battery.isNull())
            {
                return false;
            }

            QString enabled ;
            enabled = battery->getChargeAllowData()->getGuid();

            DataPoint* data = NULL;
            Service::ServiceStatus status = dataService->readData(enabled,data);

            if(Service::SERVICE_OK == status)
            {
                bool value = false;
                unsigned int length = sizeof(bool);
                bool ok = data->getValue((void *)&value,length);
                if(ok)
                {
                    result = value;
                }
            }

            return result;
        }

        /*
         * @brief check switch state is fine
         * @QSharedPointer<Platform::Middleware::DataService> dataService
         * @QSharedPointer<BatteryClass> charger : battery
        */
        bool MobileAppClass::checkSwitchStateValid(QSharedPointer<DataService> dataService,
                                             QSharedPointer<SwitchClass> switcher,
                                                   APP_POWER_MODE_ENUM powerMode)
        {
            bool result = false;
            if(dataService.isNull() || switcher.isNull())
            {
                return false;
            }

            if(powerMode >= APP_POWER_MODE_MIN || powerMode <= APP_POWER_MODE_MIN)
            {
                return false;
            }

            switch (powerMode)
            {
            case APP_POWER_MODE_AC:
                result = this->checkAcSwitchStateValid(dataService,switcher);
                break;
            case APP_POWER_MODE_DC:
                result = this->checkDcSwitchStateValid(dataService,switcher);
                break;
            case APP_POWER_MODE_CHARGE:
                result = this->checkChargeSwitchStateValid(dataService,switcher);
                break;
            default:
                break;
            }

            return result;
        }

        bool MobileAppClass::checkDcSwitchStateValid(QSharedPointer<DataService> dataService,
                                                     QSharedPointer<SwitchClass> switcher)
        {
            bool result = false;
            if(dataService.isNull() || switcher.isNull())
            {
                return false;
            }
            QString km12 ;
            km12 = switcher->getKM12StatusData()->getGuid();
            DataPoint* data = NULL;
            Service::ServiceStatus status = dataService->readData(km12,data);
            if(Service::SERVICE_OK == status)
            {
                bool value = false;
                unsigned int length = sizeof(bool);
                bool ok = data->getValue((void *)&value,length);
                if(ok)
                {
                    if(switcher->getKM12StatusData()->getDcModeSwValue() != value)
                    {
                        return false;
                    }
                }
            }


            QString km34;
            km34 = switcher->getKM3_4StatusData()->getGuid();
            status = dataService->readData(km34,data);
            if(Service::SERVICE_OK == status)
            {
                bool value = false;
                unsigned int length = sizeof(bool);
                bool ok = data->getValue((void *)&value,length);
                if(ok)
                {
                    if(switcher->getKM3_4StatusData()->getDcModeSwValue() != value)
                    {
                        return false;
                    }
                }
            }

            QString qf;
            qf = switcher->getQfStatusData()->getGuid();
            status = dataService->readData(qf,data);
            if(Service::SERVICE_OK == status)
            {
                bool value = false;
                unsigned int length = sizeof(bool);
                bool ok = data->getValue((void *)&value,length);
                if(ok)
                {
                    if(switcher->getQfStatusData()->getDcModeSwValue() != value)
                    {
                        return false;
                    }
                }
            }
            return result;
        }

        bool MobileAppClass::checkAcSwitchStateValid(QSharedPointer<DataService> dataService, QSharedPointer<SwitchClass> switcher)
        {
            bool result = false;
            if(dataService.isNull() || switcher.isNull())
            {
                return false;
            }
            return result;
        }

        bool MobileAppClass::checkChargeSwitchStateValid(QSharedPointer<DataService> dataService, QSharedPointer<SwitchClass> switcher)
        {
            if(dataService.isNull() || switcher.isNull())
            {
                return false;
            }
            return true;
        }
    }
}
