#ifndef LOGICMODULEABSTRACTCLASS_H
#define LOGICMODULEABSTRACTCLASS_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QMap>
#include <QSharedPointer>
#include "NIO_type.h"
#include "DataService.h"
#include "CtrlService.h"
#include "BatteryControllerClass.h"
#include "ChargerControllerClass.h"
#include "SwitchControllerClass.h"
#include "app_global.h"
#define GUID QString

namespace Appilication
{
    namespace Power
    {
        class LogicModuleAbstractClass : public QObject
        {
            Q_OBJECT
        public:
            typedef NIO_UINT16 (LogicModuleAbstractClass::*callback)(const GUID &,const QVariant &);
            /*
             * @constructor
            */
            explicit LogicModuleAbstractClass(QObject *parent = 0);

            /*
             * @disconstructor
            */
            virtual ~LogicModuleAbstractClass();
        public:

            /*
             * @brief set battery controller
            */
            void setBatteryController(QSharedPointer<BatteryControllerClass> controller);

            /*
             * @brief set charger controller
            */
            void setChargerController(QSharedPointer<ChargerControllerClass> controller);

            /*
             * @brief set switch controller
            */
            void setSwitcherController(QSharedPointer<SwitchControllerClass> controller);

            /*
             * @brief callback
            */
            virtual void registerCallback();

            /*
             * @brief data initialize module
            */
            virtual void initializeLogicModule();

            /*
             * @brief set data service instance
            */
            void setDataService(Platform::Middleware::DataService * dataService);

            /*
             * @set ctrl service instance
            */
            void setCtrlService(Platform::Middleware::CtrlService * ctrlService);

            /*
             * @brief check power conditions ready
            */
            virtual NIO_UINT16 checkSatfyBeforePowerBattery(QSharedPointer<ChargerClass> charger,
                                                                QSharedPointer<BatteryClass> battery,
                                                                QSharedPointer<SwitchClass> switcher,
                                                                const GUID & ctrlMode);

            /*
             * @brief check power conditions ready
            */
            virtual NIO_UINT16 checkSatfyBeforeStopPower(QSharedPointer<ChargerClass> charger,
                                                         QSharedPointer<BatteryClass> battery,
                                                         QSharedPointer<SwitchClass> switcher);

            /*
             * @brief ctrl service instance
            */
            virtual NIO_UINT16 checkSatfyBeforeSetting(QSharedPointer<BatteryClass> battery);

            /*
             * @brief ctrl service instance
            */
            virtual NIO_UINT16 performSwitchStateLogicCheck(const GUID & guid,const QVariant & value);

            /*
             * @brief reset board
            */
            NIO_UINT16 performResetPowerBoardLogicCheck(const GUID & guid,const QVariant & value);

            /*
             * @brief switch ctrl logic check
            */
            NIO_UINT16 performSwitchCtrlLogicCheck(const GUID & guid,const QVariant & value);

            /*
             * @brief start charge logic check
            */
            NIO_UINT16 performStartChargeLogicCheck(const GUID & guid,const QVariant & value);

            /*
             * @brief ctrl service instance
            */
            NIO_UINT16 performSettingLogicCheck(const QList<GUID> & guid,const QVariant & value);

            /*
             * @brief reset
            */
            void reset();
        signals:
            void set_ctrl_callback_signal(const GUID & guid,const QVariant & value,NIO_INT16 errorCode);
        public slots:
            /*
             * @brief logic check
            */
            void peroformLogicCheck( const GUID & guid ,QVariant  &value);
        protected:
            QSharedPointer<BatteryControllerClass> m_batteryController;
            QSharedPointer<ChargerControllerClass> m_chargercontroller;
            QSharedPointer<SwitchControllerClass> m_switchController;
            std::map<GUID,callback> m_logicCallbackMap;
            QSharedPointer<Platform::Middleware::DataService> m_dataService;
            QSharedPointer<Platform::Middleware::CtrlService> m_ctrlService;
        };
    }
}
#endif // LOGICMODULEABSTRACTCLASS_H
