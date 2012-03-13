#include "liiketunnistin.h"
#include <QDebug>

LiikeTunnistin::LiikeTunnistin(QObject *parent) :
    QObject(parent)
{

    //connect(this,SIGNAL(sensori(bool)),this,SIGNAL(sensori(bool)));

}

//SLOT
void LiikeTunnistin::sensoriHavainto(bool saakoSensoriHavainnon){

    qDebug() << "Signaali ihminen tunnistettu lähetetty";
    emit sensori(saakoSensoriHavainnon);




}
