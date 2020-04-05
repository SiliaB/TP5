//
// Created by Antoine Hintzy on 26/03/2020.
//

#ifndef DIJKSTRA_SOMMET_H
#define DIJKSTRA_SOMMET_H

#include <vector>

class Sommet {
private:
    int m_id;
    std::vector<std::pair<Sommet *const, int>> m_successeurs;

public:
    Sommet(int id);

    ~Sommet();

    void addSuccesseur(Sommet *successeur, int poids);

    void afficher() const;
    void afficherA() const;

    const std::vector<std::pair<Sommet *const, int>> &getSuccesseurs() const;

    int getId() const;
};


#endif //DIJKSTRA_SOMMET_H
