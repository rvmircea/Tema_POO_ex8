#include <iostream>
#include "Coada.h"
//#include <string.h>

using namespace std;

void AfisMenu()
{
    cout<<"\nLista optiuni: \n";
    cout<<"1 - Adaugati in coada \n";
    cout<<"2 - Scoateti din coada \n";
    cout<<"3 - Verificati daca coada este goala \n";
    cout<<"4 - Afisare continut coada ";
    cout<<"\n5 - Iesire \n\n";
}


Coada* Citire(int n)
{
    Coada *v;
    char aux;
    v = new Coada[n];

    for(int i=0;i<n;i++)
    {
        int num_of_ele;

        cout<<"Cititi cate elemente are coada: \n";
        cin>>num_of_ele;
        while(num_of_ele)
        {
             cin>>aux;
             v[i].push(aux);
             num_of_ele--;
        }

        v[i].afis();
        cout<<endl;
    }



    return v;



}



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
        //cout<<"\nCoada este goala\n";
        return 1;
    }
   // cout<<"\nCoada contine elemente\n";
    return 0;
}



int main()
{
    Coada *v;
    int n = 3;

   v = Citire(n);

    v[1].afis();


    /*
    Coada A, B,C;
    int OK = 1;
    char aux,auy;
    cout<<"introduceti valoare: ";
    cin>>aux;
    A.push(aux);
    cout<<"\nintroduceti valoare: ";
    cin>>aux;
    A.push(aux);

    cout<<"introduceti valoare: ";
    cin>>aux;
    B.push(aux);
    cout<<"introduceti valoare: ";
    cin>>aux;
    B.push(aux);

    C=A-B;

    C.afis();

    cout<<"\n "<<auy<<endl;
/*
    while(OK)
    {
        AfisMenu();
        int opt;
        cout<<"Selectati optiune: ";
        cin>>opt;
        switch(opt)
        {
        case 1:
            //cin>>aux;
            //A.push(aux);
            cin>>A;
            break;
        case 2:
            A.pop(aux);
            break;
        case 3:
            A.isempty();
            break;
        case 4:
            A.afis();
            break;
        case 5:
            OK = 0;
            return 1;
        default:
            cout<<"\n\nOptiune nepermisa !";
        }
    }

*/
    return 0;
}
