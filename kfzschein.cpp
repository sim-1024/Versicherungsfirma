#include "kfzschein.h"

KFZSchein::KFZSchein(int sNummer, string vName, string nName)
    : VSchein::VSchein(sNummer, vName, nName)
{
    cout << "KFZ-Kennzeichen? ";
    cin.ignore(10, '\n');
    getline(cin, KfzKennzeichen);
    cout << "Versicherungsbeginn (Jahr)? ";
    cin >> vBeginn;
    schadensfreieJahre=2024-vBeginn;
    if(schadensfreieJahre<=0) {
        schadensfreieJahre=0;
    }
    beitragBerechnen();
    cout << "KFZ-Versicherung wurde angelegt" << endl;
}

KFZSchein::KFZSchein(const KFZSchein &k)
    : VSchein(k) {
    monatsbeitrag=k.monatsbeitrag;
    KfzKennzeichen=k.KfzKennzeichen;
    vBeginn=k.vBeginn;
    schadensfreieJahre=k.schadensfreieJahre;
}

KFZSchein::~KFZSchein() {}

void KFZSchein::anzeigen() {
    VSchein::anzeigen();
    cout << "KFZ-Versicherung " << KfzKennzeichen << " seit "
         << vBeginn << " mit der SF-Klasse SF" << schadensfreieJahre
         << " und Monatsbeitrag von " << fixed
         << setprecision(2) << monatsbeitrag << " Euro" << endl;
}

void KFZSchein::beitragBerechnen() {
    if(schadensfreieJahre==0) {
        monatsbeitrag=68.74*150/100.0;
    } else if(schadensfreieJahre==2) {
        monatsbeitrag=68.74*85/100.0;
    } else if(schadensfreieJahre==3) {
        monatsbeitrag=68.74*70/100.0;
    } else if(schadensfreieJahre==4) {
        monatsbeitrag=68.74*55/100.0;
    } else {
        monatsbeitrag=68.74*(50-schadensfreieJahre)/100.0;
    }
}

void KFZSchein::anpassen() {
    char wahl;
    while(true) {
        cout << "Bitte waehlen Sie U fuer einen Unfall melden oder W fuer Fahrzeug wechseln" << endl;
        cin >> wahl;
        if(wahl == 'U' || wahl == 'u') {
            double alte_monatsbeitrag=monatsbeitrag;
            schadensfreieJahre-=6;
            if(schadensfreieJahre<=0) {
                schadensfreieJahre=0;
            }
            beitragBerechnen();
            cout << "Rueckstufung in SF" << schadensfreieJahre
                 << " erfolgt: Monatsbeitrag stieg von " << fixed << setprecision(2)
                 << alte_monatsbeitrag << " Euro auf " << monatsbeitrag << " Euro" << endl;
            break;
        } else if(wahl == 'W' || wahl == 'w') {
            cout << "Neues KFZ-Kennzeichen? ";
            cin.ignore(10, '\n');
            getline(cin, KfzKennzeichen);
            cout << "Versicherung auf " << KfzKennzeichen << " umgeschrieben" << endl;
            break;
        } else {
            cout << "Ungueltige Eingabe" << endl;
            continue;
        }
    }
}
