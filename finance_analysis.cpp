#include <iostream>
#include <fstream>

/*short _FOOD = 200.00;
short _RENT 800.00
short _ENT = 100.00;
short _CLEAN = 50.00;
short _GAS = 50.00;
short _MISC = 30.00;
*/
short _BUDGET = 1250.00;

int main(){
    
    char sel;
    char filename[50];
    int size;
    double spent=0, totalSpent=0, food=0, rent=0, ent=0, clean=0, gas=0, misc=0, remBudg=0;
    std::ifstream get;
    
    do{
    std::cout << "Which file?" << std::endl;
    std::cin >> filename;
    
    get.open(filename);
    
    if(!get)
        std::cout << "Input Valid File" << std::endl;
    }while(!get);
    
    get >> size; 
    
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

    get.close();

    std::cout << "Budget: " << _BUDGET << "\n\nTotal Spent: " << totalSpent << "\nRemaining Budget: " << remBudg << std::endl;
    std:: cout << "Rent: " << rent << "\nFood: " << food << "\nEntertainment: " << ent << "\nGas: " << gas << "\nCleaning: " << clean << "\nMisc: " << misc << std::endl; 
return 0;
}