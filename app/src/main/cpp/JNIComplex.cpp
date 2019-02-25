//
// Created by thinhnguyen on 25/02/2019.
//

#include <jni.h>
#include "complex.h"

extern "C" JNIEXPORT jobject JNICALL
Java_com_example_nativec_MainActivity_Add(JNIEnv *env, jobject unusedObject, jobject no1,
                                          jobject no2) {
    Complex complex1, complex2, complex3;
    //Java class to c++ class
    jclass num1 = env->GetObjectClass(no1);
    jclass num2 = env->GetObjectClass(no2);
    jmethodID num1MethodIDgetReal = env->GetMethodID(num1, "getReal",
                                                     "()D"); //getReal in Java Class
    jmethodID num1MethodIDgetImage = env->GetMethodID(num1, "getImage", "()D");
    jmethodID num2MethodIDgetReal = env->GetMethodID(num2, "getReal", "()D");
    jmethodID num2MethodIDgetImage = env->GetMethodID(num2, "getImage", "()D");
    complex1.setReal(env->CallDoubleMethod(no1, num1MethodIDgetReal));
    complex1.setImage(env->CallDoubleMethod(no1, num1MethodIDgetImage));

    complex2.setReal(env->CallDoubleMethod(no2, num2MethodIDgetReal));
    complex2.setImage(env->CallDoubleMethod(no2, num2MethodIDgetImage));
    complex3 = complex1 + complex2;
    //C++ class to java class
    jclass numberClass = env->FindClass("com/example/nativec/Complex");

    jmethodID midConstructor = env->GetMethodID(numberClass, "<init>", "(DD)V");
    jobject complexObject = env->NewObject(numberClass, midConstructor, complex3.getReal(),
                                           complex3.getImage());
    return complexObject;
}