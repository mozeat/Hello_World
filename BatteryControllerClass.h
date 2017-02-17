#ifndef BATTERYCONTROLLERCLASS_H
#define BATTERYCONTROLLERCLASS_H
#include "BatteryClass.h"
namespace Appilication
{
    namespace Power
    {
        class BatteryControllerClass
        {
        public:
            BatteryControllerClass();
            ~BatteryControllerClass();
        public:
            /*
             * @brief read data config file
            */
            void readDataConfigFromXML(QString fileName);

            /*
             * @brief create all models
            */
            void createALlModels();

            /*
             * @brief get model
            */
            QSharedPointer<BatteryClass> getModelByGuid(QString guid);

        private:
            /*
             * @brief create model by id
            */
            void createModel(int batteryId);
        private:
            /*
             * @guid from GUID
            */
            QMap<int,QString> m_batteryDataGuid;

            /*
             * @Battery map
            */
            QMap<QString,QSharedPointer<BatteryClass> > m_guidBatteryInstanceMap;
        };
    }
}

#endif // BATTERYCONTROLLERCLASS_H
