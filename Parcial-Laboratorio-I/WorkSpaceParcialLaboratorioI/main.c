#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#define TAM 20
#define OCUPADO 1
#define LIBRE 0


int main(){

ePropietarios propietario[TAM];
eAutos autos [TAM];
int flag=0;
int opcion;
int index;
char respuesta[2];
inicializar(propietario,TAM);
inicializarAutos (autos,TAM);

do{
printf("\n 1.  dar de alta un propietario\n 2.  dar de baja un propietario \n 3.  modificar un propietario\n 4.  ingresar automovil\n");
printf(" 5.  egresar Autommovil\n 6.  total recaudado\n 7.  recaudado por marca\n 8.  mostrar lista de autos de propietario\n");
printf(" 9.  mostrar lista de propietarios con Audi\n 10. mostrar listado de autos estacionados segun su patente\n 11. lista de propietarios\n 12. lista de autos\n 13. salir\n");
printf("\n opcion: ");

fflush(stdin);
opcion=validarNumero(opcion);

switch(opcion){

case 1:
    index=altapropietario(propietario,TAM);
    if(index==0){
        printf("propietario Agregado\n");
        propietarioMostrarListado(propietario, TAM);
    }
    else{
        printf("Error\n");
    }
    break;
case 2:
    propietarioMostrarListado(propietario, TAM);
    index=bajaPropietario(propietario,TAM, autos);
    if(index==0){
        printf("\n propietario dado de baja\n");
         propietarioMostrarListado(propietario, TAM);
         autosMostrarListado(autos, TAM);
    }
    else{
        printf("\n ningun propietario  ha sido dado de baja\n");
    }
    break;
case 3:
    propietarioMostrarListado(propietario, TAM);
    index=modificarPropietario(propietario, TAM);
    if(index==0){
        printf("\n propietario modificado\n");
        propietarioMostrarListado(propietario, TAM);
    }
    else{
        printf("\n ningun propietarioha sido modificado\n");
    }
    break;
case 4:
    index=altaAuto(autos,propietario,TAM);
    if(index==0){
        printf("\n auto ingresado\n");
        autosMostrarListado(autos, TAM);
    }
    else{
        printf("\n no se ha ingresado ningun auto\n");
    }
    break;
case 5:
    autosMostrarListado(autos, TAM);
    index=bajaAutos(autos, TAM, propietario);
     if(index==0){
        printf("\n auto egresado\n");
    }
    else{
        printf("\n el auto no ha egresado\n");
    }
    break;
case 6:
    mostrarTotalRecaudado();
    break;
case 7:
    mostrarRecaudadoMarca();
    break;
case 8:
    propietarioMostrarListado(propietario, TAM);
    propietarioMostrarPorId(propietario, autos, TAM);
    break;
case 9:
    autosMostrarListado(autos, TAM);
    PropietarioMostrarAudi(propietario, autos, TAM);
    break;
case 10:
    mostrarautosPorPatente(autos, propietario, TAM);
    break;
case 11:
    propietarioMostrarListado(propietario, TAM);
    break;
case 12:
    autosMostrarListado(autos, TAM);
    break;
case 13:
    printf("\n seguro que quiere salir?(presione 's' para salir): ");
    scanf("%s", respuesta);
    break;
default :
    printf("\n Error: ingrese alguna de las opciones dadas con anterioridad.\n");
    break;
}
if(strcmp(respuesta,"s")==0){
    flag=1;
}
}while(flag==0);

return 0;
}


