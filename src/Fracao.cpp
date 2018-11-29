
#include <exception>
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

Fracao::Fracao() {
    this->n = 1;
    this->d = 1;
}

Fracao::Fracao(int numerador, int denominador) {
    if (denominador == 0)
        throw std::range_error("Division by zero");
    this->n = numerador;
    this->d = denominador;
}

Fracao::~Fracao() {

}

void Fracao::setNumerador(int numerador) {
    this->n = numerador;
}

void Fracao::setDenominador(int denominador) {
    if (denominador == 0)
        throw std::range_error("Division by zero");
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
                this->n = this->n/i;
                this->d = this->d/i;
                menor = menor/i;
                maior = maior/i;
                fim=false;

                break;
            }
        }
    }
}

Fracao Fracao::operator+(const Fracao& f) {
    if (this->d == f.d)
        return Fracao(this->n + f.n, this->d);
    
    Fracao ret(1, 1);
    ret.n = this->n * f.d + f.n * this->d;
    ret.d = this->d * f.d;
    ret.simplificar();

    return ret;
}

std::ostream& operator<<(std::ostream& os, const Fracao& f) {
    os << f.n << '/' << f.d;
    return os;
}
