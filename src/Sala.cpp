//
// Created by vbogd on 5/4/2023.
//

#include "../headers/Sala.h"

const size_t Sala::MAX_NUMAR_MESE = 5;

Sala::Sala() : used(false) {}

bool Sala::isUsed() const {
    return used;
}

void Sala::use() {
    used = true;
}

void Sala::stopUsing() {
    if (mese.empty()) {
        used = false;
    }
    throw Eroare_Inchidere_Sala("Nu se poate inchide o sala care are mese asociate!");
}

void Sala::goleste_sala() {
    mese.clear();
}

void Sala::addMasa(std::shared_ptr<Masa> masa) {
    if (std::find(mese.begin(), mese.end(), masa) != mese.end() || mese.size() == MAX_NUMAR_MESE) {
        throw Eroare_Update_Sala(mese.size() == MAX_NUMAR_MESE ? "Numar maxim de mese atins in sala." :
                                 "Masa exista deja in sala.");
    }
    mese.push_back(masa);
}

void Sala::removeMasa(std::shared_ptr<Masa> masa) {
    if (std::find(mese.begin(), mese.end(), masa) == mese.end()) {
        throw Eroare_Update_Sala("Masa pe care incercati sa o eliminati nu exista in sala indicata.");
    }
    mese.erase(std::find(mese.begin(), mese.end(), masa));
}

double Sala::get_pret() const {
    double answer = 0;
    for (auto &m : mese) {
        answer += m -> pret_masa();
    }
    return answer;
}

std::ostream& operator << (std::ostream &out, const Sala &S) {
    if (!S.used) {
        out << "Sala nu este folosita.\n";
        return out;
    }

    out << "Sala are " << S.mese.size() << " mese alocate.\n";
    for (auto &M : S.mese) {
        out << M;
    }
    out << "\n";
    return out;
}