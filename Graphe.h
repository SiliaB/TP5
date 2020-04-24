//
// Created by Antoine Hintzy on 26/03/2020.
//

#ifndef KRUSKAL_GRAPHE_H
#define KRUSKAL_GRAPHE_H

#include <list>
#include <ostream>
#include "Sommet.h"
#include "Arrete.h"
#define arete std::pair<int,int>

class Graphe {
private:
    std::vector<Sommet *> m_sommets;
    std::vector<Arete*> m_aretes;
    std::vector<std::pair<int,arete>> Arbre;
    int *predecesseur;

public:
    Graphe(std::string filename);

    ~Graphe();

    void Kruskal();
    int verifPredecesseur(int Sommet);
    void memePredecesseur(int sommetDepart, int sommetArrivee);
    void afficherKruskal();
    void TrierCroissant();

    friend std::ostream &operator<<(std::ostream &out, const Graphe &graphe);
};


#endif //KRUSKAL_GRAPHE_H
