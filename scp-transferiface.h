#ifndef SCPTRANSFERIFACE_H
#define SCPTRANSFERIFACE_H

#include <TransferEngine-qt5/transferplugininterface.h>
#include <TransferEngine-qt5/transferplugininfo.h>
#include <TransferEngine-qt5/transfermethodinfo.h>
#include <TransferEngine-qt5/mediatransferinterface.h>

class ScpSharePlugin : public QObject, public TransferPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "harbour.scp.transfer.plugin")
    Q_INTERFACES(TransferPluginInterface)
public:
    ScpSharePlugin();
    ~ScpSharePlugin();

    QString pluginId() const;
    bool enabled() const;
    TransferPluginInfo *infoObject();
    MediaTransferInterface *transferObject();
};

#endif // SCPTRANSFERIFACE_H
