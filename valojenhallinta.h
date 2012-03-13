#ifndef VALOJENHALLINTA_H
#define VALOJENHALLINTA_H


#include <QObject>

class ValojenHallinta : public QObject
{
    Q_OBJECT
public:
    explicit ValojenHallinta(QObject *parent = 0);
private:

    void setValontaso(int taso);

    int m_valontaso;

signals:

    void valonTasoMuuttunut(int m_valontaso);

public slots:

    void muutaValonTasoa(int);

};

#endif // VALOJENHALLINTA_H
