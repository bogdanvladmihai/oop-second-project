//
// Created by vbogd on 5/4/2023.
//

#ifndef OOP_SALA_H
#define OOP_SALA_H

#include <vector>
#include "Erori.h"
#include "Masa.h"
#include <fstream>

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
    void modif_salariu(const size_t posMasa, const size_t posAng, double newSal);
    void add_fel(const size_t idMasa, const size_t idInv, std::shared_ptr<Fel> F);
    void del_fel(const size_t idMasa, const size_t idInv, const size_t idPos);
    void readData(std::ifstream &in);
    void writeData(std::ofstream &out);
};

class Sala_Pool {
private:
    static const size_t MAX_SALI;
    std::vector<Sala> sali;
public:
    Sala_Pool();
    Sala& get_sala();
};

#endif //OOP_SALA_H
