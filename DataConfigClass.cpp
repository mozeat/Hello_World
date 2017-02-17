#include "DataConfigClass.h"
#include "app_global.h"
#include "TraceClass.h"

namespace Appilication
{
    namespace Power
    {


        AppGuidStruct g_app_guid_config[APP_GUID_MAX] =
        {
            {CHARGE_1_STATE,             "CHARGE_1_STATE"               "C3D97BA5-5FB5F597-50C89CA0-41720EAE"},
            {CHARGE_1_WORK_STATE,        "CHARGE_1_WORK_STATE"          "B90AE82D-568BF72B-4E6CD5FB-CCC97E1D"},
            {CHARGE_1_COMM_STATE,        "CHARGE_1_COMM_STATE",         "F1A03050-51C7B52C-79F85EDC-15FABFC6"},
            {CHARGE_1_GUN_STATE,         "CHARGE_1_GUN_STATE",          "--"},
            {BATTERY_1_STATE,            "BATTERY_1_STATE",             "B7A01633-48D7EFC1-044DDE81-CF94BC2E"},
            {BATTERY_1_WORK_STATUS,      "BATTERY_1_WORK_STATUS",       "2BF0E24C-F797502B-839D76FC-463545E9"},
            {BATTERY_1_FAULT_LEVEL,      "BATTERY_1_FAULT_LEVEL",       "F996AC42-4081A73F-CD8E9487-7EA9614B"},
            {BATTERY_1_CHARGE_ENABLED,   "BATTERY_1_CHARGE_ENABLED",    "97EAA8BD-C9050F37-BA434E83-CD9D0B96"},
            {BATTERY_1_CHARGE_ALLOWED,   "BATTERY_1_CHARGE_ALLOWED",    "E8788F85-4298B361-99B5563B-00C63EE9"},
            {BATTERY_1_SOC_REACH_SETTING,"BATTERY_1_SOC_REACH_SETTING", "D75E3E30-54BAE1AE-8650B306-509B4719"},
            {CHARGE_1_START_STOP_CTRL,   "CHARGE_1_START_STOP_CTRL",    "918ECAA2-1AE55394-3F03440B-07D10E73"},
            {CHARGE_1_RESET_CTRL,        "CHARGE_1_RESET_CTRL",         "F37CBEA1-2BC6604F-7F429BCC-93E76136"},
            {CHARGE_1_SWITCH_CTRL,       "CHARGE_1_SWITCH_CTRL",        "0CDDD039-3E71AAA7-6138044B-2803756D"},
            {SWITCH_1KM_STATUS,          "SWITCH_1KM_STATUS",           "--"},
            {SWITCH_1KM_1_2_STATUS,      "SWITCH_1KM_1_2_STATUS",       "--"},
            {SWITCH_1KM_3_4_STATUS,      "SWITCH_1KM_3_4_STATUS",       "--"},
            {SWITCH_1KM_5_6_STATUS,      "SWITCH_1KM_5_6_STATUS",       "--"},
            {SWITCH_1KM_7_STATUS,        "SWITCH_1KM_7_STATUS",         "--"},
            {SWITCH_1KM_8_STATUS,        "SWITCH_1KM_8_STATUS",         "--"},
            {SWITCH_1KM_9_STATUS,        "SWITCH_1KM_9_STATUS",         "--"},
            {SWITCH_1KM_10_STATUS,       "SWITCH_1KM_10_STATUS",        "--"},
            {SWITCH_1KM_11_STATUS,       "SWITCH_1KM_11_STATUS",        "--"},
            {SWITCH_1KM_12_STATUS,       "SWITCH_1KM_12_STATUS",        "--"},
            {SWITCH_1KM_13_STATUS,       "SWITCH_1KM_13_STATUS",        "--"},
            {SWITCH_1KM_14_STATUS,       "SWITCH_1KM_14_STATUS",        "--"},
            {SWITCH_1KM_15_STATUS,       "SWITCH_1KM_15_STATUS",        "--"},
            {SWITCH_1QF_STATUS,          "SWITCH_1QF_STATUS",           "--"},
            {SWITCH_QF_STATUS,           "SWITCH_QF_STATUS",            "--"},
            {CHARGE_2_STATE ,            "CHARGE_2_STATE",              "F5923183-FE168C10-9B6073A1-2B303140"},
            {CHARGE_2_WORK_STATE,        "CHARGE_2_WORK_STATE",         "E46BB075-B9DE90B3-7B27A9E3-046A38B5"},
            {CHARGE_2_COMM_STATE,        "CHARGE_2_COMM_STATE",         "9CC52D87-8EB6E6B0-1F3F5BFE-4A33BBD5"},
            {CHARGE_2_GUN_STATE,         "CHARGE_2_GUN_STATE",          "--"},
            {BATTERY_2_STATE ,           "BATTERY_2_STATE",             "DF1A278F-AE66FF3E-DF4F9805-EC407DCB"},
            {BATTERY_2_WORK_STATUS,      "BATTERY_2_WORK_STATUS",       "12545B4F-3229CE55-A5BDD9E6-B44BB46F"},
            {BATTERY_2_FAULT_LEVEL,      "BATTERY_2_FAULT_LEVEL",       "095B91AE-1C6EF2D6-1A496A9B-9C176E5E"},
            {BATTERY_2_CHARGE_ENABLED ,  "BATTERY_2_CHARGE_ENABLED",    "38FFD490-F3812AE4-B8CF77B7-1AAFB573"},
            {BATTERY_2_CHARGE_ALLOWED,   "BATTERY_2_CHARGE_ALLOWED",    "7C14F7B9-42626AFC-0C63EBF0-61FB4D48"},
            {BATTERY_2_SOC_REACH_SETTING,"BATTERY_2_SOC_REACH_SETTING", "09D878DB-9F4C98A7-6261F290-80BAA54E"},
            {CHARGE_2_START_STOP_CTRL,   "CHARGE_2_START_STOP_CTRL",    "A4A46F4E-F6D144B2-EE099B44-7DF588C1"},
            {CHARGE_2_RESET_CTRL,        "CHARGE_2_RESET_CTRL",         "00776556-9A608A4E-85909021-889F3C56"},
            {CHARGE_2_SWITCH_CTRL,       "CHARGE_2_SWITCH_CTRL",        "4BABD0D4-204016FD-D8FAD9D9-9CA64D6B"},
            {SWITCH_2KM_STATUS,          "SWITCH_2KM_STATUS",           "--"},
            {SWITCH_2KM_1_2_STATUS,      "SWITCH_2KM_1_2_STATUS",       "--"},
            {SWITCH_2KM_3_4_STATUS,      "SWITCH_2KM_3_4_STATUS",       "--"},
            {SWITCH_2KM_5_6_STATUS,      "SWITCH_2KM_5_6_STATUS",       "--"},
            {SWITCH_2KM_7_STATUS,        "SWITCH_2KM_7_STATUS",         "--"},
            {SWITCH_2KM_8_STATUS,        "SWITCH_2KM_8_STATUS",         "--"},
            {SWITCH_2KM_9_STATUS,        "SWITCH_2KM_9_STATUS",         "--"},
            {SWITCH_2KM_10_STATUS,       "SWITCH_2KM_10_STATUS",        "--"},
            {SWITCH_2KM_11_STATUS,       "SWITCH_2KM_11_STATUS",        "--"},
            {SWITCH_2KM_12_STATUS,       "SWITCH_2KM_12_STATUS",        "--"},
            {SWITCH_2KM_13_STATUS,       "SWITCH_2KM_13_STATUS",        "--"},
            {SWITCH_2KM_14_STATUS,       "SWITCH_2KM_14_STATUS",        "--"},
            {SWITCH_2KM_15_STATUS,       "SWITCH_2KM_15_STATUS",        "--"},
            {SWITCH_2QF_STATUS,          "SWITCH_2QF_STATUS",           "--"}
        };
        DataConfigClass::DataConfigClass()
        {

        }

