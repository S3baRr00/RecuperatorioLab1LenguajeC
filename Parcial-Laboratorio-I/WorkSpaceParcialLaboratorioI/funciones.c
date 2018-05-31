#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
#include "validaciones.h"
#define TAM 20
#define OCUPADO 1
#define LIBRE 0
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

float recaudado1;
float recaudado2;
float recaudado3;
float recaudado4;
float Totalrecaudado;



void inicializar( ePropietarios propietario[],int cant){
int i;

 if(cant > 0 && propietario != NULL){
  for(i=0; i<cant; i++){
   propietario[i].estado= LIBRE;
   propietario[i].idPropietario=0;
  }

int id[4]= {1,2,3,4};
char nombre[4][30]={"Juan","Luis","Maria","Jose"};
char apellido[4][30]={"-----","-----","-----","-----"};
char tarjeta[4][10]={"111-111","222-222","333-333","444-444"};
char direccion[4][50]={"mitre","urquiza","belgrano","alsina"};
int edad[4]={26,60,35,10};

 for(i=0; i<4;i++){
  strcpy(propietario[i].nombre, nombre[i]);
  strcpy(propietario[i].apellido, apellido[i]);
  strcpy(propietario[i].NumeroDeTarjeta,tarjeta[i]);
  propietario[i].idPropietario=id[i];
  strcpy(propietario[i].direccion, direccion[i]);
  propietario[i].edad=edad[i];
  propietario[i].estado=OCUPADO;
  }
 }
}



int buscarLibre(ePropietarios propietario[], int cant){
int indice=-1;
int i;

 for(i=0;i<20;i++){
  if(propietario[i].estado==0){
   indice=i;
   break;
  }
 }
return indice;
}



int altapropietario(ePropietarios propietario[], int cant){
int index=-1;
int indice;
int id;
int i;

indice=buscarLibre(propietario,cant);
 if(indice!=-1){
  if(indice >= 0){
   id = propietarioSiguienteId(propietario,cant);
   propietario[indice].idPropietario=id;
   printf("\n Ingrese nombre:\n ");
   propietario[indice].nombre[30]=validarnombre(propietario[indice].nombre);
   printf("\n Ingrese apellido:\n ");
   propietario[indice].apellido[30]=validarnombre(propietario[indice].apellido);
   printf(" ingrese edad:\n ");
   propietario[indice].edad=validarNumero(propietario[indice].edad);

   printf(" Ingrese numero de tarjeta:\n ");
   do{
   fflush(stdin);
   propietario[indice].NumeroDeTarjeta[10]=validarNumerochar(propietario[indice].NumeroDeTarjeta);
    for(i=0;i<cant;i++){
     if(strcmp(propietario[indice].NumeroDeTarjeta, propietario[i].NumeroDeTarjeta)==0 && propietario[i].estado==OCUPADO){
      printf("\n NOMBRE:\t\t              APELLIDO:\t          EDAD:\t          NUMERO DE ID\t          NUMERO DE TARJETA:\t     DIRECCION: \n");
      printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
      propietarioMostrarUno(propietario[i]);
      printf("\n no puede haber 2 numeros de tarjetas iguales.\n vuelva a escribir\n ");
     }
    }
   }while(strcmp(propietario[indice].NumeroDeTarjeta,propietario[i].NumeroDeTarjeta)==0);
   printf(" Ingrese una Direccion:\n ");
   propietario[indice].direccion[50]=validarnombre(propietario[indice].direccion);
   printf(" id del propietario: %d\n ", propietario[indice].idPropietario);
   propietario[indice].estado= OCUPADO;
   index=0;
  }
 }
return index;
}



int propietarioSiguienteId(ePropietarios propietario[],int cant){
int retorno = 0;
int i;
if(cant > 0 && propietario != NULL){
 for(i=0; i<cant; i++){
  if(propietario[i].estado == OCUPADO){
   if(propietario[i].idPropietario>retorno){
    retorno=propietario[i].idPropietario;
   }
  }
 }
}
retorno++;
return retorno;
}



