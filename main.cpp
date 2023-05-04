#include <iostream>
#include "headers/Meniu.h"

// TODO maine: clasa Sala (cu object pool), clasa Manager (cu singleton si builder),
// TODO maine: de completat clasa cu exceptii
// TODO maine: retine datele intr-un fisier, gandeste-te la cum ar arata un meniu

int main() {
    Meniu M;

    M.adaugaFel(Fel_Factory::fel_3_Vegan());
    M.adaugaFel(Fel_Factory::fel_Principal_Vegan());
    M.adaugaFel(Fel_Factory::desert_Vegan());
    M.adaugaFel(Fel_Factory::fel_2_Vegan());
    M.adaugaFel(Fel_Factory::aperitiv_Vegan());

    Meniu T;
    T.adaugaFel(Fel_Factory::aperitiv_Normal());
    T.adaugaFel(Fel_Factory::fel_Principal_Normal());
    T.adaugaFel(Fel_Factory::fel_2_Normal());
    T.adaugaFel(Fel_Factory::fel_3_Normal());
    T.adaugaFel(Fel_Factory::desert_Normal());

    Meniu X;
    X.adaugaFel(Fel_Factory::aperitiv_Vegetarian());
    X.adaugaFel(Fel_Factory::fel_Principal_Vegetarian());
    X.adaugaFel(Fel_Factory::fel_2_Vegetarian());
    X.adaugaFel(Fel_Factory::fel_3_Vegetarian());
    X.adaugaFel(Fel_Factory::desert_Vegetarian());

    std::cout << M.pretMeniu() << "\n" << T.pretMeniu() << "\n" << X.pretMeniu() << "\n";

    return 0;
}
