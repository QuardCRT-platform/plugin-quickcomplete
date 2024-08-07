#ifndef QUICKCOMPLETE_H_
#define QUICKCOMPLETE_H_

#include "plugininterface.h"

#define PLUGIN_NAME    "Quick Complete"
#define PLUGIN_VERSION "0.0.3"
#define PLUGIN_WEBSITE "https://github.com/QuardCRT-platform/plugin-quickcomplete"

class QuickComplete : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.quardCRT.PluginInterface" FILE "./plugininterface/plugininterface.json")
    Q_INTERFACES(PluginInterface)

public:
    QuickComplete() : PluginInterface(), m_menu(nullptr), addQuickCompleteAction(nullptr), removeQuickCompleteAction(nullptr), clearQuickCompleteAction(nullptr) {}
    virtual ~QuickComplete() {}

    int init(QMap<QString, QString> params, QWidget *parent);
    void setLanguage(const QLocale &language,QApplication *app);
    void retranslateUi();

    QString name() { return PLUGIN_NAME; }
    QString version() { return PLUGIN_VERSION; }

    QMap<QString,void *> metaObject() {
        QMap<QString,void *> ret;
        ret.insert("QMenu", (void *)m_menu);
        ret.insert("website", (void *)(&m_website));
        return ret;
    }

    QMenu *terminalContextMenu(QString selectedText, QString workingDirectory, QMenu *parentMenu) {Q_UNUSED(selectedText);Q_UNUSED(workingDirectory);Q_UNUSED(parentMenu); return nullptr;}
    QList<QAction *> terminalContextAction(QString selectedText, QString workingDirectory, QMenu *parentMenu) {Q_UNUSED(selectedText);Q_UNUSED(workingDirectory);Q_UNUSED(parentMenu); return QList<QAction *>();}
    
private:
    void quickCompleteListChanged();
    QMenu *m_menu;
    QString m_website = QString(PLUGIN_WEBSITE);
    QAction *addQuickCompleteAction;
    QAction *removeQuickCompleteAction;
    QAction *clearQuickCompleteAction;
    QStringList m_quickCompleteList;
};

#endif /* QUICKCOMPLETE_H_ */
