
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

public:
    LinkedList();
    ~LinkedList();
    void push_back(const string& word);
    void clear();
    int size();
    void print(ostream& os = cout);

    
};

#endif
