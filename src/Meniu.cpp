//
// Created by vbogd on 5/1/2023.
//

#include "../headers/Meniu.h"

Meniu::Meniu() {}

Meniu::Meniu(const Meniu &other) {
    for (const auto &f : other.feluri_mancare) {
        feluri_mancare.push_back(f -> clone());
    }
}

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