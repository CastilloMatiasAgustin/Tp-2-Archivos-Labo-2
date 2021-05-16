#include <iostream>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include "Funciones.h"
int main()
{
    bool salida=false;
    int op;
    while (salida!=true)
    {
        system("cls");
        cout<<"----------------------------------------------------"<<endl;
        cout<<"-----------------------MENU-------------------------"<<endl;
        cout<<"---------1)Listado de paises por poblacion----------"<<endl;
        cout<<"-----------------2)Agregar Ciudad-------------------"<<endl;
        cout<<"-----------3)Ranking de ciudad ingresada------------"<<endl;
        cout<<"-----4)Modificacion de poblacion Mediante Codigo----"<<endl;
        cout<<"-------------------5)Mundo.dat----------------------"<<endl;
        cout<<"---------------------0)Salir------------------------"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<< "Ingrese una opcion: "<<endl;
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            PuntoA();
            break;
        case 2:
            system("cls");
            PuntoB();
                break;
        case 3:
            system("cls");
            PuntoC();
            break;
        case 4:
            system("cls");
            PuntoD();
            break;
        case 5:
            system("cls");
            PuntoE();
            break;
        case 0:
            system("cls");
            salida=true;
            break;
        }
        system ("pause");
    }


    return 0;
}
