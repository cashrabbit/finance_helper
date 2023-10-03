#include "fin_analysis.h"

char getMenuSelection(){
    char sel;
    bool valid = false;
    
    std::cout << "Please select an option: " << std:: endl;
    std::cout << "(A) Analyze existing file" << std::endl;
    std::cout << "(W) Write a new file" << std::endl;
    std::cout << "(B) Both write and analyze a new file" << std::endl;
    std::cout << "(X) Press X to exit the program" << std::endl;
    do{
    std::cout<< "\nWhich option would you like: ";
    std:: cin >> sel;
        if(std::cin.fail())
            sel = '.';

    sel = tolower(sel);
        switch(sel){
            case 'a':
            case 'w':
            case 'b':
            case 'x':
                valid = true;
                break;
            default:
                std::cout << "Input invalid. Try again" << std::endl;\
                valid= false;
                break;
        }
    }while(!valid);

    return sel;
}