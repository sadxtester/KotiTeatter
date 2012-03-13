#ifndef VERHOJENHALLINTA_H
#define VERHOJENHALLINTA_H

#include <QObject>

class VerhojenHallinta : public QObject
{
    Q_OBJECT
public:
    explicit VerhojenHallinta(QObject *parent = 0);

private:

    bool m_onkoVerhotAuki;

signals:

    void verhojenTila(bool m_onkoVerhotAuki);

public slots:

    void avaaSuljeVerhot(bool suljetaankoVerhot);

};

#endif // VERHOJENHALLINTA_H
