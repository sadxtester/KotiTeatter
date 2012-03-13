#include "valojenhallinta.h"
#include <QDebug>

static int MAXVALONTASO = 100;

ValojenHallinta::ValojenHallinta(QObject *parent) :
    QObject(parent)
{
}

void ValojenHallinta::muutaValonTasoa(int lahetettyTaso){

    qDebug() << "Signaali valontason muuttamisesta vastaanotettu";

    setValontaso(lahetettyTaso);

}

void ValojenHallinta::setValontaso(int taso){

    if(taso < MAXVALONTASO){

        m_valontaso = taso;

    }else{

        taso = MAXVALONTASO;

        m_valontaso = taso;

    }

    qDebug() << "Valon tasoksi asetettu " << m_valontaso;


    qDebug() << "Signaali valontaso muuttunut lähetetty";
    qDebug() << "HUOM! Tällä signaalilla ei ole vastaanottajaa";
    emit valonTasoMuuttunut(m_valontaso);



}
