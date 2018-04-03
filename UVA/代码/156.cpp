#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

string getOrder(string str)
{
    for(int i = 0; i <str.length(); i++)
        str[i] = tolower(str[i]);
    sort(str.begin(), str.end());
    return str;
}

int main()
{
    string str;
    map<string, vector<string> > maps;
    while(cin >> str)
    {
        if(str[0] == '#')
            break;
        string order = getOrder(str);
        maps[order].push_back(str);
    }
    set<string> result;
    for(map<string, vector<string> >::iterator it = maps.begin(); it != maps.end(); it++)
    {
        if((it->second).size() == 1)
            result.insert(it->second[0]);
    }
    for(set<string>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}

