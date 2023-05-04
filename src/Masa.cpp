//
// Created by vbogd on 5/3/2023.
//

#include "../headers/Masa.h"
#include "../headers/Erori.h"

const int Masa::MAX_LOCURI_PER_MASA = 25;

Masa::Masa(const int numar_locuri_, const int pret_consumabile_masa_) : numar_locuri(numar_locuri_),
                                                                        pret_consumabile_masa(pret_consumabile_masa_) {
    if (numar_locuri_ > MAX_LOCURI_PER_MASA) {
        throw Eroare_Masa("S-a depasit numarul maxim de locuri la o masa.");
    }
}

// Voi vrea sa tin EXACT angajat (nu o copie a sa). La fel al invitat.
void Masa::add_angajat(const std::shared_ptr<Angajat> angajat) {
    angajati.push_back(angajat);
}
void Masa::add_invitat(const std::shared_ptr<Invitat> invitat) {
    invitati.push_back(invitat);
}

void Masa::remove_angajat(const std::shared_ptr<Angajat> angajat) {
    int pos = -1;
    for (size_t i = 0; i < angajati.size(); i++) {
        if (angajati[i] -> get_nume() == angajat -> get_nume()) {
            pos = i;
            break;
        }
    }
    if (pos == 1) {
        throw Eroare_Update_Masa("Angajatul nu raspunde de masa indicata.");
    }
    angajati.erase(angajati.begin() + pos);
}

void Masa::remove_invitat(const std::shared_ptr<Invitat> invitat) {
    size_t pos = invitati.size();
    for (size_t i = 0; i < invitati.size(); i++) {
        if (invitati[i] -> get_nume() == invitat -> get_nume()) {
            pos = i;
            break;
        }
    }
    if (pos == invitati.size()) {
        throw Eroare_Update_Masa("Invitatul nu este trecut la masa indicata.");
    }
    invitati.erase(invitati.begin() + pos);
}

double Masa::pret_masa() const {
    double answer = pret_consumabile_masa * numar_locuri;
    for (auto &a : angajati) {
        answer += a -> getSalariu();
    }
    for (auto &i : invitati) {
        answer += i -> get_cost();
    }
    return answer;
}

std::ostream& operator << (std::ostream &out, const Masa &M) {
    out << "Masa are " << M.numar_locuri << " locuri.\n";
    if (M.invitati.empty()) {
        out << "Masa nu are invitati repartizati la ea.\n";
    } else {
        out << "Masa are urmatorii invitati: \n";
        for (auto &inv : M.invitati) {
            out << inv;
        }
    }
    if (M.angajati.empty()) {
        out << "Masa nu are angajati repartizati la ea.\n";
    } else {
        out << "Masa are urmatorii angajati: \n";
        for (auto &ang : M.angajati) {
            out << ang;
        }
    }
    return out;
}