#ifndef ZODE_H
#define ZODE_H

#include <string>

class Zode {
    private:
        std::string data;
        Zode* nextZode;
        Zode* prevZode;
    public:
        // default constructor
        Zode();
        // custom data constructor
        Zode(const std::string& data);
        std::string getData() const;
        void setNextZode(Zode* n);
        void setPrevZode(Zode* p);
        Zode* getNextZode() const;
        Zode* getPrevZode() const;
        void setData(const std::string& newData);
};
// ==  !=   <  >  <=  >=
bool operator==(const Zode& lhs, const Zode& rhs);
bool operator!=(const Zode& lhs, const Zode& rhs);
bool operator<(const Zode& lhs, const Zode& rhs);
bool operator>(const Zode& lhs, const Zode& rhs);
bool operator<=(const Zode& lhs, const Zode& rhs);
bool operator>=(const Zode& lhs, const Zode& rhs);

bool operator==(const std::string& lhs, const Zode& rhs);
bool operator!=(const std::string& lhs, const Zode& rhs);
bool operator<(const std::string& lhs, const Zode& rhs);
bool operator>(const std::string& lhs, const Zode& rhs);
bool operator<=(const std::string& lhs, const Zode& rhs);
bool operator>=(const std::string& lhs, const Zode& rhs);

bool operator==(const Zode& rhs, const std::string& lhs);
bool operator!=(const Zode& rhs, const std::string& lhs);
bool operator<(const Zode& rhs, const std::string& lhs);
bool operator>(const Zode& rhs, const std::string& lhs);
bool operator<=(const Zode& rhs, const std::string& lhs);
bool operator>=(const Zode& rhs, const std::string& lhs);

#endif