#ifndef TYPE_IP
#define TYPE_IP

#include <iostream>


class typeIP
{
private:
	unsigned char id1;
	unsigned char id2;
	unsigned char id3;
	unsigned char id4;
public:
	typeIP();
	friend std::istream & operator >> (std::istream &, typeIP &);
	friend std::ostream & operator << (std::ostream &, const typeIP &);
	friend bool operator == (const typeIP &, const typeIP &);
	friend bool operator < (const typeIP &, const typeIP &);
};

typeIP::typeIP() : id1(0), id2(0), id3(0), id4(0){}

std::istream & operator >> (std::istream &input, typeIP &temp){
	unsigned short int x;
	//1
	input >> x;
	temp.id1 = (unsigned char)x;
	input.get();
	//2
	input >> x;
	temp.id2 = (unsigned char)x;
	input.get();
	//3
	input >> x;
	temp.id3 = (unsigned char)x;
	input.get();
	//4
	input >> x;
	temp.id4 = (unsigned char)x;

	return input;
}

std::ostream & operator << (std::ostream &output, const typeIP &temp){
	output << (unsigned short int)temp.id1 << '.'
		   << (unsigned short int)temp.id2 << '.'
		   << (unsigned short int)temp.id3 << '.'
		   << (unsigned short int)temp.id4;
	return output;
}

bool operator == (const typeIP &a, const typeIP &b){
	return (a.id1 == b.id1) && (a.id2 == b.id2) && (a.id3 == b.id3) && (a.id4 == b.id4);
}

bool operator < (const typeIP &a, const typeIP &b){
	return (a.id1 < b.id1) ||
		(a.id1 == b.id1 && a.id2 < b.id2) ||
		(a.id1 == b.id1 && a.id2 == b.id2 && a.id3 < b.id3)||
		(a.id1 == b.id1 && a.id2 == b.id2 && a.id3 == b.id3 && a.id4 < b.id4);
}





#endif