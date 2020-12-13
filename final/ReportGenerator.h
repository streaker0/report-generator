#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H
#include "Property.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
  
class ReportGenerator                                                   // Abstract class for the execute function
{
  protected:

    static vector<Record*> allRecords;
    static vector<Property<int>*> allYears;
    static vector<Property<string>*> allRegions;
    static vector<Property<string>*> allDegrees;
    static vector<Property<string>*> allGenders;

    static vector<int> uniqueYears;
    static vector<string> uniqueDegrees;
    static vector<string> uniqueRegions;
    static vector<string> uniqueGenders;

    string nameReport;

    static void loadAllData();
    static void loadYearData();
    static void loadRegionData();
    static void loadGenderData();
    static void loadDegreeData();
    static void deleteAllData();
    static void deleteRegionData();
    static void deleteYearData();


  public:
    ReportGenerator(string = "");
    virtual ~ReportGenerator();
    string getName();                                                 // returns the name of the report
    virtual void execute(string& outStr) =0;
};


  // concerete ReportGenerator class
class firstReport : public ReportGenerator                             
{ 
  public:
    firstReport(string="");
    virtual ~firstReport();
    virtual void execute(string& outStr);                             // generates a report on the employment percentage
                                                                      // for each region by degere for all years and genders
};


// concerete ReportGenerator class
class secondReport : public ReportGenerator
{
  private:
    /* 
    arranges the vector so that all the numbers to the left 
    of vector.at(j) is lesser than j and all the numbers to 
    the right of j is grater than j
    */
  static int partition(vector<double>&, int, int);  

  /* 
    recursively call sort on the left side of the partitioned j and the right side of the partitioned j
    */                 
  static void sort(vector<double>&, int, int);
  static vector<double> percentages;
  public:
    secondReport(string="");
    virtual ~secondReport();

    /* 
      generates a report for the top 3 and bottom 3 regions
      forpercentage of female graduates, for all years and
      all degrees

     */
    virtual void execute(string& outStr);
};

// concerete ReportGenerator class

class thirdReport : public ReportGenerator
{


  public:
    thirdReport(string="");
     virtual ~thirdReport();
    /* 
      generates a report for the employment proportion for each
      region, by year, for all degrees and all genders

     */
    virtual void execute(string& outStr);
};

// concerete ReportGenerator class

class fourthReport : public ReportGenerator
{
  public:
    fourthReport(string="");
     virtual ~fourthReport();

    /* 
      generates a report for the employment percentage for males with
      Bachelor and Master's by year, compared to the total who 
      were employed for that same year

     */
    virtual void execute(string& outStr);
};

// concerete ReportGenerator class

class fifthReport : public ReportGenerator
{
  public:
    fifthReport(string="");
     virtual ~fifthReport();
    /* 
      generates a report for the regions with number of
       females employed greater than 20,000 across all 
       years and degrees

     */
    virtual void execute(string& outStr);
};



#endif
