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

Meniu& Meniu::operator=(const Meniu &other) {
    if (feluri_mancare != other.feluri_mancare) {
        feluri_mancare.clear();
        for (auto fel : other.feluri_mancare) {
            feluri_mancare.push_back(fel -> clone());
        }
    }
    return *this;
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

    bool is_normal = false;
    for (auto &men : M.feluri_mancare) {
        if (std::dynamic_pointer_cast<Fel_Normal>(men)) {
            is_normal = true;
        }
    }
    if (is_normal) {
        out << "Meniu este normal!\n";
    } else {
        out << "Meniul este modificat (nu este normal)!";
    }
    out << "\n";
    return out;
}

void Meniu::readData(std::ifstream &in) {
    int feluri;
    in >> feluri;
    for (int i = 0; i < feluri; i++) {
        int tp;
        in >> tp;

        std::string nume;
        double a, b, c;
        in >> nume >> a >> b >> c;
        if (tp == 0) {
            feluri_mancare.push_back(std::make_shared<Fel_Normal>(Fel_Normal(nume, a, b, c)));
        } else if (tp == 1) {
            feluri_mancare.push_back(std::make_shared<Fel_Vegan>(Fel_Vegan(nume, a, b, c)));
        } else if (tp == 2) {
            feluri_mancare.push_back(std::make_shared<Fel_Vegetarian>(Fel_Vegetarian(nume, a, b, c)));
        } else {
            feluri_mancare.push_back(std::make_shared<Fel_Copil>(Fel_Copil(nume, a, b, c)));
        }
    }
}

void Meniu::writeData(std::ofstream &out) {
    out << feluri_mancare.size() << "\n";
    for (auto &f : feluri_mancare) {
        f -> writeData(out);
    }
}