#ifndef VSCHEIN_H
#define VSCHEIN_H

#include<iostream>
#include<iomanip>
using namespace std;

class VSchein
{
protected:
    int scheinNummer;
    string vorname;
    string nachname;
    double monatsbeitrag;
public:
    VSchein(int sNummer, string vName, string nName);
    VSchein(const VSchein &k);
    virtual ~VSchein();
    virtual void anzeigen() = 0;
    int getScheinNr();
    virtual void anpassen();
};

#endif // VSCHEIN_H
