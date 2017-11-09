// Lab7String.cpp
// ENCM 339 - Fall 2017 - Exercise C

#include <assert.h>
#include <string.h>
#include "lab7String.h"

Lab7String::Lab7String()
: lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
    cout <<"default ctor called..." << &(*this) << "\n";
}

Lab7String::Lab7String(const char *s)
: lengthM((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
    cout <<"ctor called..." << &(*this) << "\n";
}

Lab7String::~Lab7String()
{
    delete [] storageM;
    cout <<"dtor called..." << &(*this) << "\n";
}

int Lab7String::length() const
{
    return lengthM;
}


const char * Lab7String::c_str() const
{
    return storageM;
}

void Lab7String::set_char(int pos, char c)
{
    assert(pos >= 0 && pos < length());
    assert(c != '\0');
    storageM[pos] = c;
}


