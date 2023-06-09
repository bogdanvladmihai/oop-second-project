//
// Created by vbogd on 5/3/2023.
//

#ifndef OOP_MASA_H
#define OOP_MASA_H

#include <vector>
#include "Angajat.h"
#include "Invitat.h"
#include <fstream>

class Masa {
private:
    std::vector<std::shared_ptr<Angajat>> angajati;
    std::vector<std::shared_ptr<Invitat>> invitati;
    const static int MAX_LOCURI_PER_MASA, LIMIT_RAPORT;
    int numar_locuri, pret_consumabile_masa;
public:
    Masa(const int numar_locuri_, const int pret_consumabile_masa_);
    Masa(const Masa &other);
    Masa& operator=(const Masa &other);
    bool operator != (const Masa &other) const;
    void add_angajat(std::shared_ptr<Angajat> angajat);
    void remove_angajat(const size_t pos);
    void add_invitat(std::shared_ptr<Invitat> invitat);
    void remove_invitat(const size_t pos);
    void modif_menu(const size_t idInv, const Meniu &men);
    friend std::ostream& operator << (std::ostream &out, const Masa &M);
    double pret_masa() const;
    void add_personal();
    void modif_sal(const size_t posAng, double newSal);
    void add_fel(const size_t inInv, std::shared_ptr<Fel> F);
    void del_fel(const size_t idInv, const size_t idPos);
    void readData(std::ifstream &in);
    void writeData(std::ofstream &out);
};


#endif //OOP_MASA_H
