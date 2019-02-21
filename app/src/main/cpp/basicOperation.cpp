//
// Created by thinhnguyen on 19/02/2019.
//

#include "basicOperation.h"


BasicOperation::~BasicOperation() {

}

BasicOperation::BasicOperation() {
}

Number BasicOperation::Add(Number no1, Number no2) {
    Number temp;
    temp.setReal(no1.getReal() + no2.getReal());
    temp.setImage(no1.getImage() + no2.getImage());
    return temp;
}
