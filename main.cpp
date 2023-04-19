#include <iostream>
#include <windows.h>
#include "funcoes.cpp"

using namespace std;
int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcaoMetodos, opcaoInstancias; 
    string nomeInstancia;              

    do
    {
        menuMetodos();
        cout << "Escolher opção:";
        cin >> opcaoMetodos;

        if (opcaoMetodos > 0 && opcaoMetodos < 7)
        { // vereficando os metodos de ordenação
            menuInstancias();
            cout << " Escolher opção :";
            cin >> opcaoInstancias;
            system("cls");

            if (opcaoInstancias != 23)
            { // verificando escolha com a opção de cancelar
                if (opcaoInstancias > 0 && opcaoInstancias <= 6)
                {
                    nomeInstancia = defineInstancia(opcaoInstancias);
                    lerArquivoPalavras(nomeInstancia);
                    ordenaVetoresPalavras(opcaoMetodos);
                    system("pause");
                    system("cls");
                }
                else if (opcaoInstancias >= 7 && opcaoInstancias < 23)
                { // verificando as instancias de palavras
                    nomeInstancia = defineInstancia(opcaoInstancias);
                    lerArquivoNumeros(nomeInstancia);
                    ordenaVetoresNumeros(opcaoMetodos);
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << " Opção invalida!" << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (opcaoMetodos == 7)
        {
            break;
        }
        else
        {
            cout << " Opcão invalidade" << endl;
            system("pause");
            system("cls");
        }

    } while (opcaoMetodos != 7);


    return 0;
}

