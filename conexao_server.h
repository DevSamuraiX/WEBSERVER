#ifndef CONEXAO_SERVER_H_INCLUDED
#define CONEXAO_SERVER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/**
*   send        enviar
*   receive     recebe
*   get         pegar
*   post        publicar
*/


/**
*   Socket de conexao do servidor
*/
int conectServerSocket          = 0;

/**
*   Comprimento do acesso remoto
*/
int conectRemoteLength          = 0;

/**
*   Recebe dados da recepção na conexao com o cliente
*/
int getRemoteSocket             = 0;

int enviaMessagem               = 0;

/**
*   Porta de comunicao do servidor
*/
unsigned short serverPort       = 238;

/**
*   Estrutura para definir os parametros de comunicação do Servidor e seu tipos
*/
struct sockaddr_in strDefAddressServer;

/**
*   Estrutura para definir os parametros de comunicação do Servidor e seu tipos
*/
struct sockaddr_in strDefAddressRemote;

/**
*   Strutuda de dados WSADATA da biblioteca winsock.h
*/
WSADATA structDadosWSA;

#define BACKLOG_MAX 90000


#endif // CONEXAO_SERVER_H_INCLUDED









