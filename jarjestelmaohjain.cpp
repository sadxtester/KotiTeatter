#include "jarjestelmaohjain.h"
#include <QDebug>

static int MAXVALO = 100;
static int HIMMEAVALO = 50;
static int PIMEAVALO = 0;
JarjestelmaOhjain::JarjestelmaOhjain(QObject *parent) :
    QObject(parent)
{

    mp_liikesensori = new LiikeTunnistin(this);

    mp_valojenHallinta = new ValojenHallinta(this);

    mp_elokuvaLaitteisto = new ElokuvaLaitteisto(this);

    mp_verhojenHallinta = new VerhojenHallinta(this);

    m_ihminenHuoneessa = false;

    //Connect signals and slots
    connect(mp_liikesensori, SIGNAL(sensori(bool)),this,SLOT(ihminenHuoneessa(bool)));
    connect(this, SIGNAL(muutaValonTasoa(int)), mp_valojenHallinta,SLOT(muutaValonTasoa(int)));
    connect(mp_elokuvaLaitteisto, SIGNAL(laiteistoKytkettyPaallePois(bool)), this, SLOT(laitteistonTila(bool)));
    connect(this, SIGNAL(suljeAvaaVerhot(bool)), mp_verhojenHallinta, SLOT(avaaSuljeVerhot(bool)));
    connect(mp_elokuvaLaitteisto, SIGNAL(elokuvaPaalla(bool)), this, SLOT(elokuvaPaalla(bool)));
    connect(mp_elokuvaLaitteisto, SIGNAL(levyPoistettu()), this, SLOT(elokuaPoistettuLaitteesta()));


    testaaja();
}

JarjestelmaOhjain::~JarjestelmaOhjain(){

    delete mp_liikesensori;

    delete mp_valojenHallinta;

    delete mp_elokuvaLaitteisto;

    delete mp_verhojenHallinta;

}

//SLOT
void JarjestelmaOhjain::ihminenHuoneessa(bool onkoIhminenHuoneessa)
{

    qDebug() << "Signaali ihminen tunnistettu vastaanotettu";

    if(onkoIhminenHuoneessa && !m_ihminenHuoneessa){

        qDebug() << "Signaali valot p��lle l�hetetty";
        emit muutaValonTasoa(MAXVALO);



    }else if(!onkoIhminenHuoneessa && m_ihminenHuoneessa){

        qDebug() << "Signaali valot pois p��lt� l�hetetty";
        emit muutaValonTasoa(PIMEAVALO);



    }

    m_ihminenHuoneessa = onkoIhminenHuoneessa;
}



void JarjestelmaOhjain::laitteistonTila(bool onkoLaiteKaynnissa)
{



    if(onkoLaiteKaynnissa){
        qDebug() << "Signaali laite p�ll� vastaanotettu";

        qDebug() << "Signaali sulje verhot l�hetetty";
        emit suljeAvaaVerhot(true);

        qDebug() << "Signaali himmenn� valot l�hetetty";
        emit muutaValonTasoa(HIMMEAVALO);

    }else{
        qDebug() << "Signaali laite pois p��lt� vastaanotettu";

        qDebug() << "Signaali avaa verhot l�hetetty";
        emit suljeAvaaVerhot(false);
    }
}

void JarjestelmaOhjain::elokuvaPaalla(bool onkoElokuvaPaalla)
{

    if(onkoElokuvaPaalla){
        qDebug() << "Signaali elokuva k�ynnistetty astaanotettu";


         qDebug() << "Signaali sammuta valot l�hetetty";
         emit muutaValonTasoa(PIMEAVALO);


    }else{

        qDebug() << "Signaali elokuva pys�ytetty vastaanotettu";

         emit muutaValonTasoa(HIMMEAVALO);

    }

}

void JarjestelmaOhjain::elokuaPoistettuLaitteesta(){

    qDebug() << "Signaali elokuva poistettu laitteesta vastaan oettu";

     emit muutaValonTasoa(MAXVALO);

}

/**
  *Testi funktio
  *Kuvastaa laitteiden ja sensoreiden saamia signaaleja
  */
void JarjestelmaOhjain::testaaja(){

    connect(this, SIGNAL(lahetaSensorilleHavainto(bool)),mp_liikesensori,SLOT(sensoriHavainto(bool)));
    connect(this, SIGNAL(lahetaElokuvaLaitteistoPaalle(bool)),mp_elokuvaLaitteisto, SLOT(laitteistonTila(bool)));
    connect(this, SIGNAL(lahetaElokuvaPaalle(bool)), mp_elokuvaLaitteisto, SLOT(elokuvaPaallaPois(bool)));
    connect(this, SIGNAL(lahetaElokuvaUlosLaitteesta()), mp_elokuvaLaitteisto, SLOT(levyPoistettuLaitteesta()));

    //Viesti ihminen astuu huoneeseen
    emit lahetaSensorilleHavainto(true);

    //Viesti elokuva laitteistolle, ett� se on kytketty p��lle
    emit lahetaElokuvaLaitteistoPaalle(true);

    //Viesti elokuva laitteistolle, ett� elokuva on k�ynistetty

    emit lahetaElokuvaPaalle(true);

    //Viesti elokuva laitteistolle, ett� elokuva on pys�ytett

    emit lahetaElokuvaPaalle(false);

    //L�het� viesti elokuva poistettu laitteesta
    emit lahetaElokuvaUlosLaitteesta();

    //Viesti elokuva laitteistolle, ett� se on kytketty pois P��lt�
    emit lahetaElokuvaLaitteistoPaalle(false);

    //Viesti ihminen poistuu huoneesta
    emit lahetaSensorilleHavainto(false);




}
