#include "vschein.h"

VSchein::VSchein(int sNummer, string vName, string nName) :
    scheinNummer(sNummer), vorname(vName), nachname(nName) {}

VSchein::VSchein(const VSchein &k)
    : scheinNummer(k.scheinNummer), vorname(k.vorname), nachname(k.nachname) {
    scheinNummer=k.scheinNummer;
    vorname=k.vorname;
    nachname=k.nachname;
}

VSchein::~VSchein() {}

void VSchein::anzeigen() {
    cout << "VersicherungNr. " << scheinNummer << " fuer "
         << vorname << " " << nachname << ":" << endl;
}

int VSchein::getScheinNr() {
    return scheinNummer;
}

void VSchein::anpassen() {
}
