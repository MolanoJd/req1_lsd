/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "gestionPdM.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

bool_t *
registrarpdm_1(datos_pdm *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, registrarPdM,
		(xdrproc_t) xdr_datos_pdm, (caddr_t) argp,
		(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

datos_pdm *
consultarpdm_1(int *argp, CLIENT *clnt)
{
	static datos_pdm clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, consultarPdM,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_datos_pdm, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

datos_pdm *
abrirsesion_1(datos_sesion *argp, CLIENT *clnt)
{
	static datos_pdm clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, abrirSesion,
		(xdrproc_t) xdr_datos_sesion, (caddr_t) argp,
		(xdrproc_t) xdr_datos_pdm, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bool_t *
registrardocentepdm_1(matrizDocente_pdm *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, registrarDocentePdM,
		(xdrproc_t) xdr_matrizDocente_pdm, (caddr_t) argp,
		(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bool_t *
registrarcgcpdm_1(matrizCGC_pdm *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, registrarCGCPdM,
		(xdrproc_t) xdr_matrizCGC_pdm, (caddr_t) argp,
		(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}