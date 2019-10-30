#include "Coada.h"

Coada  Coada::operator+( Coada &aux)
    {
        Coada c;
        char auy;
        while(this->isempty() ==0)
        {
            this->pop(auy);

            c.push(auy);
        }
        while(aux.isempty()==0)
            {
                aux.pop(auy);

                c.push(auy);
            }
        return c;
    }



Coada Coada::operator-(Coada &aux)
    {
        Coada c;
        char temp1,temp2;
        while(this->isempty() == 0 || aux.isempty() == 0)
        {
            this->pop(temp1);
            aux.pop(temp2);
            if(temp1 > temp2)
                c.push(temp1);
            else c.push(temp2);
        }
        return c;
    }

istream& operator>>(istream& in,Coada& x)
{
    char aux;
    cout<<"Introduceti valoarea: ";
    in>>aux;
    x.push(aux);
    return in;

}

ostream&operator<<(ostream& out,Coada& x)
{
    char aux;
    while(x.prim!= NULL)
    {
        out<<x.prim->info<<" ";
        x.pop(aux);
    }
    return out;
}
Coada::Coada()
{
    prim=ultim=NULL;

}
Coada::~Coada()
{
    while(prim!=NULL)
    {
        Nod* nou = prim;
        prim=prim->urm;
        delete nou;

    }
}

void Coada::push(char val)
{
    Nod* nou = new Nod;
    //cout<<"\nIntroduceti valoarea: ";
  // cin>>nou->info;
   nou->info = val;
    nou->urm = NULL;
    if(ultim == NULL)
    {

        prim=nou;
        ultim=nou;
    }
    else
    {
        ultim->urm = nou;
        ultim = nou;
    }

}

void Coada::pop(char &aux)
{
    if(prim==NULL)
    {
        cout<<"Actiune nepermisa";
        return;
    }
    else
    {

        Nod* nou = prim;
        aux=prim->info;
        //cout<<prim->info<<" a fost sters \n";
        prim=prim->urm;
        delete nou;

        if(prim==NULL)
            ultim=NULL;
    }

}

void Coada::afis()
{
    Nod* nou = prim;
    while(nou != NULL)
    {
        cout<<nou->info<<" ";
        nou=nou->urm;
    }
}

int Coada::isempty()
{
    if(prim==NULL)
    {
        return 1;
    }
    return 0;
}

