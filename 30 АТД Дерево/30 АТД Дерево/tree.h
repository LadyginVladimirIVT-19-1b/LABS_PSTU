#pragma once


#define _TREENODE_

#include<conio.h>
#include<string>
#include<iomanip>
#include <cctype>
#include<iostream>
using namespace std;

class treeNode
{
private:
    treeNode* left, * right;
    string word, meaning;
    int count;
public:
    treeNode(string w, string m, int count);
    void setData(string w, string m, int count);
    string getWord();
    string getMeaning();
    int getCount();
    void DisplayWordMeaning();
    void setLeft(treeNode*);
    treeNode* getLeft();
    void setRight(treeNode*);
    treeNode* getRight();
};


unsigned int DJBHash(string str);
treeNode* FindMin(treeNode* T);
bool Find(treeNode* root, string wrd);
void Edit(treeNode* root, string wrd, string newWrd, string mng, int count);
void insert(treeNode* root, string wrd, string mng, int count);
void insert2(treeNode* root2, string wrd, string mng, int count);
void printDictionary(treeNode* root);
treeNode* Delete(treeNode* root, string wrd);
void DeleteDictionary(treeNode*);

