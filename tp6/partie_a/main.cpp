#include "calculs.hpp"
#include "regles.hpp"
#include <array>
#include <iostream>

int main()
{
    constexpr std::array notes{12.5, 14.0, 13.5, 15.0};
    const double moy = uin::arrondir(uin::moyenne(notes), 2);
    const auto m = uin::mentionPour(moy);
    std::cout << "Moyenne : " << moy << " | Mention : " << uin::libelle(m) << "\n";
    return 0;
}
