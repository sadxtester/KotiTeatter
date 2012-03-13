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

        qDebug() << "Laitteisto kytketty päälle viesti lähetetty";
        emit laiteistoKytkettyPaallePois(true);

    }else{

        qDebug() << "Laitteisto kytketty pois päältä viesti lähetetty";

        emit laiteistoKytkettyPaallePois(false);

    }


}

void ElokuvaLaitteisto::elokuvaPaallaPois(bool onkoElokuvaKaynnissa)
{



    if(onkoElokuvaKaynnissa){

        qDebug() << "signaali elokuvan käynnissä vastaanotettu ";

        qDebug() << "signaali elokuva päällä lähetetty";


        emit elokuvaPaalla(true);

    }else{

        qDebug() << "signaali elokuvan pysäytetty vastaanotettu ";

        qDebug() << "signaali elokuva poispäältä lähetetty";

        emit elokuvaPaalla(false);
    }



}

void ElokuvaLaitteisto::levyPoistettuLaitteesta()
{
    qDebug() << "signaali levypoistettulaitteesta vastaanotettu ";

    qDebug() << "signaali levy poistettu lähetetty";

    emit levyPoistettu();



}


