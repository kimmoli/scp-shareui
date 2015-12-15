#ifndef SCPMEDIATRANSFER_H
#define SCPMEDIATRANSFER_H

#include <TransferEngine-qt5/mediatransferinterface.h>
#include <TransferEngine-qt5/mediaitem.h>

#include <QString>
#include <QVariant>

class ScpMediaTransfer : public MediaTransferInterface
{
    Q_OBJECT
public:
    ScpMediaTransfer(QObject * parent = 0);
    ~ScpMediaTransfer();

    bool	cancelEnabled() const;
    QString	displayName() const;
    bool	restartEnabled() const;
    QUrl	serviceIcon() const;

private:
    QString _mediaName;
    QString _target;

public slots:
    void	cancel();
    void	start();

};

#endif // SCPMEDIATRANSFER_H
