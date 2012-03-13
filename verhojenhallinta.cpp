#include "verhojenhallinta.h"
#include <QDebug>

VerhojenHallinta::VerhojenHallinta(QObject *parent) :
    QObject(parent)
{

    m_onkoVerhotAuki = false;
}


void VerhojenHallinta::avaaSuljeVerhot(bool suljetaankoVerhot){

    qDebug() << "signaali verhojen avaamisesta/sulkemisesta vastaan otettu";

    if(suljetaankoVerhot){

        m_onkoVerhotAuki = false;

    }else{

        m_onkoVerhotAuki = true;

    }


    if(m_onkoVerhotAuki){

        qDebug() << "Verhojen tila: auki";

    }else{

        qDebug() << "Verhojen tila: kiinni";

    }


    qDebug() << "signaali verhojen tilasta lähetetty";
    qDebug() << "HUOM! Signaalilla ei vastaanottajaa";


    emit verhojenTila(m_onkoVerhotAuki);



}

