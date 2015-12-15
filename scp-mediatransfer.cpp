#include "scp-mediatransfer.h"
#include <QVariantMap>

ScpMediaTransfer::ScpMediaTransfer(QObject *parent) :
    MediaTransferInterface(parent)
{
}

ScpMediaTransfer::~ScpMediaTransfer()
{

}

bool ScpMediaTransfer::cancelEnabled() const
{
    return false;
}

QString ScpMediaTransfer::displayName() const
{
    return QString("Scp");
}

bool ScpMediaTransfer::restartEnabled() const
{
    return false;
}

QUrl ScpMediaTransfer::serviceIcon() const
{
    return QUrl::fromLocalFile("/usr/share/scp-shareui/qml/notification.png");
}

void ScpMediaTransfer::cancel()
{
    setStatus(MediaTransferInterface::TransferCanceled);
}

void ScpMediaTransfer::start()
{
    _mediaName = mediaItem()->value(MediaItem::Url).toString().replace("file://", "");

    QVariantMap userdata = mediaItem()->value(MediaItem::UserData).toMap();
    _target = userdata.value("targetpath").toString();

    /* tell that we are starting this */
    setStatus(MediaTransferInterface::TransferStarted);

    int r = system(QString("scp %1 %2").arg(_mediaName).arg(_target).toUtf8().constData());

    /* In case of error */
    if (r != 0)
        setStatus(MediaTransferInterface::TransferInterrupted);

    /* Finished */
    setStatus(MediaTransferInterface::TransferFinished);
}
