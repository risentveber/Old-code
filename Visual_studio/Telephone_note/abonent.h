#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Abonent{
public:
	string name;
	string e_mail;
	vector<unsigned _int64> phones;
	Abonent(string nName, unsigned _int64 nPhone, string nE_mail = "") : name(nName), e_mail(nE_mail) {
		phones.push_back(nPhone);
	};
	Abonent(string nName, string nE_mail = "") : name(nName), e_mail(nE_mail) {};
};