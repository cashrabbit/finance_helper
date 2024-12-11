#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "cereal/types/string.hpp"
#include <cereal/types/vector.hpp>
#include <cereal/archives/binary.hpp>

class Transaction{

    friend void printCategory(char cat);


    private:
        std::string label;
        double amount;
        bool isIncome;
        char category;
        //myDate::myDate date;

    public:
        Transaction();
        Transaction(std::string l, double a, bool i, char c);
        Transaction(Transaction& t);
        
        void print() const;
        std::string getLabel() const;
        double getAmount() const;
        bool isItIncome() const;
        char getCategory() const;

    template <class Archive>
        void serialize(Archive &ar) {
            ar(label, amount, category, isIncome); 
        }   
};

std::string catToCatLabel(char c);
void analyzeList(std::string file);
void viewTransactions(std::string file);
void addTransaction(std::string file);
char menu();