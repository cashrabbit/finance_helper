#include <fstream>
#include "fin_analysis.h"

short _BUDGET = 1250.00;

int analyze(int size, std::ifstream& get){
    char sel;
    double spent=0, totalSpent=0, food=0, rent=0, ent=0, clean=0, gas=0, misc=0, remBudg=0;
    for(int i=1; i<size; i++){
     get>>spent;
     get>>sel;
    
     totalSpent += spent;
     switch(sel){
         case 'f':
             food += spent;
             break;
         case 'e':
             ent += spent;
             break;
         case 'r':
             rent += spent;
             break;
         case 'g':
             gas += spent;
             break;
         case 'c':
             clean += spent;
             break;
         case 'm':
             misc += spent;
             break;
     }
     remBudg = _BUDGET - totalSpent;
    }
    std::cout << "Budget: " << _BUDGET << "\n\nTotal Spent: " << totalSpent << "\nRemaining Budget: " << remBudg << std::endl;
    std:: cout << "Rent: " << rent << "\nFood: " << food << "\nEntertainment: " << ent << "\nGas: " << gas << "\nCleaning: " << clean << "\nMisc: " << misc << std::endl;     
}

void runAnalysis(){
    char filename[50];
    int size;
    std::ifstream get;
    
        do{
            std::cout << "Which file?" << std::endl;
            std::cin >> filename;
    
            get.open(filename);
    
            if(!get)
                std::cout << "Input Valid File" << std::endl;
        }while(!get);
        get >> size; 
        analyze(size, get);
        get.close();
}        

void runAnalysis(char filename[50]){    
    int size;
    std::ifstream get;
    
    get.open(&filename[50]);
    get >> size; 
    analyze(size, get);
    get.close();
}