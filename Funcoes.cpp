#include <iostream>
#include <fstream> 
#include <vector>  
#include <chrono>  

using namespace std;
using namespace chrono;

vector<int> vetornumeros;     
vector<string> vetorpalavras; 

void menuMetodos()
{
    cout << " ***************************** " << endl;
    cout << " 1) Bubble Sort" << endl;
    cout << " 2) Insertion Sort" << endl;
    cout << " 3) Selection Sort" << endl;
    cout << " 4) Shell Sort" << endl;
    cout << " 5) Quick Sort" << endl;
    cout << " 6) Merge Sort" << endl;
    cout << " 7) Sair" << endl;
    cout << " ***************************** " << endl;
}

void menuInstancias()
{
    cout << " *************************************************** " << endl;
    cout << " 1) Dicionario aleatorio - 29855" << endl;
    cout << " 2) Dicionario aleatorio - 261791" << endl;
    cout << " 3) Dicionario inversamente ordenado - 29855" << endl;
    cout << " 4) Dicionario inversamente ordenado - 261791" << endl;
    cout << " 5) Dicionario ordenado - 29855" << endl;
    cout << " 6) Dicionario ordenado - 261791" << endl;
    cout << " 7) Lista aleatoria - 1.000" << endl;
    cout << " 8) Lista aleatoria - 10.000" << endl;
    cout << " 9) Lista aleatoria - 100.000" << endl;
    cout << " 10) Lista aleatoria - 1.000.000" << endl;
    cout << " 11) Lista inversamente ordenada - 1.000" << endl;
    cout << " 12) Lista inversamente ordenada - 10.000" << endl;
    cout << " 13) Lista inversamente ordenada - 100.000" << endl;
    cout << " 14) Lista inversamente ordenada - 1.000.000" << endl;
    cout << " 15) Lista ordenada - 1.000" << endl;
    cout << " 16) Lista ordenada - 10.000" << endl;
    cout << " 17) Lista ordenada - 100.000" << endl;
    cout << " 18) Lista ordenada - 1.000.000" << endl;
    cout << " 19) Lista quase ordenada - 1.000" << endl;
    cout << " 20) Lista quase ordenada - 10.000" << endl;
    cout << " 21) Lista quase ordenada - 100.000" << endl;
    cout << " 22) Lista quase ordenada - 1.000.000" << endl;
    cout << " 23) Cancelar" << endl;
    cout << " ********************************************************* " << endl;
}
// funcao de ler arquivos
void lerArquivoNumeros(string nomeInstancia)
{
    ifstream arquivo;

    arquivo.open(nomeInstancia);

    if (!arquivo.is_open())
    {
        cout << "Erro, não foi possivel abrir o arquivo." << endl;
        arquivo.clear();
    }

    while (!arquivo.eof())
    {
        int valor;
        arquivo >> valor;
        vetornumeros.push_back(valor); 
    }
    arquivo.close();
}
// funcao de ler palavras
void lerArquivoPalavras(string nomeInstancia)
{
    ifstream arquivo;

    arquivo.open(nomeInstancia);

    if (!arquivo.is_open())
    {
        cout << "Erro, não foi possivel abrir o arquivo." << endl;
        arquivo.clear();
    }

    while (!arquivo.eof())
    {
        string valor;
        arquivo >> valor;
        vetorpalavras.push_back(valor); // guarda os valores dentro do vetor
    }
    arquivo.close();
}
// funcao de definir instancia
string defineInstancia(int opInstancia)
{

    string nomeInstancia;

    if (opInstancia == 1)
    {
        nomeInstancia = "../Instancias/DicionarioAleatorio-29855.txt";
    }
    else if (opInstancia == 2)
    {
        nomeInstancia = "../Instancias/DicionarioAleatorio-261791.txt";
    }
    else if (opInstancia == 3)
    {
        nomeInstancia = "../Instancias/DicionarioInversamenteOrdenado-29855.txt";
    }
    else if (opInstancia == 4)
    {
        nomeInstancia = "../Instancias/DicionarioInversamenteOrdenado-261791.txt";
    }
    else if (opInstancia == 5)
    {
        nomeInstancia = "../Instancias/DicionarioOrdenado-29855.txt";
    }
    else if (opInstancia == 6)
    {
        nomeInstancia = "../Instancias/DicionarioOrdenado-261791.txt";
    }
    else if (opInstancia == 7)
    {
        nomeInstancia = "../Instancias/ListaAleatoria-1000.txt";
    }
    else if (opInstancia == 8)
    {
        nomeInstancia = "../Instancias/ListaAleatoria-10000.txt";
    }
    else if (opInstancia == 9)
    {
        nomeInstancia = "../Instancias/ListaAleatoria-100000.txt";
    }
    else if (opInstancia == 10)
    {
        nomeInstancia = "../Instancias/ListaAleatoria-1000000.txt";
    }
    else if (opInstancia == 11)
    {
        nomeInstancia = "../Instancias/ListaInversamenteOrdenada-1000.txt";
    }
    else if (opInstancia == 12)
    {
        nomeInstancia = "../Instancias/ListaInversamenteOrdenada-10000.txt";
    }
    else if (opInstancia == 13)
    {
        nomeInstancia = "../Instancias/ListaInversamenteOrdenada-100000.txt";
    }
    else if (opInstancia == 14)
    {
        nomeInstancia = "../Instancias/ListaInversamenteOrdenada-1000000.txt";
    }
    else if (opInstancia == 15)
    {
        nomeInstancia = "../Instancias/ListaOrdenada-1000.txt";
    }
    else if (opInstancia == 16)
    {
        nomeInstancia = "../Instancias/ListaOrdenada-10000.txt";
    }
    else if (opInstancia == 17)
    {
        nomeInstancia = "../Instancias/ListaOrdenada-100000.txt";
    }
    else if (opInstancia == 18)
    {
        nomeInstancia = "../Instancias/ListaOrdenada-1000000.txt";
    }
    else if (opInstancia == 19)
    {
        nomeInstancia = "../Instancias/ListaQuaseOrdenada-1000.txt";
    }
    else if (opInstancia == 20)
    {
        nomeInstancia = "../Instancias/ListaQuaseOrdenada-10000.txt";
    }
    else if (opInstancia == 21)
    {
        nomeInstancia = "../Instancias/ListaQuaseOrdenada-100000.txt";
    }
    else if (opInstancia == 22)
    {
        nomeInstancia = "../Instancias/ListaQuaseOrdenada-1000000.txt";
    }

    return nomeInstancia;
}

void bubbleSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int troca;
    for (int i = 0; i < vetornumeros.size() - 1; i++)
    {
        troca = 0;
        for (int j = 1; j < vetornumeros.size() - i; j++)
        {
            if (vetornumeros[j] < vetornumeros[j - 1])
            {
                (*comparacoes)++;
                int aux = vetornumeros[j];
                vetornumeros[j] = vetornumeros[j - 1];
                vetornumeros[j - 1] = aux;
                troca = 1;
                (*trocas)++;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

void bubbleSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int troca;
    for (int i = 0; i < vetorpalavras.size() - 1; i++)
    {
        troca = 0;
        for (int j = 1; j < vetorpalavras.size() - i; j++)
        {
            if (vetorpalavras[j] < vetorpalavras[j - 1])
            {
                (*comparacoes)++;
                auto aux = vetorpalavras[j];
                vetorpalavras[j] = vetorpalavras[j - 1];
                vetorpalavras[j - 1] = aux;
                troca = 1;
                (*trocas)++;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

void insertionSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int chave, j;

    for (int i = 1; i < vetornumeros.size(); i++)
    {
        chave = vetornumeros[i];
        j = i - 1;

        (*comparacoes)++;

        while (j >= 0 && vetornumeros[j] > chave)
        {
            (*comparacoes)++;

            vetornumeros[j + 1] = vetornumeros[j];
            j--;

            (*trocas)++;
        }
        vetornumeros[j + 1] = chave;
    }
}

void insertionSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    string chave;
    int j;

    for (int i = 1; i < vetorpalavras.size(); i++)
    {
        chave = vetorpalavras[i];
        j = i - 1;

        (*comparacoes)++;

        while (j >= 0 && vetorpalavras[j] > chave)
        {
            (*comparacoes)++;

            vetorpalavras[j + 1] = vetorpalavras[j];
            j--;

            (*trocas)++;
        }
        vetorpalavras[j + 1] = chave;
    }
}
void selectionSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int min, i, j;

    for (i = 0; i < vetornumeros.size(); i++)
    {
        min = i;

        for (j = i + 1; j < vetornumeros.size(); j++)
        {
            if (vetornumeros[j] < vetornumeros[min])
            {
                (*comparacoes)++;
                min = j;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        int aux = vetornumeros[i];
        vetornumeros[i] = vetornumeros[min];
        vetornumeros[min] = aux;

        (*trocas)++;
    }
}

void selectionSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int min, i, j;

    for (i = 0; i < vetorpalavras.size(); i++)
    {
        min = i;

        for (j = i + 1; j < vetorpalavras.size(); j++)
        {
            if (vetorpalavras[j] < vetorpalavras[min])
            {
                (*comparacoes)++;
                min = j;
            }
            else
            {
                (*comparacoes)++;
            }
        }
        string aux = vetorpalavras[i];
        vetorpalavras[i] = vetorpalavras[min];
        vetorpalavras[min] = aux;

        (*trocas)++;
    }
}
void shellSortNumeros(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int h, x, i, j;
    for (h = 1; h < vetornumeros.size(); h = 3 * h + 1);

    while (h > 1)
    {
        h = h / 3;
        (*comparacoes)++;
        for (i = h; i < vetornumeros.size(); i++)
        {
            x = vetornumeros[i];
            j = i;

            while (j >= h && vetornumeros[j - h] > x)
            {
                (*comparacoes)++;

                vetornumeros[j] = vetornumeros[j - h];
                j = j - h;

                (*trocas)++;
            }
            vetornumeros[j] = x;
            (*comparacoes)++;
        }
    }
}

void shellSortPalavras(unsigned long long *comparacoes, unsigned long long *trocas)
{
    int h, i, j;
    string x;
    for (h = 1; h < vetorpalavras.size(); h = 3 * h + 1);

    while (h > 1)
    {
        h = h / 3;
        (*comparacoes)++;
        for (i = h; i < vetorpalavras.size(); i++)
        {
            x = vetorpalavras[i];
            j = i;

            while (j >= h && vetorpalavras[j - h] > x)
            {
                (*comparacoes)++;

                vetorpalavras[j] = vetorpalavras[j - h];
                j = j - h;

                (*trocas)++;
            }
            vetorpalavras[j] = x;
            (*comparacoes)++;
        }
    }
}

void quickSortNumeros(int esquerda, int direita, unsigned long long *comparacoes, unsigned long long *trocas)
{
    int i = esquerda, j = direita;
    int pivot = vetornumeros[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (vetornumeros[i] < pivot)
            i++;
        while (vetornumeros[j] > pivot)
            j--;

        (*comparacoes)++;
        if (i <= j)
        {
            auto temp = vetornumeros[i];
            vetornumeros[i] = vetornumeros[j];
            vetornumeros[j] = temp;
            i++;
            j--;

            (*trocas)++;
        }
    }

    (*comparacoes)++;
    if (esquerda < j)
        quickSortNumeros(esquerda, j, comparacoes, trocas);
    (*comparacoes)++;
    if (i < direita)
        quickSortNumeros(i, direita, comparacoes, trocas);
}

void quickSortPalavras(int esquerda, int direita, unsigned long long *comparacoes, unsigned long long *trocas)
{
    int i = esquerda, j = direita;
    string pivot = vetorpalavras[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (vetorpalavras[i] < pivot)
            i++;
        while (vetorpalavras[j] > pivot)
            j--;

        (*comparacoes)++;
        if (i <= j)
        {
            auto temp = vetorpalavras[i];
            vetorpalavras[i] = vetorpalavras[j];
            vetorpalavras[j] = temp;
            i++;
            j--;

            (*trocas)++;
        }
    }

    (*comparacoes)++;
    if (esquerda < j)
        quickSortPalavras(esquerda, j, comparacoes, trocas);
    (*comparacoes)++;
    if (i < direita)
        quickSortPalavras(i, direita, comparacoes, trocas);
}

void IntercalaNumeros(int inicio, int meio, int fim, unsigned long long *comparacoes, unsigned long long *trocas)
{
    int *vetAux = (int *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= meio; i++)
    {
        vetAux[i] = vetornumeros[i];
    }

    for (j = meio + 1; j <= fim; j++)
    {
        vetAux[fim + meio + 1 - j] = vetornumeros[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        (*comparacoes)++;
        if (vetAux[i] <= vetAux[j])
        {
            vetornumeros[k] = vetAux[i];
            i++;
            (*trocas)++;
        }
        else
        {
            vetornumeros[k] = vetAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(vetAux);
}


void mergeSortNumeros(int inicio, int fim, unsigned long long *comparacoes, unsigned long long int *trocas)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergeSortNumeros(inicio, meio, comparacoes, trocas);
        mergeSortNumeros(meio + 1, fim, comparacoes, trocas);
        IntercalaNumeros(inicio, meio, fim, comparacoes, trocas);
        (*comparacoes)++;
    }
}


void IntercalaPalavras(int inicio, int meio, int fim, unsigned long long *comparacoes, unsigned long long *trocas)
{
    string *vetAux = (string *)calloc(fim + 1, sizeof(string));

    int i, j;
    for (i = inicio; i <= meio; i++)
    {
        vetAux[i] = vetorpalavras[i];
    }

    for (j = meio + 1; j <= fim; j++)
    {
        vetAux[fim + meio + 1 - j] = vetorpalavras[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        (*comparacoes)++;
        if (vetAux[i] <= vetAux[j])
        {
            vetorpalavras[k] = vetAux[i];
            i++;
            (*trocas)++;
        }
        else
        {
            vetorpalavras[k] = vetAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(vetAux);
}
void mergeSortPalavras(int inicio, int fim, unsigned long long *comparacoes, unsigned long long int *trocas)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergeSortPalavras(inicio, meio, comparacoes, trocas);
        mergeSortPalavras(meio + 1, fim, comparacoes, trocas);
        IntercalaPalavras(inicio, meio, fim, comparacoes, trocas);
        (*comparacoes)++;
    }
}


void imprimiNumeros()
{
    for (int i = 0; i < vetornumeros.size(); i++)
    {
        cout << vetornumeros[i] << endl;
    }
    vetornumeros.clear(); // limpar o vetor
}
void imprimiPalavras()
{
    for (int i = 0; i < vetorpalavras.size(); i++)
    {
        cout << vetorpalavras[i] << endl;
    }
    vetorpalavras.clear(); // limpar o vetor
}

void ordenaVetoresNumeros(int opMetodos)
{
    unsigned long long comparacoes = 0; // Varial para controle das comparacoes
    unsigned long long trocas = 0;      // Varial para controle das trocas

    if (opMetodos == 1)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        bubbleSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiNumeros();
        cout << "\n O numero de comparaçoes : " << comparacoes << endl;
        cout << "O numero de trocas: " << trocas << endl;
        cout << "O tempo total e: " << tempototal.count() << endl;
    }
    else if (opMetodos == 2)
    {

        steady_clock::time_point tempoinicial = steady_clock::now();
        insertionSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiNumeros();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl;
    }
    else if (opMetodos == 3)
    {
       
        steady_clock::time_point tempoinicial = steady_clock::now();
        selectionSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiNumeros();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl; 
    }
    else if (opMetodos == 4)
    {
          steady_clock::time_point tempoinicial = steady_clock::now();
       shellSortNumeros(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiNumeros();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "NUmero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl; 
    }
    else if (opMetodos == 5)
    {
         steady_clock::time_point tempoinicial = steady_clock::now();
       quickSortNumeros(0, vetornumeros.size()-1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiNumeros();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl;
    }
    else if (opMetodos == 6)
    {
         steady_clock::time_point tempoinicial = steady_clock::now();
        mergeSortNumeros(0, vetornumeros.size()-1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiNumeros();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl;
    }
}

void ordenaVetoresPalavras(int opMetodos)
{

    unsigned long long comparacoes = 0; 
    unsigned long long trocas = 0;      

    if (opMetodos == 1)
    {

        steady_clock::time_point tempoinicial = steady_clock::now();
        bubbleSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiPalavras();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl;
    }
    else if (opMetodos == 2)
    {

        steady_clock::time_point tempoinicial = steady_clock::now();
        insertionSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiPalavras();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl;
    }
    else if (opMetodos == 3)
    {
         steady_clock::time_point tempoinicial = steady_clock::now();
        selectionSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiPalavras();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl; 
    }
    else if (opMetodos == 4)
    {
          steady_clock::time_point tempoinicial = steady_clock::now();
       shellSortPalavras(&comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiPalavras();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl; 
    }
    else if (opMetodos == 5)
    {
         steady_clock::time_point tempoinicial = steady_clock::now();
       quickSortPalavras(0, vetorpalavras.size()-1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiPalavras();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl; 
    }
    else if (opMetodos == 6)
    {
        steady_clock::time_point tempoinicial = steady_clock::now();
        mergeSortPalavras(0, vetorpalavras.size()-1, &comparacoes, &trocas);
        steady_clock::time_point tempofinal = steady_clock::now();
        duration<double> tempototal = duration_cast<duration<double>>(tempofinal - tempoinicial);

        imprimiPalavras();
        cout << "\nNumero de comparaçoes:   " << comparacoes << endl;
        cout << "Numero de trocas:  " << trocas << endl;
        cout << "O tempo total e:  " << tempototal.count() << endl;
    }
}
