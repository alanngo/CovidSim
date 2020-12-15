#include <string>
#include <exception>
using namespace std;
enum Status
{
    SICK, //when they are sick, they can infect other people
    SUSEPTIBLE, //they are healthy, but can be infected
    RECOVERED, //they have been sick, but no longer carry the disease, and can not be infected for a second time
    INOCULATED, //they are healthy, do not carry the disease, and can not be infected
};

string getStatusString(const Status & status)
{
    switch (status)
    {
        case SICK:
            return "sick";
        case SUSEPTIBLE:
            return "suseptible";
        case RECOVERED:
            return "recovered";
        case INOCULATED:
            return "inoculated";
    }
    throw "should never go here";
}