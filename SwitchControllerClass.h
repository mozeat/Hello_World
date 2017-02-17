#ifndef SWITCHCONTROLLERCLASS_H
#define SWITCHCONTROLLERCLASS_H
#include "SwitchClass.h"
#include "app_global.h"
#include "DataService.h"
namespace Appilication
{
    namespace Power
    {
        class SwitchControllerClass
        {
        public:
            SwitchControllerClass();
            ~SwitchControllerClass();
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
            QSharedPointer<SwitchClass> getModelByGuid(QString guid);

            //ctrl cmd -guid
            void setPowerMode(QString ctrlCmd,APP_POWER_MODE_ENUM mode);

            //ctrl cmd -guid
            APP_POWER_MODE_ENUM  getPowerMode(QString ctrlCmd);

            void checkSwitchLogicStateValid(QSharedPointer<Platform::Middleware::DataService> dataService,const GUID & ctrl_id)
            {
                if(dataService.isNull() || ctrl_id.isNull())
                {
                    return;
                }
            }

        private:
            /*
             * @brief create model by id
            */
            void createModel(int SwitchId);
        private:
            /*
             * @guid from GUID
            */
            QMap<int,QString> m_switchDataGuid;

            /*
             * @Battery map
            */
            QMap<QString,QSharedPointer<SwitchClass> > m_guidSwitchInstanceMap;

            /*
             * @power mode map
            */
            QMap<QString,APP_POWER_MODE_ENUM> m_power_mode_map;
        };
    }
}
#endif // SWITCHCONTROLLERCLASS_H
