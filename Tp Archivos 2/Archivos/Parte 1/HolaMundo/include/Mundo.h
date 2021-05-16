#ifndef MUNDO_H
#define MUNDO_H
#include <cstring>

class Mundo
{
    private:
    char codigoPais[4];
    char nombrePais[45];
    char nombreciudadconmayorPoblacion[50];
    int PoblacionCiudadMayor;

    public:

    Mundo();
    void Mostrar();
    char *getcodigoPais()
    {
        return codigoPais;
    }
    char *getnombrePais()
    {
        return nombrePais;
    }
    char *getnombreciudadconmayorPoblacion()
    {
        return nombreciudadconmayorPoblacion;
    }
    int getPoblacionCiudadMayor()
    {
        return PoblacionCiudadMayor;
    }
    void setCodigoPais(char *cod)
    {
        strcpy(codigoPais,cod);
    }
    void setNombrePais(char *nom)
    {
        strcpy(nombrePais,nom);
    }
    void setNombreciudadconmayorPoblacion(char *nom)
    {
        strcpy(codigoPais,nom);
    }
    void setPoblacionCiudadMayor(int ciu)
    {
        PoblacionCiudadMayor=ciu;
    }
    void grabarendisco();
    bool Leerdedisco(int pos);
};

#endif // MUNDO_H
