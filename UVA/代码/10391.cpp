#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

string word[140000];
map<string, int> maps[26];

int main()
{
    int n = 0;
    string str;
    while(cin >> str)
    {
        maps[str[0] - 'a'][str] = 1;
        word[n++] = str;
    }
    string a, b;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < word[i].size(); j++)
        {
            a = word[i].substr(0,j + 1);
            if(maps[a[0] - 'a'].empty())
                continue;
            if(!maps[a[0] - 'a'][a])
                continue;
            b = word[i].substr(j + 1);
            if(b.empty() || maps[b[0] - 'a'].empty())
                continue;
            if(!maps[b[0] - 'a'][b])
                continue;
            cout << word[i] << endl;
            break;
        }
    }
    return 0;
}
