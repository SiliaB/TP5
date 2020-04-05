#include <iostream>
#include <vector>
#include "Graphe.h"

void afficherArborescence(size_t s0, const std::vector<int> &arborescence) {
    std::cout << std::endl << "Arborescence :" << std::endl;
    for (size_t i = 0; i < arborescence.size(); ++i) {
        if (i != s0) {
            if (arborescence[i] != -1) {
                std::cout << "   " << i << " <--- ";
                size_t j = arborescence[i];
                while (j != s0) {
                    std::cout << j << " <--- ";
                    j = arborescence[j];
                }
                std::cout << j << std::endl;
            }
        }
    }
}

int main() {
    int s0 = 1;
    Graphe g{"../graphe.txt"};
    std::cout << g;
    afficherArborescence(s0, g.Kruskal());
    return 0;
}