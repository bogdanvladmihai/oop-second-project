//
// Created by vbogd on 5/1/2023.
//

#include "Meniu.h"

Meniu::Meniu() {}

void Meniu::adaugaFel(const std::shared_ptr<Fel> &fel) {
    feluri_mancare.push_back(fel);
}

double Meniu::pretMeniu() const {
    double sum = 0;
    for (const auto &item : feluri_mancare) {
        sum += item -> pretProdus();
    }
    return sum;
}