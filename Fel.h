//
// Created by vbogd on 5/1/2023.
//

#ifndef OOP_FEL_H
#define OOP_FEL_H

#include <string>
#include <memory>

class Fel {
private:
    std::string nume;
protected:
    double pret;
public:
    Fel(const std::string &nume_, const double pret_);
    virtual double pretProdus() const = 0;
    virtual ~Fel() = default;
};

class Fel_Normal : public Fel {
private:
    double pretCarne, pretOrigineAnimala;
public:
    Fel_Normal(const std::string &nume_, const double pret_, const double pretCarne_, const double pretOrigineAnimala_);
    double pretProdus() const override;
    virtual ~Fel_Normal() = default;
};

class Fel_Vegetarian : public Fel {
private:
    double pretOrigineAnimala, pretInlocuitorProteine;
public:
    Fel_Vegetarian(const std::string &nume_, const double pret_, const double pretOrigineAnimala_, const double pretInlocuitorProteine_);
    double pretProdus() const override;
    virtual ~Fel_Vegetarian() = default;
};

class Fel_Vegan : public Fel {
private:
    double pretInlocuitorProteine, pretInlocuitorLactate;
public:
    Fel_Vegan(const std::string &nume_, const double pret_, const double pretInlocuitorProteine_, const double pretInlocuitorLactate_);
    double pretProdus() const override;
    virtual ~Fel_Vegan() = default;
};

class Fel_Factory {
public:
    static std::shared_ptr<Fel> aperitiv_Normal();
    static std::shared_ptr<Fel> fel_Principal_Normal();
    static std::shared_ptr<Fel> fel_2_Normal();
    static std::shared_ptr<Fel> fel_3_Normal();
    static std::shared_ptr<Fel> desert_Normal();

    static std::shared_ptr<Fel> aperitiv_Vegetarian();
    static std::shared_ptr<Fel> fel_Principal_Vegetarian();
    static std::shared_ptr<Fel> fel_2_Vegetarian();
    static std::shared_ptr<Fel> fel_3_Vegetarian();
    static std::shared_ptr<Fel> desert_Vegetarian();

    static std::shared_ptr<Fel> aperitiv_Vegan();
    static std::shared_ptr<Fel> fel_Principal_Vegan();
    static std::shared_ptr<Fel> fel_2_Vegan();
    static std::shared_ptr<Fel> fel_3_Vegan();
    static std::shared_ptr<Fel> desert_Vegan();
};

#endif //OOP_FEL_H
