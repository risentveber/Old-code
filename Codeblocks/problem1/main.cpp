#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int result = 0;
    char previos = 'u';
    int subsuq = 1;
    for(int i = 0; i < str.length(); ++i){
        if (previos != str[i]){
            if(subsuq % 2 != 1)
                result++;
            previos = str[i];
            subsuq = 1;
        }else
            subsuq++;

    }
    if(subsuq % 2 != 1)
                result++;

    cout << result << endl;
    return 0;
}
