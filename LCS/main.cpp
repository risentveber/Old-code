#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 1000
#define max(a,b) ((a>b) ? a : b)




int main()
{
	int * L[N];
	for(int i = 0; i < N; i++)
	{
		L[i] = (int*)malloc(N*sizeof(int));
	}
    char a[N];
    char b[N];


    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    int m = strlen(b);

    for(int j = 0; j <= m ; j++ )
    {
       L[0][j] = 0;
    }

    for(int i = 0; i <= n; i++)
    {
       L[i][0] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
       for(int j = 1; j <= m ; j++)
       {

          if( a[i-1] == b[j-1] )
             L[i][j] = L[i-1][j-1] + 1;
          else
             L[i][j] = max( L[i][j-1], L[i-1][j] );
       }
    }

	int result =  L[n][m];
    int x = n;
	int y = m;
	char* massiv = (char*)malloc((result+1)*sizeof(char));
	massiv[result] = '\0';

	for(int i = result-1; i >= 0; )
	{
		if( a[x-1] == b[y-1] )
		{

             massiv[i] = a[x-1];
			 i--;
			 x--;
			 y--;
		}
          else
        {
			if (L[x-1][y] < L[x][y-1])
				y--;
			else
				x--;
		};
	}
	puts(massiv);
	system("PAUSE");
    return 0;
}
