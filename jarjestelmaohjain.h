#ifndef JARJESTELMAOHJAIN_H
#define JARJESTELMAOHJAIN_H

#include <QObject>

#include "liiketunnistin.h"
#include "valojenhallinta.h"
#include "elokuvalaitteisto.h"
#include "verhojenhallinta.h"

class JarjestelmaOhjain : public QObject
{
    Q_OBJECT
public:
    explicit JarjestelmaOhjain(QObject *parent = 0);
    ~JarjestelmaOhjain();


protected:

    LiikeTunnistin *mp_liikesensori;
    ValojenHallinta *mp_valojenHallinta;
    ElokuvaLaitteisto *mp_elokuvaLaitteisto;
    VerhojenHallinta *mp_verhojenHallinta;



private:

//    LiikeTunnistin *mp_liikesensori;
//    ValojenHallinta *mp_valojenHallinta;


    bool m_ihminenHuoneessa;
    void testaaja();

signals:

    void muutaValonTasoa(int valonTaso);

    void suljeAvaaVerhot(bool suljetaankoVerhot);

    //Tämä vain testi tarkoitusta varten
    void lahetaSensorilleHavainto(bool ihminenTunnistettu);

    //Tämä vain testi tarkoitusta varten
    void lahetaElokuvaLaitteistoPaalle(bool laitePaalle);

    //Tämä vain testi tarkoitusta varten
    void lahetaElokuvaPaalle(bool elokuvaPaalle);

    //Tämä vain testi tarkoitusta varten
    void lahetaElokuvaUlosLaitteesta();

public slots:

    void ihminenHuoneessa(bool onkoIhminenHuoneessa);
    void laitteistonTila(bool onkoLaiteKaynnissa);
    void elokuvaPaalla(bool onkoElokuvaPaalla);
    void elokuaPoistettuLaitteesta();


};

#endif // JARJESTELMAOHJAIN_H
