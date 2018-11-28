#ifndef FRACAO_H
#define FRACAO_H

#include <iostream>  

class Fracao {
    public:
        Fracao(int, int);
        ~Fracao();
        void setNumerador(int);
        void setDenominador(int);
        int getNumerador();
        int getDenominador();
        void simplificar();
        Fracao operator+(const Fracao&);
        Fracao operator-(const Fracao&);
        Fracao operator*(const Fracao&);
        Fracao operator/(const Fracao&);
        friend std::ostream& operator<<(std::ostream&, const Fracao&);
    protected:
        int n;
        int d;
};

#endif