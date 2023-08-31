#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock.h>
#include <mysql.h>
#include <wchar.h>
#include "configuracao.cpp"
#include "conexao_server.cpp"
#include "send_requisicoes.cpp"
//#include "conexao_server.h"


// HABILITA O TERMINAL CONSOLE EM CORES
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

// THREADS QUANTIDADE DE PROCESSO LIBERADO POR PROCESSADOR
#define NUM_THREADS 4
// THREADS

// HABILITA O TERMINAL CONSOLE EM CORES
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwMode = 0;

using namespace std;

int quantDiv=0;

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

#define IP_MYSQL "127.0.0.1"
#define USER_MYSQL "root"
#define PASS_MYSQL ""
#define DB_MYSQL "banco"

MYSQL conexao;

int conecta_ao_db() { // retorna 1 se conectou com sucesso
                      // retorna 0 caso tenha dado falha na conexão

  // Aqui tenho um servidor mysql rodando no IP: 127.0.0.1 com usuário "dev" sem senha "". ele conecta ao database "test"
  if ( mysql_real_connect(&conexao, IP_MYSQL, USER_MYSQL, PASS_MYSQL, DB_MYSQL, 0, NULL, 0) ) {
    return 1;
  } else {
    printf("\nFalha de conexao");
    printf("\nErro %d : %s", mysql_errno(&conexao), mysql_error(&conexao));
    return 0;
  }

}

char *lista_funcionario(char *query) {
  MYSQL_RES *result;
  MYSQL_ROW row;
  char *resutado;
  int i, num_fields;

  mysql_init(&conexao);

  if(conecta_ao_db() == 1) {


    printf("\n\n||||----%s||||\n\n", query);

    /// CONDICAO QUE EXECUTA O COMANDO DA QUERY
    //SELECT * FROM `nomes` WHERE `nome` LIKE '%001%';
    if(mysql_query(&conexao, query) != 0){
        printf("Erro na execuxao!\n");
    }


    result = mysql_store_result(&conexao);
    if (result == NULL) {
      printf("\nFalha no result");
    }

    num_fields = mysql_num_fields(result);

    row = mysql_fetch_row(result);
    //printf("%s \n", row[0] ? row[0] : "NULL");
    printf("%s \n", row[1] ? row[1] : "NULL");
    //printf("%s \n", row[2] ? row[2] : "NULL");
    //printf("%s \n", row[3] ? row[3] : "NULL");
    //printf("%s \n", row[4] ? row[4] : "NULL");

    //row = mysql_fetch_row(result);
    //printf("%s \n", row[0] ? row[0] : "NULL");
    //printf("%s \n", row[1] ? row[1] : "NULL");
    //printf("%s \n", row[2] ? row[2] : "NULL");
    //printf("%s \n", row[3] ? row[3] : "NULL");
    //printf("%s \n", row[4] ? row[4] : "NULL");

    /**printf("\n|     NOME     |     CPF    |    TELEFONE    |   CARGO   |  SALARIO  | FILHOS |\n");
    while ((row = mysql_fetch_row(result))) {
      for( i = 0; i < num_fields; i++) {
        printf("%s ", row[i] ? row[i] : "NULL");
        printf(" | ");
      }

      printf("\n");
    }*/
    printf("\n################# LISTA ####################\n");
    mysql_free_result(result);
    ///if(row[1] ? row[1] : "NULL")
    resutado = row[1];
    return resutado;
  }
  mysql_close(&conexao);
}
//------------------------------------FIM MYSQL-----------------------------------

class lerArquivo_{
public:
    char dados[99999];

        int lerArq(){
        char *url = "E:\\CONEXAO_C++\\img\\aquivo_a004.gif";
        FILE *arq;
        arq = fopen(url, "rb");

        char c;
        int cont=0;
        do{
            dados[cont] = fgetc(arq);
            ///printf("%c", dados[cont]);
            cont++;
        }while(cont <= 55513);
        return cont;
    }
};

// HABILITA PARA QUE O TERMINAL SEJA EM CORES
int Habilita_Texto_Cores_Console(){

    /*
        /// https://docs.microsoft.com/pt-br/windows/console/console-virtual-terminal-sequences
        vermelho 14 41
        verde    14 42
        amarelo  14 43
        azul     14 44
        violeta  14 45
        azul cla 14 46
    */

    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }
}


