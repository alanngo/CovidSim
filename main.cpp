#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"
using namespace std;

template<class E>
void log(const E& e){cout<<e<<endl;}

vector<string> loadNames(string fileName)
{
      vector<string> ret;
      string line ="";
      ifstream infile;
      infile.open(fileName);
      while (getline(infile, line))
            ret.push_back(line);
      infile.close();
      return ret;
}
void populate(vector<Person*>*population, vector<string> names, int n, Status status)
{
      
      for (int i =0; i< n; i++)
      {
            int randIndex = rand() % names.size() + 1;
            Person* tmp = new Person(names[randIndex], status);
            population->push_back(tmp);
      }
}
vector<Person*>* populate(int suseptible, int sick, int recovered, int inoculated)
{
      vector<string> names = loadNames("names.txt");
      vector<Person*> *ret = new vector<Person*>();
      populate(ret, names, suseptible, SUSEPTIBLE);
      populate(ret, names, sick, SICK);
      populate(ret, names, recovered, RECOVERED);
      populate(ret, names, inoculated, INOCULATED);
      return ret;
}

void simulate(vector<Person*>* population)
{
      int infectorIndex =  rand() % population->size() + 1;
      int infectedIndex =  rand() % population->size() + 1;

}
void printAll(vector<Person*>* population)
{
      for (Person *p: *population)
            log(*p);
}
int main(int argc, char*argv[])
{     
      int suseptible = 5;
      int sick = 4;
      int recovered = 8;
      int inoculated = 1;

      vector<Person*> *people = populate(suseptible, sick, recovered, inoculated);
      printAll(people);

      return 0;
}
