#include "ChargerControllerClass.h"
#include "app_global.h"
#include "TR4A_if.h"

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
            TR4A_FuncEntry(__FUNCTION__,fileName);
            if(fileName.isNull())
                return;
            for(int i = CHARGE_1_STATE; i < APP_GUID_MAX;i++)
            {
                //this->m_guidBatteryInstanceMap[] =
            }
            TR4A_FuncExit(__FUNCTION__,"null",0);
        }

        /*
         * @brief create all models
        */
        void ChargerControllerClass::createALlModels()
        {
            TR4A_FuncEntry(__FUNCTION__,"null");

            TR4A_FuncTrace(__FUNCTION__,"creating model 1 ...");
            this->createModel(1);
            TR4A_FuncTrace(__FUNCTION__,"creating model 1 ...DONE");

            TR4A_FuncTrace(__FUNCTION__,"creating model 2 ...");
            this->createModel(2);
            TR4A_FuncTrace(__FUNCTION__,"creating model 2 ...DONE");

            TR4A_FuncExit(__FUNCTION__,"null",0);
        }

        /*
         * @brief get model
        */
        QSharedPointer<ChargerClass> ChargerControllerClass::getModelByGuid(QString guid)
        {
            TR4A_FuncEntry(__FUNCTION__,QString("input :guid[%1]").arg(guid));
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

            TR4A_FuncExit(__FUNCTION__,"null",errorCode);
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
