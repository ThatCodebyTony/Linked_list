// Node.h
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
    Node();
    Node(const string& w);
    string getWord() const;      
    void setNext(Node* n);
    void setPrev(Node* p);
    Node* getNext() const;        
    Node* getPrev() const;        
    void setWord(const string& newWord);
};

// Declare operator overloads as non-member functions
bool operator==(const Node& lhs, const Node& rhs);
bool operator!=(const Node& lhs, const Node& rhs);
bool operator<(const Node& lhs, const Node& rhs);
bool operator>(const Node& lhs, const Node& rhs);
bool operator<=(const Node& lhs, const Node& rhs);
bool operator>=(const Node& lhs, const Node& rhs);

bool operator==(const Node& lhs, const string& rhs);
bool operator!=(const Node& lhs, const string& rhs);
bool operator<(const Node& lhs, const string& rhs);
bool operator>(const Node& lhs, const string& rhs);
bool operator<=(const Node& lhs, const string& rhs);
bool operator>=(const Node& lhs, const string& rhs);

bool operator==(const string& lhs, const Node& rhs);
bool operator!=(const string& lhs, const Node& rhs);
bool operator<(const string& lhs, const Node& rhs);
bool operator>(const string& lhs, const Node& rhs);
bool operator<=(const string& lhs, const Node& rhs);
bool operator>=(const string& lhs, const Node& rhs);

#endif
