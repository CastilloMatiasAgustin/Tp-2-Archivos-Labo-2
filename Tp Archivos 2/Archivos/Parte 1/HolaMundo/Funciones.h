#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdio>
#include <cstring>
#include "Mundo.h"
void leerPaises(Pais *vec,int tam)
{
    FILE *p;
    p=fopen("paises.dat","rb");
    fread(vec,sizeof(Pais),tam,p);
    fclose(p);
}


void PuntoA()
{
    FILE *p;
    int t,cr;
    p=fopen("paises.dat","rb");
    if(p==NULL)
    {
        cout<< "ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(p,0,SEEK_END);
    t=ftell(p);
    cr=t/sizeof(Pais);
    Pais *vec=NULL;
    vec= new Pais [cr];
    if(vec==NULL)
    {
        cout<< "No hay memoria"<<endl;
        delete vec;
        return;
    }
    leerPaises(vec,cr);
    int posmax;
    for(int i=0; i<cr-1; i++)
    {
        posmax=i;
        for(int j=i+1; j<cr; j++)
        {
            if(vec[j].getPoblacion()>vec[posmax].getPoblacion())
            {
                posmax=j;
            }
        }
        Pais aux=vec[i];
        vec[i]=vec[posmax];
        vec[posmax]=aux;
    }

    for (int i=0; i<cr; i++)
    {
        vec[i].Mostrarcodpaisnumpoblacion();
    }
}

int buscarciudad(int id)
{
    Ciudad obj;
    int pos=0;
    while (obj.leerdedisco(pos))
    {
        obj.mostrar();
        if(obj.getID()==id)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

bool buscarIDpais(char *idpais)
{
    Ciudad obj;
    int pos=0;
    while(obj.leerdedisco(pos))
    {
        if(strcmp(obj.getIDPais(),idpais)==0)
        {
            return true;
        }
        pos++;
    }
    return false;
}

void PuntoB()
{
    Ciudad obj;
    int _ID;
    char _nombre[35];
    char _idpais[4];
    int _poblacion;
    int pos;
    cout<< "Ingrese un ID de ciudad: "<<endl;
    cin>> _ID;
    pos=buscarciudad(_ID);
    while(pos!=-1)
    {
        cout<< ">>ID de ciudad existente reingrese nuevamente un ID no existente<<"<<endl;
        cin>>_ID;
        pos=buscarciudad(_ID);
    }
    obj.setID(_ID);
    cout<< "Ingrese el Nombre del Pais: "<<endl;
    cin.ignore();
    cin.getline(_nombre,35);
    obj.setNombre(_nombre);
    cout<< "Ingrese el ID del Pais: "<<endl;
    cin>>_idpais;
    while(buscarIDpais(_idpais)!=true)
    {
        cout<< ">>ID de pais ingresado no existente, reingrese nuevamente <<"<<endl;
        cin>>_idpais;
    }
    obj.setIDPais(_idpais);
    cout<< "Ingrese la Poblacion de la Ciudad: "<<endl;
    cin>> _poblacion;
    while(_poblacion<=0)
    {
        cout<< ">>Reingrese la Poblacion de la Ciudad<<"<<endl;
        cin>> _poblacion;
    }
    obj.setPoblacion(_poblacion);

    if(obj.AgregarRegistro(pos))
    {
        cout<< "Registro Agregado con exito"<<endl;
    }
}

void leerciudades(Ciudad *vec,int tam)
{
    FILE *p;
    p=fopen("ciudades.dat","rb");
    fread(vec,sizeof(Ciudad),tam,p);
    fclose(p);
}

void PuntoC()
{
    char nombre[50];
    int poblacion;
    cout<< "Ingrese El nombre de la ciudad a analizar: "<<endl;
    cin.ignore();
    cin.getline(nombre,50);
    cout<< "Ingrese la poblacion de la ciudad a analizar"<<endl;
    cin>>poblacion;

    FILE *p;
    int t,cr;
    p=fopen("ciudades.dat","rb");
    if(p==NULL)
    {
        cout<< "ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(p,0,SEEK_END);
    t=ftell(p);
    cr=t/sizeof(Ciudad);
    Ciudad *vec=NULL;
    vec= new Ciudad [cr];
    if(vec==NULL)
    {
        cout<< "No hay memoria"<<endl;
        delete vec;
        return;
    }
    leerciudades(vec,cr);
    int posmax;
    for(int i=0; i<cr-1; i++)
    {
        posmax=i;
        for(int j=i+1; j<cr; j++)
        {
            if(vec[j].getPoblacion()>vec[posmax].getPoblacion())
            {
                posmax=j;
            }
        }
        Ciudad aux=vec[i];
        vec[i]=vec[posmax];
        vec[posmax]=aux;
    }

    int posranking=0;
    for (int i=0; i<cr; i++)
    {
        if(poblacion<vec[i].getPoblacion())
        {
            posranking++;
        }
    }
    cout<< "La ciudad "<<nombre<< " Estaria en el ranking: "<<posranking<<endl;
}

int buscarPais(char *id)
{
    Pais obj;
    int pos=0;
    while (obj.leerdedisco(pos))
    {
        if(strcmp(obj.getCodigo(),id)==0)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

void PuntoD()
{
    char codPais[4];
    int pos,poblacionNew;
    Pais obj;
    cout<< "Ingrese el Codigo del Pais a Actualizar: "<<endl;
    cin>>codPais;
    FILE *p;
    p=fopen("paises.dat","rb+");
    if(p==NULL)
    {
        cout<< "ERROR EN MEMORIA"<<endl;
        return;
    }
    pos=buscarPais(codPais);
    obj.leerdedisco(pos);
    obj.mostrar();
    cout<< "Ingrese La nueva poblacion de este pais: "<<endl;
    cin>>poblacionNew;
    obj.setPoblacion(poblacionNew);
    if(obj.ModificarRegistro(pos)==true)
    {
        cout<< "Poblacion Modificada con excito"<<endl;
    }
    else
    {
        cout<< "La poblacion No se ha podido modificar"<<endl;
    }
}

void PuntoE()
{
    FILE *p;
    int t,cr;
    p=fopen("ciudades.dat","rb");
    if(p==NULL)
    {
        cout<< "ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(p,0,SEEK_END);
    t=ftell(p);
    cr=t/sizeof(Ciudad);
    Ciudad *vec=NULL;
    vec= new Ciudad [cr];
    if(vec==NULL)
    {
        cout<< "No hay memoria"<<endl;
        delete vec;
        return;
    }
    leerciudades(vec,cr);
    int posmax;
    for(int i=0; i<cr-1; i++)
    {
        posmax=i;
        for(int j=i+1; j<cr; j++)
        {
            if(vec[j].getPoblacion()>vec[posmax].getPoblacion())
            {
                posmax=j;
            }
        }
        Ciudad aux=vec[i];
        vec[i]=vec[posmax];
        vec[posmax]=aux;
    }
    fclose(p);

    int pos=0,posi=0;
    Ciudad ciu;
    Pais pai;
    Mundo aux[cr];
    Mundo auxi;
    while(pai.leerdedisco(pos++))
    {
        aux[pos].setNombrePais(pai.getNombre());
        aux[pos].setCodigoPais(pai.getCodigo());
        aux[pos].grabarendisco();
    }
    while (ciu.leerdedisco(posi++))
    {
        aux[pos].setNombreciudadconmayorPoblacion(vec[posi].getNombre());
        aux[pos].setPoblacionCiudadMayor(vec[posi].getPoblacion());
        aux[pos].grabarendisco();
    }
    int i=0;
    while(auxi.Leerdedisco(i++))
    {
        auxi.Mostrar();
    }
}
#endif // FUNCIONES_H_INCLUDED
