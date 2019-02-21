//
// Created by thinhnguyen on 19/02/2019.
//

#include "number.h"


int Number::getReal() const {
    return real;
}

void Number::setReal(int real) {
    Number::real = real;
}

int Number::getImage() const {
    return image;
}

void Number::setImage(int image) {
    Number::image = image;
}

Number::Number(int real, int image) : real(real), image(image) {}

Number::~Number() {

}

Number::Number() {}

Number Number::operator=(const Number &number) {

    Number rnumber;
    rnumber.setImage(number.getImage());
    rnumber.setReal(number.getReal());
    return rnumber;
}
