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
Node* LinkedList::linearSearch(const string& word, string& prevWord, string& nextWord) {
    Node* current = head;
    prevWord = "";
    nextWord = "";

    while (current != nullptr) {
        if (current->getWord() == word) {
            // Fill previous and next words
            if (current->getPrev()) {
                prevWord = current->getPrev()->getWord();
            }
            if (current->getNext()) {
                nextWord = current->getNext()->getWord();
            }
            return current;  // Return the node where the word is found
        } else if (current->getWord() < word) {
            prevWord = current->getWord();
        } else if (current->getWord() > word && nextWord.empty()) {
            nextWord = current->getWord();
        }
        current = current->getNext();
    }

    return nullptr;  // Return nullptr if the word was not found
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

Node* LinkedList::deleteWord(Node* nodeToDelete) {
    if (nodeToDelete == nullptr) {
        return nullptr;  // Nothing to delete if the node is nullptr
    }

    // If nodeToDelete is the first node in the list
    if (nodeToDelete == head) {
        head = nodeToDelete->getNext();
        if (head != nullptr) {
            head->setPrev(nullptr);  // Set the previous pointer of the new head to nullptr
        }
    } 
    // If nodeToDelete is the last node in the list
    else if (nodeToDelete == tail) {
        tail = nodeToDelete->getPrev();
        if (tail != nullptr) {
            tail->setNext(nullptr);  // Set the next pointer of the new tail to nullptr
        }
    } 
    // If nodeToDelete is in the middle of the list
    else {
        Node* prevNode = nodeToDelete->getPrev();
        Node* nextNode = nodeToDelete->getNext();

        if (prevNode != nullptr) {
            prevNode->setNext(nextNode);
        }
        if (nextNode != nullptr) {
            nextNode->setPrev(prevNode);
        }
    }

    Node* nextNode = nodeToDelete->getNext();
    delete nodeToDelete;  // Deallocate memory for the deleted node
    listSize--;
    return nextNode;  // Return the next node (or nullptr if it was the last node)
}
