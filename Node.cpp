#include "Node.h"

Node::Node() : next(nullptr), prev(nullptr) {}

Node::Node(const string& w) : word(w), next(nullptr), prev(nullptr) {}

string Node::getWord() const {
    return word;
}

void Node::setWord(const string& newWord) {
    word = newWord;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* n) {
    next = n;
}

Node* Node::getPrev() const {
    return prev;
}

void Node::setPrev(Node* p) {
    prev = p;
}


// Non-member operator overloads

// Node compared to Node
bool operator==(const Node& lhs, const Node& rhs) {
    return lhs.getWord() == rhs.getWord();
}

bool operator!=(const Node& lhs, const Node& rhs) {
    return lhs.getWord() != rhs.getWord();
}

bool operator<(const Node& lhs, const Node& rhs) {
    return lhs.getWord() < rhs.getWord();
}

bool operator>(const Node& lhs, const Node& rhs) {
    return lhs.getWord() > rhs.getWord();
}

bool operator<=(const Node& lhs, const Node& rhs) {
    return lhs.getWord() <= rhs.getWord();
}

bool operator>=(const Node& lhs, const Node& rhs) {
    return lhs.getWord() >= rhs.getWord();
}

// Node compared to string
bool operator==(const Node& lhs, const string& rhs) {
    return lhs.getWord() == rhs;
}

bool operator!=(const Node& lhs, const string& rhs) {
    return lhs.getWord() != rhs;
}

bool operator<(const Node& lhs, const string& rhs) {
    return lhs.getWord() < rhs;
}

bool operator>(const Node& lhs, const string& rhs) {
    return lhs.getWord() > rhs;
}

bool operator<=(const Node& lhs, const string& rhs) {
    return lhs.getWord() <= rhs;
}

bool operator>=(const Node& lhs, const string& rhs) {
    return lhs.getWord() >= rhs;
}

// String compared to Node
bool operator==(const string& lhs, const Node& rhs) {
    return lhs == rhs.getWord();
}

bool operator!=(const string& lhs, const Node& rhs) {
    return lhs != rhs.getWord();
}

bool operator<(const string& lhs, const Node& rhs) {
    return lhs < rhs.getWord();
}

bool operator>(const string& lhs, const Node& rhs) {
    return lhs > rhs.getWord();
}

bool operator<=(const string& lhs, const Node& rhs) {
    return lhs <= rhs.getWord();
}

bool operator>=(const string& lhs, const Node& rhs) {
    return lhs >= rhs.getWord();
}
