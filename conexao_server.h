#ifndef CONEXAO_SERVER_H_INCLUDED
#define CONEXAO_SERVER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*
send    enviar
receive    recebe
get     pegar
post    publicar
*/


/** Socket de conexao do servidor */
int conectServerSocket  = 0;
/** Comprimento do acesso remoto */
int conectRemoteLength  = 0;
/** Recebe dados da recepção na conexao com o cliente*/
int getRemoteSocket       = 0;
int enviaMessagem       = 0;
/** Porta de comunicao do servidor */
unsigned short serverPort   = 238;
/** Estrutura para definir os parametros de comunicação do Servidor e seu tipos */
struct sockaddr_in strDefAddressServer;
/** Estrutura para definir os parametros de comunicação do Servidor e seu tipos */
struct sockaddr_in strDefAddressRemote;
/** Strutuda de dados WSADATA da biblioteca winsock.h */
WSADATA structDadosWSA;

#define BACKLOG_MAX 90000


#endif // CONEXAO_SERVER_H_INCLUDED

/**

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock.h>
#include "configuracao.cpp"
#include "conexao_server.cpp"
//#include "conexao_server.h"

using namespace std;

class quebra{
public:
     void d(){
        printf("\n");
    }
};

int  *teste::ret(){
    printf("\n teste ok \n");
}

int *conexaoServer::conexao(){
    printf("Conectado com sucesso");
}

int main()
{
    quebra p;
    configConexao config;
    cout << config.returnIPServer();
    p.d();
    config.configIPServer("192.168.0.120");
    p.d();
    cout << config.returnIPServer();


    //teste *tt = new teste;
    / *teste tt;

    tt.ret();* /

    //tt->ret();

    conectaClient conec;
    //int ff = con.defineIPCliente(10);

    p.d();
    conexaoServer conecServ;
    char *dados = conecServ.a_rquivo("T:\arquivo");
    cout << dados;
    p.d();

    arquivo arq;
    char *testeUrl = arq.lerUrl();
    cout << testeUrl;
    p.d();
    cout << arq.caminhoArquivo("E:\\CONEXAO_C++\\arquivo_dados.txt");
    p.d();
    if(arq.validaArquivo() == true){
        p.d();
        cout << "vai criar um arquivo novo!";
        arq.novoArquivo();
        if(arq.validaArquivo() == true){
            p.d();
        }
    }
    p.d();




    //conexaoServer conect;
    ///conexaoServer *conectServer = new conexaoServer;
    ///conectServer->conexao();
    p.d();
    char *testeDadosArq = arq.lerDadosArquivo();
    printf("%s", testeDadosArq);
    p.d();

    / **conexaoServerWew server;
    server.serverWeb();* /
    conexaoServerWew *server = new conexaoServerWew;
    server->serverWeb();* /
    p.d();

    while(1){

        int TamArq = 500;
        int tamCab = 480;
        char corpoCabecalho[480] = {
            "\r\n"
            "HTTP/1.1 200 OK\r\n"
            "Connection: close\r\n"
            "Date: Mon, 30 May 2022 01:45:41 GMT\r\n"
            "Server: AS(2008-2011)\r\n"
            "Content-Length: 2302\r\n"
            "Last-Modified: 30/05/2022\r\n"
            "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,* / *;q=0.8\r\n"
            "Accept-Encoding: gzip, deflate\r\n"
            "Referer: http://127.0.0.1:238\r\n"
            "Accept: * /*\r\n"
            "Connection: keep-alive\r\n"
            "Content-Type: text/html\r\n\r\n"
        };

        int tam_ = 349;
        char css_[350] = {
        "GET / HTTP/0.9\r\n"
        "Host: 127.0.0.1:238\r\n"
        "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:109.0) Gecko/20100101 Firefox/116.0\r\n"
        "Accept: text/css,* /*;q=0.1\r\n"
        "Accept-Language: pt-BR,pt;q=0.8,en-US;q=0.5,en;q=0.3\r\n"
        "Accept-Encoding: gzip, deflate, br\r\n"
        "Connection: keep-alive\r\n"
        "Sec-Fetch-Dest: style\r\n"
        "Sec-Fetch-Mode: no-cors\r\n"
        "Sec-Fetch-Site: cross-site\r\n"
        };

        / **int tamHtm = 280;
        char corpoHtml[280] = {
            "<!DOCTYPE html>"
            "<html lang=" "en" ">"
            "<head>"
                "<meta charset=" "UTF-8" ">"
                "<meta name=" "viewport" "content=" "width=device-width, initial-scale=1.0" ">"
                "<title>Document</title>"
                "<link rel=" "stylesheet" "href=" "http://127.0.0.1:238" ">"
            "</head>"
            "<body>"
                "<h1>TESTE DE CODIGO OK</h1>"
            "</body>"
            "</html>"
        };* /


        int tamHtm = 37;
        char corpoHtml[38] = {
            "h1{color: brown;}"
            "<style></style> \r\n"
        };

        int tamjs = 264;
        char jscode[27] = {
            //"document.getElementById(\"demo\").innerHTML = \"Hello JavaScript!\";\r\n"
            "alert(\"Eu sou um ;"
        };



        / **
        "cross-origin-opener-policy: same-origin; report-to=\"one-google-eng\" \r\n"
        "report-to: {\"group\":\"one-google-eng\",\"max_age\":2592000,\"endpoints\":[{\"url\":\"ttp://127.0.0.1:238\"}]}\r\n"
        "content-length: 637\r\n"
        * /

        conexaoServerWew *server = new conexaoServerWew;
        server->serverWeb();

        /// RECEBE OS DADOS DOS CLIENTES
        char recebe_cabecalho_cliente[2];
        if((server->conectRemoteLength = recv(server->getRemoteSocket, recebe_cabecalho_cliente, 900, 0)) == SOCKET_ERROR);
        printf("Dados Recebidos Tentativa 1: %s\n\n", recebe_cabecalho_cliente);

        / *if(recebe_cabecalho_cliente[0] == 'G'){
            printf("Dados recebido com sucesso! \n");
        }* /



        /// ENVIA OS DADOS DA IMAGEM
        //int cabecalho  = send(server->getRemoteSocket, corpoCabecalho, tamCab, 0);
        /// css
        //int codigoHtml_ = send(server->getRemoteSocket, css, tam, 0);
        /// js
        int codigoHtml_ = send(server->getRemoteSocket, jscode, tamjs, 0);

        //int codigoHtml = send(server->getRemoteSocket, corpoHtml, tamHtm, 0);
        closesocket(server->getRemoteSocket);
        //Sleep(1900);

        / *char limpa[9999] = {""};
        strcpy(corpoCabecalho, limpa);
        strcat(corpoCabecalho-1, limpa);
        free(corpoCabecalho);

        strcpy(corpoHtml, limpa);
        strcat(corpoHtml-1, limpa);
        free(corpoHtml);* /

        /// RECEBE NOVO DADOS DO CLIENTE
        //if (bind(server->conectServerSocket, (struct sockaddr *) &server->strDefAddressServer, sizeof(server->strDefAddressServer)) == SOCKET_ERROR){}
        //server->getRemoteSocket = accept(server->conectServerSocket, (struct sockaddr *) &server->strDefAddressRemote, &server->conectRemoteLength);
        //printf("\n1 conexao estabelecida com sucesso %s\n\n", inet_ntoa(server->strDefAddressRemote.sin_addr));

    }

}



/ **

int tamHtm = 32;
        char corpoHtml[33] = {

            "/ * fallback * /"
            "@font-face {
              "font-family: 'Material Icons';
              "font-style: normal;
              "font-weight: 400;
              "src: url(https://fonts.gstatic.com/s/materialicons/v140/flUhRq6tzZclQEJ-Vdg-IuiaDsNc.woff2) format('woff2');
            "}

            ".material-icons {
              "font-family: 'Material Icons';
              font-weight: normal;
              font-style: normal;
              font-size: 24px;
              line-height: 1;
              letter-spacing: normal;
              text-transform: none;
              display: inline-block;
              white-space: nowrap;
              word-wrap: normal;
              direction: ltr;
              "-moz-font-feature-settings: 'liga';
              "-moz-osx-font-smoothing: grayscale;
            "}


        };
* /




*/









