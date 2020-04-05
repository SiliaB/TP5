//
// Created by Antoine Hintzy on 26/03/2020.
//

#include "Sommet.h"
#include <iostream>

Sommet::Sommet(int id) : m_id(id) {}

Sommet::~Sommet() {
    std::cout << "Destruction du sommet " << m_id << "." << std::endl;
}

void Sommet::addSuccesseur(Sommet *successeur, int poids) {
    m_successeurs.emplace_back(successeur, poids);
}

int Sommet::getId() const {
    return m_id;
}

void Sommet::afficher() const {

    std::cout << m_id+1 << ", ";
}
void Sommet::afficherA() const {

    for (auto addrSommet : m_successeurs) {
        std::cout << "      " << m_id << "---" << "(" << addrSommet.second << ")" << "--->" << addrSommet.first->getId()
                  << std::endl;
    }
}

const std::vector<std::pair<Sommet *const, int>> &Sommet::getSuccesseurs() const {
    return m_successeurs;
}
