#ifndef TR4A_IF_H
#define TR4A_IF_H
#include <QString>


void TR4A_FuncEntry(const char * funcName,QString context);

void TR4A_FuncExit(const char * funcName,QString context,int errorCode);

void TR4A_FuncTrace(const char * funcName,QString context);

#endif // TR4A_IF_H
