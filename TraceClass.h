#ifndef TRACECLASS_H
#define TRACECLASS_H
#include <QString>


void AppFuncEntry(const char * funcName,QString context);

void AppFuncExit(const char * funcName,QString context,int errorCode);

void AppTrace(const char * funcName,QString context);

#endif // TRACECLASS_H
