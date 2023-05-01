//
// Created by vbogd on 5/1/2023.
//

#include "Fel.h"
#include <exception>

Fel::Fel(const std::string nume_, const double pret_) : nume(nume_), pret(pret_) {
    if (nume.empty()) {
        throw std::runtime_error("Numele NU poate sa fie vid");
    }
}

Fel_Normal::Fel_Normal(const std::string nume_, const double pret_, const double pretCarne_,
                       const double pretOrigineAnimala_) : Fel(nume_, pret_),
                       pretCarne(pretCarne_), pretOrigineAnimala(pretOrigineAnimala_) {}
double Fel_Normal::pretProdus() const {
    return pret + pretCarne * 0.8 + pretOrigineAnimala;
}

Fel_Vegetarian::Fel_Vegetarian(const std::string nume_, const double pret_, const double pretOrigineAnimala_,
                               const double pretInlocuitorProteine_) : Fel(nume_, pret_),
                               pretOrigineAnimala(pretOrigineAnimala_), pretInlocuitorProteine(pretInlocuitorProteine_) {}
double Fel_Vegetarian::pretProdus() const {
    return pret + pretInlocuitorProteine * 1.4 + pretOrigineAnimala;
}

Fel_Vegan::Fel_Vegan(const std::string nume_, const double pret_, const double pretInlocuitorProteine_,
                     const double pretInlocuitorLactate_) : Fel(nume_, pret_),
                     pretInlocuitorProteine(pretInlocuitorProteine_), pretInlocuitorLactate(pretInlocuitorLactate_) {}
double Fel_Vegan::pretProdus() const {
    return pret + pretInlocuitorProteine * 1.4 + pretInlocuitorLactate * 1.5;
}

std::shared_ptr<Fel> Fel_Factory::aperitiv_Normal() {
    return std::make_shared<Fel_Normal>(Fel_Normal("Chiftele, salată, mezeluri", 8.7, 12.5, 9.4));
}
std::shared_ptr<Fel> Fel_Factory::aperitiv_Vegetarian() {
    return std::make_shared<Fel_Vegetarian>(Fel_Vegetarian("Chiftele din legume, salată, ouă", 7.73, 10.5, 9.4));
}
std::shared_ptr<Fel> Fel_Factory::aperitiv_Vegan() {
    return std::make_shared<Fel_Vegan>(Fel_Vegan("Salataă, avocado", 12.3, 15.4, 7.6));
}
std::shared_ptr<Fel> Fel_Factory::desert_Normal() {
    return std::make_shared<Fel_Normal>(Fel_Normal("Tort frisca si capsuni", 24.5, 0, 9.5));
}
std::shared_ptr<Fel> Fel_Factory::desert_Vegetarian() {
    return std::make_shared<Fel_Vegetarian>(Fel_Vegetarian("Tort cu frisca si capsuni", 24.5, 9.5, 0));
}
std::shared_ptr<Fel> Fel_Factory::desert_Vegan() {
    return std::make_shared<Fel_Vegan>(Fel_Vegan("Placinta cu banane si dovleac", 13.5, 3.4, 19.4));
}
std::shared_ptr<Fel> Fel_Factory::fel_2_Normal() {
    return std::make_shared<Fel_Normal>(Fel_Normal("Coaste de porc si cartofi", 25.4, 29.4, 3.4));
}
std::shared_ptr<Fel> Fel_Factory::fel_2_Vegetarian() {
    return std::make_shared<Fel_Vegetarian>(Fel_Vegetarian("Cartofi si cascaval pane", 15.7, 20.3, 3.4));
}
std::shared_ptr<Fel> Fel_Factory::fel_2_Vegan() {
    return std::make_shared<Fel_Vegan>(Fel_Vegan("Soia cu legume", 22.6, 12.5, 17));
}
std::shared_ptr<Fel> Fel_Factory::fel_3_Normal() {
    return std::make_shared<Fel_Normal>(Fel_Normal("Ciorba radauteana de pui", 18.7, 12.3, 9.5));
}
std::shared_ptr<Fel> Fel_Factory::fel_3_Vegetarian() {
    return std::make_shared<Fel_Vegetarian>(Fel_Vegetarian("Supa crema de legume cu cafea", 20.5, 5.7, 8.3));
}
std::shared_ptr<Fel> Fel_Factory::fel_3_Vegan() {
    return std::make_shared<Fel_Vegan>(Fel_Vegan("Supa crema de legume cu cafea", 20.5, 5.7, 8.3));
}
std::shared_ptr<Fel> Fel_Factory::fel_Principal_Normal() {
    return std::make_shared<Fel_Normal>(Fel_Normal("Snitel de pui cu cartofi", 13.5, 20.9, 15.6));
}
std::shared_ptr<Fel> Fel_Factory::fel_Principal_Vegetarian() {
    return std::make_shared<Fel_Vegetarian>(Fel_Vegetarian("Crochete de mozarella cu legume", 23.5, 15.3, 4.2));
}
std::shared_ptr<Fel> Fel_Factory::fel_Principal_Vegan() {
    return std::make_shared<Fel_Vegan>(Fel_Vegan("Crochete de mozarella cu legume", 23.5, 15.3, 4.2));
}
