// ENCM 339 Fall 2016 - lab 8 - Exercise E
//  simpleVector.cpp

/*
 NOTES ON MEMORY ALLOCATION POLICIES FOR SimpleVector OBJECT:
 
 - If vector objects are supposed to be empty storageM will be NULL and the values
   of sizeM and capacityM must be set to zero.
 - If the objects of vector are supposed to be initialize with supplied values of
   an array, the size a and values in the dynamically memory space for storageM
   must be identical to the size and values in the supplied array. And, the
   values of sizeM and capacityM should be both set to the exact size of array.
 
- If any member function need to resize the vector, it should check the values of
  sizeM and capacityM:
  - If sizeM is equal to capacityM and vector is empty (i.e. capaictyM is equal to
    zero), capcityM should be changed to 2.
  - Otherwise, if sizeM is equal to capacityM, and capacityM is not zero (i.e.
    vector is NOT empty), the value of capacityM should be doubled up
  EXAMPLE: if capacityM is 5 and sizeM is also 5:
     1. the value of capacityM should be changed to 10.
     2. the dynamically allocated memory space for storageM should be reallocated
        to 10.
     3. The current values in the vector should be preserved and any unnecessary
        dynamically allocated memory must to deallocated.
*/

#include "simpleVector.h"
#include <cassert>
using namespace std;

SimpleVector::SimpleVector(const TYPE *arr, int n) {
    storageM = new TYPE[n];
    sizeM = n;
    capacityM = n;
    for(int i =0; i < sizeM; i++)
        storageM[i] = arr[i];
}

TYPE& SimpleVector::at(int i) {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}

const TYPE& SimpleVector::at(int i)const {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}


// The followng member function should follow the above-mentioned memory
// management policy to resize the vector, if necessary. More specifically:
//   - If sizeM < capacityM it doesn't need to make any changes to the size of
//     allocated memory for vector
//   - Otherwise it follows the above-mentioned memory policy to create additionl
//     memory space and adds the new value, val, to the end of the current vector
//     and increments the value of sizeM by 1
void SimpleVector::push_back(TYPE val) {
    
//  THIS FUNCTION MUST BE COMPLETED BY THE STUDENTS

  // Checking if there is space for val
  if(sizeM < capacityM) 
  {
    storageM[sizeM] = val;
    sizeM++;
    return;
  }
  // Checking if SimpleVector is empty
  else if (((sizeM || capacityM) == 0 ) && (storageM == 0) )
  { 
    capacityM = 2;
    storageM = new TYPE[capacityM];
    storageM[sizeM] = val; // sizeM = 0;
    sizeM++;
  }
  // Checking if SimpleVector has no more room
  else if (sizeM == capacityM)
  {
    int i = 0;
    capacityM *= 2;
    TYPE* temp = new TYPE[capacityM];

    while (i < sizeM)
    {
      temp[i] = storageM[i];
      i++;
    }
    temp[i] = val;
    sizeM++;
    delete [] storageM;
    storageM = temp;
  }
}


SimpleVector::SimpleVector(const SimpleVector& source) {
//  THIS FUNCTION MUST BE COMPLETED BY THE STUDENTS
  sizeM = 0;
  capacityM = source.capacityM;
  storageM = new TYPE[source.capacityM];

  while(sizeM < source.sizeM)
  {
    storageM[sizeM] = source.storageM[sizeM];
    sizeM++;
  }

}

SimpleVector& SimpleVector::operator= (const SimpleVector& rhs ){
//  THIS FUNCTION MUST BE COMPLETED BY THE STUDENTS    
  if (this != &rhs) // self-copy protection
  {
    delete [] storageM;
    sizeM = 0;
    capacityM = rhs.capacityM;
    storageM = new TYPE[rhs.capacityM];

    while(sizeM < rhs.sizeM)
    {
      storageM[sizeM] = rhs.storageM[sizeM];
      sizeM++;
    }

  }
  return *this;
}
