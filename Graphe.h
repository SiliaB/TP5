//
// Created by Antoine Hintzy on 26/03/2020.
//

#ifndef DIJKSTRA_GRAPHE_H
#define DIJKSTRA_GRAPHE_H

#include <list>
#include <ostream>
#include "Sommet.h"

class Graphe {
private:
    std::vector<Sommet *> m_sommets;

public:
    Graphe(std::string filename);

    ~Graphe();

    std::vector<int> Kruskal() const;

    friend std::ostream &operator<<(std::ostream &out, const Graphe &graphe);
};


#endif //DIJKSTRA_GRAPHE_H
