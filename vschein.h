#ifndef VSCHEIN_H
#define VSCHEIN_H

#include <iostream>
#include <iomanip>
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
    virtual ~VSchein();
    virtual void anzeigen()=0;
    int getScheinNummer() const;
    virtual void anpassen();
};

#endif // VSCHEIN_H
