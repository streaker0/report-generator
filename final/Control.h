#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include "View.h"

/*
  Class:    Control
  Purpose:  contols the flow of input and output

  Member function:  constructor
     Side effects:  

  Member function:  destructor
     Side effects: 

  Member function:  launch
          Purpose:  gets a choice of report  to display from the user 
                    then displays the report back to te user

  Member function:  initReports
          Purpose:  initializes reports to the vector of report pointers
               in:  vector of report pointers
*/

class Control
{
  public:
    Control();
    ~Control();
    void launch(); 

  private:
    void initReports(vector<ReportGenerator*>& );
    View view;
    vector<ReportGenerator*> Reports;
};
#endif