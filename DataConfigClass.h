#ifndef DATACONFIGCLASS_H
#define DATACONFIGCLASS_H
#include <QString>
#include <QVariant>
#include <QDebug>

namespace Appilication
{
    namespace Power
    {
        class DataConfigClass
        {
        public:
            DataConfigClass();
            DataConfigClass(QString name ,
                            QString guid);
            ~DataConfigClass();
        public:
            /*
             * @brief data name
            */
            void setName(QString name);
            const QString & getName();

            /*
             * @brief set guid
            */
            void setGuid(QString guid);
            const QString & getGuid();

            /*
             * @brief set switch ctrl data value in ac charge mode
            */
            void setAcModeSwValue(QVariant ac_value);
            const QVariant & getAcModeSwValue();

            /*
             * @brief set switch ctrl data value in Dc charge mode
            */
            void setDcModeSwValue(QVariant dc_value);
            const QVariant & getDcModeSwValue();

            /*
             * @brief set switch ctrl data value in ac charge mode
            */
            void setChargeModeSwValue(QVariant charge_value);
            const QVariant & getChargeModeSwValue();

            /*
             * @brief set ctrl data value
            */
            void setDefaultValue(QVariant default_value);
            const QVariant & getDefaultValue();

            /*
             * @brief set work data value
            */
            void setWorkValue(QVariant value);
            const QVariant & getWorkValue();

            /*
             * @brief set error data value
            */
            void setErrorValue(QVariant value);
            const QVariant & getErrorValue();
        private:
            QString m_name;
            QString m_guid;
            QVariant m_defaultValue;
            QVariant m_AC_value;
            QVariant m_DC_value;
            QVariant m_chargeValue;
            QVariant m_value;
            QVariant m_workValue;
            QVariant m_errorValue;
        };
    }
}


#endif // DATACONFIGCLASS_H