        DataConfigClass::DataConfigClass(QString name,
                                         QString guid)
            :m_name(name)
            ,m_guid(guid)
        {

        }

        DataConfigClass::~DataConfigClass()
        {

        }

        /*
         * @brief data name
        */
        void DataConfigClass::setName(QString name)
        {
            this->m_name = name;
        }

        const QString &DataConfigClass::getName()
        {
            return this->m_name;
        }

        /*
         * @brief set guid
        */
        void DataConfigClass::setGuid(QString guid)
        {
            this->m_guid = guid;
        }

        const QString &DataConfigClass::getGuid()
        {
            return this->m_guid;
        }

        /*
         * @brief set switch ctrl data value in ac charge mode
        */
        void DataConfigClass::setAcModeSwValue(QVariant ac_value)
        {
            this->m_AC_value = ac_value;
        }

        const QVariant &DataConfigClass::getAcModeSwValue()
        {
            return this->m_AC_value;
        }

        /*
         * @brief set switch ctrl data value in Dc charge mode
        */
        void DataConfigClass::setDcModeSwValue(QVariant dc_value)
        {
             this->m_DC_value = dc_value;
        }

        const QVariant &DataConfigClass::getDcModeSwValue()
        {
            return this->m_DC_value;
        }

        /*
         * @brief set switch ctrl data value in ac charge mode
        */
        void DataConfigClass::setChargeModeSwValue(QVariant charge_value)
        {
            this->m_chargeValue = charge_value;
        }

        const QVariant &DataConfigClass::getChargeModeSwValue()
        {
            return this->m_chargeValue;
        }

        /*
         * @brief set ctrl data value
        */
        void DataConfigClass::setDefaultValue(QVariant default_value)
        {
            this->m_defaultValue = default_value;
        }

        const QVariant &DataConfigClass::getDefaultValue()
        {
            return this->m_defaultValue;
        }

        /*
         * @brief set work data value
        */
        void DataConfigClass::setWorkValue(QVariant value)
        {
            this->m_workValue = value;
        }

        const QVariant &DataConfigClass::getWorkValue()
        {
            return this->m_workValue;
        }

        /*
         * @brief set error data value
        */
        void DataConfigClass::setErrorValue(QVariant value)
        {
            this->m_errorValue = value;
        }

        const QVariant &DataConfigClass::getErrorValue()
        {
            return this->m_errorValue;
        }
    }
}
