#include "Pais.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

void Pais::mostrar()
{
    cout << _codigo << " " << _codigo2 << " " << _nombre << " " << _continente << " " << _superficie << " ";
    cout << _poblacion << " " << _independencia << " " << _expectativaDeVida << " " << _capital << endl;
}

void Pais::Mostrarcodpaisnumpoblacion()
{
    cout<< _codigo<< " "<< _nombre << " "<< _poblacion<<endl;
}

void Pais::setCodigo(const char *codigo)
{
    strcpy(_codigo, codigo);
}
void Pais::setCodigo2(const char *codigo2)
{
    strcpy(_codigo2, codigo2);
}
void Pais::setNombre(const char *nombre)
{
    strcpy(_nombre, nombre);
}
void Pais::setContinente(const char *continente)
{
    strcpy(_continente, continente);
}
void Pais::setSuperficie(float superficie)
{
    _superficie = superficie;
}
void Pais::setPoblacion(int poblacion)
{
    _poblacion = poblacion;
}
void Pais::setIndependencia(short independencia)
{
    _independencia = independencia;
}
void Pais::setExpectativaDeVida(float expectativa)
{
    _expectativaDeVida = expectativa;
}
void Pais::setIDCapital(int IDCapital)
{
    _capital = IDCapital;
}
char * Pais::getCodigo()
{
    return _codigo;
}
char * Pais::getCodigo2()
{
    return _codigo2;
}
char * Pais::getNombre()
{
    return _nombre;
}
char * Pais::getContinente()
{
    return _continente;
}
float Pais::getSuperficie()
{
    return _superficie;
}
int Pais::getPoblacion()
{
    return _poblacion;
}
short Pais::getIndependencia()
{
    return _independencia;
}
float Pais::getExpectativaDeVida()
{
    return _expectativaDeVida;
}
int Pais::getIDCapital()
{
    return _capital;
}

bool Pais::leerdedisco(int pos)
{
    FILE *p;
    bool leyo;
    p=fopen("paises.dat","rb");
    if(p==NULL)
    {
        cout<< "Error en memoria"<<endl;
        return false;
    }
    fseek(p,sizeof(Pais)*pos,0);
    leyo=fread(this,sizeof(Pais),1,p);
    fclose(p);
    return leyo;
}

bool Pais::ModificarRegistro(int pos)
{
    FILE *p;
    bool escribio;
    p=fopen("paises.dat","rb+");
    if(p==NULL)
    {
        cout<< "ERROR DE MEMORIA"<<endl;
        return false;
    }
    fseek(p,sizeof(Pais)*pos,0);
    escribio=fwrite(this,sizeof(Pais),1,p);
    fclose(p);
    return escribio;
}

