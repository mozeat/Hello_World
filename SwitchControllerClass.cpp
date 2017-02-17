#include "SwitchControllerClass.h"
#include "app_global.h"
#include "TraceClass.h"

namespace Appilication
{
    namespace Power
    {
        extern AppGuidStruct g_app_guid_config[APP_GUID_MAX];

        SwitchControllerClass::SwitchControllerClass()
        {

        }

        SwitchControllerClass::~SwitchControllerClass()
        {

        }

        /*
         * @brief read data config file
        */
        void SwitchControllerClass::readDataConfigFromXML(QString fileName)
        {
            const char* funcName = "SwitchControllerClass::readDataConfigFromXML";
            AppFuncEntry(funcName,fileName);
            if(fileName.isNull())
                return;
            for(int i = CHARGE_1_STATE; i < APP_GUID_MAX;i++)
            {
                //this->m_guidBatteryInstanceMap[] =
            }
            AppFuncExit(funcName,"null",0);
        }

        /*
         * @brief create all models
        */
        void SwitchControllerClass::createALlModels()
        {
            const char* funcName = "SwitchControllerClass::createALlModels";
            AppFuncEntry(funcName,"null");

            AppTrace(funcName,"creating model 1 ...");
            this->createModel(1);
            AppTrace(funcName,"creating model 1 ...DONE");

            AppTrace(funcName,"creating model 2 ...");
            this->createModel(2);
            AppTrace(funcName,"creating model 2 ...DONE");

            AppFuncExit(funcName,"null",0);
        }

        /*
         * @brief get model
        */
        QSharedPointer<SwitchClass> SwitchControllerClass::getModelByGuid(QString guid)
        {
            const char* funcName = "SwitchControllerClass::getModelByGuid";
            AppFuncEntry(funcName,QString("input :guid[%s]").arg(guid));
            int errorCode = APP_OK;
            QSharedPointer<SwitchClass> switcher;
            if(this->m_guidSwitchInstanceMap.find(guid) != this->m_guidSwitchInstanceMap.end())
            {
                switcher = *this->m_guidSwitchInstanceMap.find(guid);
            }
            else
            {
                errorCode = APP_PARAMETER_ERROR;
            }

            AppFuncExit(funcName,"null",errorCode);
            return switcher;
        }

        /*
         * @brief set power mode
        */
        void SwitchControllerClass::setPowerMode(QString ctrlCmd, APP_POWER_MODE_ENUM mode)
        {
            this->m_power_mode_map[ctrlCmd] = mode;
        }

        /*
         * @brief get power mode
        */
        APP_POWER_MODE_ENUM SwitchControllerClass::getPowerMode(QString ctrlCmd)
        {
            const char* funcName = "SwitchControllerClass::getPowerMode";
            AppFuncEntry(funcName,QString("input :guid[%1]").arg(ctrlCmd));
            if(this->m_power_mode_map.find(ctrlCmd) != this->m_power_mode_map.end())
            {
                return this->m_power_mode_map[ctrlCmd];
            }
            AppFuncExit(funcName,"null",0x01);
            return APP_POWER_MODE_MAX;
        }

