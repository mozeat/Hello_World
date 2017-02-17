#ifndef CHARGERCLASS_H
#define CHARGERCLASS_H
#include <QList>
#include <QSharedPointer>
#include "DataConfigClass.h"
#include "DeviceAbstractClass.h"
namespace Appilication
{
    namespace Power
    {
        class ChargerClass:public DeviceAbstractClass
        {
        public:
            ChargerClass();
            ~ChargerClass();
        public:
            /*
             * @brief set state data config
            */
            void setStateData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getStateData();

            /*
             * @brief set work state data config
            */
            void setWorkStateData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getWorkStateData();

            /*
             * @brief set connect state data config
            */
            void setConnectStateData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getConnectStateData();
        private:

            QSharedPointer<DataConfigClass> m_stateData;
            QSharedPointer<DataConfigClass> m_connectData;
            QSharedPointer<DataConfigClass> m_workStateData;
        };
    }
}
#endif // CHARGERCLASS_H
