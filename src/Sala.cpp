//
// Created by vbogd on 5/4/2023.
//

#include "../headers/Sala.h"

const size_t Sala::MAX_NUMAR_MESE = 5;

Sala::Sala() : used(false) {}

Sala::Sala(const Sala &other) : used(other.used) {
    for (auto m : other.mese) {
        mese.push_back(std::make_shared<Masa>(*m));
    }
}

Sala& Sala::operator=(const Sala &other) {
    if (used != other.used || mese != other.mese) {
        used = other.used;
        mese.clear();
        for (auto e : other.mese) {
            mese.push_back(std::make_shared<Masa>(*e));
        }
    }
    return *this;
}

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

void Sala::removeMasa(const size_t pos) {
    if (pos >= mese.size()) {
        throw Eroare_Update_Sala("Masa pe care incercati sa o eliminati nu exista in sala indicata.");
    }
    mese.erase(mese.begin() + pos);
}

double Sala::get_pret() const {
    double answer = 0;
    for (auto &m : mese) {
        answer += m -> pret_masa();
    }
    return answer;
}

void Sala::add_invitat(const size_t posMasa, std::shared_ptr<Invitat> I) {
    if (posMasa >= mese.size()) {
        throw Eroare_Masa("Masa nu exista.");
    }
    try {
        mese[posMasa] -> add_invitat(I);
    } catch(Eroare_Update_Masa& err) {
        std::cout << err.what() << "\n";
    }
}

void Sala::add_anagajat(const size_t posMasa, std::shared_ptr<Angajat> A) {
    if (posMasa >= mese.size()) {
        throw Eroare_Masa("Masa nu exista.");
    }
    try {
        mese[posMasa] -> add_angajat(A);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Sala::rem_angajati(const size_t posMasa, const size_t posAng) {
    if (posMasa >= mese.size()) {
        throw Eroare_Masa("Masa nu exista.");
    }
    try {
        mese[posMasa] -> remove_angajat(posAng);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Sala::rem_invitat(const size_t posMasa, const size_t posInv) {
    if (posMasa >= mese.size()) {
        throw Eroare_Masa("Masa nu exista.");
    }
    try {
        mese[posMasa] -> remove_invitat(posInv);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Sala::modif_meniu(const size_t posMasa, const size_t posInv, const Meniu &men) {
    if (posMasa >= mese.size()) {
        throw Eroare_Masa("Masa nu există.");
    }
    try {
        mese[posMasa]->modif_menu(posInv, men);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Sala::add_personal() {
    for (auto &M : mese) {
        M -> add_personal();
    }
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

Sala_Pool::Sala_Pool() = default;

Sala& Sala_Pool::get_sala() {
    for (auto &s : sali) {
        if (!s.isUsed()) {
            s.use();
            return s;
        }
    }
    throw Eroare_Sali("Prea multi sali folosite.");
}

void Sala::modif_salariu(size_t posMasa, size_t posAng, double newSal) {
    if (posMasa >= mese.size()) {
        throw Eroare_Masa("Masa nu există");
    }
    mese[posMasa].modif_salariu(posAng, newSal);
}