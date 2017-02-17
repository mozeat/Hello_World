#include "ExceptionClass.h"

namespace Appilication
{
    namespace Power
    {
        ExceptionClass::ExceptionClass(NIO_INT16 errorCode,
                                       QString msg,
                                       const char *stdException)
            :m_errorCode(errorCode)
            ,m_msg(msg)
            ,m_stdException(stdException)
        {

        }

        ExceptionClass::~ExceptionClass() throw()
        {

        }

        const NIO_INT16  &ExceptionClass::getErrorCode()
        {
            return this->m_errorCode;
        }

        const QString  &ExceptionClass::getErrorMsg()
        {
            return this->m_msg;
        }

        const char *ExceptionClass::stdException()
        {
            return this->m_stdException;
        }

    }
}
