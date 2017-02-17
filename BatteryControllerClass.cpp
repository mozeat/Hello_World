#include "BatteryControllerClass.h"
#include "app_global.h"
#include "TraceClass.h"

namespace Appilication
{
    namespace Power
    {
        extern AppGuidStruct g_app_guid_config[APP_GUID_MAX];

        BatteryControllerClass::BatteryControllerClass()
        {

        }

        BatteryControllerClass::~BatteryControllerClass()
        {

        }

        /*
         * @brief read data config file
        */
        void BatteryControllerClass::readDataConfigFromXML(QString fileName)
        {
            AppFuncEntry(__FUNCTION__,fileName);
            if(fileName.isNull())
                return;
            for(int i = CHARGE_1_STATE; i < APP_GUID_MAX;i++)
            {
                //this->m_guidBatteryInstanceMap[] =
            }
            AppFuncExit(__FUNCTION__,"null",0);
        }

        /*
         * @brief create all models
        */
        void BatteryControllerClass::createALlModels()
        {
             AppFuncEntry(__FUNCTION__,"null");

             AppTrace(__FUNCTION__,"creating model 1 ...");
             this->createModel(1);
             AppTrace(__FUNCTION__,"creating model 1 ...DONE");

             AppTrace(__FUNCTION__,"creating model 2 ...");
             this->createModel(2);
             AppTrace(__FUNCTION__,"creating model 2 ...DONE");

             AppFuncExit(__FUNCTION__,"null",0);
        }

        /*
         * @brief get model
        */
        QSharedPointer<BatteryClass> BatteryControllerClass::getModelByGuid(QString guid)
        {
            AppFuncEntry(__FUNCTION__,QString("input :guid[%1]").arg(guid));
            int errorCode = APP_OK;
            QSharedPointer<BatteryClass> battery;
            if(this->m_guidBatteryInstanceMap.find(guid) != this->m_guidBatteryInstanceMap.end())
            {
                battery = *this->m_guidBatteryInstanceMap.find(guid);
            }
            else
            {
                errorCode = APP_PARAMETER_ERROR;
            }

            AppFuncExit(__FUNCTION__,"null",errorCode);
            return battery;
        }

        /*
         * @brief create model by id
        */
        void BatteryControllerClass::createModel(int batteryId)
        {
            AppFuncEntry(__FUNCTION__,QString("input :batteryId[%1]").arg(batteryId));
            QSharedPointer<BatteryClass> model(new BatteryClass());
            QSharedPointer<DataConfigClass> data(new DataConfigClass());
            switch (batteryId) {
            case 1:
                model->setDeviceId(1);
                //1
                data->setName(g_app_guid_config[BATTERY_1_STATE].name);
                data->setGuid(g_app_guid_config[BATTERY_1_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setBatteryStateData(data);
                //2
                data->setName(g_app_guid_config[CHARGE_1_GUN_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_1_GUN_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setChargeGunData(data);
                //3
                data->setName(g_app_guid_config[BATTERY_1_CHARGE_ALLOWED].name);
                data->setGuid(g_app_guid_config[BATTERY_1_CHARGE_ALLOWED].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(2);
                model->setChargeAllowData(data);
                //4
                data->setName(g_app_guid_config[BATTERY_1_CHARGE_ENABLED].name);
                data->setGuid(g_app_guid_config[BATTERY_1_CHARGE_ENABLED].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(2);
                model->setChargeEnableData(data);
                //5
                data->setName(g_app_guid_config[BATTERY_1_FAULT_LEVEL].name);
                data->setGuid(g_app_guid_config[BATTERY_1_FAULT_LEVEL].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setFaultLevelData(data);
                //6
                data->setName(g_app_guid_config[BATTERY_1_WORK_STATUS].name);
                data->setGuid(g_app_guid_config[BATTERY_1_WORK_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setWorkStatusData(data);
                //7
                data->setName(g_app_guid_config[BATTERY_1_SOC_REACH_SETTING].name);
                data->setGuid(g_app_guid_config[BATTERY_1_SOC_REACH_SETTING].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setReachSettingData(data);

                //ctrl service guid associate with battert model
                this->m_guidBatteryInstanceMap[g_app_guid_config[CHARGE_1_START_STOP_CTRL].guid] = model;
                this->m_guidBatteryInstanceMap[g_app_guid_config[CHARGE_1_RESET_CTRL].guid] = model;
                this->m_guidBatteryInstanceMap[g_app_guid_config[CHARGE_1_SWITCH_CTRL].guid] = model;
                break;
            case 2:
                model->setDeviceId(2);
                //1
                data->setName(g_app_guid_config[BATTERY_2_STATE].name);
                data->setGuid(g_app_guid_config[BATTERY_2_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setBatteryStateData(data);
                //2
                data->setName(g_app_guid_config[CHARGE_2_GUN_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_2_GUN_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setChargeGunData(data);
                //3
                data->setName(g_app_guid_config[BATTERY_2_CHARGE_ALLOWED].name);
                data->setGuid(g_app_guid_config[BATTERY_2_CHARGE_ALLOWED].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(2);
                model->setChargeAllowData(data);
                //4
                data->setName(g_app_guid_config[BATTERY_2_CHARGE_ENABLED].name);
                data->setGuid(g_app_guid_config[BATTERY_2_CHARGE_ENABLED].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(2);
                model->setChargeEnableData(data);
                //5
                data->setName(g_app_guid_config[BATTERY_2_FAULT_LEVEL].name);
                data->setGuid(g_app_guid_config[BATTERY_2_FAULT_LEVEL].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setFaultLevelData(data);
                //6
                data->setName(g_app_guid_config[BATTERY_2_WORK_STATUS].name);
                data->setGuid(g_app_guid_config[BATTERY_2_WORK_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setWorkStatusData(data);
                //7
                data->setName(g_app_guid_config[BATTERY_2_SOC_REACH_SETTING].name);
                data->setGuid(g_app_guid_config[BATTERY_2_SOC_REACH_SETTING].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setReachSettingData(data);


                //ctrl service guid associate with battert model
                this->m_guidBatteryInstanceMap[g_app_guid_config[CHARGE_2_START_STOP_CTRL].guid] = model;
                this->m_guidBatteryInstanceMap[g_app_guid_config[CHARGE_2_RESET_CTRL].guid] = model;
                this->m_guidBatteryInstanceMap[g_app_guid_config[CHARGE_2_SWITCH_CTRL].guid] = model;
                break;
            default:
                break;
            }

        }
    }
}
