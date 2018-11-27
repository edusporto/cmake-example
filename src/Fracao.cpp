#include "fracao.h"

/*inline int mmc(int num1, int num2) {
    int mmc, aux, i;

    for (i = 2; i <= num2; i++) {
        aux = num1 * i;
        if ((aux % num2) == 0) {
            mmc = aux;
            i = num2 + 1;
        }
    }
    return mmc;
}*/

Fracao::Fracao(int numerador, int denominador) {
    this->n = numerador;
    this->d = denominador;
}

Fracao::~Fracao() {

}

void Fracao::setNumerador(int numerador) {
    this->n = numerador;
}

void Fracao::setDenominador(int denominador) {
    this->d = denominador;
}

int Fracao::getNumerador() {
    return this->n;
}

int Fracao::getDenominador() {
    return this->d;
}

void Fracao::simplificar() {
    // TA DANDO ERRO

    bool fim;
    int i;
    int maior = (this->n > this->d ? this->n : this->d);
    int menor = (this->n < this->d ? this->n : this->d);
    
    fim=false;
    while (!fim) {
        fim=true;
        for (i=2; i<=menor; i++) {
            if (menor%i==0 && maior%i==0) {
                this->n = this->n/2;
                this->d = this->d/2;
                menor = menor/2;
                maior = maior/2;
                fim=false;

                break;
            }
        }
    }
}