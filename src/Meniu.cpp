//
// Created by vbogd on 5/1/2023.
//

#include "../headers/Meniu.h"
#include "../headers/Erori.h"

Meniu::Meniu() {}

const size_t Meniu::MAX_FELURI = 7;

Meniu::Meniu(const Meniu &other) {
    for (const auto &f : other.feluri_mancare) {
        feluri_mancare.push_back(f -> clone());
    }
}

void Meniu::clear() {
    feluri_mancare.clear();
}

void Meniu::adaugaFel(const std::shared_ptr<Fel> &fel) {
    if (feluri_mancare.size() == MAX_FELURI) {
        throw Eroare_Meniu("Prea multe feluri de mancare adaugate.");
    }
    feluri_mancare.push_back(fel);
}

void Meniu::stergeFel(const size_t pos) {
    if (pos >= feluri_mancare.size()) {
        throw Eroare_Meniu("Felul de mancare selectat nu exista.");
    }
    feluri_mancare.erase(feluri_mancare.begin() + pos);
}

double Meniu::pretMeniu() const {
    double sum = 0;
    for (const auto &item : feluri_mancare) {
        sum += item -> pretProdus();
    }
    return sum;
}

std::ostream& operator << (std::ostream &out, const Meniu &M) {
    if (M.feluri_mancare.empty()) {
        out << "Meniul nu a fost inca selectat.\n";
        return out;
    }

    int cnt_vegan = 0, cnt_normal = 0, cnt_vegetarian = 0;
    for (auto &men : M.feluri_mancare) {
        if (std::dynamic_pointer_cast<Fel_Normal>(men)) {
            cnt_normal++;
        } else if (std::dynamic_pointer_cast<Fel_Vegan>(men)) {
            cnt_vegan++;
        } else {
            cnt_vegetarian++;
        }
    }
    out << "Meniul are ";
    if (cnt_normal > 0) {
        out << cnt_normal << " elemente de tip mancare normala; ";
    }
    if (cnt_vegan) {
        out << cnt_vegan << " elemente de tip mancare vegana;";
    }
    if (cnt_vegetarian) {
        out << cnt_vegetarian << " elemente de tip mancare vegetariana;";
    }
    out << "\n";
    return out;
}