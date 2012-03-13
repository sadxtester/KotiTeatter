#include "elokuvalaitteisto.h"
#include <QDebug>

ElokuvaLaitteisto::ElokuvaLaitteisto(QObject *parent) :
    QObject(parent)
{
}

void ElokuvaLaitteisto::laitteistonTila(bool onkoLaitteistoPaalla)
{
    qDebug() << "Laitteiston tilan signaali vastaanotettu";

    if(onkoLaitteistoPaalla){

        qDebug() << "Laitteisto kytketty p��lle viesti l�hetetty";
        emit laiteistoKytkettyPaallePois(true);

    }else{

        qDebug() << "Laitteisto kytketty pois p��lt� viesti l�hetetty";

        emit laiteistoKytkettyPaallePois(false);

    }


}

void ElokuvaLaitteisto::elokuvaPaallaPois(bool onkoElokuvaKaynnissa)
{



    if(onkoElokuvaKaynnissa){

        qDebug() << "signaali elokuvan k�ynniss� vastaanotettu ";

        qDebug() << "signaali elokuva p��ll� l�hetetty";


        emit elokuvaPaalla(true);

    }else{

        qDebug() << "signaali elokuvan pys�ytetty vastaanotettu ";

        qDebug() << "signaali elokuva poisp��lt� l�hetetty";

        emit elokuvaPaalla(false);
    }



}

void ElokuvaLaitteisto::levyPoistettuLaitteesta()
{
    qDebug() << "signaali levypoistettulaitteesta vastaanotettu ";

    qDebug() << "signaali levy poistettu l�hetetty";

    emit levyPoistettu();



}


