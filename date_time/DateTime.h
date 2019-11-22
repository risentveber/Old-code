#include <iostream>
#include <iomanip>
#define YEAR 1970
#define SECONDS_IN_YEAR 31536000

bool isNotClear(std::istream & input);

typedef enum mounthes{
	january = 1,
	february = 2,
	march = 3,
	april = 4,
	may = 5,
	june = 6,
	july = 7,
	august = 8,
	september = 9,
	october = 10,
	november = 11,
	december = 12
};

static int mounthLong[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


class TimeSpan{
private:
	__int64 _span;
public:
	TimeSpan();
	TimeSpan(__int64);
	void setTotalSeconds(__int64 );
	__int64 getTotalSeconds() const;
	__int64 getTotalHours() const;
	__int64 getTotalMinutes() const;
	__int64 getTotalDays() const;
	friend TimeSpan operator - (const TimeSpan &, const TimeSpan &);
	friend TimeSpan operator + (const TimeSpan &, const TimeSpan &);
	friend bool operator == (const TimeSpan &, const TimeSpan &);
	friend bool operator != (const TimeSpan &, const TimeSpan &);
	friend bool operator < (const TimeSpan &, const TimeSpan &);
	friend bool operator > (const TimeSpan &, const TimeSpan &);
	friend bool operator <= (const TimeSpan &, const TimeSpan &);
	friend bool operator >= (const TimeSpan &, const TimeSpan &);
	friend std::ostream & operator << (std::ostream &, const TimeSpan &);
	friend std::istream & operator >> (std::istream &, TimeSpan &);
};

class DateTime{
private:
	time_t _time;
public:
	DateTime();
	DateTime(unsigned int year, unsigned char mounth = 1, unsigned char day = 1, unsigned char hours = 0, unsigned char minutes = 0, unsigned char seconds = 0);
	void setTimeDate(unsigned int year, unsigned char mounth = 1, unsigned char day = 1, unsigned char hours = 0, unsigned char minutes = 0, unsigned char seconds = 0);
	void now();
	int getMounth() const;
	int getHours() const;
	int getDay() const;
	int getSeconds() const;
	int getYear() const;
	int getMinutes() const;
	friend bool operator == (const DateTime &, const DateTime &);
	friend bool operator != (const DateTime &, const DateTime &);
	friend bool operator < (const DateTime &, const DateTime &);
	friend bool operator > (const DateTime &, const DateTime &);
	friend bool operator <= (const DateTime &, const DateTime &);
	friend bool operator >= (const DateTime &, const DateTime &);
	friend TimeSpan operator - (const DateTime &, const DateTime &);
	friend DateTime operator - (const DateTime &, const TimeSpan &);
	friend DateTime operator + (const DateTime &, const TimeSpan &);
	friend std::ostream & operator << (std::ostream &, const DateTime &);
	friend std::istream & operator >> (std::istream &, DateTime &);
};





