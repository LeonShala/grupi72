//Grupi 72 - Regjistrimi i nxensave ne shkolla fillore.
#include <iostream>
using namespace std;

void shfaqMenu() {
    cout << "\n===== MENUJA E SISTEMIT =====\n";
    cout << "1. Regjistro nxenes\n";
    cout << "2. Modifiko nxenes\n";
    cout << "3. Fshij nxenes\n";
    cout << "4. Shfaq / Kerko nxenes\n";
    cout << "0. Dil nga sistemi\n";
    cout << "Zgjedhja juaj: ";
}

int main() {
    int zgjedhja;

    do {
        shfaqMenu();
        cin >> zgjedhja;

        switch (zgjedhja) {
            case 1:
                cout << "Funksioni: Regjistrimi i nxenesit\n";
                break;
            case 2:
                cout << "Funksioni: Modifikimi i nxenesit\n";
                break;
            case 3:
                cout << "Funksioni: Fshirja e nxenesit\n";
                break;
            case 4:
                cout << "Funksioni: Shfaqja / Kerkimi i nxenesit\n";
                break;
            case 0:
                cout << "Duke dalur nga sistemi...\n";
                break;
            default:
                cout << "Zgjedhje e pavlefshme! Provo perseri.\n";
        }

    } while (zgjedhja != 0);
    return 0;
}