int bajaPropietario(ePropietarios propietario[], int cant, eAutos autos[]){
int horas;
float aPagar=0;
float aux=0;
int index=-1;
int auxId=0;
int i;
int j;

printf(" Ingrese ID del propietario que desea dar de baja:\n ");
auxId=validarNumero(auxId);

for(j=0;j<cant;j++){
 if(autos[j].propietario==auxId){
  Totalrecaudado=aux;
  horas=devolverHorasEstadia();

  if(cant > 0 && autos != NULL){
   if( autos[j].marca== ALPHA_ROMEO){
    aPagar=150*horas;
    recaudado1=recaudado1+aPagar;
   }
   else if( autos[j].marca== FERRARI){
    aPagar=175*horas;
    recaudado2=recaudado2+aPagar;
   }
   else if( autos[j].marca== AUDI){
    aPagar=200*horas;
    recaudado3=recaudado3+aPagar;
   }
   else{
    aPagar=250*horas;
    recaudado4=recaudado4+aPagar;
   }
   Totalrecaudado=recaudado1+recaudado2+recaudado3+recaudado4;

   aPagar=Totalrecaudado-aux;
   autos[j].estado=LIBRE;
  }
 }
 for(i=0;i<cant;i++){
  if(propietario[i].idPropietario==auxId){
   propietario[i].estado=LIBRE;
   index=0;
   break;
   }
  }
 }
printf("\n total a pagar: $%.2f\n", aPagar);
return index;
}



int modificarPropietario(ePropietarios propietario[], int cant){
int index=-1;
int aux=0;
int i;
int j;

printf(" ingrese id de propietario\n ");
aux=validarNumero(aux);
 if(cant > 0 && propietario != NULL){
  for(i=0;i<cant; i++){
    if(propietario[i].estado == OCUPADO &&aux==propietario[i].idPropietario){
     printf(" Ingrese numero de tarjeta:\n ");
   do{
   fflush(stdin);
   propietario[i].NumeroDeTarjeta[10]=validarNumerochar(propietario[i].NumeroDeTarjeta);
    for(j=0;j<cant;j++){
     if(strcmp(propietario[i].NumeroDeTarjeta, propietario[j].NumeroDeTarjeta)==0 && propietario[j].estado==OCUPADO){
       printf("\n NOMBRE:\t\t              APELLIDO:\t          EDAD:\t          NUMERO DE ID\t          NUMERO DE TARJETA:\t     DIRECCION: \n");
       printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
       propietarioMostrarUno(propietario[j]);
       printf("\n no puede haber 2 numeros de tarjetas iguales.\n vuelva a escribir");
      }
     }
    }while(!strcmp(propietario[i].NumeroDeTarjeta, propietario[j].NumeroDeTarjeta)==0);
     index=0;
    }
   }
  }
 return index;
}



void propietarioMostrarUno(ePropietarios propietario){

    printf(" %s\t\t\t               %s\t\t     %d\t\t        %d\t\t      %s\t\t      %s\n",propietario.nombre ,propietario.apellido,propietario.edad,propietario.idPropietario ,propietario.NumeroDeTarjeta, propietario.direccion);
}



void propietarioMostrarListado(ePropietarios propietario[],int cant){
    int i;
    if(cant > 0 && propietario != NULL){
     printf("\n NOMBRE:\t\t              APELLIDO:\t          EDAD:\t          NUMERO DE ID\t          NUMERO DE TARJETA:\t     DIRECCION: \n");
     printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        for(i=0; i<cant; i++){
            if(propietario[i].estado==OCUPADO){
             fflush(stdin);
             propietarioMostrarUno(propietario[i]);
   }
  }
 }
}



