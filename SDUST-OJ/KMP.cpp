#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;
void get_nextvalue(char *s, int *nextval)
{
    int i = 1;
    nextval[1] = 0;
    int j = 0;
    while(i < s[0]){
        if(j == 0 || s[i] == s[j]){
            ++i;
            ++j;
            nextval[i] = j;
            if(s[i] != s[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }else
            j = nextval[j];
    }
}

int index_KMP(char *s, char *t, int *nextval)
{
    int i = 1;
    int j = 1;
    while(i <= s[0] && j <= t[0]){
        if(j == 0 || s[i] == t[j]){
            ++i;
            ++j;
        }else
            j = nextval[j];
    }
    if(j > t[0])
        return i - t[0];
    else
        return 0;
}

void print_nextval(int *nextval)
{
    for(int x = 1; x <= nextval[0]; x++){
        cout << nextval[x] << " ";
    }
    cout << endl;
}

int main()
{
    char temp[1000];
    char S[1000];
    char T[1000];
    int nextval[1000];

    gets(temp);
    int len = strlen(temp);
    S[0] = len;
    for(int i = 0; i < len; i++){
        S[i + 1] = temp[i];
    }

    gets(temp);
    len = strlen(temp);
    T[0] = len;
    nextval[0] = len;
    for(int i = 0; i < len; i++){
        T[i + 1] = temp[i];
    }

    get_nextvalue(T,nextval);
    print_nextval(nextval);

    cout << index_KMP(S, T, nextval) << endl;
}