        /*
         * @brief create model by id
        */
        void SwitchControllerClass::createModel(int SwitchId)
        {
            const char* funcName = "SwitchControllerClass::createModel";
            AppFuncEntry(funcName,QString("input :batteryId[%1]").arg(SwitchId));
            QSharedPointer<SwitchClass> model(new SwitchClass());
            QSharedPointer<DataConfigClass> data(new DataConfigClass());
            switch (SwitchId)
            {
            case 1:
                model->setDeviceId(1);
                //1
                data->setName(g_app_guid_config[SWITCH_1KM_1_2_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_1_2_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM1_2StatusData(data);

                //2
                data->setName(g_app_guid_config[SWITCH_1KM_3_4_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_3_4_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM3_4StatusData(data);

                //3
                data->setName(g_app_guid_config[SWITCH_1KM_5_6_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_5_6_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM5_6StatusData(data);

                //4
                data->setName(g_app_guid_config[SWITCH_1KM_7_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_7_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM7StatusData(data);

                //5
                data->setName(g_app_guid_config[SWITCH_1KM_8_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_8_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM8StatusData(data);

                //6
                data->setName(g_app_guid_config[SWITCH_1KM_9_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_9_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM9StatusData(data);

                //7
                data->setName(g_app_guid_config[SWITCH_1KM_10_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_10_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM10StatusData(data);

                //8
                data->setName(g_app_guid_config[SWITCH_1KM_11_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_11_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM11StatusData(data);

                //9
                data->setName(g_app_guid_config[SWITCH_1KM_12_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_12_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM12StatusData(data);

                //10
                data->setName(g_app_guid_config[SWITCH_1KM_13_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_13_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM13StatusData(data);

                //11
                data->setName(g_app_guid_config[SWITCH_1KM_14_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_14_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM14StatusData(data);

                //12
                data->setName(g_app_guid_config[SWITCH_1KM_15_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1KM_15_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM15StatusData(data);

                //12
                data->setName(g_app_guid_config[SWITCH_1QF_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_1QF_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setQfStatusData(data);

                //12
                data->setName(g_app_guid_config[SWITCH_QF_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_QF_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setHostQfStatusData(data);

                //ctrl service guid associate with battert model
                this->m_guidSwitchInstanceMap[g_app_guid_config[CHARGE_1_START_STOP_CTRL].guid] = model;
                this->m_guidSwitchInstanceMap[g_app_guid_config[CHARGE_1_RESET_CTRL].guid] = model;
                this->m_guidSwitchInstanceMap[g_app_guid_config[CHARGE_1_SWITCH_CTRL].guid] = model;
                break;

            case 2:
                model->setDeviceId(2);
                //1
                data->setName(g_app_guid_config[SWITCH_2KM_1_2_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_1_2_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM1_2StatusData(data);

                //2
                data->setName(g_app_guid_config[SWITCH_2KM_3_4_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_3_4_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM3_4StatusData(data);

                //3
                data->setName(g_app_guid_config[SWITCH_2KM_5_6_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_5_6_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM5_6StatusData(data);

                //4
                data->setName(g_app_guid_config[SWITCH_2KM_7_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_7_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM7StatusData(data);

                //5
                data->setName(g_app_guid_config[SWITCH_2KM_8_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_8_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM8StatusData(data);

                //6
                data->setName(g_app_guid_config[SWITCH_2KM_9_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_9_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM9StatusData(data);

                //7
                data->setName(g_app_guid_config[SWITCH_2KM_10_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_10_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM10StatusData(data);

                //8
                data->setName(g_app_guid_config[SWITCH_2KM_11_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_11_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM11StatusData(data);

                //9
                data->setName(g_app_guid_config[SWITCH_2KM_12_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_12_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM12StatusData(data);

                //10
                data->setName(g_app_guid_config[SWITCH_2KM_13_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_13_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM13StatusData(data);

                //11
                data->setName(g_app_guid_config[SWITCH_2KM_14_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_14_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM14StatusData(data);

                //12
                data->setName(g_app_guid_config[SWITCH_2KM_15_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2KM_15_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setKM15StatusData(data);

                //12
                data->setName(g_app_guid_config[SWITCH_2QF_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_2QF_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setQfStatusData(data);

                //12
                data->setName(g_app_guid_config[SWITCH_QF_STATUS].name);
                data->setGuid(g_app_guid_config[SWITCH_QF_STATUS].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(1);
                data->setErrorValue(1);
                model->setHostQfStatusData(data);


                //ctrl service guid associate with battert model
                this->m_guidSwitchInstanceMap[g_app_guid_config[CHARGE_2_START_STOP_CTRL].guid] = model;
                this->m_guidSwitchInstanceMap[g_app_guid_config[CHARGE_2_RESET_CTRL].guid] = model;
                this->m_guidSwitchInstanceMap[g_app_guid_config[CHARGE_2_SWITCH_CTRL].guid] = model;
                break;
            default:
                break;

            }
            AppFuncExit(funcName,"null",0x01);
        }
    }
}
