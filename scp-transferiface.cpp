#include "scp-transferiface.h"
#include "scp-plugininfo.h"
#include "scp-mediatransfer.h"

#include <QtPlugin>

ScpSharePlugin::ScpSharePlugin()
{

}

ScpSharePlugin::~ScpSharePlugin()
{

}

QString ScpSharePlugin::pluginId() const
{
    return QLatin1String("ScpSharePlugin");
}

bool ScpSharePlugin::enabled() const
{
    return true;
}

TransferPluginInfo *ScpSharePlugin::infoObject()
{
    return new ScpPluginInfo;
}

MediaTransferInterface *ScpSharePlugin::transferObject()
{
    return new ScpMediaTransfer;
}
