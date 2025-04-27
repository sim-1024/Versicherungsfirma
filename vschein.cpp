#include "vschein.h"


VSchein::VSchein(int sNummer, string vName, string nName)
    : scheinNummer(sNummer), vorname(vName), nachname(nName) {}

VSchein::~VSchein() {}

int VSchein::getScheinNummer() const {
    return scheinNummer;
}

void VSchein::anpassen() {}
