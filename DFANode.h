//
// Created by yexuf on 4/8/2019.
//

#ifndef DAY0408_COMPLINGPRICIPLE_DFA_DFANODE_H
#define DAY0408_COMPLINGPRICIPLE_DFA_DFANODE_H


#include <string>
#include <map>

class DFANode {
private :
    /*
     * 当前状态
     * 条件-迁移
     * */
    std::string current;
    std::map<std::string, std::string> transations;

public:
    std::string currentInput();
    void transationInput();
public:

    const std::map<std::string, std::string>::iterator getTransBegin();

    const std::map<std::string, std::string>::iterator getTransEnd();

    const std::map<std::string, std::string>::iterator findTrans(std::string condition);

    const std::string &getCurrent() const;

    void setCurrent(const std::string &current);

    const std::map<std::string, std::string>& getTransations();

    void setTransations(const std::map<std::string, std::string> &transations);

    void nodeTransationList();


};


#endif //DAY0408_COMPLINGPRICIPLE_DFA_DFANODE_H