void inicializarAutos( eAutos autos[],int cant){
int i;
int j;

   if(cant > 0 && autos != NULL){
    for(i=0; i<cant; i++){
     autos[i].estado= LIBRE;
     autos[i].idAuto=0;
    }

    recaudado1=0;
    recaudado2=0;
    recaudado3=0;
    recaudado4=0;
    Totalrecaudado=0;

    int idauto[10]= {1,2,3,4,5,6,7,8,9,10};
    char patente[10][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[10]= {ALPHA_ROMEO,AUDI,AUDI,FERRARI,FERRARI,AUDI,AUDI,OTRO,AUDI,ALPHA_ROMEO};
    int propietarioid[10]= {2,1,2,1,3,3,4,1,4,3};

        for(i=0; i<10;i++){
        autos[i].idAuto=idauto[i];
        strcpy(autos[i].patente,patente[i]);
        autos[i].propietario =propietarioid[i];
        autos[i].marca= marca[i];
        autos[i].estado=OCUPADO;
    }

    int marca1[10]= {1,1,2,3,2,2,3,4,1,1};
    float importe[10]= {100,200,100,300,100,100,200,200,100,100};

    for(j=0; j<10;j++){
      if( marca1[j] == ALPHA_ROMEO){
       recaudado1=recaudado1+importe[j];
      }
      else if( marca1[j] == FERRARI){
       recaudado2=recaudado2+importe[j];
      }
      else if( marca1[j] == AUDI){
       recaudado3=recaudado3+importe[j];
      }
      else{
       recaudado4=recaudado4+importe[j];
      }
      Totalrecaudado=recaudado1+recaudado2+recaudado3+recaudado4;
     }

 }
}



int altaAuto (eAutos autos[],ePropietarios propietario[], int cant){
int index=-1;
int indice;
int id;
int i;

indice=buscarLibreAutos(autos,cant);

  if(indice!=-1){
   if(indice >= 0){
    index=-3;
    id = autosSiguienteId(autos,cant);
    autos[indice].idAuto=id;
    printf("\n Ingrese patente:\n ");
    autos[indice].patente[10]=validarnombre(autos[indice].patente);
    printf(" Ingrese id del propietario:\n ");

    do{
    fflush(stdin);
    autos[indice].propietario=validarNumero(autos[indice].propietario);

    for(i=0;i<cant;i++){
        if(propietario[i].estado==OCUPADO){
        if(autos[indice].propietario==propietario[i].idPropietario){
         index=2;
        }
        else{
         index=-4;
        }
     }
    }
    if(index==-4){
        printf("solo puede usarse el id de un propietario ingresado con anterioridad\n ");
    }
    }while(index==-4);

    printf(" ingrese la marca del auto\n ");
    printf(" 1=ALPHA ROMEO  2=FERRARI  3=AUDI  4=OTRO\n\n");
    autos[indice].marca=validarNumero(autos[indice].marca);
    printf(" id del auto: %d\n", autos[indice].idAuto);
    autos[indice].estado= OCUPADO;
    index=0;
  }
 }
return index;
}



int buscarLibreAutos(eAutos autos[], int cant){
int indice=-1;
int i;

for(i=0;i<20;i++){
    if(autos[i].estado==0){
     indice=i;
     break;
    }
}
return indice;
}



int autosSiguienteId(eAutos autos[],int cant){
int retorno = 0;
int i;

    if(cant > 0 && autos != NULL){
     for(i=0; i<cant; i++){
      if(autos[i].estado == OCUPADO){
       if(autos[i].idAuto>retorno){
        retorno=autos[i].idAuto;
       }
      }
     }
    }
retorno++;
return retorno;
}



int bajaAutos(eAutos autos[], int cant, ePropietarios propietario[]){
int index=-1;
int auxId=0;
int i;

printf(" Ingrese ID del auto que desea dar de baja:\n ");
auxId=validarNumero(auxId);

    for(i=0;i<cant;i++){
     if(autos[i].idAuto==auxId){
      autos[i].estado=LIBRE;
      tarifaaPagar(autos, TAM, auxId-1 ,propietario);
      index=0;
      break;
     }
    }

return index;
}



void autosMostrarUno(eAutos autos){
printf(" %d\t           %s\t\t\t     %d\t\t      %d\n",autos.idAuto ,autos.patente ,autos.marca, autos.propietario);
}



void autosMostrarListado(eAutos autos[],int cant){
int i;

    if(cant > 0 && autos != NULL){
     printf("\n ID AUTO\t  PATENTE\t          MARCA\t          ID DEL PROPIETARIO \n");
     printf("-----------------------------------------------------------------------------\n");
      for(i=0; i<cant; i++){
       if(autos[i].estado==OCUPADO){
        fflush(stdin);
        autosMostrarUno(autos[i]);
       }
      }
    }
}



int devolverHorasEstadia(){

int horas;

srand(time(NULL));
horas = (rand()%24)+1;

return horas ;
}



void tarifaaPagar(eAutos autos[], int cant, int id, ePropietarios propietario[]){
int horas;
float aPagar;
int i;
char nombre[30];
char apellido[30];

horas=devolverHorasEstadia();

 if(cant > 0 && autos != NULL){
   if( autos[id].marca == ALPHA_ROMEO){
    aPagar=150*horas;
    recaudado1=recaudado1+aPagar;
   }
   else if( autos[id].marca == FERRARI){
    aPagar=175*horas;
    recaudado2=recaudado2+aPagar;
   }
   else if( autos[id].marca == AUDI){
    aPagar=200*horas;
    recaudado3=recaudado3+aPagar;
   }
   else{
    aPagar=250*horas;
    recaudado4=recaudado4+aPagar;
   }
   Totalrecaudado=recaudado1+recaudado2+recaudado3+recaudado4;

   for(i=0;i<20;i++){
    if(propietario[i].idPropietario==autos[id].propietario){
     strcpy(nombre, propietario[i].nombre);
     strcpy(apellido, propietario[i].apellido);
    }
   }
  }

printf("\n NOMBRE DE PROPIETARIO:\t APELLIDO DE PROPIETARIO:\t PATENTE DE AUTO:\t      MARCA:\t\t VALOR DE ESTADIA:\n");
printf("---------------------------------------------------------------------------------------------------------------\n");
printf("\t%s\t\t\t %s\t\t\t %s\t\t\t\t %d\t\t %.2f\t\n\n", nombre ,apellido, autos[id].patente, autos[id].marca, aPagar);
}



void mostrarTotalRecaudado(){
    printf("\n TOTAL RECAUDADO: $%.2f\n", Totalrecaudado);
}



void mostrarRecaudadoMarca(){
     printf("\n RECAUDADO EN ALPHA ROMEO: $%.2f\n", recaudado1);
      printf(" RECAUDADO EN FERRARI: $%.2f\n", recaudado2);
       printf(" RECAUDADO EN AUDI: $%.2f\n", recaudado3);
        printf(" RECAUDADO EN OTRO: $%.2f\n", recaudado4);
}



void propietarioMostrarPorId(ePropietarios propietario[], eAutos autos[], int cant){
int auxId=0;
int i;
int j;

printf(" Ingrese ID del propietario:\n");
auxId=validarNumero(auxId);

for(i=0;i<cant;i++){
 if(propietario[i].idPropietario==auxId && propietario[i].estado==OCUPADO){
  printf(" %s \n", propietario[i].nombre);
   for(j=0;j<cant;j++){
    if(autos[j].propietario==propietario[i].idPropietario && autos[j].estado==OCUPADO){
     printf(" PATENTE: %s -- MARCA: %d  \n",autos[j].patente, autos[j].marca);
    }
   }
  }
 }
}



void PropietarioMostrarAudi(ePropietarios propietario[], eAutos autos[], int cant){
int i;
int j;
for(j=0;j<cant;j++){
 if(propietario[j].estado==OCUPADO){
  for(i=0;i<cant;i++){
   if(autos[i].propietario==propietario[j].idPropietario && autos[i].marca==AUDI){
    printf("\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n TARJETA: %s\n DIRECCION: %s\n", propietario[j].idPropietario, propietario[j].nombre,propietario[j].apellido, propietario[j].NumeroDeTarjeta, propietario[j].direccion);
    break;
    }
   }
  }
 }

}



void mostrarautosPorPatente(eAutos autos[], ePropietarios propietario[], int cant){
int i;
int j;
int k;
int l;
char auxNombre[10];
int auxMarca;
int auxPropietario;
int auxId;

for(i=0;i<cant-1;i++){
 if(cant > 0 && autos != NULL && autos[i].estado == OCUPADO){
  for(j=i+1;j<cant;j++){
   if(strcmp(autos[j].patente,autos[i].patente)<0 && autos[j].estado==OCUPADO){
    strcpy(auxNombre, autos[j].patente);
    strcpy(autos[j].patente, autos[i].patente);
    strcpy(autos[i].patente, auxNombre);

    auxMarca = autos[j].marca;
    autos[j].marca= autos[i].marca;
    autos[i].marca= auxMarca;

    auxId=autos[j].idAuto;
    autos[j].idAuto=autos[i].idAuto;
    autos[i].idAuto=auxId;

    auxPropietario=autos[j].propietario;
    autos[j].propietario=autos[i].propietario;
    autos[i].propietario=auxPropietario;
   }
  }
 }
}

for(k=0;k<20;k++){
    if(autos[k].estado==OCUPADO){
     for(l=0;l<cant;l++){
      if(autos[k].propietario == propietario[l].idPropietario && propietario[l].estado==OCUPADO){
       printf("\n  ID DE AUTO: %d\n PATENTE: %s\n MARCA: %d\n PROPIETARIO: %s \n \n ", autos[k].idAuto, autos[k].patente, autos[k].marca, propietario[l].nombre);
       break;
      }
     }
    }
   }
}

void ordenarPropietariosPorNombre(ePropietarios propietario[], int cant){
int i;
int j;
int opcion=0;
ePropietarios propietario2[TAM];
ePropietarios propietarioAux;
for(i=0;i<cant;i++){
    strcpy(propietario2[i].apellido,propietario[i].apellido);
    strcpy(propietario2[i].direccion,propietario[i].direccion);
    strcpy(propietario2[i].nombre,propietario[i].nombre);
    strcpy(propietario2[i].NumeroDeTarjeta,propietario[i].NumeroDeTarjeta);
    propietario2[i].edad=propietario[i].edad;
    propietario2[i].estado=propietario[i].estado;
    propietario2[i].idPropietario=propietario[i].idPropietario;

}
printf("\n como desea que se muestre el listado?\n");
printf(" ingrese 1 para orden ascendente\n Ingrese 2 para orden descendente\n ");
do{
fflush(stdin);
opcion=validarNumero(opcion);
if(opcion==1){
for(i=0;i<cant-1;i++){
 if(cant > 0 && propietario2 != NULL && propietario2[i].estado == OCUPADO){
  for(j=i+1;j<cant;j++){
   if(strcmp(propietario2[j].nombre,propietario2[i].nombre)<0 && propietario2[j].estado==OCUPADO){
    propietarioAux=propietario2[i];
    propietario2[i]=propietario2[j];
    propietario2[j]=propietarioAux;
   }
  }
 }
}
}
else if(opcion==2){
    for(i=0;i<cant-1;i++){
  if(cant > 0 && propietario2 != NULL && propietario2[i].estado == OCUPADO){
  for(j=i+1;j<cant;j++){
   if(strcmp(propietario2[j].nombre,propietario2[i].nombre)>0 && propietario2[j].estado==OCUPADO){
    propietarioAux=propietario2[i];
    propietario2[i]=propietario2[j];
    propietario2[j]=propietarioAux;
    }
   }
  }
 }
}
else{
    printf("seleccione unicamente 1 o 2\n ");
}
}while(opcion<1 || opcion>2);
propietarioMostrarListado(propietario2, cant);
}

void listarPorEdad(ePropietarios propietario[], int cant){
int auxedad=0;
int i;
int j;

printf(" Ingrese a partir de que edad se debe mostrar los propietarios:\n ");
auxedad=validarNumero(auxedad);


for(i=0;i<cant;i++){
 if(propietario[i].edad>=auxedad && propietario[i].estado==OCUPADO){
    printf("\n NOMBRE:\t                      APELLIDO:\t          EDAD:\t          NUMERO DE ID\t          NUMERO DE TARJETA:\t     DIRECCION: \n");
     printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    propietarioMostrarUno(propietario[i]);

  }
 }
}

