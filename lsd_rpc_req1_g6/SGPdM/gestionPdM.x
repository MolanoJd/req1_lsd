/*Declaración de datos a transferir entre el cliente y el servidor*/
/*Declaración de constantes*/
const MAXNOM = 30;
const MAXDAT = 12;
/*Declaración de la estructura que permite almacenar los datos de un PdM*/
struct datos_pdm{
int codigo;
char nombrePrograma[MAXNOM];
char nombreCoordinador[MAXNOM];
char usuario[MAXDAT];
char clave[MAXDAT];
};
struct datos_sesion{
int codigo;
char usuario[MAXDAT];
char clave[MAXDAT];
};
/*Declaración de la estructura que permite agregar los datos a la matriz PdM Datos por el Docente*/
struct matrizDocente_pdm{
int codigo;
char fuente[MAXNOM];
char tipoHallazgo[MAXNOM];
char factor[MAXNOM];
char descripcion[MAXNOM];
char proyecto[MAXNOM];
char responsable[MAXNOM];
};
/*Declaración de la estructura que permite agregar los datos a la matriz PdM Datos por el CGC*/
struct matrizCGC_pdm{
int codigo;
int porcentaje;
char evidencia[MAXNOM];
char fechaInicio[MAXNOM];
char fechaFinal[MAXNOM];
};
/*Definición de las operaciones que se pueden realizar*/
program gestion_pdm{
version gestion_pdm_version{
bool registrarPdM(datos_pdm objPdM)=1;
datos_pdm consultarPdM(int id)=2;
datos_pdm abrirSesion(datos_sesion objSesion)=3;
bool registrarDocentePdM(matrizDocente_pdm objDOCPdM)=4;
bool registrarCGCPdM(matrizCGC_pdm objCGCPdM)=5;
}=1;
}=0x20000001;
