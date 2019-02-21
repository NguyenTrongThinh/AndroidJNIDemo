//
// Created by thinhnguyen on 19/02/2019.
//

#include <jni.h>
#include "number.h"
#include "basicOperation.h"


extern "C" JNIEXPORT jobject JNICALL
Java_com_example_nativec_MainActivity_Add(JNIEnv *env, jobject unusedObject, jobject no1,
                                          jobject no2) {
    Number complex1, complex2, complex3;
    BasicOperation operation;
    //Java class to c++ class
    jclass num1 = env->GetObjectClass(no1);
    jclass num2 = env->GetObjectClass(no2);
    jmethodID num1MethodIDgetReal = env->GetMethodID(num1, "getReal", "()I");
    jmethodID num1MethodIDgetImage = env->GetMethodID(num1, "getImage", "()I");
    jmethodID num2MethodIDgetReal = env->GetMethodID(num2, "getReal", "()I");
    jmethodID num2MethodIDgetImage = env->GetMethodID(num2, "getImage", "()I");
    complex1.setReal(env->CallIntMethod(no1, num1MethodIDgetReal));
    complex2.setReal(env->CallIntMethod(no2, num2MethodIDgetReal));
    complex1.setImage(env->CallIntMethod(no1, num1MethodIDgetImage));
    complex2.setImage(env->CallIntMethod(no2, num2MethodIDgetImage));
    complex3.setReal(complex1.getReal() + complex2.getReal());
    complex3.setImage(complex1.getImage() + complex2.getImage());
    //C++ class to java class
    jclass numberClass = env->FindClass("Lcom/example/nativec/Number;");
    jmethodID midConstructor = env->GetMethodID(numberClass, "<init>", "(II)V");
    jobject complexObject = env->NewObject(numberClass, midConstructor, complex3.getReal(),
                                           complex3.getImage());
    return complexObject;
}