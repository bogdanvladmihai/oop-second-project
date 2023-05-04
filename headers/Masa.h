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
    const static int MAX_LOCURI_PER_MASA;
    int numar_locuri, pret_consumabile_masa;
public:
    Masa(const int numar_locuri_, const int pret_consumabile_masa_);
    void add_angajat(const std::shared_ptr<Angajat> angajat);
    void remove_angajat(const std::shared_ptr<Angajat> angajat);
    void add_invitat(const std::shared_ptr<Invitat> invitat);
    void remove_invitat(const std::shared_ptr<Invitat> invitat);
    friend std::ostream& operator << (std::ostream &out, const Masa &M);
    double pret_masa() const;
};


#endif //OOP_MASA_H
