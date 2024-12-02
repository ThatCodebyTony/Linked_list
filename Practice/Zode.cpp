#include "Zode.h"

Zode::Zode(){
    nextZode = nullptr;
    prevZode = nullptr;
}

Zode::Zode(const std::string& data){
    this->data = data;
    nextZode = nullptr;
    prevZode = nullptr;
}

std::string Zode::getData() const {
    return data;
}

void Zode::setNextZode(Zode* n){
    nextZode = n;
}

void Zode::setPrevZode(Zode* p){
    prevZode = p;
}

Zode* Zode::getNextZode() const{
    return nextZode;
}

Zode* Zode::getPrevZode() const{
    return prevZode;
}

void Zode::setData(const std::string& newData){
    this->data = newData;
}





bool operator==(const Zode& lhs,const Zode& rhs){
    return lhs.getData() == rhs.getData();
}

bool operator!=(const Zode& lhs, const Zode& rhs){
    return lhs.getData() != rhs.getData();
}
bool operator<(const Zode& lhs, const Zode& rhs){
    return lhs.getData() < rhs.getData();
}
bool operator>(const Zode& lhs, const Zode& rhs){
    return lhs.getData() > rhs.getData();
}
bool operator<=(const Zode& lhs, const Zode& rhs){
    return lhs.getData() <= rhs.getData();
}
bool operator>=(const Zode& lhs, const Zode& rhs){
    return lhs.getData() >= rhs.getData();
}


bool operator==(const std::string& lhs, const Zode& rhs){
    return lhs == rhs.getData();
}
bool operator!=(const std::string& lhs, const Zode& rhs){
    return lhs != rhs.getData();
}
bool operator<(const std::string& lhs, const Zode& rhs){
    return lhs < rhs.getData();
}
bool operator>(const std::string& lhs, const Zode& rhs){
    return lhs > rhs.getData();
}
bool operator<=(const std::string& lhs, const Zode& rhs){
    return lhs <= rhs.getData();
}
bool operator>=(const std::string& lhs, const Zode& rhs){
    return lhs >= rhs.getData();
}


bool operator==(const Zode& lhs, const std::string&rhs){
    return lhs.getData() == rhs;
}
bool operator!=(const Zode& lhs, const std::string&rhs){
    return lhs.getData() != rhs;
}

bool operator<(const Zode& lhs, const std::string&rhs){
    return lhs.getData() < rhs;
}

bool operator>(const Zode& lhs, const std::string&rhs){
    return lhs.getData() > rhs;
}

bool operator<=(const Zode& lhs, const std::string&rhs){
    return lhs.getData() <= rhs;
}
bool operator>=(const Zode& lhs, const std::string&rhs){
    return lhs.getData() >= rhs;
}