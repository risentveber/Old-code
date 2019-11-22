#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

typedef unsigned long int element;

class Contact{
    public:
        string name;
        string e_mail;
        vector<element> phones;
        Contact(string nName, element nPhone, string nE_mail = "") : name(nName), e_mail(nE_mail) {
            phones.push_back(nPhone);
        };
        Contact(string nName, string nE_mail = "") : name(nName), e_mail(nE_mail) {};
};
