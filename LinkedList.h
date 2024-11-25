#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

class LinkedList {
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
    
    LinkedList& operator+=(LinkedList& otherList);


    void push_back(const string& word);
    void push_back(Node * newWordNode);
    void clear();
    int size();
    void print(ostream& os = cout);
    void reversePrint(ostream& os = cout);
    Node* linearSearch(const string& word, string& prevWord, string& nextWord);
    Node* deleteWord(Node* nodeToDelete);
    Node* insert_before(string newWord, Node* knownNode);

    // Declare the insert_in_order method
    void insert_in_order(const string& newWord);

    Node* getHead() const;
    Node* getTail() const;
    
    void mergeDicts(LinkedList* listB);
      void mergeSort();
      void mergeSort(LinkedList* topListPtr);
      void split(LinkedList& leftList, LinkedList& rightList);

};

// Function declaration for external use
Node* findWord(LinkedList* lDict, string userWord);

#endif
