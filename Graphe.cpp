//
// Created by Antoine Hintzy on 26/03/2020.
//

#include "Graphe.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include "Sommet.h"

Graphe::Graphe(std::string filename) {
    std::ifstream ifs{filename};
    if (!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + filename);
    }
    int ordre = 0;
    ifs >> ordre;
    if (ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'ordre du graphe.");
    }
    for (int i = 0; i < ordre; ++i) {
        m_sommets.push_back(new Sommet(i));
    }
    int taille = 0;
    ifs >> taille;
    if (ifs.fail()) {
        throw std::runtime_error("Problème de lecture de la taille du graphe.");
    }
    int num1 = 0, num2 = 0, poids = 0;
    for (int i = 0; i < taille; ++i) {
        ifs >> num1 >> num2 >> poids;
        m_aretes.push_back(new Arete(num1, num2,poids));

        if (ifs.fail()) {
            throw std::runtime_error("Problème de lecture d'un arc.");
        }
        m_sommets[num1]->addSuccesseur(m_sommets[num2], poids);


    }
    predecesseur = new int[m_sommets.size()];

    //i 0 1 2 3 4 5
    //parent[i] 0 1 2 3 4 5
    for (int i = 0; i < m_sommets.size(); i++)
    {
        predecesseur[i] = i;
    }


}

Graphe::~Graphe() {
    std::cout << "Destruction d'un graphe." << std::endl;
    for (auto s: m_sommets) {
        delete s;
    }
}

std::ostream &operator<<(std::ostream &out, const Graphe &graphe) {
    out << "Ordre : " << graphe.m_sommets.size() << std::endl;
    out << "Liste des Sommets : " << std::endl;
    for (auto s : graphe.m_sommets) {
        s->afficher();
    }
    std::cout<<std::endl<<"Listes des arretes et leurs poids :"<<std::endl;
    for (auto s : graphe.m_sommets) {
        s->afficherA();
    }
    return out;
}
void Graphe::TrierCroissant ()
{
    int a =0;
    for (const auto& pz: m_aretes)
    {
        if (pz->getPoids()>(pz+1)->getPoids())
        {
            a=pz->getPoids();
            pz->setPoids((pz+1)->getPoids());
            (pz+1)->setPoids(a);
        }

    }

}
int Graphe::verifPredecesseur(int Sommet) {
    // Si le sommet est son propre predecesseur
    if (Sommet == predecesseur[Sommet]){
        return Sommet;
    }
    else
    {
        //Si le sommet n'est pas son propre predecessur

        return verifPredecesseur(predecesseur[Sommet]);
    }

}

void Graphe::memePredecesseur(int sommetDepart, int sommetArrivee) {
    predecesseur[sommetDepart] = predecesseur[sommetArrivee];
}
void Graphe::Kruskal ()
{

    int sommetDepart=0,sommetArrivee=0;
    TrierCroissant();
    for (const auto& pz: m_aretes)
    {
        sommetDepart=verifPredecesseur(pz->getDepart());
        sommetArrivee=verifPredecesseur(pz->getArrive());
        if (sommetDepart!=sommetArrivee)
        {
            Arbre.emplace_back(pz->getPoids(),arete(pz->getDepart(),pz->getArrive()));
            memePredecesseur(sommetDepart,sommetArrivee);

        }
    }
}

void Graphe::afficherKruskal() {
    int distance=0;

    std::cout << "Passage par les aretes :" << std::endl;
    for (int i = 0; i < Arbre.size(); i++) {
        std::cout << Arbre[i].second.first << " - " << Arbre[i].second.second << " de poids "
                  << Arbre[i].first;
        std::cout << std::endl;
        distance=distance+Arbre[i].first;

    }
    std::cout<<std::endl << "Poids total :" << distance<< std::endl;
    //probleme avec le poids mais on ne comprends pas pourquoi
}
