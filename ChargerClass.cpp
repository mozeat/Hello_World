#include "ChargerClass.h"
#include "TR4A_if.h"

namespace Appilication
{
    namespace Power
    {
        ChargerClass::ChargerClass()
        {

        }

        ChargerClass::~ChargerClass()
        {

        }

        /*
         * @brief set state data config
        */
        void ChargerClass::setStateData(QSharedPointer<DataConfigClass> data)
        {
            TR4A_FuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(data->getName()).arg(data->getGuid()));
            this->m_stateData = data;
            TR4A_FuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> ChargerClass::getStateData()
        {
            return this->m_stateData;
        }

        /*
         * @brief set work state data config
        */
        void ChargerClass::setWorkStateData(QSharedPointer<DataConfigClass> data)
        {
            TR4A_FuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(data->getName()).arg(data->getGuid()));
            this->m_workStateData = data;
            TR4A_FuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> ChargerClass::getWorkStateData()
        {
            return this->m_workStateData;
        }

        /*
         * @brief set connect state data config
        */
        void ChargerClass::setConnectStateData(QSharedPointer<DataConfigClass> data)
        {
            TR4A_FuncEntry(__FUNCTION__,QString("name[%1]-guid[%2]").arg(data->getName()).arg(data->getGuid()));
            this->m_connectData = data;
            TR4A_FuncExit(__FUNCTION__,"null",0);
        }

        QSharedPointer<DataConfigClass> ChargerClass::getConnectStateData()
        {
            return this->m_connectData;
        }

    }
}
