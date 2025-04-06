#include "lvschein.h"

LVSchein::LVSchein(int sNummer, string vName, string nName)
    : VSchein::VSchein(sNummer, vName, nName)
{
    cout << "Versicherungssumme? ";
    cin >> vSumme;
    cout << "Versicherungsbeginn (Jahr)? ";
    cin >> vBeginn;
    cout << "Laufzeit in Jahren? ";
    cin >> laufzeit;
    beitragBerechnen();
    cout << "Lebensversicherung wurde angelegt" << endl;
}

LVSchein::~LVSchein() {}

void LVSchein::anzeigen() {
    VSchein::anzeigen();
    cout << "Lebensversicherung ueber " << vSumme << " Euro seit "
         << vBeginn << " mit Laufzeit von " << laufzeit
         << " Jahren und Monatsbeitrag von " << fixed
         << setprecision(2) << monatsbeitrag << " Euro" << endl;
}

void LVSchein::beitragBerechnen() {
    monatsbeitrag=(vSumme/100000.0)*3.52;
}

void LVSchein::anpassen() {
    double alte_monatsbeitrag=monatsbeitrag;
    cout << "Neue LV-Summe? ";
    cin >> vSumme;
    beitragBerechnen();
    cout << "Der Monatsbeitrag der LV betraegt nun " << fixed << setprecision(2) << monatsbeitrag
    << " Euro, zuvor waren es " << alte_monatsbeitrag << " Euro" << endl;
}
