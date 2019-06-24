//
//  PERSON.cpp
//  Lab5
//
//  Created by Lily Tang on 5/30/19.
//  Copyright © 2019 Lily Tang. All rights reserved.
//

#include "PERSON.h"
#include <string>
#include <iostream>

using namespace std;
ostream &operator << (ostream &strm, Person &obj){
    strm << obj.name << "\t"<< obj.birthDate << endl;
    return strm;
}

Person::Person(string n, string b){
    name = n;
    birthDate = b;
}
void Person::setBirth(string b){
    birthDate = b;
}
void Person::setName(string f){
    name = f;
}
string Person::getBirth()const{
    return birthDate;
}
string Person::getName() const{
    return name;
}
void Person::operator = (const Person &r){
    name = r.name;
    birthDate = r.birthDate;
    
}
bool Person::operator == (const Person &right) const{
    return (birthDate == right.birthDate);
}
bool Person::operator != (const Person &right) const{
    return (birthDate != right.birthDate);
}
bool Person::operator < (const Person &right) const{
    return (birthDate < right.birthDate);
}
bool Person::operator > (const Person &right) const{
    return (birthDate > right.birthDate);
}
bool Person::operator >= (const Person &right) const{
    return (birthDate >= right.birthDate);
}
bool Person::operator <= (const Person &right) const{
    return (birthDate <= right.birthDate);
}
