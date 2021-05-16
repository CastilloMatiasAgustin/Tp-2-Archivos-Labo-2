#include "Ciudad.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int  Ciudad::getID()
{
    return _ID;
}
char * Ciudad::getNombre()
{
    return _nombre;
}
char * Ciudad::getIDPais()
{
    return _idpais;
}
int  Ciudad::getPoblacion()
{
    return _poblacion;
}
void Ciudad::setID(int val)
{
    _ID = val;
}
void Ciudad::setNombre(const char * val)
{
    strcpy(_nombre, val);
}
void Ciudad::setIDPais(const char * val)
{
    strcpy(_idpais, val);
}
void Ciudad::setPoblacion(int val)
{
    _poblacion = val;
}
void Ciudad::mostrar(){
    cout << _ID << " " << _idpais << " " << _nombre << " " << _poblacion << endl;
}
void Ciudad::carga()
{
    cout<< "Ingrese un ID de ciudad: "<<endl;
    cin>> _ID;
    cout<< "Ingrese el Nombre del Pais: "<<endl;
    cin.ignore();
    cin.getline(_nombre,35);
    cout<< "Ingrese el ID del Pais: "<<endl;
    cin.getline(_idpais,4);
    cout<< "Ingrese la Poblacion de la Ciudad: "<<endl;
    cin>> _poblacion;
}

bool Ciudad::AgregarRegistro(int pos)
{
    FILE *p;
    bool escribio;
    p=fopen("ciudades.dat","ab");
    if(p==NULL)
    {
        cout<< "ERROR DE MEMORIA"<<endl;
        return false;
    }
    fseek(p,sizeof(Ciudad)*pos,0);
    escribio=fwrite(this,sizeof(Ciudad),1,p);
    fclose(p);
    return escribio;
}

bool Ciudad::leerdedisco(int pos)
{
    FILE *p;
    bool leyo;
    p=fopen("ciudades.dat","rb");
    if(p==NULL)
    {
        cout<< "Error en memoria"<<endl;
        return false;
    }
    fseek(p,sizeof(Ciudad)*pos,0);
    leyo=fread(this,sizeof(Ciudad),1,p);
    fclose(p);
    return leyo;
}
