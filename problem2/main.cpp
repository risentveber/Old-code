#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int result = 0;
    int alfa[28];
    for(int i = 0; i < 28; ++i){
        alfa[i] = 0;
    }
    for(int i = 0; i < str.length(); ++i){
        alfa[str[i]-'A']++;
    }
    char tmp_char;
    int tmp_result, tmp_result2;
    int p;
    int f;
    for(int i = 0; i < 28; ++i){
        tmp_char = 'A' + i;
        tmp_result = 0;
        tmp_result2 = 0;
        int f = 0;
        p = -1;
        for(int k = 0; k < str.length(); ++k){
            if (str[k] == tmp_char){
                if ((k - p) % 2 == 0 && p >= 0){
                tmp_result++;
                p = k + 1;
                }
                else{
                    if (f != 0)
                        f = k;
                }
                if (p < 0){
                    tmp_result++;
                    p = k + 1;
                }
            }

        }
        p = -1;
        for(int k = f; k < str.length(); ++k){
            if (str[k] == tmp_char){
                if ((k - p) % 2 == 0 && p >= 0){
                tmp_result2++;
                p = k + 1;
                }
                if (p < 0){
                    tmp_result2++;
                    p = k + 1;
                }
            }

        }

        if (tmp_result > result)
            result = tmp_result;
        if (tmp_result2 > result)
            result = tmp_result2;
    }


    cout << result << endl;
    return 0;
}
