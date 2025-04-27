#ifndef LVSCHEIN_H
#define LVSCHEIN_H

#include "vschein.h"

class LVSchein : public VSchein
{
private:
    double vSumme;
    int vBeginn;
    int laufzeit;
public:
    LVSchein(int sNummer, string vName, string nName);
    virtual ~LVSchein();
    void anzeigen();
    void beitragBerechnen();
    void anpassen();
};

#endif // LVSCHEIN_H
