#ifndef EXCEPTIONCLASS_H
#define EXCEPTIONCLASS_H
#include <exception>
#include <QString>
#include "NIO_type.h"

#define __THROW_PM_EXCEPTION(e)  throw(e)
#define __PM_TRY  try
#define __PM_CATCH(e) catch(Appilication::Power::ExceptionClass & e)

namespace Appilication
{
    namespace Power
    {
        class ExceptionClass : public std::exception
        {
        public:
            ExceptionClass(NIO_INT16 errorCode,
                           QString msg,
                           const char* stdException);
            ~ExceptionClass() throw();
        public:
            const NIO_INT16 & getErrorCode();
            const QString & getErrorMsg();
            const char * stdException();
        private:
            NIO_INT16 m_errorCode;
            QString m_msg;
            const char* m_stdException;
        };
    }
}
#endif // EXCEPTIONCLASS_H
