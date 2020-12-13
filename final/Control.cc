#include "Control.h"

Control::Control(){

}

Control::~Control(){
	for (size_t i = 0; i < Reports.size(); ++i)
	{
		delete Reports.at(i);
	}
	Reports.clear();

}

void Control::launch(){
	initReports(Reports);
	string output;
	size_t choice;
	 while (1) {
    view.showMenu(choice, Reports);
    if(choice == 0){
    	return;
    }else{
    	output = "";
    	Reports.at(choice-1)->execute(output);
    	view.printStr(output);
    }
    
  }
}

void Control::initReports(vector<ReportGenerator*>& r){
	r.push_back(new firstReport("Report on distribution of degrees by region"));
	r.push_back(new thirdReport("Report on the employment proportion for each region, by year compared to the total who were employed in Canada overall, for that same year"));
	r.push_back(new secondReport("Report on the top 3 and bottom 3 regions for percentage of female graduates"));
	r.push_back(new fourthReport("Report on the employment percentage for males with Bachelor and Master's by year, compared to the total who were employed for that same year"));
	r.push_back(new fifthReport("Report on the regions with number of females employed greater than 20,000 across all years and degrees"));
}