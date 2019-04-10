//
// Created by yexuf on 4/8/2019.
//

#include "DFA.h"
#include <iostream>
#include <algorithm>

#define DEBUG true


class string;

const std::vector<std::string> &DFA::getEndFlags() const {
    return endFlags;
}

void DFA::setEndFlags(const std::vector<std::string> &endFlags) {
    DFA::endFlags = endFlags;
}
const std::map<std::string, DFANode> &DFA::getNodes() const {
    return nodes;
}

void DFA::setNodes(const std::map<std::string, DFANode> &nodes)
{

    DFA::nodes = nodes;
}


DFANode *DFA::getPDFAStart() const {
    return pDFAStart;
}

void DFA::setPDFAStart(DFANode *pDFAStart)
{
    DFA::pDFAStart = pDFAStart;
}

std::map<std::string, DFANode>::iterator DFA::getIterator(std::string key)
{
    return this->nodes.find(key);
}

std::map<std::string, DFANode>::iterator DFA::getNodesIterBegin() {
    return this->nodes.begin();
}

std::map<std::string, DFANode>::iterator DFA::getNodesIterEnd() {
    return this->nodes.end();
}


std::map<std::string, DFANode>::iterator DFA::getNodesIterByFind(std::string condition)
{
    return this->nodes.find(condition);
}



int DFA::setAutomation() {
    std::cout << "请问该DFA有多少节点:";
    int count = 0;
    std::cin >> count;

    //起始节点
    DFANode *pStart = new DFANode();
    std::cout << "请输入起始节点信息" << std::endl;
    std::string status = pStart->currentInput();
    pStart->transationInput();
    this->setPDFAStart(pStart);
    this->nodes.insert(std::pair<std::string, DFANode>(status, *pStart));

    //所有状态、迁移节点
    for (int i = 0; i < count; ++i) {
        DFANode *pNode = new DFANode();
        std::string nStatus = pNode->currentInput();
        pNode->transationInput();

        this->nodes.insert(std::pair<std::string, DFANode>(nStatus, *pNode));
    }

    //终止节点
    int endNodeQuality = 0;

    std::cout << "终止节点有多少个:" ;
    std::cin >> endNodeQuality;
    for (int i = 0; i < endNodeQuality; ++i) {
        std::map<std::string, DFANode>::iterator it = this->nodes.end();
        std::cout << "请输入第" << i << "个节点状态";
        std::cin >> status;
        if((it = this->nodes.find(status)) == this->nodes.end()){
            //Not found
            std::cout << "Key:[" << status << "]" << "not fount" << std::endl;
            exit(1);
        } else{
            this->endFlags.push_back(status);
        }
    }

    return 0;
}

void DFA::DFANodesShow()
{

    std::map<std::string, DFANode>::iterator it= this->nodes.begin();
    for (; it != this->nodes.end();  it++)    {
        it->second.nodeTransationList();
    }
}




bool DFA::checkSequence(std::string &seq)
{
    bool res = false;
    if (seq.empty()){
        std::cout << "Error, Sequence is None" << std::endl;
        res = false;
    } else{
        //开始节点

        auto iter_begin = this->getNodesIterBegin(), iter_end = this->getNodesIterEnd();
        std::map<std::string, DFANode>::iterator iter_before, iter_current = iter_begin;
        std::map<std::string,std::string>::iterator iter_seek = iter_begin->second.getTransBegin();

        int i;
        for (i = 0; i < seq.length(); ++i) {
            std::cout << "Current: " << iter_current->second.getCurrent() << " Condition: " << seq.substr(i, 1)  << std::endl;
            iter_seek = iter_current->second.findTrans(seq.substr(i, 1));
            if (iter_seek == iter_current->second.getTransEnd()) {
                //没根据条件找到跳转关系
                std::cout << "Above Condition >" << seq.substr(i, 1) << " Not found transation" << std::endl;
                res = false;
                break;
            } else {
                //Find
                iter_before = iter_current;
                if ((iter_current = this->getNodesIterByFind(iter_seek->second)) == iter_end) {
                    //没根据跳转关系找到下一个节点
                    std::cout << "EXP-STR>" << iter_seek->second << std::endl;
                    iter_current = iter_before;
                    res = false;
                    break;
                } else {
                    std::cout << "Jump to " << iter_current->first << std::endl;
                }
            }
        }

        if ((std::find(this->endFlags.begin(), this->endFlags.end(), iter_current->first)) != this->endFlags.end()){
            res = true;
        } else{
            res = false;
            std::cout << "not reached end of DFA" << std::endl;
        }
    }

    return res;
}















