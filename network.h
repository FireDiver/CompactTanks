#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTimer>
#include "tank.h"
#include "bullet.h"

class Network : public QObject
{
    Q_OBJECT
private slots:
    void on_tcpRecv();
    void on_udpRecv();
    void on_tmain();
private:
    QHostAddress ip;
    QTimer *t_main;
    QTcpSocket *tcpSocket;
    QUdpSocket *udpSocketListen;
    QUdpSocket *udpSocket;
    QVector <Tank*> players;
    Tank *ownTank;
    Tank *sucheTank(QString name);
    int getArrayPos(QString name);
    void fetchUDP(QString data);
    void fetchTCP(QString data);
    quint16 udpPort;
public:
    explicit Network(Tank *ownTank, QVector<Tank*> t, QHostAddress ip, QObject *parent = 0);
    ~Network();
    void send(QString data);

signals:
    void newPlayer(Tank *t);
    void newlvlObj(int x,int y,int w,int h);
    void delPlayer(int i);
    void newBullet(Bullet *b);
    void delBullet(int pos);
    void syncBullet(int pos,int x,int y);
    void setViewRange(int vr);
public slots:
};

#endif // NETWORK_H