#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

struct LinkedList {
private:
    Node* head;
    Node* tail;
    int listSize;

    void setHead(Node* h);
    void setTail(Node* t);
    void setSize(int s);

public:
    LinkedList();
    LinkedList(const string& wordInfo);
    ~LinkedList();
    void push_back(const string& word);
    void clear();
    int size();
    void print(ostream& os = cout);
    bool linearSearch(const string& word, string& prevWord, string& nextWord);

    Node* getHead() const;
    Node* getTail() const;
};

// Function declaration
Node* findWord(LinkedList* lDict, string userWord);

#endif
