#include <iostream>
#include <string>
#include "Matematica.h"

using namespace std;

bool fim()
{
    string resp;
    cout << "\nDeseja terminar o programa? (N/s)" << endl;
    getline(cin, resp);
    getline(cin, resp);

    if (resp.empty())
        return false;
    if (resp.at(0) == 'S' || resp.at(0) == 's')
        return true;
    return false;
}

int main()
{
    double n1;
    double n2;
    double resposta;
    int opcao;

    do
    {
        cout << endl;
        cout << "Qual operacao deseja executar?" << endl;
        cout << "1) Somar" << endl;
        cout << "2) Subtrair" << endl;
        cout << "3) Multiplicar" << endl;
        cout << "4) Dividir" << endl;
        cout << "5) Potencia" << endl;
        cout << "6) Raiz" << endl;

        cin >> opcao;

        if (opcao < 1 || opcao > 6)
        {
            cout << "Opcao invalida!" << endl;
            continue;
        }

        cout << "\nDigite o primeiro valor:" << endl;
        cin >> n1;
        cout << "\nDigite o segundo valor:" << endl;
        cin >> n2;

        switch (opcao)
        {
            case 1: resposta = Matematica::somar(n1, n2); break;
            case 2: resposta = Matematica::subtrair(n1, n2); break;
            case 3: resposta = Matematica::multiplicar(n1, n2); break;
            case 4: resposta = Matematica::dividir(n1, n2); break;
            case 5: resposta = Matematica::elevado(n1, int(n2)); break;
            case 6: resposta = Matematica::raiz(n1, n2); break;
        }

        cout << "\nA resposta eh: " << resposta << endl;
    } while (!fim());
    
    return 0;
}