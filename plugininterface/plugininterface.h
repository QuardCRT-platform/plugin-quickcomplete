#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QtPlugin>
#include <QObject>
#include <QMap>
#include <QMenu>
#include <QAction>
#include <QVariant>
#include <QLocale>

class PluginInterface : public QObject
{
    Q_OBJECT
public:
    virtual ~PluginInterface() {}
    virtual int init(QMap<QString, QString> params, QWidget *parent) = 0;
    virtual QString name() = 0;
    virtual QString version() = 0;
    virtual QMenu *menu() = 0;
    virtual QAction *action() = 0;
    virtual void setLanguage(const QLocale &language,QApplication *app) = 0;
    virtual void retranslateUi() = 0;

signals:
    void sendCommand(QString cmd);
    void writeSettings(QString path, QString key, QVariant value);
    void readSettings(QString path, QString key, QVariant &value);
};

#define PluginInterface_iid "org.quardCRT.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGININTERFACE_H