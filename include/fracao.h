#ifndef FRACAO_H
#define FRACAO_H

#include <iostream>  

class Fracao {
    public:
	Fracao();
        Fracao(int, int);
        Fracao(double);
        virtual ~Fracao();
        void setNumerador(int);
        void setDenominador(int);
        int getNumerador();
        int getDenominador();
        void simplificar();
        Fracao operator+(const Fracao&);
        Fracao operator-(const Fracao&);
        Fracao operator*(const Fracao&);
        Fracao operator/(const Fracao&);
        Fracao operator+(int);
        Fracao operator-(int);
        Fracao operator*(int);
        Fracao operator/(int);
        operator int();
        operator float();
        operator double();
        operator int() const;
        operator float() const;
        operator double() const;
        friend std::ostream& operator<<(std::ostream&, const Fracao&);
        bool operator < (const Fracao&);
        bool operator > (const Fracao&);
        Fracao operator++ ();
        Fracao operator++ (int);
        Fracao operator-- ();
        Fracao operator-- (int);
        Fracao& operator+= (const Fracao&);
        Fracao& operator+= (int);
        Fracao& operator-= (const Fracao&);
        Fracao& operator-= (int);
        bool operator==(const Fracao&);
    protected:
        int n;
        int d;
};

Fracao operator+(int, Fracao);
Fracao operator-(int, Fracao);
Fracao operator*(int, Fracao);
Fracao operator/(int, Fracao);

#endif
