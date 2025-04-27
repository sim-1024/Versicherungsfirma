#include "kfzschein.h"

KFZSchein::KFZSchein(int sNummer, string vName, string nName)
    : VSchein(sNummer, vName, nName) {
    cout << "KFZ-Kennzeichen? ";
    cin.ignore(10,'\n');
    getline(cin, kfzKennzeichen);
    cout << "Versicherungsbegin (Jahr)? ";
    cin >> vBeginn;
    cout << "KFZ-Versicherung wurde angelegt" << endl;
    schadensfreieJahre=2025-vBeginn;
    if(schadensfreieJahre<0) {
        schadensfreieJahre=0;
    }
    beitragBerechnen();
}

KFZSchein::~KFZSchein() {}

void KFZSchein::anzeigen() {
    cout << "VersicherungNr. " << scheinNummer << " fuer " << vorname << " " << nachname << ": " << endl;
    cout << "KFZ-Versicherung " << kfzKennzeichen << " seit " << vBeginn
         << " mit der SF-Klasse SF" << schadensfreieJahre << " und Monatsbeitrag von "
         << fixed << setprecision(2) << monatsbeitrag << " Euro" << endl;
}

void KFZSchein::beitragBerechnen() {
    double pauschaltarif=68.74;;
    if(schadensfreieJahre==0) {
        monatsbeitrag = pauschaltarif * 1.5;
    } else if(schadensfreieJahre==1) {
        monatsbeitrag = pauschaltarif;
    } else if(schadensfreieJahre==2) {
        monatsbeitrag = pauschaltarif * 0.85;
    } else if(schadensfreieJahre==3) {
        monatsbeitrag = pauschaltarif * 0.70;
    } else if(schadensfreieJahre==4) {
        monatsbeitrag = pauschaltarif * 0.55;
    } else {
        monatsbeitrag = pauschaltarif * ((50 - schadensfreieJahre)/100.0);
    }
}

void KFZSchein::anpassen() {
    char choice;
    cout << "Bitte waehlen Sie U fuer einen Unfall melden oder W fuer Fahrzeug wechseln" << endl;
    while(true) {
        cin >> choice;
        if(choice == 'U' || choice == 'u') {
            double alte_monatsbeitrag = monatsbeitrag;
            schadensfreieJahre-=6;
            if(schadensfreieJahre<0) {
                schadensfreieJahre=0;
            }
            beitragBerechnen();
            cout << "Rueckstufung in SF" << schadensfreieJahre << " erfolgt: Monatsbeitrag stieg von "
                 << alte_monatsbeitrag << " Euro auf " << monatsbeitrag << " Euro" << endl;
            break;
        } else if(choice == 'W' || choice == 'w') {
            cout << "Neues KFZ-Kennzeichen? ";
            cin.ignore(10, '\n');
            getline(cin, kfzKennzeichen);
            cout << "Versicherung auf " << kfzKennzeichen << " umgeschrieben" << endl;
            break;
        } else {
            cout << "Ungueltige Eingabe! U fuer einen Unfall melden oder W fuer Fahrzeug wechseln" << endl;
        }
    }
}
