//
// Created by vbogd on 5/3/2023.
//

#include "../headers/Masa.h"
#include "../headers/Erori.h"

const int Masa::MAX_LOCURI_PER_MASA = 25;
const int Masa::LIMIT_RAPORT = 6;

Masa::Masa(const int numar_locuri_, const int pret_consumabile_masa_) : numar_locuri(numar_locuri_),
                                                                        pret_consumabile_masa(pret_consumabile_masa_) {
    if (numar_locuri_ > MAX_LOCURI_PER_MASA) {
        throw Eroare_Masa("S-a depasit numarul maxim de locuri la o masa.");
    }
}

Masa::Masa(const Masa &other) : numar_locuri(other.numar_locuri), pret_consumabile_masa(other.pret_consumabile_masa) {
    for (auto e : other.angajati) {
        angajati.push_back(std::make_shared<Angajat>(*e));
    }
    for (auto e : other.invitati) {
        invitati.push_back(std::make_shared<Invitat>(*e));
    }
}

Masa& Masa::operator=(const Masa &other) {
    if (*this != other) {
        numar_locuri = other.numar_locuri;
        pret_consumabile_masa = other.pret_consumabile_masa;
        invitati.clear();
        angajati.clear();
        for (auto e : other.angajati) {
            angajati.push_back(std::make_shared<Angajat>(*e));
        }
        for (auto e : other.invitati) {
            invitati.push_back(std::make_shared<Invitat>(*e));
        }
    }
    return *this;
}

bool Masa::operator!=(const Masa &other) const {
    return numar_locuri == other.numar_locuri && pret_consumabile_masa == other.pret_consumabile_masa &&
            invitati == other.invitati && angajati == other.angajati;
}

// Voi vrea sa tin EXACT angajat (nu o copie a sa). La fel al invitat.
void Masa::add_angajat(const std::shared_ptr<Angajat> angajat) {
    angajati.push_back(angajat);
}
void Masa::add_invitat(const std::shared_ptr<Invitat> invitat) {
    invitati.push_back(invitat);
}

void Masa::remove_angajat(const size_t pos) {
    if (pos >= angajati.size()) {
        throw Eroare_Update_Masa("Angajatul nu raspunde de masa indicata.");
    }
    angajati.erase(angajati.begin() + pos);
}

void Masa::remove_invitat(const size_t pos) {
    if (pos >= invitati.size()) {
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

void Masa::add_personal() {
    int tmp = 0;
    while (invitati.size() / angajati.size() >= LIMIT_RAPORT) {
        if (tmp % 4 == 0) {
            add_angajat(Angajat_Factory::Ospatar());
        } else if (tmp % 4 == 1) {
            add_angajat(Angajat_Factory::Barman());
        } else if (tmp % 4 == 2) {
            add_angajat(Angajat_Factory::Ajutor_Bucatarie());
        } else {
            add_angajat(Angajat_Factory::Bucatar());
        }
        tmp++;
    }
}

void Masa::modif_menu(const size_t idInv, const Meniu &men) {
    if (idInv >= invitati.size()) {
        throw Eroare_Update_Masa("Invitatul nu există.");
    }
    invitati[idInv] -> modif_meniu(men);
}

std::ostream& operator << (std::ostream &out, const Masa &M) {
    out << "Masa are " << M.numar_locuri << " locuri.\n";
    if (M.invitati.empty()) {
        out << "Masa nu are invitati repartizati la ea.\n";
    } else {
        out << "Masa are urmatorii invitati: \n";
        for (size_t i = 0; i < M.invitati.size(); i++) {
            out << i << " " << *M.invitati[i];
        }
    }
    if (M.angajati.empty()) {
        out << "Masa nu are angajati repartizati la ea.\n";
    } else {
        out << "Masa are urmatorii angajati: \n";
        for (size_t i = 0; i < M.angajati.size(); i++) {
            out << i << ": " << *M.angajati[i];
        }
    }
    return out;
}

void Masa::modif_sal(const size_t posAng, double newSal) {
    if (posAng >= angajati.size()) {
        throw Eroare_Masa("Angajatul nu există.");
    }
    angajati[posAng]->setSalariu(newSal);
}

void Masa::add_fel(const size_t idInv, std::shared_ptr<Fel> F) {
    if (idInv >= invitati.size()) {
        throw Eroare_Masa("Invitatul nu există.");
    }
    invitati[idInv]->add_fel(F);
}

void Masa::del_fel(const size_t idInv, const size_t idPos) {
    if (idInv >= invitati.size()) {
        throw Eroare_Masa("Invitatul nu există.");
    }
    invitati[idInv] ->del_fel(idPos);
}

void Masa::readData(std::ifstream &in) {
    int nrAng;
    in >> nrAng;
    for (int i = 0; i < nrAng; i++) {
        std::string nume;
        in >> nume;
        int sal;
        in >> sal;
        angajati.push_back(std::make_shared<Angajat>(Angajat(nume, sal)));
    }

    int nrInv;
    in >> nrInv;
    for (int i = 0; i < nrInv; i++) {
        std::string nume;
        in >> nume;
        std::shared_ptr<Meniu> menu;
        menu -> readData(in);

        invitati.push_back(std::make_shared<Invitat>(*menu, nume));
    }
}

void Masa::writeData(std::ofstream &out) {
    out << numar_locuri << " " << pret_consumabile_masa << "\n";
    out << angajati.size() << "\n";
    for (auto &a : angajati) {
        a -> writeData(out);
    }

    out << invitati.size() << "\n";
    for (auto &a : invitati) {
        a -> writeData(out);
    }
}