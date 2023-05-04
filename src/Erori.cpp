//
// Created by vbogd on 5/3/2023.
//

#include "../headers/Erori.h"

Eroare_Masa::Eroare_Masa(const std::string &err) noexcept : std::logic_error(err) {}

Eroare_Update_Masa::Eroare_Update_Masa(const std::string &err) noexcept : Eroare_Masa(err) {}

Eroare_Sali::Eroare_Sali(const std::string &err) noexcept : std::logic_error(err) {}

Eroare_Inchidere_Sala::Eroare_Inchidere_Sala(const std::string &err) noexcept : Eroare_Sali(err) {}

Eroare_Update_Sala::Eroare_Update_Sala(const std::string &err) noexcept : Eroare_Sali(err) {}