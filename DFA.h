//
// Created by yexuf on 4/8/2019.
//

#ifndef DAY0408_COMPLINGPRICIPLE_DFA_DFA_H
#define DAY0408_COMPLINGPRICIPLE_DFA_DFA_H


#include <map>
#include <vector>
#include "DFANode.h"

class DFA {
private:
    //起始节点
    DFANode *pDFAStart;
    //终止节点
    std::vector<std::string>endFlags;
    //节点
    std::map<std::string, DFANode> nodes;
private:
//    int setDFANodes();
public:
    int setAutomation();
    void DFANodesShow();


public:
    DFANode *getPDFAStart() const;

    void setPDFAStart(DFANode *pDFAStart);

    const std::vector<std::string> &getEndFlags() const;

    const std::map<std::string, DFANode> &getNodes() const;

    void setNodes(const std::map<std::string, DFANode> &nodes);

    void setEndFlags(const std::vector<std::string> &endFlags);

    std::map<std::string, DFANode>::iterator getNodesIterBegin();

    std::map<std::string, DFANode>::iterator getNodesIterEnd();

    std::map<std::string, DFANode>::iterator getNodesIterByFind(std::string condition);

    std::map<std::string, DFANode>::iterator getIterator(std::string key);


public:
    bool checkSequence(std::string &seq);
};



#endif //DAY0408_COMPLINGPRICIPLE_DFA_DFA_H
