#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= STRUKTURA =================
struct Nxenes {
    int id;
    string emri;
    string mbiemri;
    // Mund të shtoni fusha të tjera si klasa, shkolla, prindi etj.
};

// ================= VARIABLA GLOBALE =================
vector<Nxenes> listaNxenesve;
int idAktual = 1000; // ID fillestare

// ================= FUNKSIONI: GJENERIMI I ID =================
int gjeneroID() {
    idAktual++;
    return idAktual;
}

// ================= FUNKSIONI: REGJISTRIMI =================
void regjistroNxenes() {
    Nxenes n;
    n.id = gjeneroID();
    cout << "Shkruaj emrin: ";
    cin >> n.emri;
    cout << "Shkruaj mbiemrin: ";
    cin >> n.mbiemri;

    listaNxenesve.push_back(n);
    cout << "Nxenesi u regjistrua me sukses! ID = " << n.id << endl;
}

// ================= FUNKSIONI: MODIFIKIMI =================
void modifikoNxenes() {
    int id;
    cout << "Shkruaj ID-ne e nxenesit per modifikim: ";
    cin >> id;

    for (size_t i = 0; i < listaNxenesve.size(); i++) {
        if (listaNxenesve[i].id == id) {
            cout << "Shkruaj emrin e ri: ";
            cin >> listaNxenesve[i].emri;
            cout << "Shkruaj mbiemrin e ri: ";
            cin >> listaNxenesve[i].mbiemri;
            cout << "Nxenesi u modifikua me sukses!\n";
            return;
        }
    }
    cout << "Nxenesi me kete ID nuk u gjet!\n";
}

// ================= FUNKSIONI: FSHIRJA =================
void fshijNxenes() {
    int id;
    cout << "Shkruaj ID-ne e nxenesit per fshirje: ";
    cin >> id;

    for (size_t i = 0; i < listaNxenesve.size(); i++) {
        if (listaNxenesve[i].id == id) {
            char konfirmim;
            cout << "A jeni i sigurt? (p/j): ";
            cin >> konfirmim;

            if (konfirmim == 'p' || konfirmim == 'P') {
                listaNxenesve.erase(listaNxenesve.begin() + i);
                cout << "Nxenesi u fshi me sukses!\n";
            } else {
                cout << "Fshirja u anulua.\n";
            }
            return;
        }
    }

    cout << "Nxenesi me kete ID nuk u gjet!\n";
}

// ================= FUNKSIONI: SHFAQ/KERKO =================
void shfaqKerkoNxenes() {
    if (listaNxenesve.empty()) {
        cout << "Nuk ka nxenes te regjistruar.\n";
        return;
    }

    cout << "\n--- Lista e nxenesve ---\n";
    for (size_t i = 0; i < listaNxenesve.size(); i++) {
        cout << "ID: " << listaNxenesve[i].id << " | "
             << listaNxenesve[i].emri << " " << listaNxenesve[i].mbiemri << endl;
    }

    string emriKerko;
    cout << "Shkruaj emrin per kerkimin (ose enter per te anashkaluar): ";
    cin.ignore(); // për të pastruar buffer-in
    getline(cin, emriKerko);

    if (!emriKerko.empty()) {
        bool gjet = false;
        for (size_t i = 0; i < listaNxenesve.size(); i++) {
            if (listaNxenesve[i].emri == emriKerko) {
                cout << "Nxenesi u gjet: ID=" << listaNxenesve[i].id
                     << ", Emri=" << listaNxenesve[i].emri
                     << ", Mbiemri=" << listaNxenesve[i].mbiemri << endl;
                gjet = true;
            }
        }
        if (!gjet) cout << "Nuk u gjet nxenes me kete emer.\n";
    }
}

// ================= FUNKSIONI: MENUJA =================
void shfaqMenu() {
    cout << "\n===== MENUJA E SISTEMIT =====\n";
    cout << "1. Regjistro nxenes\n";
    cout << "2. Modifiko nxenes\n";
    cout << "3. Fshij nxenes\n";
    cout << "4. Shfaq / Kerko nxenes\n";
    cout << "0. Dil nga sistemi\n";
    cout << "Zgjedhja juaj: ";
}

// ================= MAIN =================
int main() {
    int zgjedhja;

    do {
        shfaqMenu();
        cin >> zgjedhja;

        switch (zgjedhja) {
    case 1:
        regjistroNxenes();
        break;

    case 2:
        if (listaNxenesve.empty()) {
            cout << "Nuk ka nxenes per modifikim!\n";
        } else {
            modifikoNxenes();
        }
        break;

    case 3:
        if (listaNxenesve.empty()) {
            cout << "Nuk ka nxenes per fshirje!\n";
        } else {
            fshijNxenes();
        }
        break;

    case 4:
        if (listaNxenesve.empty()) {
            cout << "Nuk ka nxenes per shfaqje ose kerkimin!\n";
        } else {
            shfaqKerkoNxenes();
        }
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