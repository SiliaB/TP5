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
        if (ifs.fail()) {
            throw std::runtime_error("Problème de lecture d'un arc.");
        }
        m_sommets[num1]->addSuccesseur(m_sommets[num2], poids);

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

std::vector<int> Graphe::Kruskal() const {
    std::cout << std::endl << std::endl << "LANCEMENT DE Kruskal :" << std::endl;
    // INITIALISATION
    int nbMarques = 0;
    int s0=0;
    std::vector<int> couleurs(m_sommets.size(), 0); // tous les sommets sont non marqués
    std::vector<int> predecesseurs(m_sommets.size(), -1); // nous ne connaissons pas encore les prédécesseurs
    //Trouver le plus petit poids
    /*for (size_t i=0;i<m_sommets.size();i++){
        s0=m_sommets[i]->getSuccesseurs();
    }*/
    predecesseurs[s0] = 0; // on pourrait laisser -1, s0 n'a pas vraiment de prédécesseur car il s'agit du sommet initial

    do {
        int s = 0;
        int distanceMini = std::numeric_limits<int>::max();
        std::cout << std::endl << std::endl;
        std::cout << std::endl << std::endl;

        couleurs[s] = 1;
        nbMarques++;
        std::cout << "Sommet choisi : " << s << " (plus petite distance depuis le sommet " << s0 << " (" << distanceMini
                  << ")"
                  << "). Ses successeurs non marqués sont :" << std::endl;
        for (auto successeur: m_sommets[s]->getSuccesseurs()) {
            if (couleurs[successeur.first->getId()] == 0) {

            }
        }
    } while (nbMarques < m_sommets.size());

    std::cout << std::endl << "FIN DE DIJKSTRA." << std::endl;
    return predecesseurs;
}
