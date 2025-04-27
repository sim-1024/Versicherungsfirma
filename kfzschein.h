#ifndef KFZSCHEIN_H
#define KFZSCHEIN_H

#include "vschein.h"

class KFZSchein : public VSchein
{
private:
    string kfzKennzeichen;
    int vBeginn;
    int schadensfreieJahre;
public:
    KFZSchein(int sNummer, string vName, string nName);
    virtual ~KFZSchein();
    void anzeigen();
    void beitragBerechnen();
    void anpassen();
};

#endif // KFZSCHEIN_H
