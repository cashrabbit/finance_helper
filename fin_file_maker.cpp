#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ofstream make;

    double exp;
    char type;
    bool valType, valExp;
    char filename[50];
    FILE * point;
    int fileSize;

    std::cout << "enter .txt file name: "; 
    std:: cin >> filename;
    point = make.open(filename);

    do{
        valType = true;
        valExp = true; 

        do{
            std::cout << "Input expense category (f, e, r, g, c, m) or 'x' to quit: ";
            std::cin >> type;
            while(!(std::cin)){
                std::cin.clear();
                std::cin.ignore(50, '\n');
                std::cout << "Invalid input. Please input a number\n";
            }
            switch(type){
                case 'f':
                case 'e':
                case 'r':
                case 'g':
                case 'c':
                case 'm':
                case 'x': break;
                default:
                std::cout << "Invalid type try again\n";
                valType=false;
                break;
            }
            }while(!valType);
        if(type == 'x'){
            std::cout << "File completed. Enjoy" << std::endl;
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
        }while(!valExp);

    make << exp << " ";
    make << type << "\n";
    fileSize+=1;

    fseek(point, 0, SEEK_SET);
    make << fileSize << "\n";
        }while(type !='x');

    make.close();

    return 0;
}