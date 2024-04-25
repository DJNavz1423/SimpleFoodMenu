#include "Payment&etc.h"

int main() {
    Menu foodMenu{};
    system("chcp 65001 > nul");
    
    bool run = false;

    do {
        foodMenu.intro();
        char input;
        std::cin >> input;

        switch (input) {
        case 'N':
        case 'n':
            std::cout << "\nExiting Program...\n";
            Sleep(1000);
            run = true;
            break;
        case 'Y':
        case 'y':
            foodMenu.Functionality();
            run = true;
            break;
        default:
            std::cout << "\a\nINVALID INPUT! PRESS ANY KEY TO CONTINUE!";
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;
        }
    } while (!run);
    return 0;
}
