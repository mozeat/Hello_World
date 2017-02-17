#include "DeviceAbstractClass.h"
#include "TR4A_if.h"

namespace Appilication
{
    namespace Power
    {
        DeviceAbstractClass::DeviceAbstractClass()
        {
            this->m_alarmInfo = new AlarmInformationsStruct();
        }

        DeviceAbstractClass::~DeviceAbstractClass()
        {
            delete this->m_alarmInfo;
        }

        /*
         * @brief register data config
        */
        void DeviceAbstractClass::registerDataConfig(const QList<QSharedPointer<DataConfigClass> > & dataConfigList)
        {
            for(QList<QSharedPointer<DataConfigClass> >::const_iterator ite = dataConfigList.begin();
                ite != dataConfigList.end();
                ite ++)
            {
                if(NULL != *ite)
                {
                    this->m_dataConfigMap[(*ite)->getGuid()] = *ite;
                }
            }
        }

        /*
         * @brief get data config
        */
        QSharedPointer<DataConfigClass> DeviceAbstractClass::getDataConfig(QString guid)
        {
            QSharedPointer<DataConfigClass> data;
            if(this->m_dataConfigMap.find(guid) != this->m_dataConfigMap.end())
            {
                data = *this->m_dataConfigMap.find(guid);
            }
            return data;
        }

        /*
         * @brief set device id
        */
        void DeviceAbstractClass::setDeviceId(int id)
        {
            this->m_deviceId = id;
        }

        /*
         * @brief get device id
        */
        const int &DeviceAbstractClass::getDeviceId()
        {
            return this->m_deviceId;
        }

        /*
         * @brief add data config
        */
        void DeviceAbstractClass::add(QSharedPointer<DataConfigClass> dataConfig)
        {
            this->m_dataConfigMap[dataConfig->getGuid()] = dataConfig;
        }

        /*
         * @brief build alarm info ...
        */
        void DeviceAbstractClass::buildAlarmInfo(int error, QString context, QString description)
        {
            this->m_alarmInfo->error_code = error;
            this->m_alarmInfo->error_context = context;
            this->m_alarmInfo->error_description =description ;
        }

        /**
         * @brief get alarm info struct
         */
        AlarmInformationsStruct *DeviceAbstractClass::getAlarmInfo()
        {
            return this->m_alarmInfo;
        }

        /*
         * @brief clear all register data
        */
        void DeviceAbstractClass::clear()
        {
            this->m_dataConfigMap.clear();
        }
    }
}
