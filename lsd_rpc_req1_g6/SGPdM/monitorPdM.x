/*Declaración de datos a transferir entre el cliente y el servidor*/
/*Declaración de constantes*/
/*Declaración de la estructura que permite agregar los datos a la matriz PdM Datos por el Docente*/
/*Definicion de las operaciones que se pueden realizar*/
program monitor_pdm{
version monitor_pdm_version{
void enviarNotificacion(int codigo)=1;
bool guardarPdM(matrizDocente_pdm objDOCPdM)=2;
bool guardarPdMS(matrizCGC_pdm objCGCPdM)=3;
}=1;
}=0x30000001;
