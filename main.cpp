#include <iostream>
#include <string>
#include "Matematica.h"
#include "fracao.h"

using namespace std;

bool fim() {
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

int main() {
    // Testes com a classe Fracao

    cout << "Teste 1" << endl;
    Fracao f1(2, 10), f2(3, 45), f3(10, 6);
    f1.simplificar();
    f2.simplificar();
    f3.simplificar();
    cout << "f1 = " << f1.getNumerador() << "/" << f1.getDenominador() << endl;
    cout << "f2 = " << f2.getNumerador() << "/" << f2.getDenominador() << endl;
    cout << "f3 = " << f3.getNumerador() << "/" << f3.getDenominador() << endl;
    cout << endl;
    
    cout << "Teste 2" << endl;
    f3 = f1 + f2;
    cout << "f1 + f2 = " << f3 << endl;
    cout << "2/3 + 3/4 = " << Fracao(2, 3) + Fracao(3, 4) << endl;
    cout << "f1 + 1 = " << f1 + 1 << endl;
    cout << "1 + f1 = " << 1 + f1 << endl;
    cout << endl;

    cout << "Teste 3" << endl;
    //Fracao f4(1, 0); // lanca excecao
    //cout << f4 << endl;
    cout << endl;

    cout << "Teste 4" << endl;
    cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
    cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
    cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
    cout << endl;

    //cout << "Teste 4.5" << endl;
    //cout << Fracao(1,1) / Fracao(0,1) << endl;

    cout << "Teste 5" << endl;
    cout << "(int)f1 = " << (int)f1 << endl;
    cout << "(float)f1 = "  << (float)f1 << endl;
    cout << "(double)f1 = "  << (double)f1 << endl;
    cout << endl;

    cout << "Teste 6" << endl;
    cout << f1 << " < " << f2 << " = " << (f1 < f2) << endl;
    cout << f1 << " > " << f2 << " = " << (f1 > f2) << endl;
    cout << endl;

    cout << "Teste 7" << endl;
    cout << "f1++ retorna " << f1++ << endl;
    f1--;
    cout << "++f1 retorna " << ++f1 << endl;
    f1--;
    cout << "f1-- retorna " << f1-- << endl;
    f1++;
    cout << "--f1 retorna " << --f1 << endl;
    f1++;
    cout << endl;

    cout << "Teste 8" << endl;
    cout << "(2/4 == 1/2) = " << (Fracao(2,4) == Fracao(1,2)) << endl;
    cout << endl;

    cout << "Teste 9" << endl;
    cout << "-0.75 = " << Fracao(-0.75) << endl;
    cout << endl;

    Fracao* frac = new Fracao(2, 3);
    Fracao* frac2 = new Fracao;
    frac2->setNumerador(4); frac2->setDenominador(5);
    cout << "Teste 10" << endl;
    cout << "2/3 += 4/5 = " << (*frac += *frac2) << endl;
    cout << *frac << "-= 4 = " << (*frac -= 4) << endl; 
    cout << endl;
    delete frac;
    delete frac2;

    // Testes com a classe Matematica
    /*
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
    */

    return 0;
}
