#include "Mundo.h"
#include <cstdio>
#include <iostream>
using namespace std;
Mundo::Mundo()
{
    //ctor
}
void Mundo::Mostrar()
{
    cout<< codigoPais<< " "<< nombrePais<< " "<< nombreciudadconmayorPoblacion<< " "<<PoblacionCiudadMayor<<endl;
}
void Mundo::grabarendisco()
{
    FILE *p;
    p=fopen("mundo.dat","ab");
    if(p==NULL)return;
    fwrite(this,sizeof (Mundo),1,p);
    fclose(p);
}

bool Mundo::Leerdedisco(int pos)
{
    FILE *p;
    bool leyo;
    p=fopen("mundo.dat","rb");
    if(p==NULL)
    {
        cout<< "Error en memoria"<<endl;
        return false;
    }
    fseek(p,sizeof(Mundo)*pos,0);
    leyo=fread(this,sizeof(Mundo),1,p);
    fclose(p);
    return leyo;
}
