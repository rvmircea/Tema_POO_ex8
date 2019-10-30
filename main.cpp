#include <iostream>
#include "Coada.h"

using namespace std;

void AfisMenu()
{
    cout<<"\nLista optiuni: \n";
    cout<<"1 - Cititi coada de caractere \n";
    cout<<"2 - Adaugati in coada \n";
    cout<<"3 - Scoateti din coada \n";
    cout<<"4 - Verificati daca coada este goala \n";
    cout<<"5 - Afisare continut coada \n";
    cout<<"6 - Concatenati 2 cozi \n";
    cout<<"7 - Aplicati operatia \"-\" pentru 2 cozi";
    cout<<"\n8 - Iesire \n\n";
}

Coada* Citire(int n)
{
    Coada *v;
   // char aux;
    v = new Coada[n];

    for(int i=0;i<n;i++)
    {
        int num_of_ele;

        cout<<"Cititi cate elemente are coada "<<i<<" : ";
        cin>>num_of_ele;
        cout<<"\nCititi caracterele: \n";
        while(num_of_ele)
        {

             /*cin>>aux;
             v[i].push(aux);*/
             cin>>v[i];
             num_of_ele--;
        }

        v[i].afis();
        cout<<endl;
    }
    return v;
}



int main()
{
    int OK = 1;
    int nr_cozi;
    int i,j;
    char val_char;
    Coada *v, w,u;

    while(OK)
    {
        AfisMenu();
        int opt;
        cout<<"Selectati optiune: ";
        cin>>opt;
        switch(opt)
        {
        case 1:
            cout<<"Dati numarul de cozi: ";
            cin>>nr_cozi;
            cout<<endl;
             v = Citire(nr_cozi);
            break;
        case 2:
            cout<<"\nSelecati coada in care doriti sa adaugati: ";
            cin>>i;
            cout<<"\nIntroduceti caracterul pe care doriti sa-l adaugati: ";
            cin>>val_char;
            v[i].push(val_char);
            break;
        case 3:
            cout<<"\nSelecati coada din care doriti sa stergeti: ";
            cin>>i;
            v[i].pop(val_char);
            break;
        case 4:
            cout<<"\nSelecati coada pe care doriti sa o verificati daca este goala: ";
            cin>>i;
            if(v[i].isempty())
                cout<<"\nCoada selectata este goala\n";
            else
                cout<<"\nCoada contine elemente \n";
            break;
        case 5:
            cout<<"\n1 - Coada citita \n2 - Coada obtiunuta prin concatenare \n3 - Coada optinuta prin operatia \"-\" \n";
            cin>>j;

            if(j == 1)
            {
                cout<<"\nSelecati coada pe care doriti sa o afisati: ";
                cin>>i;
                v[i].afis();
            }
            else if(j == 2)
                w.afis();
            else if(j == 3)
                u.afis();
            break;
        case 6:
            cout<<"\nSelectati cozile pe care doriti sa le concatenati: ";
            cin>>i>>j;
            w= v[i] + v[j];
            break;
        case 7:
            cout<<"\nSelecati cozile: \n";
            cin>>i>>j;
            u = v[i] - v[j];
            break;
        case 8:
            OK = 0;
            break;
        default:
            cout<<"\n\nOptiune nepermisa !";
        }
    }


    return 0;
}
