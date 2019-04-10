//
// Created by yexuf on 4/9/2019.
//

#include "DFATestingCase.h"

#include <iostream>

// 生成测试用例 DFA
// 编译原理 P65页 Figure 3.18
DFA& DFATestingCase::getDFAInstance() {
    using  namespace std;

    DFA *pIns = new DFA();

    //设置DFA的节点集合
    map<string, DFANode> nodes;

    //Node of Start
    DFANode *pStart = new DFANode();
    pStart->setCurrent("1");
    map<string, string> CT;
    CT.insert(pair<string, string>("a", "3"));
    CT.insert(pair<string, string>("b", "2"));
    pStart->setTransations(CT);

    //设置首部节点指针
    pIns->setPDFAStart(pStart);
    nodes.insert(pair<string, DFANode>("1", *pStart));

    //node 2
    DFANode *pNode2 = new DFANode();
    pNode2->setCurrent("2");
    map<string, string> ct2;
    ct2.insert(pair<string, string>("b", "2"));
    ct2.insert(pair<string, string>("a", "4"));
    pNode2->setTransations(ct2);

    nodes.insert(pair<string, DFANode>("2", *pNode2));

    //node 3
    DFANode *pNode3 = new DFANode();
    pNode3->setCurrent("3");
    map<string, string> ct3;
    ct3.insert(pair<string, string>("c", "3"));
    ct3.insert(pair<string, string>("b", "6"));
    ct3.insert(pair<string, string>("d", "5"));
    pNode3->setTransations(ct3);

    nodes.insert(pair<string, DFANode>("3", *pNode3));
//    cout << "Length: " << nodes.size() << endl;

    //node 4
    DFANode *pNode4 = new DFANode();
    pNode4->setCurrent("4");

    map<string, string> ct4;
    ct4.insert(pair<string, string>("c", "3"));
    ct4.insert(pair<string, string>("b", "7"));
    ct4.insert(pair<string, string>("d", "5"));

    pNode4->setTransations(ct4);

    nodes.insert(pair<string, DFANode>("4", *pNode4));
//    cout << "Length: " << nodes.size() << endl;

    //node 5
    DFANode *pNode5 = new DFANode();
    pNode5->setCurrent("5");
    map<string, string> ct5;
    ct5.insert(pair<string, string>("a", "4"));

    pNode5->setTransations(ct5);

    nodes.insert(pair<string, DFANode>("5", *pNode5));
//    cout << "Length: " << nodes.size() << endl;


    //node 6
    DFANode *pNode6 = new DFANode();
    pNode6->setCurrent("6");
    map<string, string> ct6;
    ct6.insert(pair<string, string>("b", "6"));

    pNode6->setTransations(ct6);

    nodes.insert(pair<string, DFANode>("6", *pNode6));
//    cout << "Length: " << nodes.size() << endl;


    //node 7
    DFANode *pNode7 = new DFANode();
    pNode7->setCurrent("7");
    map<string, string> ct7;
    ct7.insert(pair<string, string>("b", "6"));

    pNode7->setTransations(ct7);
    nodes.insert(pair<string, DFANode>("7", *pNode7));
//    cout << "Length: " << nodes.size() << endl;


    pIns->setNodes(nodes);

    vector<string> ends;
    ends.emplace_back("6");
    ends.emplace_back("7");

    pIns->setEndFlags(ends);




    return *pIns;
}
