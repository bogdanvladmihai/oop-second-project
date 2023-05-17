//
// Created by vbogd on 5/4/2023.
//

#ifndef OOP_SALA_H
#define OOP_SALA_H

#include <vector>
#include "Erori.h"
#include "Masa.h"

class Sala {
private:
    static const size_t MAX_NUMAR_MESE;
    bool used;
    std::vector<std::shared_ptr<Masa>> mese;
    friend class Sala_Builder;
public:
    Sala();
    Sala(const Sala &other);
    Sala& operator=(const Sala &other);
    bool isUsed() const;
    void use();
    void goleste_sala();
    void stopUsing();
    void addMasa(std::shared_ptr<Masa> masa);
    void removeMasa(const size_t pos);
    void add_invitat(const size_t posMasa, std::shared_ptr<Invitat> I);
    void add_anagajat(const size_t posMasa, std::shared_ptr<Angajat> A);
    void rem_invitat(const size_t posMasa, const size_t posInv);
    void rem_angajati(const size_t posMasa, const size_t posAng);
    void modif_meniu(const size_t posMasa, const size_t posInv, const Meniu &men);
    void add_personal();
    friend std::ostream& operator << (std::ostream &out, const Sala &S);
    double get_pret() const;
    void modif_salariu(size_t posMasa, size_t posAng, double newSal);
};

class Sala_Pool {
private:
    static const int MAX_SALI;
    std::vector<Sala> sali;
public:
    Sala_Pool();
    Sala& get_sala();
};

#endif //OOP_SALA_H
