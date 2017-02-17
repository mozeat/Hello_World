#ifndef MobileAppClass_H
#define MobileAppClass_H

#include "app_global.h"
#include <QObject>
#include <QMap>
#include <map>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSharedPointer>

#include "LogicModuleAbstractClass.h"
namespace Appilication
{
    namespace Power
    {
        class APPSHARED_EXPORT MobileAppClass : public Appilication::Power::LogicModuleAbstractClass
        {
        public:
            typedef NIO_UINT16 (MobileAppClass::*callback)(const GUID &,QVariant &);
        public:
            MobileAppClass();
            ~MobileAppClass();
        public:
            /*
             * @brief check power conditions ready
             * @QSharedPointer<ChargerClass> charger : Charge system
             * @QSharedPointer<BatteryClass> battery : battery status
             * @QSharedPointer<SwitchClass> switcher : switch status
            */
            OVERRIDE
            NIO_UINT16 checkSatfyBeforePowerBattery(QSharedPointer<ChargerClass> charger,
                                                    QSharedPointer<BatteryClass> battery,
                                                    QSharedPointer<SwitchClass> switcher,
                                                    const QString &ctrlMode);

            /* @brief check STOP power conditions ready
             * @QSharedPointer<ChargerClass> charger : Charge system
             * @QSharedPointer<BatteryClass> battery : battery status
             * @QSharedPointer<SwitchClass> switcher : switch status
            */
            OVERRIDE
            NIO_UINT16 checkSatfyBeforeStopPower(QSharedPointer<ChargerClass> charger,
                                                         QSharedPointer<BatteryClass> battery,
                                                         QSharedPointer<SwitchClass> switcher);
            /*
             * @brief ctrl service instance
             * @QSharedPointer<BatteryClass> battery : battery status
            */
            OVERRIDE
            NIO_UINT16 checkSatfyBeforeSetting(QSharedPointer<BatteryClass> battery);

        private:
            /*
             * @brief check board connected state
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<ChargerClass> charger : charger status
            */
            bool isBoardConnected( QSharedPointer<Platform::Middleware::DataService> dataService,
                                   QSharedPointer<ChargerClass> charger);
            /*
             * @brief check charge is free
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<ChargerClass> charger : charger status
            */
            bool isChargerIdle(QSharedPointer<Platform::Middleware::DataService> dataService,
                                               QSharedPointer<ChargerClass> charger);
            /*
             * @brief check charge is healthy
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<ChargerClass> charger : charger status
            */
            bool isChargerHealth(QSharedPointer<Platform::Middleware::DataService> dataService,
                                               QSharedPointer<ChargerClass> charger);

            /*
             * @brief check charge is healthy
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<BatteryClass> charger : battery
            */
            bool isBatteryIdle(QSharedPointer<Platform::Middleware::DataService> dataService,
                               QSharedPointer<BatteryClass> battery);

            /*
             * @brief check battery is healthy
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<BatteryClass> charger : battery
            */
            bool isBatteryHealth(QSharedPointer<Platform::Middleware::DataService> dataService,
                                               QSharedPointer<BatteryClass> battery);

            /*
             * @brief check battery is allow to charge
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<BatteryClass> charger : battery
            */
            bool isBatteryAllowTocharge(QSharedPointer<Platform::Middleware::DataService> dataService,
                                               QSharedPointer<BatteryClass> battery);
            /*
             * @brief check battery is enable to charge
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<BatteryClass> charger : battery
            */
            bool isBatteryEnableTocharge(QSharedPointer<Platform::Middleware::DataService> dataService,
                                               QSharedPointer<BatteryClass> battery);

            /*
             * @brief check switch state is fine
             * @QSharedPointer<Platform::Middleware::DataService> dataService
             * @QSharedPointer<BatteryClass> charger : battery
            */
            bool checkSwitchStateValid(QSharedPointer<Platform::Middleware::DataService> dataService,
                                 QSharedPointer<SwitchClass> switcher,
                                       APP_POWER_MODE_ENUM powerMode);
        private:
            bool checkDcSwitchStateValid(QSharedPointer<Platform::Middleware::DataService> dataService,
                                   QSharedPointer<SwitchClass> switcher);
            bool checkAcSwitchStateValid(QSharedPointer<Platform::Middleware::DataService> dataService,
                                   QSharedPointer<SwitchClass> switcher);
            bool checkChargeSwitchStateValid(QSharedPointer<Platform::Middleware::DataService> dataService,
                                   QSharedPointer<SwitchClass> switcher);
        };
    }

}
#endif // MobileAppClass_H
