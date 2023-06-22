#include "headers/Manager.h"
#include <rlutil.h>
#include "headers/Reducere.h"

void printMenu() {
    rlutil::cls();
    std::cout << "[0] Afișare informații despre săli, mese, angajați și invitați.\n";
    std::cout << "[1] Adăugare sală.\n";
    std::cout << "[2] Ștergere sală.\n";
    std::cout << "[3] Adăugare masă.\n";
    std::cout << "[4] Ștergere masă.\n";
    std::cout << "[5] Adăugare angajat.\n";
    std::cout << "[6] Ștergere angajat.\n";
    std::cout << "[7] Adăugare invitat.\n";
    std::cout << "[8] Ștergere invitat.\n";
    std::cout << "[9] Schimbare meniu pentru invitat.\n";
    std::cout << "[10] Adăugare fel de mâncare pentru invitat.\n";
    std::cout << "[11] Adăugare personal lipsă.\n";
    std::cout << "[12] Afișare preț total.\n";
    std::cout << "[13] Ștergeți un fel de mâncare din meniul unui invitat.\n";
    std::cout << "[14] Modifică salariul unui angajat.\n";
    std::cout << "[15] Golește o sală.\n";
    std::cout << "[Q] Quit.\n";
    std::cout << "Opțiunea selectată: ";
}

bool checkOption(const std::string &S) {
    if (S.size() > 2 || S.empty()) {
        return false;
    }
    if (S.size() == 1) {
        return (S[0] >= '0' && S[0] <= '9') || S[0] == 'Q';
    }
    return S[0] == '1' && S[1] >= '0' && S[1] <= '5';
}


