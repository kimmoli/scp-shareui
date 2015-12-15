#ifndef SCPPLUGININFO_H
#define SCPPLUGININFO_H

#include <TransferEngine-qt5/transferplugininfo.h>
#include <TransferEngine-qt5/transfermethodinfo.h>

class ScpPluginInfo : public TransferPluginInfo
{
    Q_OBJECT
public:
    ScpPluginInfo();
    ~ScpPluginInfo();
    QList<TransferMethodInfo> info() const;
    void query();
    bool ready() const;

private:
    QList<TransferMethodInfo> m_infoList;
    bool m_ready;

};

#endif // SCPPLUGININFO_H
