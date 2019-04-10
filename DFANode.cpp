//
// Created by yexuf on 4/8/2019.
//

#include "DFANode.h"

#include <iostream>

#define DEBUG true

const std::map<std::string, std::string>::iterator DFANode::getTransBegin() {
    return this->transations.begin();
}

const std::map<std::string, std::string>::iterator DFANode::getTransEnd() {
    return this->transations.end();
}


const std::string &DFANode::getCurrent() const {
    return current;
}

void DFANode::setCurrent(const std::string &current) {
    DFANode::current = current;
}

const std::map<std::string, std::string> &DFANode::getTransations() {
    return transations;
}

void DFANode::setTransations(const std::map<std::string, std::string> &transations) {
    DFANode::transations = transations;
}

const std::map<std::string, std::string>::iterator DFANode::findTrans(std::string condition) {
    return this->transations.find(condition);
}


void DFANode::nodeTransationList()
{
    std::map<std::string, std::string>::iterator it_trans = this->getTransBegin();
    for(; it_trans != this->getTransEnd(); it_trans++){
        std::cout << "Element :" <<  this->getCurrent() << " [C: " << it_trans->first << "; " << "T:" << it_trans->second <<  "]" <<std::endl;
    }
}




std::string DFANode::currentInput()
{
    std::string current;
    std::cout << "请输入节点的当前状态: " ;
    std::cin >> current;
    this->setCurrent(current);

    std::cout << "DEBUG:["<< this->getCurrent() << "]" << std::endl;

    return current;
}

void DFANode::transationInput() {
    std::string condition, transation;
    std::cout << "您要输入几条状态迁移序列？" ;
    int num = 0;
    std::cin >> num;
//    using  namespace std;
    for (int i = 0; i < num; ++i) {
        DFANode *pNode = new DFANode();
        std::cout << "请输入条件： " ;
        std::cin >> condition;

        std::cout << "请输入迁移的下一个状态:";
        std::cin >> transation;

//        this->getTransations().insert(std::pair<std::string, std::string>(condition, transation));
        this->transations.insert(std::map<std::string, std::string>::value_type(condition, transation));
    }

    if (DEBUG){
        std::map<std::string, std::string>::iterator it = this->transations.begin();
        for (this->transations.begin(); it!= this->transations.end(); ++it){
            std::cout << "Debug: "<< it->first << " => " << it->second << '\n';
        }

    }
}


