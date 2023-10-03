#include "fin_analysis.h"

int main(){
    char sel;

    sel=getMenuSelection();

    switch(sel){
        case 'a':
            runAnalysis();
            break;
        case 'w':
            makeNewFile();
            break;
        case 'b':
        
    }


    return 0;
}