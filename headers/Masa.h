//
// Created by vbogd on 5/3/2023.
//

#ifndef OOP_MASA_H
#define OOP_MASA_H

#include <vector>
#include "Angajat.h"
#include "Invitat.h"

class Masa {
private:
    std::vector<std::shared_ptr<Angajat>> angajati;
    std::vector<std::shared_ptr<Invitat>> invitati;
    const static int MAX_LOCURI_PER_MASA, LIMIT_RAPORT;
    int numar_locuri, pret_consumabile_masa;
public:
    Masa(const int numar_locuri_, const int pret_consumabile_masa_);
    void add_angajat(std::shared_ptr<Angajat> angajat);
    void add_angajat(const Angajat &A);
    void remove_angajat(const size_t pos);
    void add_invitat(std::shared_ptr<Invitat> invitat);
    void remove_invitat(const size_t pos);
    friend std::ostream& operator << (std::ostream &out, const Masa &M);
    double pret_masa() const;
    void add_personal();
};


#endif //OOP_MASA_H
