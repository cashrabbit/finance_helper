#include "Transaction.h"

int main(){
    //variable declarations
    char selection;
    std::string filename;

    std::cout << "Input the file name in this format(month.year): ";
    std::cin >> filename;


    selection = menu();
    switch(selection){
        case 'A':
            addTransactions(filename);
            break;
        case ' V':
            viewTransactions(filename);
            break;
        case 'G':
            analyzeList(filename);
            break;
        case 'M':

            break;
        default:
            break;
    }
    return 0;
}

char menu(){
    char sel;
    bool valid = false;

    std::cout << "(A) Add transactions\n"
    std::cout << "(V) View a list of tranactions\n";
    std::cout << "(G) Get Analysis of a list\n";
    std::cout << "(M) Get Analysis of multiple lists\n";
    std::cout << "(Q) Quit\n";

    if(isalpha(sel))
        toupper(sel);
    do{
        std::cout << "Select a menu option: ";
        cin >> sel;

        switch(sel){
            case 'A':
            case 'V':
            case 'G':
            case 'M':
            case 'Q':
                valid = true;
            default:
                std::cout << "Invalid Input. Try again\n\n";
                break;
        }
    }while(!valid);

    return sel;
}

void addTransaction(std::string file){
    std::string label;
    double amount;
    char category, incomeResponse;
    bool isIncome;

    std::cout << "Label: ";
    std::cin >> label;

    std::cout << "Amount: ";
    std::cin >> amount;

    do{
    std::cout << "Is this income (Y/N)";
    std::cin >> incomeResponse;
    toupper(incomeResponse);
    }while(incomeResponse != 'Y' && incomeResponse != 'N');
    isIncome = (incomeResponse == 'Y');

    std::cout << "Category: ";
    std::cin >> category;

    Transaction t(label, amount, isIncome, category);

    std::ofstream os(file, std::ios::binary);

    if (!os) {
        std::cerr << "Failed to write to file!" << std::endl;
        return 1;
    }

    cereal::BinaryOutputArchive archiveOut(os);

    archiveOut(t);
    os.close();
}

void viewTransactions(std::string file){
    do{
        Transaction t;
        // Create an output file stream
        std::ifstream is(file, std::ios::binary);

        if (!is) {
            std::cerr << "Failed to open file for reading!" << std::endl;
            return 1;
        }   


    cereal::BinaryInputArchive archiveIn(is);

    archiveIn(t);

    t.print();
    }while(is,peek() != EOF);
}

void analyzeList(std::string file){
    std::vector<int> list;
    std::vector<char> charList;
    double totalSpent, totalEarned, balance;
    int transactionCount;

    totalSpent = 0.0;
    totalEarned = 0.0;
    balance = 0.0;
    transactionCount = 0;

    do{
        Transaction t;
        // Create an output file stream
        std::ifstream is(file, std::ios::binary);

        if (!is) {
            std::cerr << "Failed to open file for reading!" << std::endl;
            return 1;
        }   

        cereal::BinaryInputArchive archiveIn(is);

        archiveIn(t);
    
        transactionCount++;

        if(isIncome)
            totalIncome += t.getAmount();
        else
            totalSpent -= t.getAmount;
        if(list.size() > 0){
            bool repeat = false;

            for(int i = 0; i < list.size(); i++){
                if(charList[i] == t.getCategory()){
                    repeat = true;
                    list[i] += t.getAmount;
                }
            }
            if(!repeat){
                list.push_back(t.getAmount());
                charList.push_back(t.getCategory());
            }
        }
        else{
            list.push_back(t.getAmount());
            charList.push_back(t.getCategory());
        }

    }while(is,peek() != EOF);

    balance = totalSpent + totalEarned;

    std::cout << "\t\t\tMonthly Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    std::cout << "Monthly Earned: $" << std::fixed << std::setprecision(2) << totalEarned << std::endl;
    std::cout << "Monthly Spent: $" << std::fixed << std::setprecision(2) << totalSPent << std::endl << std::endl;
    std::cout << "Categories: \n";
    for(inr i = 0; i < list.size(); i++){
        std::cout << catToCatLabel(charList[i]) << ": \t$" << std::fixed << std::setprecision(2) << list[i];
        if(t.isItIncome())
            std::cout << std::fixed << std::setprecision(2) << (list[i]/totalEarned * 100) << "% of Income\n";
        else
            std::cout << std::fixed << std::setprecision(2) << (list[i]/totalSpent * 100) << "% of Expenses\n";

    }

}