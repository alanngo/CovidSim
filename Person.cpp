#include "Person.h"
Status Person::getStatus() const {return status;}  //returns a description of the person’s state
        
void Person::update(const Status &s) //update the person’s status to the next day;
{
    if (status == SICK)
        numDays++;
    status = s;
} 

void Person::infect(Person & p, int n) // infect a person, with the disease to run for n days
{
    bool canInfect = (status == SICK || status == SUSEPTIBLE);
    bool canBeInfected = (p.status!=RECOVERED && p.status!=INOCULATED);
    if (canInfect && canBeInfected)
    {
        p.numDays = n;
        p.status = SICK;
    }
    else
        throw runtime_error("cannot infect");      
    
} 

bool Person::isStable() const {return status==RECOVERED;} // report whether the person has been sick and is recovered.