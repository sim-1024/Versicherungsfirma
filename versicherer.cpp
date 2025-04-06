#include "versicherer.h"
#include "kfzschein.h"
#include "lvschein.h"


Versicherer::Versicherer() {}

Versicherer::~Versicherer() {
    for (auto schein : versicherungen) {
        delete schein;
    }
    versicherungen.clear();
    cout << "Bis bald!" << endl;
}

void Versicherer::dialog() {
    while (true){
        char eingabe;
        int sNummer;
        cout << "\n1: Versicherung anlegen" << endl;
        cout << "2: Versicherungsdetails ausgeben" << endl;
        cout << "3: Alle Versicherungen anzeigen" << endl;
        cout << "4: Versicherung loeschen" << endl;
        cout << "5: Versicherung anpassen" << endl;
        cout << "0: Programm beenden" << endl;
        cin >> eingabe;

        switch(eingabe){
        case '1':{
            string vTyp, vName, nName;
            cout << "ScheinNummer? ";
            cin >> sNummer;
            nummerPruefen(sNummer);
            cout << "Vorname? ";
            cin >> vName;
            cout << "Nachname? ";
            cin >> nName;
            while(true){
                cout << "K fuer KFZ-Versicherung oder L fuer Lebensversicherung? ";
                cin >> vTyp;
                if (vTyp == "K" || vTyp == "k"){
                    KFZSchein* kSchein = new KFZSchein(sNummer, vName, nName);
                    versicherungen.push_back(kSchein);
                    printDetails(*kSchein);
                    break;
                }
                else if (vTyp == "L" || vTyp == "l"){
                    LVSchein* lSchein = new LVSchein(sNummer, vName, nName);
                    versicherungen.push_back(lSchein);
                    break;
                }
                else{
                    cout << "Ungueltige Eingabe" << endl;
                    continue;
                }
            }
        }
        break;

        case '2':{
            cout << "Scheinnummer? ";
            cin >> sNummer;
            bool gefunden=false;
            for (size_t i = 0; i<versicherungen.size(); i++) {
                if (versicherungen[i]->getScheinNr()==sNummer) {
                    versicherungen[i]->anzeigen();
                    gefunden=true;
                    break;
                }
            }
            if(gefunden) {
                break;
            }
            cout << "Versicherungsschein existiert nicht" << endl;
        }
        break;

        case '3':{
            for (auto schein : versicherungen) {
                schein->anzeigen();
                cout << "-----------------------------------------------------------" << endl;
            }
        }
        break;

        case '4':{
            cout << "Versicherungsnummer (Nr.)? ";
            cin >> sNummer;
            versicherungLoeschen(sNummer);
        }
        break;

        case '5':{
            cout << "Versicherungsnummer (Nr.)? ";
            cin >> sNummer;
            for (size_t i = 0; i < versicherungen.size(); i++) {
                if(versicherungen[i]->getScheinNr()==sNummer) {
                    versicherungen[i]->anpassen();
                }
            }
        }
        break;

        case '0':
            return;
            break;
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}

int Versicherer::nummerPruefen(int sNummer) {
    for (auto schein : versicherungen) {
        while(schein->getScheinNr()==sNummer) {
            cout << "Scheinnummer existiert bereits!" << endl;
            cout << "ScheinNummer? ";
            cin >> sNummer;
        }
    }
    return sNummer;
}

void Versicherer::versicherungLoeschen(int sNummer) {
    bool gefunden=false;
    for (size_t i=0 ; i < versicherungen.size() ; i++) {
        if(versicherungen[i]->getScheinNr()==sNummer) {
            versicherungen.erase(versicherungen.begin() + i);
            cout << "Versicherung Nr. " << sNummer <<" wurde geloescht" << endl;
            gefunden=true;
            break;
        }
    }
    if(!gefunden) {
        cout << "Keine Versicherung zu dieser Nummer gefunden" << endl;
    }
}

void Versicherer::printDetails(KFZSchein k) {
    cout << "-----------------------------------------------------------------------------------------" << endl;
    k.anzeigen();
    cout << "-----------------------------------------------------------------------------------------" << endl;
}
