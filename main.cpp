#include "headers/Manager.h"
// TODO maine: retine datele intr-un fisier, gandeste-te la cum ar arata un meniu

void printMenu() {
    std::cout << "[0] Afișare informații despre săli, mese, angajați și invitați.\n";
    std::cout << "[1] Adăugare sală.\n";
    std::cout << "[2] Ștergere sală.\n";
    std::cout << "[3] Adăugare masă.\n";
    std::cout << "[4] Ștergere masă.\n";
    std::cout << "[5] Adăugare angajat.\n";
    std::cout << "[6] Ștergere angajat.\n";
    std::cout << "[7] Adăugare invitat.\n";
    std::cout << "[8] Ștergere invitat.\n";
    std::cout << "[9] Adăugare meniu pentru invitat.\n";
    std::cout << "[10] Adăugare fel de mâncare pentru invitat.\n";
    std::cout << "[11] Adăugare personal lipsă.\n";
    std::cout << "[12] Afișare preț total.\n";
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
    return S[0] == '1' && S[1] >= '0' && S[1] <= '2';
}

int main() {
    Meniu M;

    M.adaugaFel(Fel_Factory::fel_3_Vegan());
    M.adaugaFel(Fel_Factory::fel_Principal_Vegan());
    M.adaugaFel(Fel_Factory::desert_Vegan());
    M.adaugaFel(Fel_Factory::fel_2_Vegan());
    M.adaugaFel(Fel_Factory::aperitiv_Vegan());

    Meniu T;
    T.adaugaFel(Fel_Factory::aperitiv_Normal());
    T.adaugaFel(Fel_Factory::fel_Principal_Normal());
    T.adaugaFel(Fel_Factory::fel_2_Normal());
    T.adaugaFel(Fel_Factory::fel_3_Normal());
    T.adaugaFel(Fel_Factory::desert_Normal());

    Meniu X;
    X.adaugaFel(Fel_Factory::aperitiv_Vegetarian());
    X.adaugaFel(Fel_Factory::fel_Principal_Vegetarian());
    X.adaugaFel(Fel_Factory::fel_2_Vegetarian());
    X.adaugaFel(Fel_Factory::fel_3_Vegetarian());
    X.adaugaFel(Fel_Factory::desert_Vegetarian());

    std::cout << M.pretMeniu() << "\n" << T.pretMeniu() << "\n" << X.pretMeniu() << "\n";

    auto &manager = Manager::get_manager();
    std::string command;
    do {
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
        switch (option) {
            case 0:
                std::cout << manager << "\n";
                break;
            case 1:
                manager.add_sala();
                break;
            case 2:
                std::cout << manager << "\n";
                size_t idSala;
                std::cout << "Număul sălii pe care doriți să o ștergeți: ";
                std::cin >> idSala;
                try {
                    manager.rem_sala(idSala);
                } catch(Eroare_Sali &err) {
                    std::cout << err.what() << "\n";
                }
                break;
            case 3:
                std::cout << manager << "\n";
                int numar_locuri, pret_consumabile_masa;
                std::cout << "Numarul sălii în care doriți să adăugați masa: ";
                std::cin >> idSala;
                std::cout << "Numărul de locuri din sală: ";
                std::cin >> numar_locuri;
                std::cout << "Prețul pentru consumabilele de la masă: ";
                std::cin >> pret_consumabile_masa;
                try {
                    manager.add_masa(idSala, numar_locuri, pret_consumabile_masa);
                } catch(Eroare_Sali &err) {
                    std::cout << err.what() << "\n";
                }
                break;
            case 4:
                std::cout << manager << "\n";
                size_t idMasa;
                std::cout << "Numarul sălii din care doriți să ștergeți masa: ";
                std::cin >> idSala;
                std::cout << "Numărul mesei pe care doriți să o ștergeți: ";
                std::cin >> idMasa;
                try {
                    manager.rem_masa(idSala, idMasa);
                } catch(Eroare_Sali &err) {
                    std::cout << err.what() << "\n";
                }
                break;
            case 5:
                std::cout << manager << "\n";

                break;
            case 6:
                std::cout << manager << "\n";

                break;
            case 7:
                std::cout << manager << "\n";

                break;
            case 8:
                std::cout << manager << "\n";

                break;
            case 9:
                std::cout << manager << "\n";

                break;
            case 10:

                break;
            case 11:
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
                    try {
                        std::cout << "Numărul sălii pe care doriți să o completați cu personal este: ";
                        std::cin >> idSala;
                        manager.add_personal(idSala);
                    } catch(Eroare_Sali &err) {
                        std::cout << err.what() << "\n";
                    }
                }
                break;
            case 12:
                std::cout << "Costul total pentru organiarea evenimentului este " << manager.get_cost() << "\n";
                break;
            default:
                std::cout << "Eroare la identificarea operației.\n";
                break;
        }
    } while(true);

    return 0;
}
