
#include <iostream>
#include <fstream>
#include <string>
#include "ReportGenerator.h"
#define MAX_FEMALES 3 //number of top regions of females graduates percentages
#define MIN_FEMALES 3	//number of bottom  regions of females graduates percentages

#define NUM_EMPLOYED_FEMALES 20000 // minimum number used to check number of employed females in each region

 vector<Record*> ReportGenerator:: allRecords;
 vector<Property<int>*> ReportGenerator:: allYears;
 vector<Property<string>*> ReportGenerator::allRegions;
 vector<Property<string>*> ReportGenerator::allDegrees;
 vector<Property<string>*> ReportGenerator::allGenders;
 vector<int> ReportGenerator::uniqueYears;
 vector<string> ReportGenerator::uniqueDegrees;
 vector<string> ReportGenerator::uniqueRegions;
 vector<string> ReportGenerator::uniqueGenders;
 vector<double> secondReport::percentages;

 ReportGenerator::ReportGenerator(string n):nameReport(n){
 }

ReportGenerator::~ReportGenerator(){
}

void ReportGenerator::deleteAllData(){
	for (size_t i = 0; i < allRecords.size(); ++i)
	{
		delete allRecords[i];
	}
	allRecords.clear();
}
void ReportGenerator::deleteRegionData(){
	for (size_t i = 0; i < allRegions.size(); ++i)
	{
		delete allRegions.at(i);
	}
	allRegions.clear();

}
void ReportGenerator::deleteYearData(){
	for (size_t i = 0; i < allYears.size(); ++i)
	{
		delete allYears.at(i);
	}
	allYears.clear();

}

 void ReportGenerator::loadAllData(){
 	int year;
  	string region;
 	string degree;
  	string gender;
  	int numEmployed;
  	int numGrads;

 	ifstream infile("grad.dat",ios::in);

  if(!infile){
    cout<<"Error: could not open file"<<endl;
    exit(1);
  }
  while(infile>> year >> region >> degree >> gender >> numEmployed >> numGrads ){
  		bool foundYear = false;
  		bool foundRegion = false;
  		bool foundDegree = false;
  		bool foundGender = false;
  		for(size_t i =0; i<uniqueYears.size();++i){
  			if(year == uniqueYears.at(i)){
  				foundYear = true;
  			}
  		}
  		if(!foundYear){
  			uniqueYears.push_back(year);
  		}
  		for(size_t i =0; i<uniqueRegions.size();++i){
  			if(region == uniqueRegions.at(i)){
  				foundRegion = true;
  			}
  		}
  		if(!foundRegion){
  			uniqueRegions.push_back(region);
  		}
  		for(size_t i =0; i<uniqueDegrees.size();++i){
  			if(degree == uniqueDegrees.at(i)){
  				foundDegree = true;
  			}
  		}
  		if(!foundDegree){
  			uniqueDegrees.push_back(degree);
  		}
  		for(size_t i =0; i<uniqueGenders.size();++i){
  			if(gender == uniqueGenders.at(i)){
  				foundGender = true;
  			}
  		}
  		if(!foundGender){
  			uniqueGenders.push_back(gender);
  		}
    allRecords.push_back(new Record (year,region, degree,gender,numEmployed,numGrads));
  }

 }
 string ReportGenerator::getName(){
 	return nameReport;
 }

 void ReportGenerator::loadYearData(){
	for(size_t i =0; i<uniqueYears.size();++i){
  		allYears.push_back(new Property<int>(uniqueYears.at(i)));
  		for (size_t j =0; j<allRecords.size();++j){
  			if((allRecords.at(j)->getYear() == uniqueYears.at(i))){
  				*(allYears.at(i))+= allRecords.at(j);
  			}
  			
  		}

  	}
 }

 void ReportGenerator::loadRegionData(){
 	for(size_t i =0; i<uniqueRegions.size();++i){
  		allRegions.push_back(new Property<string>(uniqueRegions.at(i)));
  		for (size_t j =0; j<allRecords.size();++j){
  			if((allRecords.at(j)->getRegion() == uniqueRegions.at(i))){
  				*(allRegions.at(i))+= allRecords.at(j);
  			}
  			
  		}

  	}
 }

 void ReportGenerator::loadGenderData(){
 	 for(size_t i =0; i<uniqueDegrees.size();++i){
  		allDegrees.push_back(new Property<string>(uniqueDegrees.at(i)));
  		for (size_t j =0; j<allRecords.size();++j){
  			if((allRecords.at(j)->getDegree() == uniqueDegrees.at(i))){
  				*(allDegrees.at(i))+= allRecords.at(j);
  			}
  			
  		}

  	}

 }
 void ReportGenerator::loadDegreeData(){
 	for(size_t i =0; i<uniqueGenders.size();++i){
  		allGenders.push_back(new Property<string>(uniqueGenders.at(i)));
  		for (size_t j =0; j<allRecords.size();++j){
  			if((allRecords.at(j)->getGender() == uniqueGenders.at(i))){
  				*(allGenders.at(i))+= allRecords.at(j);
  			}
  			
  		}

  	}

 }

 int secondReport::partition(vector<double> &numbers, int left, int right){
 	int pivot = right;
 	int j =left;
 	for (int i = left; i < right; ++i)
 	{
 		if(numbers[i]<numbers[pivot]){
 			double temp = numbers[i];
 			numbers[i] = numbers[j];
 			numbers[j] = temp;
 			++j;
 		}
 	}
 	double tempi = numbers[j];
 	numbers[j] = numbers[pivot];
 	numbers[pivot] = tempi;
 	return j;
 }
 void secondReport::sort(vector<double> &numbers, int left, int right){
 	if(left<right){
 		int pivot = secondReport::partition(numbers,left,right);
 		secondReport::sort(numbers,left,pivot-1);
 		secondReport::sort(numbers,pivot+1,right);
 	}
 }



 firstReport::firstReport(string n):ReportGenerator(n){

 	
 }
 firstReport::~firstReport(){
 	
 }

 void firstReport::execute(string& outStr){
 	ReportGenerator::loadAllData();
 	ReportGenerator::loadRegionData();
 	stringstream ss;
  	ss <<"The record for employment percentage by degree for each region:"<<endl;
  	ss<< "starts here: "<<endl<<endl;
  	
  	ss<<"\t";
  	for(size_t j=0; j<uniqueDegrees.size();++j){
  		ss<<setw(10)<<uniqueDegrees.at(j)<<"\t \t";
  	}
  	ss<<endl;
  	
  	for(size_t i=0;i<allRegions.size();++i){
  		ss<<allRegions.at(i)->getValue()<<"\t";
  		for(size_t j=0; j<uniqueDegrees.size();++j){
  			double totalGrad = 0;
  			double totalEmployed =0;
  			double percentage =0;
  			for(size_t k =0; k<allRegions.at(i)->getPropSize();++k){
  				Property<string> props = *(allRegions.at(i));
  				if((props[k]->getDegree() == uniqueDegrees.at(j))&&(props[k]->getGender() == "All")){
  					totalGrad = totalGrad + props[k]->getNumGrads();
  					totalEmployed = totalEmployed + props[k]->getNumEmployed();
  				}
  			}
  			if(totalEmployed !=0 && totalGrad !=0){
  				percentage = totalEmployed/totalGrad;
  				percentage = percentage * 100;
  			}
  			
  			ss<<setw(10)<<fixed<<setprecision(2)<<percentage;
  			ss<<"%"<<"\t \t";
  		}
  		ss<<endl;

  	}
  	outStr = ss.str();
  	ReportGenerator::deleteRegionData();
  	ReportGenerator::deleteAllData();


}

 secondReport::secondReport(string n):ReportGenerator(n){
 	
 }
 secondReport::~secondReport(){

 }

