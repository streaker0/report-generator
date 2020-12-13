#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(size_t& choice, vector<ReportGenerator*> &vect)
{
  cout << endl << endl;
  cout << "What report would you like to view:"<< endl;
  for(size_t i=0;i<vect.size(); ++i){
    cout<<"("<<i+1<<") "<< vect.at(i)->getName()<<endl;
  }
  cout << endl <<"Press  (0) to exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > vect.size()) {
   
    cout << "What report would you like to view:"<< endl;
    for(size_t i=0;i<vect.size(); ++i){
      cout<<"("<<i+1<<") "<< vect.at(i)->getName()<<endl;
    }
    cout << endl <<"Press  (0) to exit" << endl<<endl;
    cout << "Enter your selection: ";
    cin >> choice;
    if (choice == 0)
    return;
  }

}

void View::printStr(string str)
{
  cout << str;
}



