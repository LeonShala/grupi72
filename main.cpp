#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

// ================= STRUKTURA =================
struct Nxenes {
    int id;
    string emri;
    string mbiemri;
    string datalindjes;
    string gjinia;
    string klasa;
    string shkolla;
    string prindi;
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

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pastrimi i buffer-it

    cout << "Shkruaj emrin: ";
    getline(cin, n.emri);
    cout << "Shkruaj mbiemrin: ";
    getline(cin, n.mbiemri);
    cout << "Shkruaj daten e lindjes: ";
    getline(cin, n.datalindjes);
    cout << "Shkruaj gjininë: ";
    getline(cin, n.gjinia);
    cout << "Shkruaj klasen: ";
    getline(cin, n.klasa);
    cout << "Shkruaj shkollen: ";
    getline(cin, n.shkolla);
    cout << "Shkruaj emrin e prindit/kujdestarit: ";
    getline(cin, n.prindi);

    listaNxenesve.push_back(n);
    cout << "Nxenesi u regjistrua me sukses! ID = " << n.id << endl;
}

// ================= FUNKSIONI: MODIFIKIMI =================
void modifikoNxenes() {
    if (listaNxenesve.empty()) {
        cout << "Nuk ka nxenes per modifikim!\n";
        return;
    }

    int id;
    cout << "Shkruaj ID-ne e nxenesit per modifikim: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (size_t i = 0; i < listaNxenesve.size(); i++) {
        if (listaNxenesve[i].id == id) {
            cout << "Shkruaj emrin e ri: ";
            getline(cin, listaNxenesve[i].emri);
            cout << "Shkruaj mbiemrin e ri: ";
            getline(cin, listaNxenesve[i].mbiemri);
            cout << "Shkruaj daten e re te lindjes: ";
            getline(cin, listaNxenesve[i].datalindjes);
            cout << "Shkruaj gjininë e re: ";
            getline(cin, listaNxenesve[i].gjinia);
            cout << "Shkruaj klasen e re: ";
            getline(cin, listaNxenesve[i].klasa);
            cout << "Shkruaj shkollen e re: ";
            getline(cin, listaNxenesve[i].shkolla);
            cout << "Shkruaj emrin e ri te prindit/kujdestarit: ";
            getline(cin, listaNxenesve[i].prindi);

            cout << "Nxenesi u modifikua me sukses!\n";
            return;
        }
    }

    cout << "Nxenesi me kete ID nuk u gjet!\n";
}

// ================= FUNKSIONI: FSHIRJA =================
void fshijNxenes() {
    if (listaNxenesve.empty()) {
        cout << "Nuk ka nxenes per fshirje!\n";
        return;
    }

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

    string shkolla, klasa;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pastro buffer-in
    cout << "Filtrimi sipas shkollës (ose enter per te lene bosh): ";
    getline(cin, shkolla);
    cout << "Filtrimi sipas klasës (ose enter per te lene bosh): ";
    getline(cin, klasa);

    cout << "\n--- Nxenesit e filtruar ---\n";
    bool kaNxenes = false;
    for (size_t i = 0; i < listaNxenesve.size(); i++) {
        bool shkollaOk = shkolla.empty() || listaNxenesve[i].shkolla == shkolla;
        bool klasaOk = klasa.empty() || listaNxenesve[i].klasa == klasa;

        if (shkollaOk && klasaOk) {
            cout << "ID: " << listaNxenesve[i].id
                 << " | " << listaNxenesve[i].emri << " " << listaNxenesve[i].mbiemri
                 << " | DataLindjes: " << listaNxenesve[i].datalindjes
                 << " | Gjinia: " << listaNxenesve[i].gjinia
                 << " | Klasa: " << listaNxenesve[i].klasa
                 << " | Shkolla: " << listaNxenesve[i].shkolla
                 << " | Prindi: " << listaNxenesve[i].prindi << endl;
            kaNxenes = true;
        }
    }
    if (!kaNxenes) cout << "Nuk u gjet asnje nxenes me keto kritere.\n";

    // Kerkimi sipas emrit, mbiemrit ose ID-se
    string kerkimi;
    cout << "\nKerko nxenes sipas emrit, mbiemrit ose ID-se (ose enter per te anashkaluar): ";
    getline(cin, kerkimi);

    if (!kerkimi.empty()) {
        bool gjet = false;
        for (size_t i = 0; i < listaNxenesve.size(); i++) {
            stringstream ss;
            ss << listaNxenesve[i].id;
            string idStr = ss.str();

            if (listaNxenesve[i].emri == kerkimi ||
                listaNxenesve[i].mbiemri == kerkimi ||
                idStr == kerkimi) {
                cout << "Nxenesi u gjet: ID=" << listaNxenesve[i].id
                     << ", Emri=" << listaNxenesve[i].emri
                     << ", Mbiemri=" << listaNxenesve[i].mbiemri
                     << ", DataLindjes=" << listaNxenesve[i].datalindjes
                     << ", Gjinia=" << listaNxenesve[i].gjinia
                     << ", Klasa=" << listaNxenesve[i].klasa
                     << ", Shkolla=" << listaNxenesve[i].shkolla
                     << ", Prindi=" << listaNxenesve[i].prindi << endl;
                gjet = true;
            }
        }
        if (!gjet) cout << "Nuk u gjet nxenes me kete emer/ID.\n";
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
        cin >> zgjedhja;43

        switch (zgjedhja) {
            case 1: regjistroNxenes(); break;
            case 2: modifikoNxenes(); break;
            case 3: fshijNxenes(); break;
            case 4: shfaqKerkoNxenes(); break;
            case 0: cout << "Duke dalur nga sistemi...\n"; break;
            default: cout << "Zgjedhje e pavlefshme! Provo perseri.\n";
        }

    } while (zgjedhja != 0);

    return 0;
}