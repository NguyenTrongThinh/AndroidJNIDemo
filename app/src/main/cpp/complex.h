//
// Created by thinhnguyen on 25/02/2019.
//

#ifndef NATIVEC_COMPLEX_H
#define NATIVEC_COMPLEX_H


#include <ostream>

class Complex {
private:
    double real;
    double image;

public:
    friend std::ostream &operator<<(std::ostream &os, const Complex &complex);

public:
    bool operator==(const Complex &rhs) const;

    bool operator!=(const Complex &rhs) const;

    Complex operator+(const Complex &rhs) const;

public:
    virtual ~Complex();

public:

    Complex(double real, double image);

    Complex();

    double getReal() const;

    double getImage() const;

    void setReal(double real);

    void setImage(double image);


};


#endif //NATIVEC_COMPLEX_H
