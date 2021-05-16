#ifndef CIUDAD_H
#define CIUDAD_H

class Ciudad
{
private:
    int _ID;
    char _nombre[35];
    char _idpais[4];
    int _poblacion;
public:
    void carga();
    int getID();
    char * getIDPais();
    char * getNombre();
    bool leerdedisco(int);
    bool AgregarRegistro(int);
    int getPoblacion();
    void setID(int);
    void setIDPais(const char *);
    void setNombre(const char *);
    void setPoblacion(int);
    void mostrar();
};

#endif // CIUDAD_H
