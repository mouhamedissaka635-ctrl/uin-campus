#include "calculs.hpp"
#include <cassert>
#include <cmath>
#include <numeric>

namespace uin {

double somme(std::span<const double> valeurs)
{
    return std::accumulate(valeurs.begin(), valeurs.end(), 0.0);
}

double moyenne(std::span<const double> notes)
{
    assert(!notes.empty() && "moyenne(): aucune note");
    return somme(notes) / static_cast<double>(notes.size());
}

double arrondir(double valeur, int decimales)
{
    const double facteur = std::pow(10.0, decimales);
    return std::round(valeur * facteur) / facteur;
}

} // namespace uin
