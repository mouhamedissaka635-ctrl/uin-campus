#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace carnet {

struct Statistiques {
    double minimum{};
    double maximum{};
    double moyenne{};
    int nbValidees{};
};

[[nodiscard]] Statistiques calculerStatistiques(const std::vector<double>& notes) {
    if (notes.empty()) return {};
    double min = notes[0], max = notes[0], somme = 0;
    int validees = 0;
    for (double n : notes) {
        if (n < min) min = n;
        if (n > max) max = n;
        somme += n;
        if (n >= 10.0) ++validees;
    }
    return {min, max, somme / notes.size(), validees};
}

void afficherNotes(const std::vector<double>& notes) {
    if (notes.empty()) {
        std::cout << "Aucune note.\n";
        return;
    }
    for (size_t i = 0; i < notes.size(); ++i) {
        std::cout << i + 1 << ". " << notes[i] << "\n";
    }
}

void ajouter(std::vector<double>& notes) {
    double note = -1;
    while (note < 0 || note > 20) {
        std::cout << "Note à ajouter (0-20) : ";
        std::cin >> note;
    }
    notes.push_back(note);
}

void afficherStatistiques(const std::vector<double>& notes) {
    if (notes.empty()) {
        std::cout << "Aucune note.\n";
        return;
    }
    auto [mini, maxi, moyenne, validees] = calculerStatistiques(notes);
    std::cout << "Min : " << mini << " | Max : " << maxi 
              << " | Moyenne : " << moyenne 
              << " | Validées : " << validees << "/" << notes.size() << "\n";
}

int afficherMenu() {
    std::cout << "\n=== Carnet de notes ===\n";
    std::cout << "1. Ajouter une note\n2. Afficher les notes\n3. Statistiques\n0. Quitter\n";
    std::cout << "Votre choix : ";
    int choix = 0;
    std::cin >> choix;
    return choix;
}

} // namespace carnet

int main() {
    std::vector<double> notes;
    int choix = 0;
    do {
        choix = carnet::afficherMenu();
        switch (choix) {
            case 1: carnet::ajouter(notes); break;
            case 2: carnet::afficherNotes(notes); break;
            case 3: carnet::afficherStatistiques(notes); break;
            case 0: break;
            default: std::cout << "Choix invalide.\n"; break;
        }
    } while (choix != 0);
    return 0;
}
