#ifndef COADA_H
#define COADA_H
#include <iostream>
#include "Nod.h"


using namespace std;


class Coada
{
    private:
        Nod* prim, *ultim;
public:
    Coada();
    ~Coada();
    void pop(char &);
    void push(char);
    void afis();
    int isempty();
    Coada operator+(Coada &);
    Coada operator-(Coada &);

    friend ostream& operator<<(ostream&,Coada&);
    friend istream& operator>>(istream&,Coada&);
};
#endif // COADA_H

