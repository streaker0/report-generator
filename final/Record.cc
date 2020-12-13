
#include "Record.h"
#include <string>

Record::Record(int y, string r, string d, string g, int nE, int nG)
  : year(y), region(r), degree(d), gender(g), numEmployed(nE), numGrads(nG)
{

}

Record::~Record()
{

}
int Record::getYear(){
  return year;
}

string Record::getRegion(){
  return region;
}
string Record::getDegree(){
  return degree;
}
string Record::getGender(){
	return gender;
}
int Record::getNumGrads(){
  return numGrads;
}
int Record::getNumEmployed(){
  return numEmployed;
}

