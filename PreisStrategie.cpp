#include"PreisStrategie.h"
#include<list>


int PreisStrategie::typ()
{
    return _typ;
}

PreisStrategie::PreisStrategie()
{
    _typ=0;
}

MitarbeiterPreis::MitarbeiterPreis():PreisStrategie()
{
    _typ=1;
}

GrossKundenPreis::GrossKundenPreis():PreisStrategie()
{
    _typ=2;
}

int PreisStrategie::preis(Dictionary<CD*>  cds, Date tag)
{
    int sum=0;


    return sum;
}



int GrossKundenPreis::preis(Dictionary<CD*> cds, Date tag)
{

	int sum=0;

    cds.first();



    return sum;
}


int MitarbeiterPreis::preis(Dictionary<CD*> cds, Date tag)
{
    int sum=0;

    return sum;
}