void secondReport::execute(string& outStr){
	ReportGenerator::loadAllData();
 	ReportGenerator::loadRegionData();

  	stringstream ss;
  	ss << "The top 3 and bottom 3 regions for percentage of female graduates, for all years and degrees";
  	ss<<endl<<endl;

  	
  	
  	for(size_t i=0;i<allRegions.size();++i){
  		double totalFemales = 0;
  		double totalGraduated =0;
  		double percentage =0;
  		for(size_t j=0; j<uniqueGenders.size();++j){
  			for(size_t k =0; k<allRegions.at(i)->getPropSize();++k){
  				Property<string> props = *(allRegions.at(i));
  				if(props[k]->getGender() == "Females"){
  					totalFemales = totalFemales + props[k]->getNumGrads();
  				}
  				else if(props[k]->getGender() == "All"){
  					totalGraduated = totalGraduated + props[k]->getNumGrads();
  				}
  			}
  		}
		if(totalFemales !=0 && totalGraduated !=0){
			percentage = totalFemales/totalGraduated;
			percentage = percentage * 100;
			percentages.push_back(percentage);
		}
		
  	}

  	secondReport::sort(percentages, 0, percentages.size()-1);

  	for(size_t x =percentages.size();x-->0;){
  		for(size_t i=0;i<allRegions.size();++i){
	  		double totalFemales = 0;
	  		double totalGraduated =0;
	  		double percentage =0;
	  		// cout<<allRegions.at(i)->getValue()<<"\t"<<endl;
	  		for(size_t j=0; j<uniqueGenders.size();++j){
	  			for(size_t k =0; k<allRegions.at(i)->getPropSize();++k){
	  				Property<string> props = *(allRegions.at(i));
	  				if(props[k]->getGender() == "Females"){
	  					totalFemales = totalFemales + props[k]->getNumGrads();
	  				}
	  				else if(props[k]->getGender() == "All"){
	  					totalGraduated = totalGraduated + props[k]->getNumGrads();
	  				}
	  			}
	  		}
	  // 		
			if(totalFemales !=0 && totalGraduated !=0){
				percentage = totalFemales/totalGraduated;
				percentage = percentage * 100;
				if(percentage == percentages.at(x)){
					if(x == percentages.size()-1){
						ss<<"The top "<<MAX_FEMALES<<" regions for percentage female graduates are:"<<endl;
					}
					if(x>(percentages.size()-1 - MAX_FEMALES)){
						ss<< allRegions.at(i)->getValue()+":";
						ss<<setw(10)<<fixed<<setprecision(2)<<percentage;
						ss<<"%"<<"\t \t";
	  					ss<<endl;
					}
					if(x == MIN_FEMALES-1){
						ss<<endl<<"The bottom "<<MIN_FEMALES<<" regions for percentage female graduates are:"<<endl;
					}
					if(x<(MIN_FEMALES)){
						ss<< allRegions.at(i)->getValue()+":";
						ss<<setw(10)<<fixed<<setprecision(2)<<percentage;
						ss<<"%"<<"\t \t";
	  					ss<<endl;
					}
					
				}
			}
			
			
  		}

  	}
  	outStr = ss.str();
  	ReportGenerator::deleteRegionData();
  	ReportGenerator::deleteAllData();

}

