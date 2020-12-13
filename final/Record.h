#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <cstdlib>
using namespace std;

/*
  Class:    Record
  Purpose:  Makes a record object from year,region, degree, gender, numEmployed, numGrads.
  Member function:  constructor
     Side effects:  creates a record object from the data given


  Member function:  destructor
     Side effects:  

  Member function:  getYear
          Purpose:  getter for the year variable
              out:  year

  Member function:  getRegion
          Purpose:  getter for the region variable
              out:  region

  Member function:  getDegree
          Purpose:  getter for the degree variable
              out:  degree

  Member function:  getGender
          Purpose:  getter for the gender variable
              out:  gender

  Member function:  getNumGrads
          Purpose:  getter for the numGrads variable
              out:  numGrads

  Member function:  getNumEmployed
          Purpose:  getter for the numEmployed variable
              out:  numEmployed
*/
class Record
{
  public:
    Record(int = 0, string="", string="", string="", int = 0, int = 0);
    ~Record();
    int getYear();
    string getRegion();
    string getDegree();
    string getGender();
    int getNumGrads();
    int getNumEmployed();

  private:
     int year;
    const string region;
    const string degree;
    const string gender;
    const int numEmployed;
    const int numGrads;

};

#endif
