#ifndef LIIKETUNNISTIN_H
#define LIIKETUNNISTIN_H

#include <QObject>

class LiikeTunnistin : public QObject
{
    Q_OBJECT
public:
    explicit LiikeTunnistin(QObject *parent = 0);

signals:

    void sensori(bool onkoIhminenHuoneessa);

public slots:

    void sensoriHavainto(bool saakoSensoriHavainnon);

};

#endif // LIIKETUNNISTIN_H
