#include <iostream>
#include <cstdlib>
#include <iterator>
#include <vector>
#include <cstdlib>
#include "Record.h"
using namespace std;

/*
  Class:    Property
  Purpose:  Template class that is specialized for the data type of that property

  Member function:  constructor
     Side effects:  Sets the value of the property class

  Member function:  destructor
     Side effects:  

  Member function:  operator []
          Purpose:  To return a record object at a specific location
               in:  location of record pointer in the vector
              out:  record pointer

  Member function:  operator +=
          Purpose:  To add a Record pointer to the record pointers vector
               in:  Record pointer
              out:  refrence of this property class

  Member function:  getPropSize
          Purpose:  return the size of the record pointer vector in this class
               in:  
              out:  size of the vector

  Member function:  getValue
          Purpose:  returns the value of te property class
               in:  
              out:  value
*/

template <class T>

class Property{
public:
  Property(T);
  ~Property();
  Record* operator[](size_t);
  Property<T>& operator +=(Record*&);
  size_t getPropSize();
  T& getValue();
private:
  T value;
  vector<Record*> properties;
};


//constuctor
template <class T>
Property<T>::Property(T v){
  value = v;


}

//destructor
template<class T>
Property<T>::~Property(){

}

template <class T>
T& Property<T>::getValue(){
  return value;
}


//overloading the += operator
template <class T>
Property<T>& Property<T>::operator+=(Record*& r){
    properties.push_back((r));
    return *this;

}

//overloading the [] operator
template <class T>
 Record* Property<T>::operator[](size_t s){
  if(s<0||s>= properties.size()){
    cerr<<"overflow"<<endl;
    exit(1);
  }
  return properties.at(s);
 }

template <class T>
size_t Property<T>:: getPropSize(){
  return properties.size();
}
