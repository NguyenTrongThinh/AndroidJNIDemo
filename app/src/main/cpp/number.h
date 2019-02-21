//
// Created by thinhnguyen on 19/02/2019.
//

#ifndef NATIVEC_NUMBER_H
#define NATIVEC_NUMBER_H


class Number {
public:
    Number(int real, int image);

    Number();

    virtual ~Number();

    Number operator=(const Number &number);

private:
    int real;
    int image;
public:
    int getReal() const;

    void setReal(int real);

    int getImage() const;

    void setImage(int image);

};


#endif //NATIVEC_NUMBER_H
