#include <fstream>
#include <string>
#include "fin_analysis.h"

char* makeNewFile(){
    std::ofstream make;

    double exp;
    char type;
    bool valType, valExp;
    char filename[50];
    int fileSize=0;
    char* file[50];

    std::cout << "enter .txt file name: "; 
    std:: cin >> filename;
    file[50] = filename;
    make.open(filename);
    
    make << "\n";

    do{
        valType = true;
        valExp = true; 

        do{
            std::cout << "Input expense category (f, e, r, g, c, m) or 'x' to quit: ";
            std::cin >> type;
            while(!(std::cin)){
                std::cin.clear();
                std::cin.ignore(50, '\n');
                std::cout << "Invalid input. Try again\n";
            }
            switch(type){
                case 'f':
                case 'e':
                case 'r':
                case 'g':
                case 'c':
                case 'm':
                case 'x': 
                    valType=true;
                    break;
                default:
                std::cout << "Invalid type try again\n";
                valType=false;
                break;
            }
            }while(!valType);
        if(type == 'x'){
            std::cout << "File completed. Goodluck" << std::endl;
            break;
        }
        do{
            std::cout << "Input expense: ";
            std::cin >>exp;
            while(!(std::cin)){
                std::cin.clear();
                std::cin.ignore(50, '\n');
                std::cout << "Invalid input. Please input a number\n";
            }
            exp = static_cast <double> (exp);
            if(0 > exp || 1000 < exp){
                std::cout << "Input positve, realistic expense: " << std::endl;
                valExp = false;
            }
            else
                valExp=true;
        }while(!valExp);

    make << exp << " " << type << "\n";
    fileSize+=1;
        }while(type !='x');
    make.seekp(0, std::ios_base::beg);
    make << "\n\n";
    make.seekp(0,std::ios_base::beg);
    make << fileSize << "\n";


    make.close();

    return file[50];
}