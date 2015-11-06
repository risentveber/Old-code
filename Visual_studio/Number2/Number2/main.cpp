#include "iostream"
#include "clocale"
using namespace std;

struct integer
{
	unsigned int s0: 1;
	unsigned int s1 : 1;
	unsigned int s2 : 1;
	unsigned int s3 : 1;
	unsigned int s4 : 1;
	unsigned int s5 : 1;
	unsigned int s6 : 1;
	unsigned int s7 : 1;
	unsigned int s8 : 1;
	unsigned int s9 : 1;
	unsigned int s10: 1;
	unsigned int s11: 1;
	unsigned int s12: 1;
	unsigned int s13: 1;
	unsigned int s14: 1;
	unsigned int s15: 1;
	unsigned int s16: 1;
	unsigned int s17: 1;
	unsigned int s18: 1;
	unsigned int s19: 1;
	unsigned int s20: 1;
	unsigned int s21: 1;
	unsigned int s22: 1;
	unsigned int s23: 1;
	unsigned int s24: 1;
	unsigned int s25: 1;
	unsigned int s26: 1;
	unsigned int s27: 1;
	unsigned int s28: 1;
	unsigned int s29: 1;
	unsigned int s30: 1;
	unsigned int s31: 1;
	
};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	float x;
	integer s;
	printf("%i", sizeof(float));
	printf("Введите пожалуйста число\n");
	scanf ("%f" , &x); 

	if ( x - (int)x < 0 ) // представляем число как integer
	{
		int * num = (int*) &s;   
		*num = n;
		printf ("%2u" , s.s31);
		printf ("%2u" , s.s30);
		printf ("%2u" , s.s29);
		printf ("%2u" , s.s28);
		printf ("%2u" , s.s27);
		printf ("%2u" , s.s26);
		printf ("%2u" , s.s25);
		printf ("%2u" , s.s24);
		printf ("%2u" , s.s23);
		printf ("%2u" , s.s22);
		printf ("%2u" , s.s21);
		printf ("%2u" , s.s20);
		printf ("%2u" , s.s19);
		printf ("%2u" , s.s18);
		printf ("%2u" , s.s17);
		printf ("%2u" , s.s16);
		printf ("%2u" , s.s15);
		printf ("%2u" , s.s14);
		printf ("%2u" , s.s13);
		printf ("%2u" , s.s12);
		printf ("%2u" , s.s11);
		printf ("%2u" , s.s10);
		printf ("%2u" , s.s9);
		printf ("%2u" , s.s8);
		printf ("%2u" , s.s7);
		printf ("%2u" , s.s6);
		printf ("%2u" , s.s5);
		printf ("%2u" , s.s4);
		printf ("%2u" , s.s3);
		printf ("%2u" , s.s2);
		printf ("%2u" , s.s1);
		printf ("%2u" , s.s0);
		printf ("\n");

	}
	else  // представляем число как real
	{
		float * num = (float*) &s;
		*num = x;
		printf ("Знак числа\n");
		printf ("%2u" , s.s31);
		printf ("\n");

		printf ("Степень экспоненты\n");
		printf ("%2u" , s.s30);
		printf ("%2u" , s.s29);
		printf ("%2u" , s.s28);
		printf ("%2u" , s.s27);
		printf ("%2u" , s.s26);
		printf ("%2u" , s.s25);
		printf ("%2u" , s.s24);
		printf ("%2u" , s.s23);
		printf ("\n");

		printf ("Мантисса\n");
		printf ("%2u" , s.s22);
		printf ("%2u" , s.s21);
		printf ("%2u" , s.s20);
		printf ("%2u" , s.s19);
		printf ("%2u" , s.s18);
		printf ("%2u" , s.s17);
		printf ("%2u" , s.s16);
		printf ("%2u" , s.s15);
		printf ("%2u" , s.s14);
		printf ("%2u" , s.s13);
		printf ("%2u" , s.s12);
		printf ("%2u" , s.s11);
		printf ("%2u" , s.s10);
		printf ("%2u" , s.s9);
		printf ("%2u" , s.s8);
		printf ("%2u" , s.s7);
		printf ("%2u" , s.s6);
		printf ("%2u" , s.s5);
		printf ("%2u" , s.s4);
		printf ("%2u" , s.s3);
		printf ("%2u" , s.s2);
		printf ("%2u" , s.s1);
		printf ("%2u" , s.s0);
		printf ("\n");



	};
	

	
	
	system ( "pause" );
	return 0;
}