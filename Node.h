#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

struct Node {
private:
    string word;
    Node* next;
    Node* prev;

public:
    Node(const string& w);
    string getWord();
    void setNext(Node* n);
    void setPrev(Node* p);
    Node* getNext();
    Node* getPrev();
};

#endif
