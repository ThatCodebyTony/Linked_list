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
        head = newNode;
        tail = newNode;
        // cout << "First word added: " << word << endl;  // Debugging line
    } else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
        // cout << "Added word: " << word << endl;  // Debugging line
    }
    // Ensure head is not nullptr
    if (head == nullptr) {
        head = newNode;
    }
    listSize++;
}
LinkedList& LinkedList::operator+=(LinkedList& otherList) {
    Node* current = otherList.getHead();
    while (current != nullptr) {
        push_back((*current).getWord());  // Add the current node's word to this list
        current = (*current).getNext();  // Move to the next node
    }

    // Clear the other list after merging
    otherList.clear();  // This will set head, tail, and size to default (nullptr and 0)

    return *this;  // Return the current list (the one we're appending to)
}

void LinkedList::push_back(Node* newWordNode) {
    if (tail == nullptr) {
        head = newWordNode;
        tail = newWordNode;
    } else {
        (*tail).setNext(newWordNode);
        (*newWordNode).setPrev(tail);
        tail = newWordNode;
    }
    listSize++;
}


int LinkedList::size() {
    return listSize;
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
    head = nullptr;  // Reset head and tail to nullptr after clearing
    tail = nullptr;
    listSize = 0;  // Reset list size
}

void LinkedList::print(ostream& os) {
    if (head == nullptr) {
        // os << "The list is empty." << endl;
    } else {
        Node* current = head;
        while (current != nullptr) {
            os << current->getWord() << endl;
            current = current->getNext();
        }
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

    if (nodeToDelete == head) {
        head = nodeToDelete->getNext();
        if (head != nullptr) {
            head->setPrev(nullptr);
        }
    }

    if (nodeToDelete == tail) {
        tail = nodeToDelete->getPrev();
        if (tail != nullptr) {
            tail->setNext(nullptr);
        }
    }

    if (nodeToDelete->getPrev() != nullptr) {
        nodeToDelete->getPrev()->setNext(nodeToDelete->getNext());
    }
    if (nodeToDelete->getNext() != nullptr) {
        nodeToDelete->getNext()->setPrev(nodeToDelete->getPrev());
    }

    delete nodeToDelete;
    listSize--;

    // If the list is now empty, ensure both head and tail are nullptr
    if (listSize == 0) {
        head = nullptr;
        tail = nullptr;
    }

    return nullptr;
}


void LinkedList::insert_in_order(const string& newWord) {
    Node* current = head;
    Node* prevNode = nullptr;

    // Traverse the list to find the correct position
    while (current != nullptr && current->getWord() < newWord) {
        prevNode = current;
        current = current->getNext();
    }

    // Now, check if the word is found
    if (current != nullptr && current->getWord() == newWord) {
        // Word already exists
        cout << "Your word was '" << newWord << "'." << endl;
        // Output previous and next words
        if (current->getPrev()) {
            cout << " The previous word would be '" << current->getPrev()->getWord() << "'." << endl;
        } else {
            cout << " There is no word before " << newWord << ". It is the first word." << endl;
        }
        if (current->getNext()) {
            cout << " The next word would be '" << current->getNext()->getWord() << "'." << endl;
        } else {
            cout << " There is no word after " << newWord << ". It is the last word." << endl;
        }
        return;
    }

    // Word not found, insert it
    cout << "Your word was '" << newWord << "'." << endl;
    cout << " We did not find your word. Adding word to dictionary..." << endl;

    Node* newNode = new Node(newWord);

    if (prevNode == nullptr) {
        // Insert at the beginning
        newNode->setNext(head);
        if (head != nullptr) {
            head->setPrev(newNode);
        } else {
            tail = newNode; // List was empty
        }
        head = newNode;
    } else {
        // Insert after prevNode
        newNode->setNext(prevNode->getNext());
        newNode->setPrev(prevNode);
        prevNode->setNext(newNode);
        if (newNode->getNext() != nullptr) {
            newNode->getNext()->setPrev(newNode);
        } else {
            tail = newNode; // Inserted at the end
        }
    }
    listSize++;

    cout << "Inserted!" << endl;

    // Output previous and next words
    if (newNode->getPrev()) {
        cout << " The previous word would be '" << newNode->getPrev()->getWord() << "'." << endl;
    } else {
        cout << " There is no word before " << newWord << ". It is the first word." << endl;
    }
    if (newNode->getNext()) {
        cout << " The next word would be '" << newNode->getNext()->getWord() << "'." << endl;
    } else {
        cout << " There is no word after " << newWord << ". It is the last word." << endl;
    }
}




Node* LinkedList::insert_before(string newWord, Node* knownNode) {
    if (knownNode == nullptr) {
        // Cannot insert before a null node
        return nullptr;
    }

    // Create a new node
    Node* newNode = new Node(newWord);

    // If knownNode is the head
    if (knownNode == head) {
        // Insert at the beginning
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
    else {
        // Insert before knownNode
        Node* prevNode = knownNode->getPrev();
        prevNode->setNext(newNode);
        newNode->setPrev(prevNode);
        newNode->setNext(knownNode);
        knownNode->setPrev(newNode);
    }

    // Increment the list size
    listSize++;

    return newNode;
}

void LinkedList::mergeDicts(LinkedList* listB) {
    Node* currentA = this->head;
    Node* currentB = listB->head;
    Node* mergedHead = nullptr;
    Node* mergedTail = nullptr;
    int newSize = 0;

    while (currentA != nullptr && currentB != nullptr) {
        if (currentA->getWord() < currentB->getWord()) {
            Node* nextA = currentA->getNext();

            // Detach currentA
            currentA->setPrev(nullptr);
            currentA->setNext(nullptr);

            // Append currentA to merged list
            if (mergedTail == nullptr) {
                mergedHead = currentA;
                mergedTail = currentA;
            } else {
                mergedTail->setNext(currentA);
                currentA->setPrev(mergedTail);
                mergedTail = currentA;
            }

            currentA = nextA;
            newSize++;
        } else if (currentA->getWord() > currentB->getWord()) {
            Node* nextB = currentB->getNext();

            // Detach currentB
            currentB->setPrev(nullptr);
            currentB->setNext(nullptr);

            // Append currentB to merged list
            if (mergedTail == nullptr) {
                mergedHead = currentB;
                mergedTail = currentB;
            } else {
                mergedTail->setNext(currentB);
                currentB->setPrev(mergedTail);
                mergedTail = currentB;
            }

            currentB = nextB;
            newSize++;
        } else {
            // Words are equal, include one and delete the other
            Node* nextA = currentA->getNext();
            Node* nextB = currentB->getNext();

            // Detach currentA
            currentA->setPrev(nullptr);
            currentA->setNext(nullptr);

            // Append currentA to merged list
            if (mergedTail == nullptr) {
                mergedHead = currentA;
                mergedTail = currentA;
            } else {
                mergedTail->setNext(currentA);
                currentA->setPrev(mergedTail);
                mergedTail = currentA;
            }

            // Delete currentB
            delete currentB;
            listB->listSize--;

            currentA = nextA;
            currentB = nextB;
            newSize++;
        }
    }

    // Append remaining nodes from currentA
    while (currentA != nullptr) {
        Node* nextA = currentA->getNext();

        // Detach currentA
        currentA->setPrev(nullptr);
        currentA->setNext(nullptr);

        // Append currentA to merged list
        if (mergedTail == nullptr) {
            mergedHead = currentA;
            mergedTail = currentA;
        } else {
            mergedTail->setNext(currentA);
            currentA->setPrev(mergedTail);
            mergedTail = currentA;
        }

        currentA = nextA;
        newSize++;
    }

    // Append remaining nodes from currentB
    while (currentB != nullptr) {
        Node* nextB = currentB->getNext();

        // Detach currentB
        currentB->setPrev(nullptr);
        currentB->setNext(nullptr);

        // Append currentB to merged list
        if (mergedTail == nullptr) {
            mergedHead = currentB;
            mergedTail = currentB;
        } else {
            mergedTail->setNext(currentB);
            currentB->setPrev(mergedTail);
            mergedTail = currentB;
        }

        currentB = nextB;
        newSize++;
    }

    // Update this list's head, tail, and size
    this->head = mergedHead;
    this->tail = mergedTail;
    this->listSize = newSize;

    // Clear listB
    listB->head = nullptr;
    listB->tail = nullptr;
    listB->listSize = 0;
}



void LinkedList::mergeSort() {
    mergeSort(this);
}

void LinkedList::mergeSort(LinkedList* topListPtr) {
    if (topListPtr->size() <= 1) {
        return; // Base case: list is already sorted
    }

    // Split the list into left and right halves
    LinkedList leftList;
    LinkedList rightList;

    topListPtr->split(leftList, rightList);

    // Recursively sort the left and right halves
    leftList.mergeSort(&leftList);
    rightList.mergeSort(&rightList);

    // Merge the sorted halves back into topListPtr
    // topListPtr is currently empty after the split
    topListPtr->mergeDicts(&leftList);
    topListPtr->mergeDicts(&rightList);
}

void LinkedList::split(LinkedList& leftList, LinkedList& rightList) {
    if (this->size() <= 1) {
        // Cannot split, list too small
        leftList.head = this->head;
        leftList.tail = this->tail;
        leftList.listSize = this->listSize;

        rightList.head = nullptr;
        rightList.tail = nullptr;
        rightList.listSize = 0;

        // Empty the current list
        this->head = nullptr;
        this->tail = nullptr;
        this->listSize = 0;
        return;
    }

    // Use slow and fast pointers to find the midpoint
    Node* slow = this->head;
    Node* fast = this->head;

    while (fast->getNext() != nullptr && fast->getNext()->getNext() != nullptr) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    // Split the list at the midpoint
    Node* rightHead = slow->getNext();
    slow->setNext(nullptr);
    if (rightHead != nullptr) {
        rightHead->setPrev(nullptr);
    }

    // Left half
    leftList.head = this->head;
    leftList.tail = slow;
    leftList.listSize = 0;
    Node* current = leftList.head;
    while (current != nullptr) {
        leftList.listSize++;
        current = current->getNext();
    }

    // Right half
    rightList.head = rightHead;
    rightList.tail = this->tail;
    rightList.listSize = 0;
    current = rightList.head;
    while (current != nullptr) {
        rightList.listSize++;
        current = current->getNext();
    }

    // Empty the current list
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
}
