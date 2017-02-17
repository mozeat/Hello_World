#ifndef CHARGERCONTROLLERCLASS_H
#define CHARGERCONTROLLERCLASS_H
#include "ChargerClass.h"
namespace Appilication
{
    namespace Power
    {
        class ChargerControllerClass
        {
        public:
            ChargerControllerClass();
            ~ChargerControllerClass();
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
            QSharedPointer<ChargerClass> getModelByGuid(QString guid);
        private:

            /*
             * @brief create model by id
            */
            void createModel(int ChargerId);
        private:
            /*
             * @guid from GUID
            */
            QMap<int,QString> m_chargerDataGuid;

            /*
             * @Battery map
            */
            QMap<QString,QSharedPointer<ChargerClass> > m_guidChargerInstanceMap;
        };
    }
}

#endif // CHARGERCONTROLLERCLASS_H
