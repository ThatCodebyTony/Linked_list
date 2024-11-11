#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

LinkedList::LinkedList(const string& wordInfo) : head(nullptr), tail(nullptr), listSize(0) {
    push_back(wordInfo);
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = (*current).getNext();
        delete current;
        current = nextNode;
    }
}

void LinkedList::push_back(const string& word) {
    Node* newNode = new Node(word);
    if (tail == nullptr) {
        // List is empty
        head = newNode;
        tail = newNode;
    } else {
        (*tail).setNext(newNode);
        (*newNode).setPrev(tail);
        tail = newNode;
    }
    listSize++;
}

int LinkedList::size() {
    return listSize;
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->getNext();  // Save the next node
        delete current;  // Delete the current node
        current = nextNode;  // Move to the next node
    }
    head = nullptr;  // Reset head and tail to nullptr after clearing
    tail = nullptr;
    listSize = 0;  // Reset list size to 0
}


void LinkedList::print(ostream& os) {
    Node* current = head;
    while (current != nullptr) {
        os << (*current).getWord() << endl;
        current = (*current).getNext();
    }
}

Node* LinkedList::getHead() const {
    return head;
}

Node* LinkedList::getTail() const {
    return tail;
}

void LinkedList::setHead(Node* h) {
    head = h;
}

void LinkedList::setTail(Node* t) {
    tail = t;
}

void LinkedList::setSize(int s) {
    listSize = s;
}