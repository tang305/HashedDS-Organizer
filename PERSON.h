#ifndef PERSON_h
#define PERSON_h

#include <string>
#include <iostream>

// forward declaration of AD
class Person;

// Function Prototype for Overloaded Stream Operators
std::ostream &operator << (std::ostream &, Person &);

class Person {
private:
    std::string name;
    std::string birthDate;
public:
    Person(){}
    Person(std::string, std::string);
    virtual ~Person(){}
    // Mutator member functions
    virtual void setName(std::string);
    virtual void setBirth(std::string);
    // Accessor member functions
    std::string getName() const;
    std::string getBirth() const;
    // overload operators
    void operator = (const Person &);
    // overload <, >, ==, !=, >=, <=
    bool operator < (const Person &) const;
    bool operator > (const Person &) const;
    bool operator == (const Person &) const;
    bool operator != (const Person &) const;
    bool operator >= (const Person &) const;
    bool operator <= (const Person &) const;
    // friend stream operators
    friend std::ostream &operator << (std::ostream &, Person &);
};

#endif /* PERSON_h */
