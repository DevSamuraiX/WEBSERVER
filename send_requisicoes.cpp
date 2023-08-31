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


/*class sendRec {
public:

    char base64[1297] {
    "Qk3eAAAAAAAAADYAAAAoAAAABwAAAAcAAAABABgAAAAAAKgAAAAAAAAAAAAAAAAAAAAAAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAA"
    };

    char cabmaisimg[1148] = {

        "BM�       6   (               �                   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   "
        "HTTP/2 200 OK\r\n"
        "cache-control: max-age=300\r\n"
        "content-security-policy: default-src 'none'; style-src 'unsafe-inline'; sandbox\r\n"
        "content-type: image/jpeg\r\n"
        "etag: W/\"71d542be57ff3795693180ce9ff696481c237646867ca35a00437b0d98ced8d5\"\r\n"
        "strict-transport-security: max-age=31536000\r\n"
        "x-content-type-options: nosniff\r\n"
        "x-frame-options: deny\r\n"
        "x-xss-protection: 1; mode=block\r\n"
        "x-github-request-id: 0F12:554D:EF0ED:114C3D:64E69FF0\r\n"
        "accept-ranges: bytes\r\n"
        "date: Thu, 24 Aug 2023 00:12:07 GMT\r\n"
        "via: 1.1 varnish\r\n"
        "x-served-by: cache-for8420-FOR\r\n"
        "x-cache: HIT\r\n"
        "x-cache-hits: 1\r\n"
        "x-timer: S1692835927.445111,VS0,VE1\r\n"
        "vary: Authorization,Accept-Encoding,Origin\r\n"
        "access-control-allow-origin: *\r\n"
        "cross-origin-resource-policy: cross-origin\r\n"
        "x-fastly-request-id: 3bbd17a6f47f6a362efa1e2baf615f4fe256e53e\r\n"
        "expires: Thu, 24 Aug 2023 00:17:07 GMT\r\n"
        "source-age: 102\r\n"
        "content-length: 29687\r\n"
        "X-Firefox-Spdy: h2\r\n"
    };

    char cabimg[925] = {
        "HTTP/2 200 OK\r\n"
        "cache-control: max-age=300\r\n"
        "content-security-policy: default-src 'none'; style-src 'unsafe-inline'; sandbox\r\n"
        "content-type: image/jpeg\r\n"
        "etag: W/\"71d542be57ff3795693180ce9ff696481c237646867ca35a00437b0d98ced8d5\"\r\n"
        "strict-transport-security: max-age=31536000\r\n"
        "x-content-type-options: nosniff\r\n"
        "x-frame-options: deny\r\n"
        "x-xss-protection: 1; mode=block\r\n"
        "x-github-request-id: 0F12:554D:EF0ED:114C3D:64E69FF0\r\n"
        "accept-ranges: bytes\r\n"
        "date: Thu, 24 Aug 2023 00:12:07 GMT\r\n"
        "via: 1.1 varnish\r\n"
        "x-served-by: cache-for8420-FOR\r\n"
        "x-cache: HIT\r\n"
        "x-cache-hits: 1\r\n"
        "x-timer: S1692835927.445111,VS0,VE1\r\n"
        "vary: Authorization,Accept-Encoding,Origin\r\n"
        "access-control-allow-origin: *\r\n"
        "cross-origin-resource-policy: cross-origin\r\n"
        "x-fastly-request-id: 3bbd17a6f47f6a362efa1e2baf615f4fe256e53e\r\n"
        "expires: Thu, 24 Aug 2023 00:17:07 GMT\r\n"
        "source-age: 102\r\n"
        "content-length: 29687\r\n"
        "X-Firefox-Spdy: h2\r\n"
    };

    char imgBase64[223] = {
    "BM�       6   (               �                   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   $�$�$�$�$�$�$�   "
    };

    char imgBase64____[1530] = {
    //"HTTP/1.1 200 OK\r\n"
    //"Content-Type: text/imagem\r\n"
    "0xffd8ffe000104a46494600010101006000600000ffdb00430002010102010102020202020202020305030303030306040403050"
    "70607070706070708090b0908080a0807070a0d0a0a0b0c0c0c0c07090e0f0d0c0e0b0c0c0cffdb00430102020203030306030306"
    "0c0807080c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0"
    "c0cffc00011080006000603012200021101031101ffc4001f0000010501010101010100000000000000000102030405060708090a"
    "0bffc400b5100002010303020403050504040000017d01020300041105122131410613516107227114328191a1082342b1c11552d"
    "1f02433627282090a161718191a25262728292a3435363738393a434445464748494a535455565758595a636465666768696a7374"
    "75767778797a838485868788898a92939495969798999aa2a3a4a5a6a7a8a9aab2b3b4b5b6b7b8b9bac2c3c4c5c6c7c8c9cad2d3d"
    "4d5d6d7d8d9dae1e2e3e4e5e6e7e8e9eaf1f2f3f4f5f6f7f8f9faffc4001f01000301010101010101010100000000000001020304"
    "05060708090a0bffc400b51100020102040403040705040400010277000102031104052131061241510761711322328108144291a"
    "1b1c109233352f0156272d10a162434e125f11718191a262728292a35363738393a434445464748494a535455565758595a636465"
    "666768696a737475767778797a82838485868788898a92939495969798999aa2a3a4a5a6a7a8a9aab2b3b4b5b6b7b8b9bac2c3c4c"
    "5c6c7c8c9cad2d3d4d5d6d7d8d9dae2e3e4e5e6e7e8e9eaf2f3f4f5f6f7f8f9faffda000c03010002110311003f00d8d4751d27e1"
    "8f84fc33e32f197867fe12ff0085de2ffed297c33e19975eb93368329b951b13e558a1b78a18d155155e59659ae65966656820b72"
    "8a2bf9d338e1ec2e635957c44aaa6925fbbad5a92b2ef1a552116fbc9ae67d5bb23e9b82eaca58295edbc7a2ff9f74df6ff0086db"
    "648fffd9\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
    };

    char imgBase64___[125] = {
    "�PNG"
    ""
    "   "
    "IHDR         o�x   sRGB ���   gAMA  ��"
    "�a   	pHYs  %  %IR$�   IDATWcT��À"
    "\" 4�� ��+��h5    IEND�B`�"
    };

    char imgBase64_a[126] = {
        "�PNG"
        ""
        "   "
        "IHDR         o�x   sRGB ���   gAMA  ���a   	pHYs  %  %IR$�   IDATWcT��À"
        "\�""�4�� ��+��h5    IEND�B`�"
    };

    char imgBase64a[1600] = {
        "BM�      6   (               t                  L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" $�$�$�$�$��|L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" $�$�$�$�$�$�$�L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" $�$�$�$�$�$�$�L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" $�$�$�$�$�$�$�L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" $�$�$�$�$�$�$�L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" $�$�$�$�$�$�$�L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" $�$�$�$�$�$�$�L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\"L�\" "
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        ///"Qk3eAAAAAAAAADYAAAAoAAAABwAAAAcAAAABABgAAAAAAKgAAAAAAAAAAAAAAAAAAAAAAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAAJBztJBztJBztJBztJBztJBztJBztAAAA\r\n"
    };

    char imbBase64b[999999] =
    {
        "/9j/4AAQSkZJRgABAQAAAQABAAD/2wCEAA"
        "kGBwgHBgkIBwgKCgkLDRYPDQwMDRsUFRAWIB0iIiAdHx8kKDQsJCYxJx8"
        "fLT0tMTU3Ojo6Iys/RD84QzQ5OjcBCgoKDQwNGg8PGjclHyU3Nzc3Nzc3"
        "Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3Nzc3N"
        "//AABEIAGQAZAMBIgACEQEDEQH/xAAcAAEAAgMBAQEAAAAAAAAAAAAAAQ"
        "IDBAUHBgj/xABBEAABAwEDBwcJBwMFAAAAAAABAAIRAxIhMQQFBhMiQVE"
        "VUlVhcZPRF1aBkZSx+HwIzIzQpKhwRSi0hZTY4PC/8QAGAEBAQEBAQAAA"
        "AAAAAAAAAAAAAEDAgT/xAAfEQEAAQIHAQAAAAAAAAAAAAAAARMhAgMREj"
        "JRYUH/2gAMAwEAAhEDEQA/APQeVc1dIZF3zPFOVc1dIZF3zPFeO+TvTDz"
        "eq0UP81Hk70w83qvtFD/ADQex8q5q6QyLvmeKcq5q6QyLvmeK8c8nemPm"
        "9W9oofETyd6Y+btb2ih8RB7HytmrpDIu+Z4qlTOeaqjbIznkrL5lmUMBX"
        "kuR6AaW0Mqp1a2i1TKKbTLqTsqoAP6ptrO7QXSdzi7/Rz73OMf1tIQCbh"
        "+JuwQeoU8vzXTdaOeKD7osvyinCy8rZp6RyLvmeK8odoFpMWQNEKocRE/"
        "11KBdjGsU5PoJpRTbV1uiVSo5xFiMrogMgicahJkXY70Hq/K2aukMi75n"
        "inKuaukMi75nivJss0D0pr2dRom+hGMZVRM+uotXyd6Y+btb2ih8RB7Hy"
        "rmrpDIu+Z4pyrmrpDIu+Z4rxzyd6Y+btb2ih8RPJ3pj5u1vaKHxEHsfKu"
        "aukMi75nii8c8nemPm7W9oofERB+goYcK+Ti/gPFZBk7xi6l3fzVS6kDa"
        "NFk8bN6h+WtYYc13oaSgyihstvaHAySGYhZYdtbYvN2zgtQ5wpgkFr7v+"
        "N3ghy+mBJa/9DvBBvWgNxU2+orW155qa881Bs2+opb6itbXnmprzzUGzb"
        "6ilvqK1teeamvPNQbNvqKW+orW155qa881Bs2lC19ceaiCxawfkJ7AoDa"
        "c/hu9IV3CqbNl7RdtS2ZPr7VDdaHC0+mWcAyD65QQWsaSCxx7ASEDWGdm"
        "I3lC2vENfTmcTTn+VDmVXMIc+kQdxp3e9BjbUpOcG6p4kxJZA+HuWVzWA"
        "kWD6BKxtyYB4LmZOWbwKIB9/YsjG1g7aqUy20TAZBjcMVLiIp/7bv0qXM"
        "Y0TqyewJFaSRUp4mJZu4YqXB9oFr2DZv2ZvntVDVM5qapnNCq1lUjbrN3"
        "XsbHbiSrkPkWXNiN4xQNU3mhNU3mhA2tF7mfo+akNqXyW9Wz80XRXVM5o"
        "UrLHUURGlnQCnTa9gDXudFoATgVzwLTi9wNTcS6zeIErpZ1cG0Gl2FriB"
        "u61zQXasQB90EC02OJXoy+IxiiGCD17mbsfRepdRBploa0yQSCGYfUq4q"
        "ta4S4BhdfJG9UDxqxBElu0AWzK0uDaFI/kYCcRZZ1KooUrLdkEEAkRT4w"
        "riobV5bMyYIkJbNoNkQQS2C37uKtxDKNJuFJnCbLLrlGoo6szTZG/ZZON"
        "yF8kfdDzB8OE/JXtWwAOy5zb5O5S4oKNHWD7JkkRe1kYfJXsNaLTGsa8O"
        "kENZN38qmvMhtpgugm23FG1XyGy2cCCQTBSYkbIymuQTrHYcW4k9u76lG"
        "165n7R94wtC791hbWbbsTeBFzm3X7go115aC1rwJBBF5jDipt8GwMqrc5"
        "5/7Gj+VKx5PUaaf4lJt9wdUj3bkXMxHQ3s6mKVO+CXx+xXKtsMQ/aAvBN"
        "0GOpdXOpIo04JG3xI3HguY51SzsxB323cNxhTK4iocHOEEk4ESePCEBAf"
        "LZtRfFS8COxWZbBB+03CS5zt/Zcq2jDySbUARrHX/ALY+taA6YDBIni7f"
        "6r1Vr6YeBbbIMD7Qxv6lYOJ31WknAF+N+FNzRtNgk3tBIGJ3wqDCy8tqX"
        "xeLUx6IQumbVRrpN5L4i/HC/5IJY2dY42pxLuHYlqHA7RE3yXA477vf1K"
        "AarWgy7aj71qMOF1ylsgzrA6Afz+ngpblD6Ys0yOIDgXbuz6lZHZZWDAT"
        "ZLr5JZh/appPQwuc4RDgQDAFrG7cshoZQWQWVGwL3Xnd2K7cqrQPw5uER"
        "H/AJV/66uAb92JGHXh1hSd3yBYB35skdIuN7j/AAixDLcrcXQ7AkQBh/a"
        "i524uhuZ12qLS0kkOnZk7upcwsuEipZAwDHg9a7rWuDQC4uPE71MFZ4cz"
        "bGg4Ia4Gzt33CGPG/tUWHzBDgZwsvj3/AFcu/BSCuqw4MOcS4MeJm4seJ"
        "vxUkOLSDTcAcdh53rvQUgpV8Hz75Mg03Xxfq33elZHMeaZNmoOFzpA9a7"
        "kFRBSqODDg5rS2o4Rjq3eKbYswKjjuMPuXfgpBSt4OC1ri4EteACALTXm"
        "6e1VfTIFnVvj8tzz+/wBcF9BBSClaRw6QDGwWON5vh4/lSu3BUKVRCIiy"
        "BERAREQEREBERAREQEREH//Z"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
        "\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
    };

};*/
