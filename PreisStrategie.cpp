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
    int preis;
    CD *CD;
    Date ausleihe;
    try
    {
        CD=cds.first().value;

        preis=CD->preis(tag-*(CD->holeAusleihen()->getDate()));
        sum+=preis;
        while(1)
        {
            CD=cds.next().value;
            if(CD->holeTyp()==1)
                continue;

            preis=CD->preis(*(CD->holeAusleihen()->getDate())-tag);
            sum+=preis;
        }
    }
    catch(...)
    {
        return sum;
    }



}



int GrossKundenPreis::preis(Dictionary<CD*> cds, Date tag)
{
    int sum=0;
    int preis;
    CD *CD;
    Date ausleihe;
    try
    {
        CD=cds.first().value;

        preis=CD->preis(tag-*(CD->holeAusleihen()->getDate()));
        sum+=preis;
        while(1)
        {
            CD=cds.next().value;
            preis=CD->preis(*(CD->holeAusleihen()->getDate())-tag);
            sum+=preis;
        }
    }
    catch(...)
    {
        sum*=0.85;

        return sum;
    }

}


int MitarbeiterPreis::preis(Dictionary<CD*> cds, Date tag)
{
    int sum=0;
    int preis;
    CD *CD;
    Date ausleihe;
    try
    {
        CD=cds.first().value;

        preis=CD->preis(tag-*(CD->holeAusleihen()->getDate()));
        sum+=preis;
        while(1)
        {
            CD=cds.next().value;
            preis=CD->preis(*(CD->holeAusleihen()->getDate())-tag);
            sum+=preis;
        }
    }
    catch(...)
    {
        return sum;
    }


}


