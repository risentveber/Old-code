#include "DateTime.h"
#include <time.h>


bool isNotClear(std::istream & input){
	while(input.peek() == ' ')
		input.get();
	return ((input.peek() != '\n') && (input.peek() != -1));
}



//TimeSpan
TimeSpan::TimeSpan(){
	_span = 0;
}
TimeSpan::TimeSpan(__int64 x){
	_span = x;
}

__int64 TimeSpan::getTotalSeconds() const{
	return _span;
}
__int64 TimeSpan::getTotalDays() const{
	return _span / 86400;
}
__int64 TimeSpan::getTotalHours() const{
	return _span / 3600;
}
__int64 TimeSpan::getTotalMinutes() const{
	return _span / 60;
}
void TimeSpan::setTotalSeconds(__int64 x){
	_span = x;
}

bool operator == (const TimeSpan &a, const TimeSpan &b){
	return a._span == b._span;
}
bool operator != (const TimeSpan &a, const TimeSpan &b){
	return a._span != b._span;
}
bool operator > (const TimeSpan &a, const TimeSpan &b){
	return a._span > b._span;
}
bool operator < (const TimeSpan &a, const TimeSpan &b){
	return a._span < b._span;
}
bool operator <= (const TimeSpan &a, const TimeSpan &b){
	return a._span <= b._span;
}
bool operator >= (const TimeSpan &a, const TimeSpan &b){
	return a._span >= b._span;
}

TimeSpan operator - (const TimeSpan &a, const TimeSpan &b){
	TimeSpan temp;
	temp._span = a._span - b._span;
	return temp;
}
TimeSpan operator + (const TimeSpan &a, const TimeSpan &b){
	TimeSpan temp;
	temp._span = a._span + b._span;
	return temp;
}

std::ostream & operator << (std::ostream &output , const TimeSpan & a){
	output << a._span << std::endl;
	return output;
}
std::istream & operator >> (std::istream &input, TimeSpan &a){
	input >> a._span;
	return input;
}


//DateTime
DateTime::DateTime(){
	now();
}
DateTime::DateTime(unsigned int year, unsigned char mounth, unsigned char day,
				   unsigned char hours, unsigned char minutes, unsigned char seconds){
	setTimeDate(year, mounth, day, hours, minutes, seconds);
}

void DateTime::setTimeDate(unsigned int year, unsigned char mounth, unsigned char day,
				   unsigned char hours, unsigned char minutes, unsigned char seconds){

	if (!(
		year >= YEAR &&
		mounth > 0 && mounth <= 12 &&
		day > 0 && (day <= mounthLong[mounth - 1] || day == 29 && mounth == 2 && (year % 4 == 0)) &&
		hours >= 0 && hours < 24 &&
		minutes >= 0 && minutes < 60 &&
		seconds >= 0 && seconds < 60
		))
	{ throw;      }

	_time = 126230400*((year - YEAR) / 4);
	_time += 31536000*((year - YEAR) % 4);
	if((year - YEAR) % 4 == 3)//високосный год был
		_time += 86400;
	if (((year - YEAR) % 4 == 2)&&(mounth > february))//високосный год - текущий
			_time += 86400;
	for(int i = 0; i < mounth - 1; i++)
		_time += mounthLong[i]*86400;
	_time += (day - 1)*86400;
	_time += hours*3600;
	_time += minutes*60;
	_time += seconds;
}

int DateTime::getYear()const{
	time_t temp;
	int result = YEAR;
	result += (_time / 126230400)*4;
	temp = _time % 126230400;
	if (temp - SECONDS_IN_YEAR >= 0){
		result++;
	    temp -= SECONDS_IN_YEAR;
	}else
		return result;
	if (temp - SECONDS_IN_YEAR >= 0){
		result++;
		temp -= SECONDS_IN_YEAR;
	}else
		return result;
	if (temp - SECONDS_IN_YEAR - 86400 >= 0)
		result++;
	else
		return result;
	return result;
}

int DateTime::getMounth()const{
	time_t temp;
	int year = YEAR;
	year += (_time / 126230400)*4;
	temp = _time % 126230400;
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
	    temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
		temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR - 86400 >= 0){
		temp -= SECONDS_IN_YEAR;
		temp -= 86400;
		year++;
	}
	int x;
	int mounth = 0;
	for(int i = 0; i < 11; i++){
		x = mounthLong[i];
		if ((i == 1) && ( year % 4 == 0))
			x++;
		x *= 86400;
		if (temp - x >= 0){
			temp -= x;
			mounth++;
		}else
			break;
		
	}
	mounth++;
	return mounth;
}

int DateTime::getDay()const{
	time_t temp;
	int year = YEAR;
	year += (_time / 126230400)*4;
	temp = _time % 126230400;
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
	    temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
		temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR - 86400 >= 0){
		temp -= SECONDS_IN_YEAR;
		temp -= 86400;
		year++;
	}
	int x;
	int mounth = 0;
	for(int i = 0; i < 11; i++){////где - то затесалась ошибка
		x = mounthLong[i];
		if ((i == 1) && ( year % 4 == 0))
			x++;
		x *= 86400;
		if (temp - x >= 0){
			temp -= x;
			mounth++;
		}else
			break;
		
	}
	mounth++;
	return temp / 86400 + 1;
}

