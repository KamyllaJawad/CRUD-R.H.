#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*cada coluna da tabela é um vetor
cada registro é uma linha da tabela
vetores que formam a tabela do cadastro*/
vector<int> vCodigos;
vector<string> vNomes;
vector<string> vCargos;
vector<string> vSetores;
vector<string> vSalarios;
vector<bool> vAdmissao;

/*variaveis que identificam a linha do vetor que esta sendo manipulado*/
int linha;

/*variaveis que guardam os dados do ultimo/recente registro manipulado*/
int cod;
string nome, cargo, setor, salario;

/*carega o arquivo de funções */
#include "funcoesrhthemonio.cpp"

/*essa parte do void é a função do menuzin*/
string mostrarMenu()
{
    string opcao;

    system("cls");
    cout << " - = -  R.H. THE MONIO  - = - " << endl;
    cout << " 1 - Consultar Funcionário: " << endl;
    cout << " 2 - Listar: " << endl;
    cout << " 3 - Demissão: " << endl;
    cout << " 4 - Readmissão: " << endl;
    cout << " 0 - Sair: " << endl;
    cout << " Opcao: ";
    cin >> opcao;

    return opcao;
}

main()

{

    setlocale(LC_ALL, "Portuguese");

    string op;

    while (true)
    {
        op = mostrarMenu();

        if (op == "0")
            break;

        if (op == "1")
            CRUDrhthemonio();

        if (op == "2")
            listarFuncionario();

        if (op == "3")
            demitirFuncionario();

        if (op == "4")
            readmitirFuncionario();
    }
}
