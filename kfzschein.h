#ifndef KFZSCHEIN_H
#define KFZSCHEIN_H

#include "vschein.h"

class KFZSchein : public VSchein
{
private:
    string KfzKennzeichen;
    int vBeginn;
    int schadensfreieJahre;
public:
    KFZSchein(int sNummer, string vName, string nName);
    KFZSchein(const KFZSchein &k);
    virtual ~KFZSchein();
    void anzeigen();
    void beitragBerechnen();
    void anpassen();
};

#endif // KFZSCHEIN_H
