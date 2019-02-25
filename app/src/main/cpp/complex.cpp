//
// Created by thinhnguyen on 25/02/2019.
//

#include "complex.h"

double Complex::getReal() const {
    return real;
}

double Complex::getImage() const {
    return image;
}

Complex::Complex(double real, double image) : real(real), image(image) {}

Complex::~Complex() {

}

void Complex::setReal(double real) {
    Complex::real = real;
}

void Complex::setImage(double image) {
    Complex::image = image;
}

bool Complex::operator==(const Complex &rhs) const {
    return real == rhs.real &&
           image == rhs.image;
}

bool Complex::operator!=(const Complex &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Complex &complex) {
    os << "real: " << complex.real << " image: " << complex.image;
    return os;
}

Complex Complex::operator+(const Complex &rhs) const {
    Complex result(0, 0);
    result.real = this->real + rhs.real;
    result.image = this->image + rhs.image;
    return result;
}

Complex::Complex() {
    this->real = 0;
    this->image = 0;
}
