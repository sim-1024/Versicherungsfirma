#include "versicherer.h"

Versicherer::Versicherer() {}

Versicherer::~Versicherer() {
    for (auto versicherung : versicherungen) {
        delete versicherung;
    }
    versicherungen.clear();
    cout << "Bis bald!" << endl;
}

void Versicherer::dialog() {

    while (true){
        char eingabe;
        cout << "\n1: Versicherung anlegen" << endl;
        cout << "2: Versicherungsdetails ausgeben" << endl;
        cout << "3: Alle Versicherungen anzeigen" << endl;
        cout << "4: Versicherung loeschen" << endl;
        cout << "5: Versicherung anpassen" << endl;
        cout << "0: Programm beenden" << endl;
        cin >> eingabe;

        int sNummer;

        switch(eingabe){
        case '1':{
            string vTyp, vName, nName;

            cout << "ScheinNummer? ";
            cin >> sNummer;

            if(nummerPruefen(sNummer)!=-1) {
                cout << "Die Nummer ist schon vergeben!" << endl;
            }

            cout << "Vorname? ";
            cin >> vName;
            cout << "Nachname? ";
            cin >> nName;

            while(true){
                cout << "K fuer KFZ-Versicherung oder L fuer Lebensversicherung? ";
                cin >> vTyp;

                if (vTyp == "K" || vTyp == "k"){
                    VSchein* neueKfzV = new KFZSchein(sNummer, vName, nName);
                    versicherungen.push_back(neueKfzV);
                    break;
                }
                else if (vTyp == "L" || vTyp == "l"){
                    VSchein* neueLV = new LVSchein(sNummer, vName, nName);
                    versicherungen.push_back(neueLV);
                    break;
                }
                else{
                    cout << "Ungueltige Eingabe" << endl;
                }
            }
        }
        break;

        case '2':{
            cout << "ScheinNummer? ";
            cin >> sNummer;

            int index = nummerPruefen(sNummer);

            if(index==-1) {
                cout << "Versicherungsschein existiert nicht" << endl;
            } else {
                versicherungen[index]->anzeigen();
            }
        }
        break;

        case '3':{
            for (size_t i = 0; i < versicherungen.size(); i++) {
                versicherungen[i]->anzeigen();
                cout << "----------------------------------------------" << endl;
            }
        }
        break;

        case '4':{
            cout << "ScheinNummer? ";
            cin >> sNummer;

            int index = nummerPruefen(sNummer);

            if(index==-1) {
                cout << "Keine Versicherung zu dieser Nummer gefunden" << endl;
            } else {
                versicherungen.erase(versicherungen.begin()+index);
                cout << "Versicherung Nr. " << sNummer << " wurde geloescht" << endl;
            }
        }
        break;

        case '5':{
            cout << "ScheinNummer? ";
            cin >> sNummer;

            int index = nummerPruefen(sNummer);

            if(index==-1) {
                cout << "Keine Versicherung zu dieser Nummer gefunden" << endl;
            } else {
                versicherungen[index]->anpassen();
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
    for (size_t i = 0; i < versicherungen.size(); i++) {
        if(versicherungen[i]->getScheinNummer()==sNummer) {
            return i;
        }
    }
    return -1;
}
