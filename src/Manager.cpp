//
// Created by vbogd on 5/4/2023.
//

#include "../headers/Manager.h"

const size_t Manager::INV = 15;
const std::string fileName = "../data.txt";

Manager& Manager::get_manager() {
    static Manager M;
    return M;
}

std::ostream& operator << (std::ostream &out, const Manager &M) {
    if (M.sali.empty()) {
        out << "Momentan nu exista sali adaugate la nunta.\n";
        return out;
    }

    out << "Avem " << M.sali.size() << " sali deschise la nunta.\n";
    for (size_t i = 0; i < M.sali.size(); i++) {
        out << i << ": " << M.sali[i];
    }
    out << "\n";
    return out;
}

void Manager::add_sala() {
    Sala &S = Pool.get_sala();
    sali.push_back(S);
}

void Manager::goleste_sala(const size_t posSala) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu există.");
    }
    sali[posSala].goleste_sala();
}

void Manager::modifica_meniu(const size_t posSala, const size_t posMasa, const size_t posInv, const Meniu &men) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu există.");
    }
    sali[posSala].modif_meniu(posMasa, posInv, men);
}

void Manager::rem_sala(const size_t pos) {
    if (pos < sali.size()) {
        sali[pos].stopUsing();
        return;
    }
    throw Eroare_Sali("Sala nu exista.");
}

void Manager::add_masa(const size_t posSala, const int numar_locuri, int pret_consumabile_masa) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    std::shared_ptr<Masa> M = std::make_shared<Masa>(Masa(numar_locuri, pret_consumabile_masa));
    sali[posSala].addMasa(M);
}

void Manager::rem_masa(const size_t posSala, const size_t posMasa) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    sali[posSala].removeMasa(posMasa);
}

void Manager::add_angajat(const size_t posSala, const size_t posMasa, std::shared_ptr<Angajat> A) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    sali[posSala].add_anagajat(posMasa, A);
}

void Manager::add_invitat(const size_t posSala, const size_t posMasa, std::shared_ptr<Invitat> I) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    sali[posSala].add_invitat(posMasa, I);
}

void Manager::rem_angajat(const size_t posSala, const size_t posMasa, const size_t posAngajat) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    sali[posSala].rem_angajati(posMasa, posAngajat);
}

void Manager::rem_invitat(const size_t posSala, const size_t posMasa, const size_t posInvitat) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    sali[posSala].rem_invitat(posMasa, posInvitat);
}

void Manager::add_personal(const size_t posSala) {
    if (posSala == INV) {
        for (auto &S: sali) {
            S.add_personal();
        }
        return;
    }

    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista");
    }
    sali[posSala].add_personal();
}

void Manager::modif_salariu(const size_t posSala, const size_t posMasa, const size_t posAng, double newSal) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu există");
    }
    sali[posSala].modif_salariu(posMasa, posAng, newSal);
}

void Manager::add_fel(const size_t idSala, const size_t idMasa, const size_t idInv, std::shared_ptr <Fel> F) {
    if (idSala >= sali.size()) {
        throw Eroare_Sali("Sala nu există.");
    }
    sali[idSala].add_fel(idMasa, idInv, F);
}

void Manager::del_fel(const size_t idSala, const size_t idMasa, const size_t idInv, const size_t idPos) {
    if (idSala >= sali.size()) {
        throw Eroare_Sali("Sala nu există.");
    }
    sali[idSala].del_fel(idMasa, idInv, idPos);
}

double Manager::get_cost() const {
    double answer = 0;
    for (auto &S : sali) {
        answer += S.get_pret();
    }
    return answer;
}

void Manager::read() {
    std::ifstream in(fileName);
    int nrSali;
    in >> nrSali;
    for (int i = 0; i < nrSali; i++) {
        sali.push_back(Sala());
        sali.back().readData(in);
    }
    in.close();
}

void Manager::update() {
    std::ofstream out(fileName);

    out << sali.size() << "\n";
    for (auto &e : sali) {
        e.writeData(out);
    }

    out.close();
}