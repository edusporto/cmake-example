#ifndef FRACAO_H
#define FRACAO_H

#include <iostream>  

class Fracao {
    public:
	Fracao();
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
        operator int();
        operator float();
        operator double();
        operator int() const;
        operator float() const;
        operator double() const;
        friend std::ostream& operator<<(std::ostream&, const Fracao&);
        bool operator < (const Fracao&);
        bool operator > (const Fracao&);
    protected:
        int n;
        int d;
};

#endif
