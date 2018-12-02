
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
    this->simplificar();
}

Fracao::Fracao(double numero) {
    int inicio = numero;
    int n = numero;
    int d = 1;
    while ((double)n != numero) {
        n = numero = numero * 10;
        d *= 10;
    }

    this->n = inicio==0 ? numero : (inicio >= 1 || inicio <= 1 ? n : n + d*inicio);
    this->d = d;

    this->simplificar();
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

    bool negativo;
    if ((this->n < 0 && this->d > 0) ||
         this->n > 0 && this->d < 0)
        negativo = true;
    else
        negativo = false;

    bool fim;
    int i;

    if (this->n < 0) this->n = -this->n;
    if (this->d < 0) this->d = -this->d;
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

    if (negativo) this->n = -this->n;
}

Fracao Fracao::operator+(const Fracao& f) {
    if (this->d == f.d)
        return Fracao(this->n + f.n, this->d);
    
    Fracao ret;
    ret.n = this->n * f.d + f.n * this->d;
    ret.d = this->d * f.d;
    ret.simplificar();

    return ret;
}

Fracao Fracao::operator-(const Fracao& f) {
    if (this->d == f.d)
        return Fracao(this->n - f.n, this->d);
    
    Fracao ret;
    ret.n = this->n * f.d - f.n * this->d;
    ret.d = this->d * f.d;
    ret.simplificar();

    return ret;
}

Fracao Fracao::operator*(const Fracao& f) {
    Fracao ret(this->n * f.n, this->d * f.d);
    ret.simplificar();
    return ret;

    // da erro: return Fracao(this->n * f.n, this->d * f.d).simplificar();
}

Fracao Fracao::operator/(const Fracao& f) {
    Fracao ret(this->n * f.d, this->d * f.n);
    ret.simplificar();
    return ret;
    
    // da erro: return Fracao(this->n * f.d, this->d * f.n).simplificar();
}

Fracao Fracao::operator+(int i) {
    return *this + Fracao(i, 1);
}

Fracao operator+(int i, Fracao f) {
    return f + Fracao(i, 1);
}

Fracao Fracao::operator-(int i) {
    return *this - Fracao(i, 1);
}

Fracao operator-(int i, Fracao f) {
    return f - Fracao(i, 1);
}

Fracao Fracao::operator*(int i) {
    return *this * Fracao(i, 1);
}

Fracao operator*(int i, Fracao f) {
    return f * Fracao(i, 1);
}

Fracao Fracao::operator/(int i) {
    return *this / Fracao(i, 1);
}

Fracao operator/(int i, Fracao f) {
    return f / Fracao(i, 1);
}

Fracao::operator int() {
    return this->n / this->d;
}

Fracao::operator float() {
    return (float)this->n/this->d;
}

Fracao::operator double() {
    return (double)this->n/this->d;
}

Fracao::operator int() const {
    return this->n / this->d;
}

Fracao::operator float() const {
    return (float)this->n/this->d;
}

Fracao::operator double() const {
    return (double)this->n/this->d;
}

std::ostream& operator<<(std::ostream& os, const Fracao& f) {
    os << f.n << '/' << f.d;
    return os;
}

bool Fracao::operator < (const Fracao& f) {
    if ((double)*this < (double)f)
        return true;
    return false;
}

bool Fracao::operator > (const Fracao& f) {
    if ((double)*this > (double)f)
        return true;
    return false;
}

Fracao Fracao::operator ++ () {
    // ++f
    this->n += this->d;
    return *this;
}

Fracao Fracao::operator ++ (int) {
    // f++
    this->n += this->d;
    return Fracao(this->n - this->d, this->d);
}

Fracao Fracao::operator -- () {
    // --f
    this->n -= this->d;
    return *this;
}

Fracao Fracao::operator -- (int) {
    // f--
    this->n -= this->d;
    return Fracao(this->n + this->d, this->d);
}

Fracao& Fracao::operator+= (const Fracao& f) {
    *this = *this + f;
    return *this;
}

Fracao& Fracao::operator+= (int i) {
    *this = *this + i;
    return *this;
}

Fracao& Fracao::operator-= (const Fracao& f) {
    *this = *this + f;
    return *this;
}

Fracao& Fracao::operator-= (int i) {
    *this = *this - i;
    return *this;
}

bool Fracao::operator== (const Fracao& f) {
    Fracao a = *this;
    Fracao b = f;
    a.simplificar(); b.simplificar();
    if (a.n == b.n && a.d == b.d)
        return true;
    return false;
}
