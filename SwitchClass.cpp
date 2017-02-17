#include "SwitchClass.h"
#include "TR4A_if.h"

namespace Appilication
{
    namespace Power
    {
        SwitchClass::SwitchClass()
        {

        }

        SwitchClass::~SwitchClass()
        {

        }

        void SwitchClass::setKM1_2StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM1_2StatusData = data;
        }

        QSharedPointer<DataConfigClass> SwitchClass::getKM1_2StatusData()
        {
            return this->m_KM1_2StatusData;
        }

        QSharedPointer<DataConfigClass> SwitchClass::getKM12StatusData()
        {
            return this->m_KM12StatusData;
        }

        /*
         * @brief set KM13 data config
        */
        void SwitchClass::setKM13StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM13StatusData = data;
        }

        /*
         * @brief get KM13 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM13StatusData()
        {
            return this->m_KM13StatusData;
        }

        /*
         * @brief set KM14 data config
        */
        void SwitchClass::setKM14StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM14StatusData = data;
        }

        /*
         * @brief get KM14 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM14StatusData()
        {
            return this->m_KM14StatusData;
        }

        /*
         * @brief set KM15 data config
        */
        void SwitchClass::setKM15StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM15StatusData = data;
        }
        /*
         * @brief get KM15 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM15StatusData()
        {
            return this->m_KM15StatusData;
        }


        /*
         * @brief set KM12 data config
        */
        void SwitchClass::setKM12StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM12StatusData = data;
        }

        /*
         * @brief set KM34 data config
        */
        void SwitchClass::setKM3_4StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM3_4StatusData = data;
        }

        /*
         * @brief get KM34 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM3_4StatusData()
        {
            return this->m_KM3_4StatusData;
        }

        /*
         * @brief set qf data config
        */
        void SwitchClass::setQfStatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_qfStatusData = data;
        }
        /*
         *
         * @brief get qf data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getQfStatusData()
        {
            return this->m_qfStatusData;
        }

        /*
         * @brief set qf data config
        */
        void SwitchClass::setHostQfStatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_hostQFStatusData = data;
        }

        /*
         * @brief get host Qf data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getHostQfStatusData()
        {
            return this->m_hostQFStatusData;
        }

        /*
         * @brief set KM56 data config
        */
        void SwitchClass::setKM5_6StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM56StatusData = data;
        }

        /*
         * @brief set Km56 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM56StatusData()
        {
            return this->m_KM56StatusData;
        }

        /*
         * @brief set KM7 data config
        */
        void SwitchClass::setKM7StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM7StatusData = data;
        }

        /*
         * @brief get KM7 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM7StatusData()
        {
            return this->m_KM7StatusData;
        }

        /*
         * @brief set KM8 data config
        */
        void SwitchClass::setKM8StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM8StatusData = data;
        }

        /*
         * @brief get KM8 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM8StatusData()
        {
            return this->m_KM8StatusData;
        }

        /*
         * @brief set KM9 data config
        */
        void SwitchClass::setKM9StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM9StatusData = data;
        }

        /*
         * @brief set KM9 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM9StatusData()
        {
            return this->m_KM9StatusData;
        }

        void SwitchClass::setKM10StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM10StatusData = data;
        }

        /*
         * @brief set KM10 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM10StatusData()
        {
            return this->m_KM10StatusData;
        }

        /*
         * @brief set KM11 data config
        */
        void SwitchClass::setKM11StatusData(QSharedPointer<DataConfigClass> data)
        {
            this->m_KM11StatusData = data;
        }

        /*
         * @brief set KM11 data config
        */
        QSharedPointer<DataConfigClass> SwitchClass::getKM11StatusData()
        {
            return this->m_KM11StatusData;
        }

    }
}
