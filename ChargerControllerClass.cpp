#include "ChargerControllerClass.h"
#include "app_global.h"
#include "TraceClass.h"

namespace Appilication
{
    namespace Power
    {
        extern AppGuidStruct g_app_guid_config[APP_GUID_MAX];

        ChargerControllerClass::ChargerControllerClass()
        {

        }

        ChargerControllerClass::~ChargerControllerClass()
        {

        }

        /*
         * @brief read data config file
        */
        void ChargerControllerClass::readDataConfigFromXML(QString fileName)
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
        void ChargerControllerClass::createALlModels()
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
        QSharedPointer<ChargerClass> ChargerControllerClass::getModelByGuid(QString guid)
        {
            AppFuncEntry(__FUNCTION__,QString("input :guid[%1]").arg(guid));
            int errorCode = APP_OK;
            QSharedPointer<ChargerClass> charger;
            if(this->m_guidChargerInstanceMap.find(guid) != this->m_guidChargerInstanceMap.end())
            {
                charger = *this->m_guidChargerInstanceMap.find(guid);
            }
            else
            {
                errorCode = APP_PARAMETER_ERROR;
            }

            AppFuncExit(__FUNCTION__,"null",errorCode);
            return charger;
        }

        /*
         * @brief create model by id
        */
        void ChargerControllerClass::createModel(int ChargerId)
        {
            QSharedPointer<ChargerClass> model(new ChargerClass());
            QSharedPointer<DataConfigClass> data(new DataConfigClass());
            switch (ChargerId)
            {
            case 1:
                model->setDeviceId(1);
                data->setName(g_app_guid_config[CHARGE_1_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_1_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setStateData(data);

                data->setName(g_app_guid_config[CHARGE_1_WORK_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_1_WORK_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(255);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setWorkStateData(data);


                data->setName(g_app_guid_config[CHARGE_1_COMM_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_1_COMM_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(255);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setConnectStateData(data);

                //ctrl service guid associate with battert model
                this->m_guidChargerInstanceMap[g_app_guid_config[CHARGE_1_START_STOP_CTRL].guid] = model;
                this->m_guidChargerInstanceMap[g_app_guid_config[CHARGE_1_RESET_CTRL].guid] = model;
                this->m_guidChargerInstanceMap[g_app_guid_config[CHARGE_1_SWITCH_CTRL].guid] = model;
                break;
            case 2:
                model->setDeviceId(2);
                data->setName(g_app_guid_config[CHARGE_2_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_2_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(0);
                data->setWorkValue(0);
                data->setErrorValue(1);
                model->setStateData(data);

                data->setName(g_app_guid_config[CHARGE_2_WORK_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_2_WORK_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(255);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setWorkStateData(data);


                data->setName(g_app_guid_config[CHARGE_2_COMM_STATE].name);
                data->setGuid(g_app_guid_config[CHARGE_2_COMM_STATE].guid);
                data->setAcModeSwValue(0);
                data->setDcModeSwValue(0);
                data->setChargeModeSwValue(0);
                data->setDefaultValue(255);
                data->setWorkValue(0);
                data->setErrorValue(255);
                model->setConnectStateData(data);

                //ctrl service guid associate with battert model
                this->m_guidChargerInstanceMap[g_app_guid_config[CHARGE_2_START_STOP_CTRL].guid] = model;
                this->m_guidChargerInstanceMap[g_app_guid_config[CHARGE_2_RESET_CTRL].guid] = model;
                this->m_guidChargerInstanceMap[g_app_guid_config[CHARGE_2_SWITCH_CTRL].guid] = model;
                break;
            default:
                break;
            }
        }
    }
}
