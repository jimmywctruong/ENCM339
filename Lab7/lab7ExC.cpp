// ENCM 339 - Fall 2017 - Exercise C
// lab7ExC.cpp

#include "lab7String.h"

int main()
{
    // There are unsed varibales in this code, you may ignore the
    // compiler warnings for these cases, as we would rather to keep this exercise
    // relatively simple and short.
    
    Lab7String a("Hi");
    Lab7String *p;
    cout << "a: " << &a << "\n";
    
    {
        Lab7String d[2];
        cout << "d[0]: " << &d << "\n";
        cout << "d[1]: " << &d[1] << "\n";
        Lab7String b("red");
        cout << "b: " << &b << "\n";
        Lab7String *c = new Lab7String("glue");
        cout << "c: " << &(*c) << "\n";
        Lab7String *g = new Lab7String ("Blue");
        cout << "g: " << &(*g) << "\n";
        p = g;
        cout << "p: " << &(*p) << "\n";
        delete c;
    }
    
    delete p;

    return 0;
}

