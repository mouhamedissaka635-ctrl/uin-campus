#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

struct TableauDynamique {
    double* donnees{nullptr};
    std::size_t taille{0};
    std::size_t capacite{0};
};

void ajouter(TableauDynamique& t, double valeur)
{
    if (t.taille == t.capacite) {
        const std::size_t nouvelleCapacite = (t.capacite == 0) ? 4 : t.capacite * 2;
        double* nouveau = new double[nouvelleCapacite];
        for (std::size_t i{0}; i < t.taille; ++i) {
            nouveau[i] = t.donnees[i];
        }
        delete[] t.donnees;
        t.donnees = nouveau;
        t.capacite = nouvelleCapacite;
    }
    t.donnees[t.taille] = valeur;
    ++t.taille;
}

double& element(TableauDynamique& t, std::size_t i)
{
    assert(i < t.taille && "element(): indice hors limites");
    return t.donnees[i];
}

void liberer(TableauDynamique& t)
{
    delete[] t.donnees;
    t.donnees = nullptr;
    t.taille = 0;
    t.capacite = 0;
}

void partieA_et_B()
{
    std::cout << "=== Partie A : TableauDynamique ===\n";
    TableauDynamique notes;
    for (int i{0}; i < 10; ++i) {
        ajouter(notes, 10.0 + static_cast<double>(i));
        std::cout << "taille " << notes.taille
                  << ", capacite " << notes.capacite << "\n";
    }

    std::cout << "Premier element (via element()) : " << element(notes, 0) << "\n";

    // Partie B : décommenter les 2 lignes suivantes pour observer le double-free avec ASan
    // TableauDynamique copie = notes;
    // liberer(copie);

    liberer(notes);
}

void partieC()
{
    std::cout << "\n=== Partie C : std::vector ===\n";
    std::vector<double> notes;
    for (int i{0}; i < 10; ++i) {
        notes.push_back(10.0 + static_cast<double>(i));
        std::cout << "taille " << notes.size()
                  << ", capacite " << notes.capacity() << "\n";
    }
    std::vector<double> copie = notes; // copie profonde automatique, sans liberer()
    std::cout << "Copie taille : " << copie.size() << "\n";
}

int main()
{
    partieA_et_B();
    partieC();
    return 0;
}
