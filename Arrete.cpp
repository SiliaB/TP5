//
// Created by Faustine on 05/04/2020.
//

#include "Arrete.h"

Arete::Arete(int depart, int arrive,int poids): m_poids{poids}, depart{depart}, arrive{arrive}{}

int Arete:: getDepart() const {return depart;}
int Arete::getArrive() const {return arrive;}

int Arete::getPoids() const {return m_poids;}

int Arete :: setPoids(int newPoids)
{
    m_poids=newPoids;
    return m_poids;
}