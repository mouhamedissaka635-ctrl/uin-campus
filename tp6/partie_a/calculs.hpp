#pragma once
#include <span>

namespace uin {

[[nodiscard]] double somme(std::span<const double> valeurs);
[[nodiscard]] double moyenne(std::span<const double> notes);
[[nodiscard]] double arrondir(double valeur, int decimales = 2);

} // namespace uin
