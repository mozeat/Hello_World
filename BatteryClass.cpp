#include "BatteryClass.h"
#include "TraceClass.h"

namespace Appilication
{
    namespace Power
    {
        BatteryClass::BatteryClass()
        {

        }

        BatteryClass::~BatteryClass()
        {

        }

        /*
         * @brief set ctrl data config
        */
        void BatteryClass::setStartStopData(QSharedPointer<DataConfigClass> dataConfig)
        {
            this->m_startStopData = dataConfig;
            this->add(dataConfig);
        }

        QSharedPointer<DataConfigClass> BatteryClass::getStartStopData()
        {
            return this->m_startStopData;
        }

        /*
         * @brief set work status data config
        */
        void BatteryClass::setWorkStatusData(QSharedPointer<DataConfigClass> dataConfig)
        {
            AppFuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(dataConfig->getName()).arg(dataConfig->getGuid()));
            this->m_workStatusData = dataConfig;
            this->add(dataConfig);
            AppFuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> BatteryClass::getWorkStatusData()
        {
            return this->m_workStatusData;
        }

        /*
         * @brief set fault level data config
        */
        void BatteryClass::setFaultLevelData(QSharedPointer<DataConfigClass> dataConfig)
        {
            AppFuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(dataConfig->getName()).arg(dataConfig->getGuid()));
            this->m_faultLevelData = dataConfig;
            this->add(dataConfig);
            AppFuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> BatteryClass::getFaultLevelData()
        {
            return this->m_faultLevelData;
        }

        /*
         * @brief set state data config
        */
        void BatteryClass::setBatteryStateData(QSharedPointer<DataConfigClass> dataConfig)
        {
            AppFuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(dataConfig->getName()).arg(dataConfig->getGuid()));
            this->m_batteryStateData = dataConfig;
            this->add(dataConfig);

        }

        QSharedPointer<DataConfigClass> BatteryClass::getBatteryStateData()
        {
            return this->m_batteryStateData;
        }

        /*
         * @brief set enable data config
        */
        void BatteryClass::setChargeEnableData(QSharedPointer<DataConfigClass> dataConfig)
        {
            AppFuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(dataConfig->getName()).arg(dataConfig->getGuid()));
            this->m_chargeEnableData = dataConfig;
            this->add(dataConfig);
            AppFuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> BatteryClass::getChargeEnableData()
        {
            return this->m_chargeEnableData;
        }

        /*
         * @brief set allow data config
        */
        void BatteryClass::setChargeAllowData(QSharedPointer<DataConfigClass> dataConfig)
        {
            AppFuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(dataConfig->getName()).arg(dataConfig->getGuid()));
            this->m_chargeAllowData =dataConfig;
            this->add(dataConfig);
            AppFuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> BatteryClass::getChargeAllowData()
        {
            return this->m_chargeAllowData;
        }

        /*
         * @brief set reach setting soc data config
        */
        void BatteryClass::setReachSettingData(QSharedPointer<DataConfigClass> dataConfig)
        {
            AppFuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(dataConfig->getName()).arg(dataConfig->getGuid()));
            this->m_reachSettingData = dataConfig;
            this->add(dataConfig);
            AppFuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> BatteryClass::getReachSettingData()
        {
            return this->m_reachSettingData;
        }

        /*
         * @brief set gun state data config
        */
        void BatteryClass::setChargeGunData(QSharedPointer<DataConfigClass> dataConfig)
        {
            AppFuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]-workValue[%3]").arg(dataConfig->getName()).arg(dataConfig->getGuid()));
            this->m_chargeGunData = dataConfig;
            this->add(dataConfig);
            AppFuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> BatteryClass::getChargeGunData()
        {
            return this->m_chargeGunData;
        }
    }
}
