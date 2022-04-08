#include <iostream>

using namespace std;

enum conexao_t {ERR=-1,  // erro de parametros / valores
                SERIE=1, //conexao serie
                PARAL};  // conexao paralelo

    int associacao(double r1, double r2, double req)
// --+-- ------+--            --+----+-
// TIPO DO    NOME             TIPO NOME
// VALOR       DA                  DO
// RETORNADO  FUNCAO            PARAMETRO
{

    if(r1<0 || r2<0 || req<0)
        return ERR;

    if(req==r1+r2)
        return SERIE;

    if(req==1/(1/r1+1/r2))
        return PARAL;
};

int main()
{
    double r1, r2, req, valor;

    cout << "insira o valor de r1:" << endl;
    cin >> r1;

    cout << "insira o valor de r2:" << endl;
    cin >> r2;

    cout << "insira o valor da resistencia equivalente:" << endl;
    cin >> req;

    valor = associacao(r1, r2, req);
// ---+---   ---+------+---+----+---
// RETORNO    CHAMA    |   |    |
//             FUNC    |   |    |
//                     V   V    V
//                 VALORES PARAMETROS

    if(valor==SERIE)
        cout << "\nos resistores estao em serie!" << endl;

    else if(valor==PARAL)
        cout << "\nos resistores estao em paralelo!" << endl;

    else{
        cout << "\nhouve um erro!" << endl;
        return -1;
    }

    return 0;
}
