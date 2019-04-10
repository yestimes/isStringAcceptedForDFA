#include <iostream>

#include <map>

#include "DFA.h"
#include "DFATestingCase.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    std::cout << "-----" << std::endl;

    DFA dfa = DFATestingCase::getDFAInstance();
//    pDfa->setAutomation();

//    dfa.DFANodesShow();
    std::string *tmp = new std::string("accbb");
    bool  res = dfa.checkSequence(*tmp);
    if (res){
        std::cout << "DFA Accepted" << std::endl;
    } else{
        std::cout << "Fail" << std::endl;
    }
    return 0;

}