//
// Created by vbogd on 5/3/2023.
//

#ifndef OOP_ERORI_H
#define OOP_ERORI_H

#include <stdexcept>

class Eroare_Gestiune : public std::logic_error {
public:
    explicit Eroare_Gestiune(const std::string &err) noexcept;
};

class Eroare_Masa : public Eroare_Gestiune {
public:
    explicit Eroare_Masa(const std::string &err) noexcept;
};

class Eroare_Update_Masa : public Eroare_Masa {
public:
    explicit Eroare_Update_Masa(const std::string &err) noexcept;
};

class Eroare_Sali : public Eroare_Gestiune {
public:
    explicit Eroare_Sali(const std::string &err) noexcept;
 };

class Eroare_Inchidere_Sala : public Eroare_Sali {
public:
    explicit Eroare_Inchidere_Sala(const std::string &err) noexcept;
};

class Eroare_Update_Sala : public Eroare_Sali {
public:
    explicit Eroare_Update_Sala(const std::string &err) noexcept;
};

class Eroare_Meniu : public Eroare_Gestiune {
public:
    explicit Eroare_Meniu(const std::string &err) noexcept;
};

#endif //OOP_ERORI_H
