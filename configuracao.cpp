#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;


class configConexao{

private:
    /**
    *   VARIAVEL DE ARMAZENAMENTO DO IP DO SERVIÇO
    *   @Varialvel ipSever
    *   @@ IP DEFAULT 127.0.0.1
    */
    char* ipServer = "127.0.0.1";

    /**
    *   VARIAVEL DE ARMAZENAMENTO DA PORTA DO SERVIÇO
    *   @Variavel portServer_
    *   @@ PORTE SERVER 993
    */
    int portServer_ = 993;

public:
    /**
    *
    *   DEFINE O IP DO SERVIÇO DE COMUNICAO COM O CLIENTE
    *   ESSE METODO TEM COMO OBJETIVO DEFINIR O IP DE COM
    *   UNIÇÃO DO SERVER PELA VARIAVEL defineIPS QUE É DE
    *   FINIDA PELO USUARIO E GRAVA NA VARIAVEL PRINCIPAL
    *   ipServer.
    *
    *   Variavel privada que guarda o ip do serviço
    *   @Variavel ipServer  @Tipo Char*
    *
    *   Variavel publica que faz a gravação do ip
    *   @Variavel defineIPS @Tipo Char*
    */
    void configIPServer(char* defineIPS){
        ipServer = defineIPS;
    }

    /**
    *   METODO QUE RETORNA O IP DO SERVIÇO DE COMUNICAÇÃO
    *   @Variavel ipServer @Tipo Char*
    */
    char* returnIPServer(){
        return ipServer;
    }

};

class teste{
public:
    int  *ret();
};
