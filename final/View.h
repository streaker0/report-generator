#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;
#include "ReportGenerator.h"


/*
  Class:    View
  Purpose:  reads input from the user and print output to the screen


  Member function:  showMenu
          Purpose:  receives a choice of the report to be printed
              out:  size_t choice of report to print
               in:  vector of report pointers

  Member function:  printStr
          Purpose:  prints a string to the user
               in:  string to be printed
*/

class View
{
  public:
    void showMenu(size_t&, vector<ReportGenerator*>&);
    void printStr(string);

};

#endif