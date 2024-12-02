#include "RinkedRist.h"
#include <iostream>

RinkedRist::RinkedRist(){
    head = nullptr;
    tail = nullptr;
    ristSize = 0;
}

RinkedRist::RinkedRist(const std::string& dataInfo){
    head = nullptr;
    head = nullptr;
    ristSize = 0;
    pushBack(dataInfo);
}

RinkedRist::~RinkedRist(){
    Zode* current = head;
    while(current != nullptr){
        Zode* nextZode = current->getNextZode();
        delete current;
        current = nextZode;
    }
}

void RinkedRist::setHead(Zode* head){
    this->head = head;
}

void RinkedRist::setTail(Zode* tail){
    this->tail = tail;
}

void RinkedRist::setSize(int size) {
    this->ristSize = size;
}

Zode* RinkedRist::getHead() const {
    return head;
}

Zode* RinkedRist::getTail() const {
    return tail;
}

Zode* RinkedRist::linearSearch(const std::string& data, std::string& prevData, std::string& nextData){
    Zode* current = head;
    prevData = nextData = "";

    while (current!= nullptr){
        if (current->getData() == data) {
            if(current->getPrevZode()){
                prevData = current->getPrevZode()->getData();
            }
            if(current->getNextZode()) {
                nextData = current->getNextZode()->getData();
            }
            return current;
        } 
        current = current->getNextZode();
    } 
    return nullptr;
}

Zode* RinkedRist::deleteNode(Zode* zodeToDelete){
    if (zodeToDelete == head){
        head = zodeToDelete->getNextZode();
        if (head != nullptr){
            head->setPrevZode(nullptr);
        }
    }
    if (zodeToDelete == tail){
        tail = zodeToDelete->getPrevZode();
        if(tail !=nullptr){
            tail->setNextZode(nullptr);
        }
    }

    if (zodeToDelete->getPrevZode() != nullptr) {
        zodeToDelete->getPrevZode()->setNextZode(zodeToDelete->getNextZode());
    }
    if (zodeToDelete->getNextZode() != nullptr) {
        zodeToDelete->getNextZode()->setPrevZode(zodeToDelete->getPrevZode());
    }
    delete zodeToDelete;
    ristSize--;

    if (ristSize == 0) {
        head = nullptr;
        tail = nullptr;
    }

    return nullptr;

}

Zode* RinkedRist::insertBefore(std::string newData, Zode* knownZode){
    Zode* newZode = new Zode(newData);

    if (knownZode == head){
        newZode->setNextZode(head);
        head->setPrevZode(newZode);
        head = newZode;
    } else {
        Zode* prevZode = knownZode->getPrevZode();
        prevZode -> setNextZode(newZode);
        newZode -> setPrevZode(prevZode);
        newZode -> setNextZode(knownZode);
        knownZode-> setPrevZode(newZode);
    }
    
}

void RinkedRist::pushBack(const std::string& data){
    Zode* newZode = new Zode(data);
    if (tail == nullptr) {
        head = newZode;
        tail = newZode;
    } else {
        tail->setNextZode(newZode);
        newZode->setPrevZode(tail);
        tail = newZode;
    }
    ristSize++;
}

void RinkedRist::insertInOrder(const std::string& newData){
    Zode* current = head;
    Zode* prevZode = nullptr;

    // Traverse the list to find the correct position
    while (current!= nullptr && current->getData()<newData){
        prevZode = current;
        current=current->getNextZode();
    }

    if(current!=nullptr && current->getData() == newData) {
        std::cout<< "Your word exits" << std::endl;
        if (current->getPrevZode()) {
            std::cout<<"Previous word will be"<<std::endl;
        } else {
            std::cout<<"no previous word"<<std::endl;
        }

        if (current->getNextZode()){
            std::cout<<"Next would be"<<std::endl;
        } else{
            std::cout<<"no next word"<<std::endl;
        }
        return;
    }

    Zode* newZode = new Zode(newData);
    if (prevZode == nullptr) {
        newZode ->setNextZode(head);
        if (head != nullptr) {
            head->setPrevZode(newZode);
        } else {
            tail = newZode;
        }
        head = newZode;
    } else {
        newZode->setNextZode(prevZode->getNextZode());
        newZode->setPrevZode(prevZode);
        prevZode->setNextZode(newZode);
        if (newZode->getNextZode()!= nullptr){
            newZode->getNextZode()->setPrevZode(newZode);
        } else {
            tail = newZode;
        }
    }
    ristSize++;



}

void RinkedRist::pushBack(Zode* newZodeData){
    if (tail == nullptr){
        head = newZodeData;
        tail = newZodeData;
    } else {
        tail->setNextZode(newZodeData);
        newZodeData->setPrevZode(tail);
        tail = newZodeData;
    }
    ristSize++;
}

void RinkedRist::clear(){
    Zode* current = head;
    while(current != nullptr){
        Zode* nextZode = current->getNextZode();
        delete current;
        current = nextZode;
    }
    head = nullptr;
    tail = nullptr;
    ristSize = 0;
}

int RinkedRist::size(){
    return ristSize;
}

void RinkedRist::print(std::ostream& os) {
    if(head==nullptr){
    } else {
        Zode* current = head;
        while(current != nullptr) {
            os << current->getData() << std::endl;
            current = current->getNextZode();
        }
    }
}

void RinkedRist::reversePrint(std::ostream& os){
    if(tail == nullptr){
    } else {
        Zode* current = tail;
        while(current != nullptr) {
            os << current->getData() << std::endl;
            current = current->getPrevZode();
        }
    }
}

