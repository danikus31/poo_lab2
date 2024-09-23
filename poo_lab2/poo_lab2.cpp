#include "connection.cpp";
#include "factory.h";
int main()
{
    
    factory myfactory;
    int menuOption;
    system("cls");
    do {
        myfactory.showQueues();
        cout << "\nIntroduceti optiunea dorita:\n";
        cout << "1. adaugare rand\n";
        cout << "2. afiseasa cutiile randului\n";
        cout << "3. adauga o cutie\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> menuOption;

        switch (menuOption) {
        case 1:
            myfactory.addQueue();
            break;
        case 2:
            myfactory.showBoxes();
            break;
        case 3:
            myfactory.addBox();
            break;
        case 0:
            cout << "Iesire...\n";
            break;
        default:
            cout << "Optiune invalida. Incercati din nou.\n";
            break;
        }

    } while (menuOption != 0);

    return 0;
}
