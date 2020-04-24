#ifndef TP2_TG_ARETE_H
#define TP2_TG_ARETE_H
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Arrete.h"

class Arete {
private :

    int m_poids;
    int depart;
    int arrive;

public:
    Arete (int depart, int arrive,int poids);
    ~Arete()=default;

    int getPoids() const;
    int setPoids(int newPoids);
    int getDepart() const;
    int getArrive() const;




};


#endif //TP2_TG_ARETE_H

