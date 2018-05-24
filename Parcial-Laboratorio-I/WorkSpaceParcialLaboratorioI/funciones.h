#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
char nombre[30];
char apellido[30];
int idPropietario;
char NumeroDeTarjeta[10];
char direccion[50];
int estado;

}ePropietarios;

typedef struct
{
    int idAuto;
    char patente[10];
    int marca;
    int propietario;
    int estado;

}eAutos;


/** \brief inicializa los estados en 0 e ingresa los datos hardcodeados
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return
 */
void inicializar(ePropietarios propietario[],int cant);


/** \brief busca una posicion en el array con estado en 0
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return valor entero que indica si la funcion se termino con exito o no
 *
 */
int buscarLibre(ePropietarios propietario[], int cant);


/** \brief ingresa un nuevo propietario
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return valor entero que indica la posicion del array propietario con estado 0
 *
 */
int altapropietario(ePropietarios propietario[], int cant);


/** \brief vuelve el estado del propietario seleccionado a 0 y egresa los autos a su nombre con sus importes
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \param variable estructura de autos
 * \return valor entero que indica si la funcion se termino con exito o no
 *
 */
int bajaPropietario(ePropietarios propietario[], int cant, eAutos autos[]);


/** \brief indica el id correspondiente al nuevo propietario
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return el id correspondiente al nuevo propietario
 *
 */
int propietarioSiguienteId(ePropietarios propietario[],int cant);


/** \brief modifica el numero de tarjeta seleccionado propietario seleccionado
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return valor entero que indica si la funcion se termino con exito o no
 *
 */
int modificarPropietario(ePropietarios propietario[], int cant);

/** \brief muestra los datos de un propietario
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return
 *
 */
void propietarioMostrarUno(ePropietarios propietario);

/** \brief muestra todos los propietarios con sus respectivos datos
 *
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return
 *
 */
void propietarioMostrarListado(ePropietarios propietario[],int cant);

/** \brief muestra los datos de un propietario seleccionado por su id
 *
 * \param variable estructura de propietario
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \return
 *
 */
void propietarioMostrarPorId(ePropietarios propietario[], eAutos autos[], int cant);

/** \brief muestra los datos de todos los propietarios de un AUDI
 *
 * \param variable estructura de propietario
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \return
 *
 */
void PropietarioMostrarAudi(ePropietarios propietario[], eAutos autos[], int cant);

/** \brief inicializa los estados en 0 e ingresa los datos hardcodeados
 *
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \return
 *
 */
void inicializarAutos(eAutos autos[],int cant);

/** \brief ingresa un nuevo auto
 *
 * \param variable estructura de autos
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return
 *
 */
int altaAuto (eAutos autos[],ePropietarios propietario[], int cant);

/** \brief vuelve el estado del auto seleccionado a 0
 *
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \param variable estructura de propietario
 * \return
 *
 */
int bajaAutos(eAutos autos[], int cant, ePropietarios propietario[]);

/** \brief busca una posicion en el array con estado en 0
 *
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \return
 *
 */
int buscarLibreAutos(eAutos autos[], int cant);

/** \brief indica el id correspondiente al nuevo auto
 *
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \return
 *
 */
int autosSiguienteId(eAutos autos[],int cant);

/** \brief muestra los datos de un auto
 *
 * \param variable estructura de autos
 * \param
 * \return
 *
 */
void autosMostrarUno(eAutos autos);

/** \brief muestra todos los autos con sus respectivos datos
 *
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \return
 *
 */
void autosMostrarListado(eAutos autos[],int cant);

/** \brief muestra todos los autos ordenados segun su patente
 *
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \return
 *
 */
void mostrarautosPorPatente(eAutos autos[], ePropietarios propietario[], int cant);

/** \brief calcula un valor aleatorio entre 1 y 24
 *
 * \param variable estructura de autos
 * \param variable estructura de propietario
 * \param cantidad de espacios libres
 * \return devuelve el valor calculado
 *
 */
int devolverHorasEstadia(void);

/** \brief calcula cuanto se debe pagar por la estadia del auto egresado
 *
 * \param variable estructura de autos
 * \param cantidad de espacios libres
 * \param posicion del auto a egresar
 * \param variable estructura de propietario
 * \return
 *
 */
void tarifaaPagar(eAutos autos[], int cant, int id, ePropietarios propietario[]);

/** \brief muestra  lo recaudado por cada marca
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarRecaudadoMarca();

/** \brief muestra todo lo recaudado
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarTotalRecaudado();

#endif
