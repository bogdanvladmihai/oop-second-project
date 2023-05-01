#include <iostream>
#include "Meniu.h"

int main() {
    Meniu M;

    M.adaugaFel(Fel_Factory::fel_3_Vegan());
    M.adaugaFel(Fel_Factory::fel_Principal_Vegan());
    M.adaugaFel(Fel_Factory::desert_Vegan());

    std::cout << M.pretMeniu() << "\n";

    return 0;
}
