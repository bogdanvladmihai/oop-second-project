//
// Created by vbogd on 5/4/2023.
//

#ifndef OOP_MANAGER_H
#define OOP_MANAGER_H

#include "Sala.h"
#include "Erori.h"

class Manager {
private:
    Manager() = default;
    Sala_Pool Pool;
    static const size_t INV;
    std::vector<Sala> sali;
public:
    Manager(const Manager &other) = delete;
    Manager& operator=(const Manager &other) = delete;
    static Manager& get_manager();
    friend std::ostream& operator << (std::ostream &out, const Manager &M);
    void add_sala();
    void goleste_sala(const size_t posSala);
    void modifica_meniu(const size_t posSala, const size_t posMasa, const size_t posInv, const Meniu &men);
    void rem_sala(const size_t pos);
    void add_masa(const size_t posSala, const int numar_locuri, const int pret_consumabile_masa);
    void rem_masa(const size_t posSala, const size_t posMasa);
    void add_angajat(const size_t posSala, const size_t posMasa, std::shared_ptr<Angajat> A);
    void add_invitat(const size_t posSala, const size_t posMasa, std::shared_ptr<Invitat> I);
    void rem_angajat(const size_t posSala, const size_t posMasa, const size_t posAngajat);
    void rem_invitat(const size_t posSala, const size_t posMasa, const size_t posInvitat);
    void add_personal(const size_t pos = INV);
    double get_cost() const;
    void modif_salariu(const size_t posSala, const size_t posMasa, const size_t posAng, double newSal);
};


#endif //OOP_MANAGER_H