int main() {
    srand(time(NULL));

    auto &manager = Manager::get_manager();
    manager.read();

    std::string command;
    do {
        try {
            printMenu();
            std::cin >> command;
            while (!checkOption(command)) {
                std::cout << "Opțiunea greșită!\nVĂ rugăm sa încercați din nou.\n";
                std::cin >> command;
            }
            if (command == "Q") {
                break;
            }
            size_t option = std::stoi(command);
            if (option == 0) {
                std::cout << manager << "\n";
            } else if (option == 1) {
                manager.add_sala();
            } else if (option == 2) {
                std::cout << manager << "\n";
                size_t idSala;
                std::cout << "Numărul sălii pe care doriți să o ștergeți: ";
                std::cin >> idSala;
                manager.rem_sala(idSala);
            } else if (option == 3) {
                size_t idSala;
                std::cout << manager << "\n";
                int numar_locuri, pret_consumabile_masa;
                std::cout << "Numărul sălii în care doriți să adăugați masa: ";
                std::cin >> idSala;
                std::cout << "Numărul de locuri de la masă: ";
                std::cin >> numar_locuri;
                std::cout << "Prețul pentru consumabilele de la masă: ";
                std::cin >> pret_consumabile_masa;
                manager.add_masa(idSala, numar_locuri, pret_consumabile_masa);
            } else if (option == 4) {
                std::cout << manager << "\n";
                size_t idMasa, idSala;
                std::cout << "Numărul sălii din care doriți să ștergeți masa: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei pe care doriți să o ștergeți: ";
                std::cin >> idMasa;
                manager.rem_masa(idSala, idMasa);
            } else if (option == 5) {
                size_t idSala, idMasa;
                std::string nume;
                std::cout << manager << "\n";
                std::cout << "Numărul sălii în care doriți să adăugați angajatul: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei la care doriți să adăugați angajatul: ";
                std::cin >> idMasa;
                std::cout << "Numele angajatului este: ";
                std::cin >> nume;
                int salariu;
                std::cout << "Salariul angajatului este: ";
                std::cin >> salariu;
                std::shared_ptr<Angajat> A = std::make_shared<Angajat>(Angajat(nume, salariu));
                manager.add_angajat(idSala, idMasa, A);
            } else if (option == 6) {
                size_t idSala, idMasa;
                std::cout << manager << "\n";
                std::cout << "Numărul sălii din care doriți să ștergeți angajatul: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei de la care doriți să ștergeți angajatul: ";
                std::cin >> idMasa;
                size_t idAng;
                std::cout << "Numărul angajatului pe care doriți să îl ștergeți: ";
                std::cin >> idAng;
                manager.rem_angajat(idSala, idMasa, idAng);
            } else if (option == 7) {
                size_t idSala, idMasa;
                std::string nume;
                std::cout << manager << "\n";
                std::cout << manager << "\n";
                std::cout << "Numărul sălii în care doriți să adăugați invitatului: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei la care doriți să adăugați invitatului: ";
                std::cin >> idMasa;
                std::cout << "Numele angajatului este: ";
                std::cin >> nume;
                std::cout << "Alegeți meniul de mâncare: Normal (0), Vegan (1), Vegetarian (2), Niciunul (3).\n";
                size_t opt;
                do {
                    std::cin >> opt;
                    if (opt <= 3) {
                        break;
                    }
                    std::cout << "Opțiune invalidă, vă rugăm să încercați din nou.\n";
                } while (true);
                Meniu men;
                if (opt == 1) {
                    men.adaugaFel(Fel_Factory::fel_3_Vegan());
                    men.adaugaFel(Fel_Factory::fel_Principal_Vegan());
                    men.adaugaFel(Fel_Factory::desert_Vegan());
                    men.adaugaFel(Fel_Factory::fel_2_Vegan());
                    men.adaugaFel(Fel_Factory::aperitiv_Vegan());
                } else if (opt == 0) {
                    men.adaugaFel(Fel_Factory::aperitiv_Normal());
                    men.adaugaFel(Fel_Factory::fel_Principal_Normal());
                    men.adaugaFel(Fel_Factory::fel_2_Normal());
                    men.adaugaFel(Fel_Factory::fel_3_Normal());
                    men.adaugaFel(Fel_Factory::desert_Normal());
                } else if (opt == 2) {
                    men.adaugaFel(Fel_Factory::aperitiv_Vegetarian());
                    men.adaugaFel(Fel_Factory::fel_Principal_Vegetarian());
                    men.adaugaFel(Fel_Factory::fel_2_Vegetarian());
                    men.adaugaFel(Fel_Factory::fel_3_Vegetarian());
                    men.adaugaFel(Fel_Factory::desert_Vegetarian());
                }
                std::shared_ptr<Invitat> I = std::make_shared<Invitat>(Invitat(men, nume));
                manager.add_invitat(idSala, idMasa, I);
            } else if (option == 8) {
                size_t idSala, idMasa;
                std::cout << manager << "\n";
                std::cout << "Numărul sălii din care doriți să ștergeți invitatul: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei de la care doriți să ștergeți invitatul: ";
                std::cin >> idMasa;
                size_t idInv;
                std::cout << "Numărul invitatului pe care doriți să îl ștergeți: ";
                std::cin >> idInv;
                manager.rem_invitat(idSala, idMasa, idInv);
            } else if (option == 9) {
                size_t idSala, idMasa, idInv;
                std::cout << manager << "\n";
                std::cout << "Numărul sălii din care face parte invitatul al cărui meniu trebuie schimbat.\n";
                std::cin >> idSala;
                std::cout << "Numărul mesei la cre se află invitatul al cărui meniu trebuie schimbat.\n";
                std::cin >> idMasa;
                std::cout << "Numărul invitatului al cărui meniu trebuie schimbat.\n";
                std::cin >> idInv;
                std::cout << "Alegeți meniul de mâncare: Normal (0), Vegan (1), Vegetarian (2).\n";
                size_t opt;
                do {
                    std::cin >> opt;
                    if (opt <= 2) {
                        break;
                    }
                    std::cout << "Opțiune invalidă, vă rugăm să încercați din nou.\n";
                } while (true);
                Meniu men;
                if (opt == 1) {
                    men.adaugaFel(Fel_Factory::fel_3_Vegan());
                    men.adaugaFel(Fel_Factory::fel_Principal_Vegan());
                    men.adaugaFel(Fel_Factory::desert_Vegan());
                    men.adaugaFel(Fel_Factory::fel_2_Vegan());
                    men.adaugaFel(Fel_Factory::aperitiv_Vegan());
                } else if (opt == 0) {
                    men.adaugaFel(Fel_Factory::aperitiv_Normal());
                    men.adaugaFel(Fel_Factory::fel_Principal_Normal());
                    men.adaugaFel(Fel_Factory::fel_2_Normal());
                    men.adaugaFel(Fel_Factory::fel_3_Normal());
                    men.adaugaFel(Fel_Factory::desert_Normal());
                } else if (opt == 2) {
                    men.adaugaFel(Fel_Factory::aperitiv_Vegetarian());
                    men.adaugaFel(Fel_Factory::fel_Principal_Vegetarian());
                    men.adaugaFel(Fel_Factory::fel_2_Vegetarian());
                    men.adaugaFel(Fel_Factory::fel_3_Vegetarian());
                    men.adaugaFel(Fel_Factory::desert_Vegetarian());
                }
                manager.modifica_meniu(idSala, idMasa, idInv, men);
            } else if (option == 10) {
                size_t idSala, idMasa, idInv;
                std::cout << "Numărul sălii este: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei este: ";
                std::cin >> idMasa;
                std::cout << "Numărul invitatului este: ";
                std::cin >> idInv;
                std::string numeFel;
                std::cout << "Numele feluiui de mâncare este: ";
                std::cin >> numeFel;
                double P1, P2, P3;
                std::cout << "Prețurile pentru produse sunt: (trei valori) ";
                std::cin >> P1 >> P2 >> P3;
                manager.add_fel(idSala, idMasa, idInv, std::make_shared<Fel_Copil>(Fel_Copil(numeFel, P1, P2, P3)));
            } else if (option == 11) {
                std::cout << "Doriți să completați cu personal la toate sălile? (D/N): ";
                char C;
                do {
                    std::cin >> C;
                    if (C == 'D' || C == 'N') {
                        break;
                    }
                    std::cout << "Opțiune greșită, vă rugâm încercați din nou.\n";
                } while (true);
                if (C == 'D') {
                    manager.add_personal();
                } else {
                    size_t idSala;
                    std::cout << "Numărul sălii pe care doriți să o completați cu personal este: ";
                    std::cin >> idSala;
                    manager.add_personal(idSala);
                }
            } else if (option == 12) {
                std::cout << "Costul total pentru organiarea evenimentului este " << manager.get_cost() << "\n";
                int tp = rand() % 4;
                if (tp == 0) {
                    std::cout << Reducere<int>(10).combine<int>(Reducere<int>(23)) << "\n";
                } else if (tp == 1) {
                    std::cout << Reducere<int>(10).combine<std::string>(Reducere<std::string>("Sala gratis ")) << "\n";
                } else if (tp == 2) {
                    std::cout << Reducere<std::string>("Sala gratis ").combine<int>(Reducere<int>(10)) << "\n";
                } else {
                    std::cout << Reducere<std::string>("Sală gratuită ").combine<std::string>(Reducere<std::string>("Personal din partea localului  "));
                }
            } else if (option == 13) {
                std::cout << manager << "\n";
                size_t idSala, idMasa, idInv;
                std::cout << "Numărul sălii este: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei este: ";
                std::cin >> idMasa;
                std::cout << "Numărul invitatului este: ";
                std::cin >> idInv;
                size_t idPos;
                std::cout << "Numărul felului de mâncare este: ";
                std::cin >> idPos;
                manager.del_fel(idSala, idSala, idInv, idPos);
            } else if (option == 14) {
                std::cout << manager << "\n";
                size_t idSala, idMasa, idAng;
                std::cout << "Numărul sălii sala: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei este: ";
                std::cin >> idMasa;
                std::cout << "Numărul angajatului este: ";
                std::cin >> idAng;
                double newSal;
                std::cout << "Noul salariu este: ";
                std::cin >> newSal;
                manager.modif_salariu(idSala, idMasa, idAng, newSal);
            } else if (option == 15) {
                size_t idSala;
                std::cout << manager << "\n";
                std::cout << "NumĂrul sălii pe care doriți să o ștergeți: ";
                std::cin >> idSala;
                manager.goleste_sala(idSala);
            } else {
                std::cout << "Eroare la identificarea operației.\n";
            }
        } catch (Eroare_Gestiune &err) {
            std::cout << err.what() << "\n";
        }

        std::string ok;
        while (true) {
            std::cout << "Apasă tasta y pentru ca continua!\n";
            std::cin >> ok;
            if (ok == "y" || ok == "Y") {
                break;
            }
        }
    } while(true);
    manager.update();
    return 0;
}
