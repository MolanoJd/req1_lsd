/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "gestionPdM.h"
#include "gestionPdM2.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
gestion_pdm_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		datos_pdm registrarpdm_1_arg;
		int consultarpdm_1_arg;
		datos_sesion abrirsesion_1_arg;
		matrizDocente_pdm registrardocentepdm_1_arg;
		matrizCGC_pdm registrarcgcpdm_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case registrarPdM:
		_xdr_argument = (xdrproc_t) xdr_datos_pdm;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) registrarpdm_1_svc;
		break;

	case consultarPdM:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_datos_pdm;
		local = (char *(*)(char *, struct svc_req *)) consultarpdm_1_svc;
		break;

	case abrirSesion:
		_xdr_argument = (xdrproc_t) xdr_datos_sesion;
		_xdr_result = (xdrproc_t) xdr_datos_pdm;
		local = (char *(*)(char *, struct svc_req *)) abrirsesion_1_svc;
		break;

	case registrarDocentePdM:
		_xdr_argument = (xdrproc_t) xdr_matrizDocente_pdm;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) registrardocentepdm_1_svc;
		break;

	case registrarCGCPdM:
		_xdr_argument = (xdrproc_t) xdr_matrizCGC_pdm;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) registrarcgcpdm_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (gestion_pdm, gestion_pdm_version);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, gestion_pdm, gestion_pdm_version, gestion_pdm_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (gestion_pdm, gestion_pdm_version, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, gestion_pdm, gestion_pdm_version, gestion_pdm_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (gestion_pdm, gestion_pdm_version, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}