thirdReport::thirdReport(string n):ReportGenerator(n){
 }

 thirdReport::~thirdReport(){

 }
void thirdReport::execute(string& outStr){
	ReportGenerator::loadAllData();
 	ReportGenerator::loadRegionData();
  	stringstream ss;
  	ss <<"The employment proportion for each region, by year, for all degrees and all genders compared to the total who were employed in Canada overall, for that same year:"<<endl;
  	ss<< "starts here: "<<endl<<endl;
  	ss<<"\t";
  	for(size_t j=0; j<uniqueYears.size();++j){
      ss<<setw(10)<<uniqueYears.at(j)<<"\t \t";
    }
    ss<<endl;
    vector<int> eachYearCanEmployed;
    for(size_t i=0;i<allRegions.size();++i){
    	
    	if(allRegions.at(i)->getValue() == "CAN"){
    		for(size_t j=0; j<uniqueYears.size();++j){
    			int candadianSpecificYear =0;
    			for(size_t k =0; k<allRegions.at(i)->getPropSize();++k){
    				Property<string> pro = *(allRegions.at(i));
	    		
	    			if(pro[k]->getYear() == uniqueYears.at(j)){
	    				candadianSpecificYear += pro[k]->getNumEmployed();
	    				
	    			}
	    		}
	    		eachYearCanEmployed.push_back(candadianSpecificYear );
    		}

    	}
    }

  	for(size_t i=0;i<allRegions.size();++i){
  		ss<<allRegions.at(i)->getValue()<<"\t";
  		for(size_t j=0; j<uniqueYears.size();++j){
  			double totalGrad = 0;
  			double totalEmployed =0;
  			double percentage =0;
  			for(size_t k =0; k<allRegions.at(i)->getPropSize();++k){
  				Property<string> props = *(allRegions.at(i));
  				if(props[k]->getYear() == uniqueYears.at(j)){
  					totalGrad = totalGrad + props[k]->getNumGrads();
  					totalEmployed = totalEmployed + props[k]->getNumEmployed();
  				}
  			}
  			if(totalEmployed !=0 && totalGrad !=0){
  				percentage = totalEmployed/(1.0*eachYearCanEmployed.at(j));
  				percentage = percentage * 100;
  			}
  			ss<<setw(10)<<fixed<<setprecision(2)<<percentage;
        	ss<<"%"<<"\t \t";
  		}
  		ss<<endl;
  	}

  	outStr = ss.str();
  	ReportGenerator::deleteRegionData();
  	ReportGenerator::deleteAllData();

}


 fourthReport::fourthReport(string n):ReportGenerator(n){

 	
 }
 fourthReport::~fourthReport(){
 	
 }

 void fourthReport::execute(string& outStr){
	ReportGenerator::loadAllData();
 	ReportGenerator::loadYearData();
 	stringstream ss;
 	ss <<"The employment percentage for males with Bachelor and Master's by year, compared to the total who were employed for that same year:"<<endl;
  	ss<< "starts here: "<<endl<<endl;
  	ss<< "\t"<<setw(10) <<"Bachelor's"<<"\t \t"<<setw(10)<<"Master's"<<endl;
 	for(size_t i=0;i<allYears.size();++i){
 		ss<<allYears.at(i)->getValue()<<"\t";
 		double totalMaleBachelors =0;
 		double totalMaleMasters =0;
 		double totalMaleEmployed=0;
 		for(size_t k =0; k<allYears.at(i)->getPropSize();++k){
 			Property<int> props = *(allYears.at(i));
 			if(props[k]->getGender() == "Males"){
 				totalMaleEmployed = totalMaleEmployed + props[k]->getNumEmployed();
 				if(props[k]->getDegree() == "Bachelor's"){
 					totalMaleBachelors = totalMaleBachelors +props[k]->getNumEmployed();
 				}else if(props[k]->getDegree() == "Master's"){
 					totalMaleMasters = totalMaleMasters +props[k]->getNumEmployed();
 				}
 			}

 		}
 		ss<<setw(10)<<fixed<<setprecision(2)<<(totalMaleBachelors/totalMaleEmployed)*100<<"%"<<"\t \t"<<setw(10)<<fixed<<setprecision(2)<<(totalMaleMasters/totalMaleEmployed)*100<<"%"<<endl;

 	}

 	outStr = ss.str();

 	ReportGenerator::deleteYearData();
  	ReportGenerator::deleteAllData();
 }


  fifthReport::fifthReport(string n):ReportGenerator(n){

 	
 }
 fifthReport::~fifthReport(){
 	
 }

 void fifthReport::execute(string& outStr){
	ReportGenerator::loadAllData();
 	ReportGenerator::loadRegionData();
 	stringstream ss;
 	ss<<"The regions with number of females employed greater than 20,000 across all years and degrees are:"<<endl<<endl;
 	for(size_t i=0;i<allRegions.size();++i){
  			double totalEmployed =0;
  			for(size_t k =0; k<allRegions.at(i)->getPropSize();++k){
  				Property<string> props = *(allRegions.at(i));
  				if(props[k]->getGender() == "Females"){
  					totalEmployed = totalEmployed + props[k]->getNumEmployed();
  				}
  			}
  			if(totalEmployed >NUM_EMPLOYED_FEMALES){
  				ss<<allRegions.at(i)->getValue()<<"\t";
  				ss<<setw(10)<<totalEmployed;
        		ss<<"\t \t";
        		ss<<endl;
  			}
  		
  	}

  	outStr = ss.str();
 	ReportGenerator::deleteRegionData();
  	ReportGenerator::deleteAllData();
 }
