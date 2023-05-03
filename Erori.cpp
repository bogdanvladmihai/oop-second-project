//
// Created by vbogd on 5/3/2023.
//

#include "Erori.h"

Eroare_Update_Masa::Eroare_Update_Masa(const std::string &err) noexcept : std::logic_error(err){}