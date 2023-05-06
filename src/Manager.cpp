//
// Created by vbogd on 5/4/2023.
//

#include "../headers/Manager.h"

const size_t Manager::INV = 15;

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
}

void Manager::add_sala() {
    try {
        Sala &S = Pool.get_sala();
        sali.push_back(S);
    } catch(Eroare_Sali &err) {
        std::cout << err.what() << "\n";
    }
}

void Manager::rem_sala(const size_t pos) {
    if (pos < sali.size()) {
        try {
            sali[pos].stopUsing();
        } catch(Eroare_Inchidere_Sala &err) {
            std::cout << err.what() << "\n";
        }
    }
}

void Manager::add_masa(const int numar_locuri, int pret_consumabile_masa) {
    try {
        std::shared_ptr<Masa> M = std::make_shared<Masa>(Masa(numar_locuri, pret_consumabile_masa));
        mese.push_back(M);
    } catch(Eroare_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Manager::rem_masa(const size_t posSala, const size_t posMasa) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    try {
        sali[posSala].removeMasa(posMasa);
    } catch(Eroare_Update_Sala &err) {
        std::cout << err.what() << "\n";
    }
}

void Manager::add_angajat(const size_t posSala, const size_t posMasa, std::shared_ptr<Angajat> A) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    try {
        sali[posSala].add_anagajat(posMasa, A);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    } catch(Eroare_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Manager::add_invitat(const size_t posSala, const size_t posMasa, std::shared_ptr<Invitat> I) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    try {
        sali[posSala].add_invitat(posMasa, I);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    } catch(Eroare_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Manager::rem_angajat(const size_t posSala, const size_t posMasa, const size_t posAngajat) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    try {
        sali[posSala].rem_angajati(posMasa, posAngajat);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    } catch(Eroare_Masa &err) {
        std::cout << err.what() << "\n";
    }
}

void Manager::rem_invitat(const size_t posSala, const size_t posMasa, const size_t posInvitat) {
    if (posSala >= sali.size()) {
        throw Eroare_Sali("Sala nu exista.");
    }
    try {
        sali[posSala].rem_invitat(posMasa, posInvitat);
    } catch(Eroare_Update_Masa &err) {
        std::cout << err.what() << "\n";
    } catch(Eroare_Masa &err) {
        std::cout << err.what() << "\n";
    }
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