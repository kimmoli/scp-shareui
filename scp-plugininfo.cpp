#include "scp-plugininfo.h"

ScpPluginInfo::ScpPluginInfo(): m_ready(false)
{
}

ScpPluginInfo::~ScpPluginInfo()
{

}

QList<TransferMethodInfo> ScpPluginInfo::info() const
{
    return m_infoList;
}

void ScpPluginInfo::query()
{
    TransferMethodInfo info;

    QStringList capabilities;
    capabilities << QLatin1String("image/*")
                 << QLatin1String("text/*")
                 << QLatin1String("application/*")
                 << QLatin1String("video/*")
                 << QLatin1String("audio/*");

    info.displayName     = QLatin1String("Scp");
    info.methodId        = QLatin1String("ScpSharePlugin");
    info.shareUIPath     = QLatin1String("/usr/share/scp-shareui/qml/shareui.qml");
    info.capabilitities  = capabilities;
    m_infoList.clear();
    m_infoList << info;

    m_ready = true;
    Q_EMIT infoReady();
}

bool ScpPluginInfo::ready() const
{
    return m_ready;
}
