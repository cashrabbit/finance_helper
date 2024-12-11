#include "Transaction.h"


Transaction::Transaction(){
    label = "";
    amount = 0.0;
    isIncome = false;
    category = '\0';
}

Transaction::Transaction(std::string l, double a, bool i, char c){
    label = l;
    amount = a;
    isIncome = i;
    category = c;
}

Transaction::Transaction(Transaction& t){
    label = t.label;
    amount = t.amount;
    isIncome = t.isIncome;
    category = t.category;
}
void printCategory(char cat){
    return catToCatLabel(c);
}

void Transaction::print() const{
    std::cout << label;
    std::cout << "\t$" << std::fixed << std::setprecision(2) << amount;
    std::cout <<"\t";
    printCategory(category);
    std::cout << "\n\n";
}

std::string Transaction::getLabel() const{
    return label;
}
double Transaction::getAmount() const{
    return amount;
}
bool Transaction::isItIncome() const{
    return isIncome;
}
char Transaction::getCategory() const{
    return category;
}

std::string catToCatLabel(char c){
    std::string catLabel;

    switch(cat){
        case 'a':
            catLabel = "Alcohol";
            break;
        case 'b':
            catLabel = "Tickets/Fines";
            break;
        case 'c':
            catLabel = "Comfort";
            break;
        case 'd':
            catLabel = "Dates";
            break;
        case 'e':
            catLabel = "Entertainment";
            break;
        case 'f':
            catLabel = "Food";
            break;
        case 'g':
            catLabel = "Gas";
            break;
        case 'h':
            catLabel = "Hygiene";
            break;
        case 'i':
            catLabel = "Wi-Fi";
            break;
        case 'l':
            catLabel = "Lady Gifts";
            break;
        case 'm':
            catLabel = "Family Gifts";
            break;
        case 'o':
            catLabel = "Going Out";
            break;
        case 'r':
            catLabel = "Rent";
            break;
        case 't':
            catLabel = "Travel";
            break;
        case 'u':
            catLabel = "Utilities";
            break;
        case 'y':
            catLabel = "Tree/Psychs";
            break;
        default:
            catLabel = "CategoryInputError";
            break;
    }

    return catLabel;
}