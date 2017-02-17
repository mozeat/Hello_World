#ifndef DEVICEABSTRACTCLASS_H
#define DEVICEABSTRACTCLASS_H
#include <QSharedPointer>
#include "DataConfigClass.h"
#include "app_global.h"
namespace Appilication
{
    namespace Power
    {
        class DeviceAbstractClass
        {
        public:
            DeviceAbstractClass();
            virtual ~DeviceAbstractClass();
        public:
            /*
             * @brief set device id
            */
            void setDeviceId(int id);
            /*
             * @brief get device id
            */
            const int & getDeviceId();

            /*
             * @brief register data config
            */
            virtual void registerDataConfig(const QList<QSharedPointer<DataConfigClass> > & dataConfigList);

            /*
             * @brief get data config
            */
            virtual QSharedPointer<DataConfigClass> getDataConfig(QString guid);

            /*
             * @brief add data config
            */
            virtual void add(QSharedPointer<DataConfigClass> dataConfig);

            /**
             * @brief Build alarm info of device to save database
             * @param IN error_code The error code of error occur
             * @param IN context
             */
            void buildAlarmInfo(int errorCode, QString context, QString description);

            /**
             * @brief get alarm info struct
             */
            AlarmInformationsStruct * getAlarmInfo();
            /*
             * @brief clear all register data
            */
            virtual void clear();

        protected:

            int m_deviceId;

            /*
             * @brief alarm info
            */
            AlarmInformationsStruct *m_alarmInfo;

            /*
             * @brief data config
            */
            QMap<QString,QSharedPointer<DataConfigClass> > m_dataConfigMap;
        };
    }
}

#endif // DEVICEABSTRACTCLASS_H
