#include "TR4A_if.h"
#include <QDebug>
#include <QTime>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#define TR4A_FileName "/usr/local/PowerMobile/NIO/TR/DefaultTR.log"

QMutex g_app_mutex;
void TR4A_FuncEntry(const char *funcName, QString context)
{
    g_app_mutex.lock();
    if(NULL == funcName ||  context.isNull())
    {
        return;
    }
#ifdef APP_DEBUG
    QDate date = QDate::currentDate();
    QString dateFomate = "yyyy-MM-dd";
    date.toString(dateFomate);
    QTime time =QTime:: currentTime();
    QString timeFormat = "hh:mm:ss.zzz";
    time.toString(timeFormat);
    qDebug() << date << " "  << time << ": "<<funcName << ">(): " << context;

    QFile file(TR4A_FileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QString datetxt = date.toString(dateFomate);
    QString timetxt = time.toString(timeFormat);;
    QTextStream out(&file);
    out << datetxt << " "<< timetxt << ": "<<funcName << ">(): " << context << "\n";
    file.close();
#endif
    g_app_mutex.unlock();
    return;
}

void TR4A_FuncExit(const char *funcName, QString context, int errorCode)
{
    g_app_mutex.lock();
    if(NULL == funcName ||  context.isNull())
    {
        return;
    }
#ifdef APP_DEBUG
    QDate date = QDate::currentDate();
    QString dateFomate = "yyyy-MM-dd";
    date.toString(dateFomate);
    QTime time =QTime:: currentTime();
    QString timeFormat = "hh:mm:ss.zzz";
    time.toString(timeFormat);
    qDebug() << date << " " << time << ": "<< funcName << "<(): " << context << "errorCode[" << errorCode << "]";

    QFile file(TR4A_FileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QString datetxt = date.toString(dateFomate);
    QString timetxt = time.toString(timeFormat);;
    QTextStream out(&file);
    out << datetxt << " "<< timetxt << ": "<<funcName << ">(): " << context << "errorCode[" << errorCode << "]" << "\n";
    file.close();
#endif
    errorCode = errorCode;
    g_app_mutex.unlock();
    return;
}

void TR4A_FuncTrace(const char *funcName, QString context)
{
    g_app_mutex.lock();
    if(NULL == funcName ||  context.isNull())
    {
        return;
    }
#ifdef APP_DEBUG
    QDate date = QDate::currentDate();
    QString dateFomate = "yyyy-MM-dd";
    date.toString(dateFomate);
    QTime time =QTime:: currentTime();
    QString timeFormat = "hh:mm:ss.zzz";
    time.toString(timeFormat);
    qDebug() << date << " " << time << ": " << funcName << "> :: " << context;

    QFile file(TR4A_FileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QString datetxt = date.toString(dateFomate);
    QString timetxt = time.toString(timeFormat);;
    QTextStream out(&file);
    out << datetxt << " "<< timetxt << ": "<<funcName << ">(): " << context << "\n";
    file.close();
#endif
    g_app_mutex.unlock();
    return;
}