int DateTime::getHours()const{
	time_t temp;
	int year = YEAR;
	year += (_time / 126230400)*4;
	temp = _time % 126230400;
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
	    temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
		temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR - 86400 >= 0){
		temp -= SECONDS_IN_YEAR;
		temp -= 86400;
		year++;
	}
	int x;
	int mounth = 0;
	for(int i = 0; i < 11; i++){
		x = mounthLong[i];
		if ((i == 1) && ( year % 4 == 0))
			x++;
		x *= 86400;
		if (temp - x >= 0){
			temp -= x;
			mounth++;
		}else
			break;
		
	}
	mounth++;
	temp %= 86400;
	return temp / 3600 ;
}

int DateTime::getMinutes()const{
	time_t temp;
	int year = YEAR;
	year += (_time / 126230400)*4;
	temp = _time % 126230400;
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
	    temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
		temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR - 86400 >= 0){
		temp -= SECONDS_IN_YEAR;
		temp -= 86400;
		year++;
	}
	int x;
	int mounth = 0;
	for(int i = 0; i < 11; i++){
		x = mounthLong[i];
		if ((i == 1) && ( year % 4 == 0))
			x++;
		x *= 86400;
		if (temp - x >= 0){
			temp -= x;
			mounth++;
		}else
			break;
		
	}
	mounth++;
	temp %= 86400;
	temp %= 3600 ;
	return temp /60;
}

int DateTime::getSeconds()const{
	time_t temp;
	int year = YEAR;
	year += (_time / 126230400)*4;
	temp = _time % 126230400;
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
	    temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR >= 0){
		year++;
		temp -= SECONDS_IN_YEAR;
	}
	if (temp - SECONDS_IN_YEAR - 86400 >= 0){
		temp -= SECONDS_IN_YEAR;
		temp -= 86400;
		year++;
	}
	int x;
	int mounth = 0;
	for(int i = 0; i < 11; i++){
		x = mounthLong[i];
		if ((i == 1) && ( year % 4 == 0))
			x++;
		x *= 86400;
		if (temp - x >= 0){
			temp -= x;
			mounth++;
		}else
			break;
		
	}
	mounth++;
	temp %= 86400;
	temp %= 3600 ;
	return temp % 60;
}

void DateTime::now(){
	time(&_time);
	_time += 3600*4;
}


bool operator == (const DateTime &a, const DateTime &b){
	return a._time == b._time;
}
bool operator != (const DateTime &a, const DateTime &b){
	return a._time != b._time;
}
bool operator > (const DateTime &a, const DateTime &b){
	return a._time > b._time;
}
bool operator < (const DateTime &a, const DateTime &b){
	return a._time < b._time;
}
bool operator <= (const DateTime &a, const DateTime &b){
	return a._time <= b._time;
}
bool operator >= (const DateTime &a, const DateTime &b){
	return a._time >= b._time;
}

TimeSpan operator - (const DateTime &a, const DateTime &b){
	TimeSpan temp;
	temp.setTotalSeconds(a._time - b._time);
	return temp;
}
DateTime operator - (const DateTime &a, const TimeSpan &b){
	DateTime temp;
	temp._time = a._time - b.getTotalSeconds();
	return temp;
}
DateTime operator + (const DateTime &a, const TimeSpan &b){
	DateTime temp;
	temp._time = a._time + b.getTotalSeconds();
	return temp;
}
DateTime operator + (const TimeSpan &b, const DateTime &a){
	return a + b;
}

std::ostream & operator << (std::ostream &output , const DateTime & a){
	//cout << setfill('0') << setw(2)
	output << a.getYear() << '.';
	output << std::setfill('0') << std::setw(2)<< a.getMounth() << '.';
	output << std::setfill('0') << std::setw(2)<< a.getDay() << ' ';
	output << std::setfill('0') << std::setw(2)<< a.getHours() << ':';
	output << std::setfill('0') << std::setw(2)<< a.getMinutes();
	return output;
}
std::istream & operator >> (std::istream &input, DateTime &a){
	unsigned short int year = 1500;
	unsigned short int mounth = 1;
	unsigned short int day = 1;
	unsigned short int hours = 0;
	unsigned short int minutes = 0;
	unsigned short int seconds = 0;
	bool flag = true;
	while (!(
		year >= YEAR &&
		mounth > 0 && mounth <= 12 &&
		day > 0 && (day <= mounthLong[mounth - 1] || day == 29 && mounth == 2 && (year % 4 == 0)) &&
		hours >= 0 && hours < 24 &&
		minutes >= 0 && minutes < 60 &&
		seconds >= 0 && seconds < 60
		)){
		if (flag)
			flag = false;
		else{
			std::cerr << "error please repeat input" << std::endl;
			input.clear();
		}
		input >> year;
		if (isNotClear(input))
			input >> mounth;
		if (isNotClear(input))
			input >> day;
		if (isNotClear(input))
			input >> hours;
		if (isNotClear(input))
			input >> minutes;
		if (isNotClear(input))
			input >> seconds;
	}
	a.setTimeDate(year, mounth, day, hours, minutes, seconds);
	return input;
}