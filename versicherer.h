#ifndef VERSICHERER_H
#define VERSICHERER_H

#include "vschein.h"
#include "kfzschein.h"
#include "lvschein.h"
#include <vector>

class Versicherer
{
private:
    vector<VSchein*>versicherungen;
public:
    Versicherer();
    ~Versicherer();
    void dialog();
    int nummerPruefen(int sNummer);
};

#endif // VERSICHERER_H
