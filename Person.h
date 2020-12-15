#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Status.h"
using namespace std;

class Person 
{
    private:
        string name;
        Status status; // see Status.h
        int numDays; // days infected

    public:
        Person(const string & n, const Status & s): //constructor
        name(n),
        status(s),
        numDays(0)
        {}
        
        Status getStatus() const;  //returns a description of the person’s state
        void update(const Status &s); //update the person’s status to the next day;
        void infect(Person & p, int n); // infect a person, with the disease to run for n days
        bool isStable() const; // report whether the person has been sick and is recovered.
    
    friend ostream& operator <<(ostream& os, const Person& p)
    {
        os << p.name<< " is " <<getStatusString(p.status) << " and is infected for "<<p.numDays<<" days";
        return os;
    }
};
#include "Person.cpp"
#endif 
