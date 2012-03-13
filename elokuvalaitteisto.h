#ifndef ELOKUVALAITTEISTO_H
#define ELOKUVALAITTEISTO_H

#include <QObject>

class ElokuvaLaitteisto : public QObject
{
    Q_OBJECT
public:
    explicit ElokuvaLaitteisto(QObject *parent = 0);

signals:

    void laiteistoKytkettyPaallePois(bool onkoLaitteistoPaalla);

    void elokuvaPaalla(bool onkoElokuvapaalla);

    void levyPoistettu();


public slots:

    void laitteistonTila(bool onkoLaitteistoPaalla);

    void elokuvaPaallaPois(bool onkoElokuvaKaynnissa);

    void levyPoistettuLaitteesta();

};

#endif // ELOKUVALAITTEISTO_H