int main()
{

    // HABILITA PARA QUE O TERMINAL SEJA EM CORES
    Habilita_Texto_Cores_Console();
    wprintf(L"\x1b[01;45m     SERVIDOR DE MULTICONEXAO WEB 1.0.0 \r\n");
    wprintf(L"\x1b[0;1m");

    /// CONSULTA QUERY NO MYSQL
    // INSERT INTO `get_caminho` (`GET_CAM`) VALUES ('E:\\CONEXAO_C++\\img\\aquivo_a001.bmp'), ('E:\\CONEXAO_C++\\img\\aquivo_a002.bmp');
    // SELECT `nome` FROM `nomes` = 'jordan'
    // UPDATE `nomes` SET `nome` = 'C:\\Users\\Tiago\\Documents\\CONEXAO_C++\\img\\aquivo_a001.bmp' WHERE `nomes`.`id` = 1;
    // SELECT * FROM `nomes` WHERE `nome` LIKE '%001%';
    // SELECT * FROM `get_caminho` WHERE `get_cam` LIKE '%001%';
    ///char *caminho = lista_funcionario("SELECT * FROM `get_caminho` WHERE `get_cam` LIKE '%");


    quebra p;
    p.d();
    ///printf("Saida do Banco: %s", caminho);
    p.d();
     //system("pause");

    bool Atsd = false;

    p.d();

    while(1){

        /// CHAMADA DO METODO PARA CONEXÃO DE ENVIO E RECEBIMENTO DE DADOS
        //wprintf(L"\x1b[14TJ");
        wprintf(L"\x1b[14;37m[");
        wprintf(L"\x1b[12;100m");
        conexaoServerWew *server = new conexaoServerWew;
        server->serverWeb();
        wprintf(L"\x1b[14;37m]");
        wprintf(L"\x1b[12;100m");
        wprintf(L"\x1b[0;1m");

        /// css
        int  tamcss = 37;
        char cssCode[38] = {
            "h1{color: brown;}"
            "<style></style> \r\n"
        };
        /// js
        int  tamjs = 126;
        char jsCode[827] = {
            //"document.getElementById(\"demo\").innerHTML = \"Hello JavaScript!\";\r\n"
            "\r\nvar nome = \"tiago jordan\";\r\n"
            "alert(nome);\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
            "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        };

        wprintf(L"\x1b[14;42m");
        //wprintf(L"\x1b[12;100mBusca");
        /// RECEBE OS DADOS DOS CLIENTES
        char recebe_cabecalho_cliente[1000];
        if((server->conectRemoteLength = recv(server->getRemoteSocket, recebe_cabecalho_cliente, 900, 0)) == SOCKET_ERROR);
        wprintf(L"\x1b[0;1m");
        wprintf(L"\x1b[14;41m");
        printf("\n*---------------------------------------------------------------*\n");
        printf("Resposta do Cliente: \n%s\n", recebe_cabecalho_cliente);
        wprintf(L"\x1b[0;1m");
        /// imagem mysql
        // https://developer.mozilla.org/pt-BR/docs/Web/HTTP/Headers/Transfer-Encoding
        if(recebe_cabecalho_cliente[5] == 'a' && Atsd == false)
        {
            closesocket(server->getRemoteSocket);
            conexaoServerWew *server = new conexaoServerWew;
            server->serverWeb();



            Atsd = true;
            char content_Type[177] =
            {
                "HTTP/1.1 200 OK\r\n"                                   //19
                "Content-Type: text/plain\r\n"                          //47
                "Transfer-Encoding: chunked\r\n"                        //76

                "Accept: */*\r\n"                                       /// 15
                "Accept-Encoding: gzip, deflate, br\r\n"                /// 38
                "Connection: keep-alive\r\n"                            /// 26
                "Content-Length: 2\r\n"                                 /// 21
            };
            int codigoHtml = send(server->getRemoteSocket, content_Type, 176, 0);

            /**
            * TRATAMENTO DA REQUISICAO DO CLIENTE
            * PARA VERIFICAÇÃO DA SOLICITAÇAO DE
            * CAMINHOS OU PASTARS OU AQUIVOS
            */
            int tamStrCli = strlen(recebe_cabecalho_cliente);
            int newTamCli = 0;
            char query[1000] = "SELECT * FROM `get_caminho` WHERE `get_cam` LIKE '%"; /// 51 caracteres
            char tempCliBuff[1000];
            int a=5, b=0;
            char c;

            do{
                tempCliBuff[b] = recebe_cabecalho_cliente[a];
                if(recebe_cabecalho_cliente[a+2] == 'H'){
                    strcat(query, tempCliBuff);
                    break;
                }
                a++;
                b++;
            }while(a <= tamStrCli);

            /**
            * METODO PARA FAZER A CONSULTA NO BANCO DE DADOS
            * PEGA A REQUISICAO DO CLIENTE E VALIDA PASSANDO
            * O RETORNO COMO ESTRINGO.
            */
            char ch[4] = "%';";
            strcat(query, ch);
            ///system("pause");

            /**lerArqImg *imagem = new lerArqImg;
            imagem->url = lista_funcionario(query);
            char *aa = imagem->lerfile();

            for(int a=0; a<=imagem->cont; a++){
                if(imagem->cont%2==100){
                    quantDiv++;
                }
            }
            printf("\n\n%d\n\n", quantDiv);*/
            ///system("pause");

            lerArquivo_ *larq = new lerArquivo_;
            ///larq->lerArq();
            int contador = larq->lerArq();
            for(int a=0; a <= contador; a++){
                if(a%1000==0){
                    quantDiv++;
                }
            }
            printf("\n\n%d\n\n", quantDiv);
            int xi = 0;
            char buff[99999];
            int f=1;
            for(int a=0; a<=quantDiv; a++){

                wprintf(L"\x1b[0;1m");
                wprintf(L"\x1b[14;43m");
                for(int b=xi; b <= xi+1000; b++){
                    ///printf("%d", larq->dados[b]);
                    ///buff[b] = larq->dados[b];

                    ///buff[b] = larq->dados[b];
                    ///printf("%d", larq->dados[b]);
                    printf("%s", larq->dados[b]);

                    int codigoHtml = send(server->getRemoteSocket,(char*) larq->dados[b], f, 0);

                    ///wprintf(L"\x1b[14;45m");
                    ///printf("%d\n", b);
                }
                ///wprintf(L"\x1b[0;1m");
                wprintf(L"\x1b[14;45m");
                printf(":%d\n", xi);
                //conexaoServerWew *server = new conexaoServerWew;
                //char quebras[4] = "\r\n";
                //strcat(buff, quebras);
                //printf("%s", buff);
                ///server->serverWeb();
                ///int codigoHtml = send(server->getRemoteSocket, buff, xi+4, 0);
                xi = xi + 1000;
            }
            printf("|\n\n\*---------------------------------------------------------------*\n");

            //int codigoHtml = send(server->getRemoteSocket, imagem->dados, imagem->cont-1, 0);
            closesocket(server->getRemoteSocket);
            Atsd = false;
            quantDiv = 0;
        }
            printf("|\n---------\n");

        /**
        *   Tiago uma diga:
        *   Faz uma metodo de leitura da resposta do Cliente
        *   desta forma voce pode interpretar as solicita�oes
        *   e fazer o encaminhamento mais efetivo
        *   uma outra dica �, utilizar esse metodo para buscar
        *   arquivo de solicita��o, uma vez que o programador
        *   vai definir o caminho;
        */
        /// ENVIA OS DADOS DA IMAGEM

        /// css
        if(recebe_cabecalho_cliente[5] == 't'){
            printf("Ativacao do Css!\n");
            int codigoHtml = send(server->getRemoteSocket, cssCode, tamcss, 0);
            closesocket(server->getRemoteSocket);
        }

        /// js
        if(recebe_cabecalho_cliente[5] == 'j'){
            printf("Ativacao do JavaScript!\n");
            int codigoHtml_ = send(server->getRemoteSocket, jsCode, tamjs, 0);
            closesocket(server->getRemoteSocket);
        }

        /// icon bmp
        if(recebe_cabecalho_cliente[5] == 'b'){
            printf("Ativacao do Bmp!\n");

            lerArqImg imagem;
            char *aa = imagem.lerfile();

            int codigoHtml = send(server->getRemoteSocket, imagem.dados, imagem.cont, 0);
            closesocket(server->getRemoteSocket);
        }

        /// imagem jpeg
        if(recebe_cabecalho_cliente[5] == 'g'){
            printf("Ativacao do Bmp!\n");

            lerArqImg *imagem = new lerArqImg;
            char *aa = imagem->lerfile();

            int codigoHtml = send(server->getRemoteSocket, imagem->dados, imagem->cont-1, 0);
            closesocket(server->getRemoteSocket);
        }

        closesocket(server->getRemoteSocket);
        free(recebe_cabecalho_cliente);

    }

}

//-----------------------------------------------------------------------------------------------------------






// vamos criar uma string
  ///string frase("GET /caminho/pasta/arquivo.bmp"); //GET /b HTTP/1.1

  // Antes da remoção
  //cout << "Antes da remocao: " << frase << endl;

  // vamos remover "My"
  ///string nova_frase = frase.erase(0, 4);

  // e mostramos o resultado
  //cout << "Depois da remocao: " << nova_frase << endl;

  //system("PAUSE"); // pausa o programa

  //char *str = "GET /caminho/pasta/arquivo.bmp";
  //char *buffstr;
  //printf("%s", buffstr);

  /*char palavra1[50] = {"bola"}; // \0
    char palavra2[50] = {"abacate"};

    printf("\nAntes de copiar:\npalavra 1: %s\npalavra2: %s\n", palavra1, palavra2);

    strcpy(palavra2, palavra1);

    printf("\nDepois de copiar:\npalavra 1: %s\npalavra2: %s\n", palavra1, palavra2);*/
    //system("PAUSE");


    // TESTE
    //if(1 != 1){
        /*configConexao config;
        cout << config.returnIPServer();
        p.d();
        config.configIPServer("192.168.0.120");
        p.d();
        cout << config.returnIPServer();

        conectaClient conec;


        p.d();
        conexaoServer conecServ;
        char *dados = conecServ.a_rquivo("T:\arquivo");
        cout << dados;
        p.d();
        */
    //}


















//--------------------------------------------------------------------------------
//---------------------------------MYSQL CONNECT----------------------------------
/**

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>

#define IP_MYSQL "127.0.0.1"
#define USER_MYSQL "root"
#define PASS_MYSQL ""
#define DB_MYSQL "alimentar"

MYSQL conexao;

int conecta_ao_db() { // retorna 1 se conectou com sucesso
                      // retorna 0 caso tenha dado falha na conexão

  // Aqui tenho um servidor mysql rodando no IP: 127.0.0.1 com usuário "dev" sem senha "". ele conecta ao database "test"
  if ( mysql_real_connect(&conexao, IP_MYSQL, USER_MYSQL, PASS_MYSQL, DB_MYSQL, 0, NULL, 0) ) {
    return 1;
  } else {
    printf("\nFalha de conexao");
    printf("\nErro %d : %s", mysql_errno(&conexao), mysql_error(&conexao));
    return 0;
  }

}

void lista_funcionario() {
  MYSQL_RES *result;
  MYSQL_ROW row;
  int i, num_fields;

  mysql_init(&conexao);

  if(conecta_ao_db() == 1) {

    if (mysql_query(&conexao, "SELECT * FROM funcionario") != 0) {
      printf("\nFalha de cconsulta");
    }
    result = mysql_store_result(&conexao);
    if (result == NULL) {
      printf("\nFalha no result");
    }

    num_fields = mysql_num_fields(result);

    printf("\n|     NOME     |     CPF    |    TELEFONE    |   CARGO   |  SALARIO  | FILHOS |\n");
    while ((row = mysql_fetch_row(result))) {
      for( i = 0; i < num_fields; i++) {
        printf("%s ", row[i] ? row[i] : "NULL");
        printf(" | ");
      }

      printf("\n");
    }
    printf("\n################# LISTA ####################\n");
    mysql_free_result(result);
  }
  mysql_close(&conexao);
}


//------------------------------------FIM MYSQL-----------------------------------
/*














































/**

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
*/


