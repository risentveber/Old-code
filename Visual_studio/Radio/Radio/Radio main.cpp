#include <iostream>
#include <string>
#include <cstdio>
//#include "typeIP.h"
#include <vector>
#include <map>
#include <set>

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



using namespace std;

int main()
{
	map<typeIP, unsigned int> users; //пользователи <IP, lastTime>
	set<pair<int, unsigned int> > rating;//рейтинг pair<rating, track_id>
	map<unsigned int, int> compositions;//композиции<track_id, rating>

	string command;
	
	typeIP IP;
	unsigned int track_id;
	unsigned int time;
	short int score;
	

	//unsigned int
	int* composition_score;
	int comp_score;
	map<unsigned int, int>::iterator lastMin;///------
	map<typeIP, unsigned int>::iterator userIt;
	set<pair<int, unsigned int> >::iterator ratingIt;
	do{
		cin >> command;
		if (command == "VOTE") {
			cin >> IP >> track_id >> score >> time;
			userIt = users.find(IP);//ln n
			composition_score = &compositions[track_id]; //находим значение рейтинга//ln n

			if (userIt == users.end() || time - userIt->second >= 600){//если голос засчитывается
				if (userIt == users.end())//пользователь не голосовал
					users.insert(make_pair(IP, time)); //ln n
				else //пользователь голосовал
					userIt->second = time;
				ratingIt = rating.find(make_pair(*composition_score, track_id));//ln n
				if (rating.end() != ratingIt)
					rating.erase(ratingIt);
				*composition_score += score;
				rating.insert(make_pair(*composition_score, track_id));
			} else {
				ratingIt = rating.find(make_pair(*composition_score, track_id));
				if (rating.end() == ratingIt)
					rating.insert(make_pair(0, track_id));
			}
			cout << *composition_score << endl;
		} else if (command == "GET") {

			if (rating.empty()){
				rating.insert(make_pair(-1, 1));
				compositions[1] = -1;
				cout << 1 << ' ' << 0 << endl;
			} else {
				comp_score = rating.rbegin()->first;
				if (comp_score > 0) {
					ratingIt = rating.upper_bound(make_pair(comp_score, 0));
					track_id = ratingIt->second;
					cout << track_id << ' ' << comp_score << endl;
					rating.erase(make_pair(comp_score, track_id));
					rating.insert(make_pair(-1, track_id));
					compositions[track_id] = -1;
				} else if (comp_score == 0){
					ratingIt = rating.upper_bound(make_pair(0, 0));
					track_id = ratingIt->second;//
					unsigned int n = 1;
					for(map<unsigned int, int>::iterator it = compositions.begin(); it != compositions.end(); ++it){
						if (it->first != n)
							break;
						++n;
					}
					if (track_id > n){
						rating.insert(make_pair(-1, n));
						compositions[n] = -1;
						cout << n << ' ' << 0 << endl;
					}else{
						rating.erase(make_pair(0, track_id));
						rating.insert(make_pair(-1, track_id));
						compositions[track_id] = -1;
						cout << track_id << ' ' << 0 << endl;
					}

				} else {
					unsigned int n = 1;
					map<unsigned int, int>::iterator it = compositions.begin();
					for(; it != compositions.end(); ++it){
						if (it->first != n)
							break;
						++n;
					}
					/*if (it == compositions.end())
						++n;*/
					rating.insert(make_pair(-1, n));
						compositions[n] = -1;
						cout << n << ' ' << 0 << endl;
				}


			}
		}

	}while(command != "EXIT");
	cout << "OK";
	
	system("pause");
	return 0;
}