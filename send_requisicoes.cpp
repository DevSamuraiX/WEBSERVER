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

/**
 * Classe para leitura de arquivos de imagem do tipo BMP, para enviar
 * enviar os dados.
 *
*/

class lerArqImg {
public:
    /// armazena imagem
    char dados[999999];
    /// tamanho da imagem
    /// @brief cont Conta
    int cont = 0;

    /// @brief *url Recebe um cominho de arquivo definido pelo cliente
    char *url = "E:\\CONEXAO_C++\\img\\bmp.bmp";//"E:\\CONEXAO_C++\\img\\bmp.bmp";

    /// metodo define novo caminho
    char *caminhoArquivo(char *defineUrl){
        url = defineUrl;
        return url;
    }

    /// metodo de leitura da imagem
    char *lerfile(){
        FILE *arq;
        arq = fopen(url, "rb");

        char c;
        do{
          c = fgetc(arq);
          dados[cont] = c;
          printf("%c", c);
          cont++;
        }while (c != EOF);

        printf("\n\nContador gif: %d\n\n", cont);

        fclose(arq);
        return dados;
    }
};
