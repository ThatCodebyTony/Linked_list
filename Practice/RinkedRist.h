#ifndef RINKEDRIST_H
#define RINKEDRIST_H

#include "Zode.h"
#include <string>
#include <iostream>


class RinkedRist {
    private:
        Zode* head;
        Zode* tail;
        int ristSize;

        void setHead(Zode* head);
        void setTail(Zode* tail);
        void setSize(int size);
    public:
        RinkedRist();
        RinkedRist(const std::string& dataInfo);
        ~RinkedRist();
        
        Zode* getHead() const;
        Zode* getTail() const;
        Zode* linearSearch(const std::string& data, std::string& prevData, std::string& nextData);
        Zode* deleteNode(Zode* nodeToDelete);
        Zode* insertBefore(std::string newDat, Zode* knownZode);

        RinkedRist& operator+=(RinkedRist& otherList);

        void insertInOrder(const std::string& newData);
        void pushBack(const std::string& data);
        void pushBack(Zode* newDataNode);
        void clear();
        int size();
        void print(std::ostream& os = std::cout);
        void reversePrint(std::ostream& os = std::cout);


        
};

#endif