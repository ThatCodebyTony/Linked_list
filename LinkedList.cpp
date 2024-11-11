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

// bool LinkedList::linearSearch(const string& word) {
//     Node* current = head;
    
//     while (current != nullptr) {
//         if ((*current).getWord() == word) {
//             return true;  
//         }
//         current = (*current).getNext();  
//     }
//     return false;  
// }

// overloaded linearSearch function
bool LinkedList::linearSearch(const string& word, string& prevWord, string& nextWord) {
    Node* current = head;
    
    // Traverse the list and compare each word
    while (current != nullptr) {
        if ((*current).getWord() == word) {
            // If word is found, get the previous and next words
            if ((*current).getPrev() != nullptr) {
                prevWord = current->getPrev()->getWord();
            } else {
                prevWord = "";
            }

            if ((*current).getNext() != nullptr) {
                nextWord = (*current).getNext()->getWord();
            } else {
                nextWord = "";
            }
            return true;  
        }
        current = (*current).getNext();  
    }

    // If word is not found, return the last word in the list as prevWord
    if (head != nullptr) {
        current = head;
        // Traverse to the last node
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        prevWord = current->getWord();
        nextWord = "";  // Since there's no next word after the last one
    }
    return false;  
}

// Function to find a word in the linked list
Node* findWord(LinkedList* lDict, string userWord) {
    // Clean the input word (if needed)
    string cleanedWord;
    for (char c : userWord) {
        if (isalpha(c)) {  // Keep only alphabetic characters
            cleanedWord += tolower(c);  // Convert to lowercase
        }
    }

    Node* current = lDict->getHead();  // Start from the head of the list
    while (current != nullptr) {
        // Compare the cleaned word with the current node's word
        if (current->getWord() == cleanedWord) {
            return current;  // Return the node if a match is found
        }
        current = current->getNext();  // Move to the next node
    }

    return nullptr;  // Return nullptr if the word is not found
}