#ifndef SWITCHCLASS_H
#define SWITCHCLASS_H
#include <QList>
#include <QSharedPointer>
#include "DataConfigClass.h"
#include "DeviceAbstractClass.h"
namespace Appilication
{
    namespace Power
    {
        class SwitchClass:public DeviceAbstractClass
        {
        public:
            SwitchClass();
            ~SwitchClass();
        public:
            /*
             * @brief set k12 data config
            */
            void setKM1_2StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM1_2StatusData();

            /*
             * @brief set k34 data config
            */
            void setKM3_4StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM3_4StatusData();

            /*
             * @brief set qf data config
            */
            void setQfStatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getQfStatusData();

            /*
             * @brief set Host qf data config
            */
            void setHostQfStatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getHostQfStatusData();

            /*
             * @brief set KM56 data config
            */
            void setKM5_6StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM56StatusData();

            /*
             * @brief set KM56 data config
            */
            void setKM7StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM7StatusData();

            /*
             * @brief set KM8 data config
            */
            void setKM8StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM8StatusData();


            /*
             * @brief set KM9 data config
            */
            void setKM9StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM9StatusData();


            /*
             * @brief set KM10 data config
            */
            void setKM10StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM10StatusData();


            /*
             * @brief set KM11 data config
            */
            void setKM11StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM11StatusData();


            /*
             * @brief set KM12 data config
            */
            void setKM12StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM12StatusData();


            /*
             * @brief set KM13 data config
            */
            void setKM13StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM13StatusData();

            /*
             * @brief set KM14 data config
            */
            void setKM14StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM14StatusData();

            /*
             * @brief set KM15 data config
            */
            void setKM15StatusData(QSharedPointer<DataConfigClass> data);
            QSharedPointer<DataConfigClass> getKM15StatusData();

        private:
            QSharedPointer<DataConfigClass> m_qfStatusData;
            QSharedPointer<DataConfigClass> m_KM1_2StatusData;
            QSharedPointer<DataConfigClass> m_KM3_4StatusData;
            QSharedPointer<DataConfigClass> m_KM56StatusData;
            QSharedPointer<DataConfigClass> m_KM7StatusData;
            QSharedPointer<DataConfigClass> m_KM8StatusData;
            QSharedPointer<DataConfigClass> m_KM9StatusData;
            QSharedPointer<DataConfigClass> m_KM10StatusData;
            QSharedPointer<DataConfigClass> m_KM11StatusData;
            QSharedPointer<DataConfigClass> m_KM12StatusData;
            QSharedPointer<DataConfigClass> m_KM13StatusData;
            QSharedPointer<DataConfigClass> m_KM14StatusData;
            QSharedPointer<DataConfigClass> m_KM15StatusData;
            QSharedPointer<DataConfigClass> m_hostQFStatusData;
            QMap<QString,QSharedPointer<DataConfigClass> > m_dataConfigMap;
        };
    }
}
#endif // SWITCHCLASS_H
