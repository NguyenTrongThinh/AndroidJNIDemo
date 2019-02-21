//
// Created by thinhnguyen on 19/02/2019.
//

#ifndef NATIVEC_BASICOPERATION_H
#define NATIVEC_BASICOPERATION_H

#include "number.h"

class BasicOperation {
public:
    BasicOperation();

    virtual ~BasicOperation();

    Number Add(Number no1, Number no2);
};


#endif //NATIVEC_BASICOPERATION_H
