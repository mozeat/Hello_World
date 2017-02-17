#ifndef BATTERYCLASS_H
#define BATTERYCLASS_H
#include <QList>
#include <QSharedPointer>
#include "DataConfigClass.h"
#include "DeviceAbstractClass.h"
namespace Appilication
{
    namespace Power
    {
        class BatteryClass : public DeviceAbstractClass
        {
        public:
            BatteryClass();
            ~BatteryClass();
        public:

            /*
             * @brief set ctrl data config
            */
            void setStartStopData(QSharedPointer<DataConfigClass> dataConfig);

            QSharedPointer<DataConfigClass> getStartStopData();

            /*
             * @brief set work status data config
            */
            void setWorkStatusData(QSharedPointer<DataConfigClass> dataConfig);
            QSharedPointer<DataConfigClass> getWorkStatusData();

            /*
             * @brief set fault level data config
            */
            void setFaultLevelData(QSharedPointer<DataConfigClass> dataConfig);
            QSharedPointer<DataConfigClass> getFaultLevelData();

            /*
             * @brief set state data config
            */
            void setBatteryStateData(QSharedPointer<DataConfigClass> dataConfig);
            QSharedPointer<DataConfigClass> getBatteryStateData();

            /*
             * @brief set enable data config
            */
            void setChargeEnableData(QSharedPointer<DataConfigClass> dataConfig);
            QSharedPointer<DataConfigClass> getChargeEnableData();

            /*
             * @brief set allow data config
            */
            void setChargeAllowData(QSharedPointer<DataConfigClass> dataConfig);
            QSharedPointer<DataConfigClass> getChargeAllowData();

            /*
             * @brief set reach setting soc data config
            */
            void setReachSettingData(QSharedPointer<DataConfigClass> dataConfig);
            QSharedPointer<DataConfigClass> getReachSettingData();

            /*
             * @brief set gun state data config
            */
            void setChargeGunData(QSharedPointer<DataConfigClass> dataConfig);
            QSharedPointer<DataConfigClass> getChargeGunData();

        private:
            QSharedPointer<DataConfigClass> m_startStopData;
            QSharedPointer<DataConfigClass> m_workStatusData;
            QSharedPointer<DataConfigClass> m_faultLevelData;
            QSharedPointer<DataConfigClass> m_batteryStateData;
            QSharedPointer<DataConfigClass> m_chargeEnableData;
            QSharedPointer<DataConfigClass> m_chargeAllowData;
            QSharedPointer<DataConfigClass> m_chargeGunData;
            QSharedPointer<DataConfigClass> m_reachSettingData;
        };
    }
}
#endif // BATTERYCLASS_H
