// Node.cpp
#include "Node.h"
using namespace std;

Node::Node(const string& w) : word(w), next(nullptr), prev(nullptr) {}

string Node::getWord() {
    return word;
}

void Node::setNext(Node* n) {
    next = n;
}

void Node::setPrev(Node* p) {
    prev = p;
}

Node* Node::getNext() {
    return next;
}

Node* Node::getPrev() {
    return prev;
}
