#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <winsock.h>
#include <time.h>
#include <wchar.h>
#include <inttypes.h>

using namespace std;

/// METODO QUE GERA UMA CONEXÃO PARA ENTRADA E SAIDA DE DADOS COM O SOLICITANTE
class conexaoServerWew{
public:

    #include "conexao_server.h"

    int *serverWeb(){

        if (WSAStartup(MAKEWORD(2, 0), &structDadosWSA) != 0);

        conectServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (conectServerSocket == INVALID_SOCKET)
        {
           WSACleanup();
        }

        fflush(stdin);

        strDefAddressServer.sin_family = AF_INET;
        strDefAddressServer.sin_addr.s_addr = htonl(INADDR_ANY);
        strDefAddressServer.sin_port = htons(serverPort);

        /// interligando o socket com o endereço (local)
        if (bind(conectServerSocket, (struct sockaddr *) &strDefAddressServer, sizeof(strDefAddressServer)) == SOCKET_ERROR)
        {
           WSACleanup();
           closesocket(conectServerSocket);
        }

        /// coloca o socket para escutar as conexoes
        if (listen(conectServerSocket, BACKLOG_MAX) == SOCKET_ERROR)
        {
           WSACleanup();
           closesocket(conectServerSocket);
        }

        conectRemoteLength = sizeof(strDefAddressRemote);
        printf("CONEXAO EM ESCUTA PARA REQUISICAO PRIMARIA...\n");
        getRemoteSocket = accept(conectServerSocket, (struct sockaddr *) &strDefAddressRemote, &conectRemoteLength);

        if(getRemoteSocket == INVALID_SOCKET)
        {
           WSACleanup();
           closesocket(conectServerSocket);
        }

    }
};







// TESTE
class conexaoServer{
private:

public:
    int *conexao();
    char *a_rquivo(char *arq){
        printf("Teste de arquivo!");
        arq = arq = "Teste de arq ok";
        return arq;
    }
};
// TESTE
class conectaClient{
public:
    int ipCliente;
    int *defineIPCliente(int ip);
};
// TESTE
class arquivo{
private:
    /**
    * Variavel para definicao do caminho do arquivo
    * Caminho defull para criação do arquivo
    * @Metodo private
    * @Variavel url         @Tipo Char*
    * @Variavel dados       @Tipo Char[999999]
    * @Variavel criaArquivo @Tipo Bool
    *
    */
    char *url = "C:\\Users\\Tiago\\Documents\\CONEXAO_C++\\arquivo_dados.txt";
    char dados[999999];
    bool criaArquivo = false;
public:
    /**
    * Metodo publico para retornar o caminho atual do arquivo
    * @Variavel lerUrl          @Tipo Char*
    * @Retorno url
    */
    char *lerUrl(){
        return url;
    }

    /**
    * Metodo publico para definir um novo caminho
    * @Variavel caminhoArquivo  @Tipo Char*
    * @Variavel defineUrl       @Tipo Char*
    * @Retorno url
    */
    char *caminhoArquivo(char *defineUrl){
        url = defineUrl;
        return url;
    }

    /**
    * Metodo que verifica se o arquivo existe no caminho definido
    * @Variavel arq             @Tipo FILE*
    * @Variavel url             @Tipo Char*
    * @Variavel criaArquivo     @Tipo Bool
    * @Retorno  criaArquivo
    */
    bool validaArquivo(){
        FILE *arq;
        arq = fopen(url, "r");
        if(arq == NULL){
            fclose(arq);
            criaArquivo = true;
            cout << "Arquivo nao existe!";
            return criaArquivo;
        }else
        cout << "Arquivo exstente";
        fclose(arq);
        return criaArquivo;
    }

    /**
    * Metodo que verifica se o arquivo existe no caminho definido
    * @Variavel arq             @Tipo FILE*
    * @Variavel url             @Tipo Char*
    * @Variavel criaArquivo     @Tipo Bool
    * @Retorno  criaArquivo
    */
    void novoArquivo(){
        FILE *arq;
        arq = fopen(url, "w");
        fclose(arq);
        criaArquivo = false;
        cout << "Arquivo criado com sucesso!";
    }
    /**
    * Metodo de leitura para retorno dos dados do arquivo
    * @Variavel arq             @Tipo FILE*
    * @Variavel url             @Tipo Char*
    * @Variavel c               @Tipo Char
    * @Variavel dados           @Tipo Char[999999]
    * @Retorno  dados
    */
    char *lerDadosArquivo(){
        FILE *arq;
        arq = fopen(url, "r");

        char c;
        int cont = 0;
        do{
          c = fgetc(arq);
          dados[cont] = c;
          cont++;
        }while (c != EOF);

        fclose(arq);
        return dados;
    }

};

