#include "lvschein.h"

LVSchein::LVSchein(int sNummer, string vName, string nName)
    : VSchein(sNummer, vName, nName) {
    cout << "Versicherungssumme? ";
    cin >> vSumme;
    cout << "Versicherungsbegin (Jahr)? ";
    cin >> vBeginn;
    cout << "Laufzeit in Jahren? ";
    cin >> laufzeit;
    cout << "Lebensversicherung wurde angelegt" << endl;
    beitragBerechnen();
}

LVSchein::~LVSchein() {}

void LVSchein::anzeigen() {
    cout << "VersicherungNr. " << scheinNummer << " fuer " << vorname << " " << nachname << ": " << endl;
    cout << "Lebensversicherung ueber " << vSumme << " Euro seit " << vBeginn
         << " mit Laufzeit von " << laufzeit << " Jahren und Monatsbeitrag von "
         << fixed << setprecision(2) << monatsbeitrag << " Euro" << endl;
}

void LVSchein::beitragBerechnen() {
    monatsbeitrag = 3.52 * (vSumme/100000);
}

void LVSchein::anpassen() {
    double alte_monatsbeitrag = monatsbeitrag;
    cout << "Neue LV-Summe: ";
    cin >> vSumme;
    beitragBerechnen();
    cout << "Der Monatsbeitrag der LV betraegt nun " << monatsbeitrag
         << " Euro, zuvor waren es " << alte_monatsbeitrag << " Euro" << endl;
}
