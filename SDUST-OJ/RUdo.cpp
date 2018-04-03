#include<iostream>
#include<list>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int N;
    cin >> N;
    getchar();
    while(N--){
        string str;
        list<char> li;
        list<char>::iterator it = li.end();
        list<char>::iterator it1;
        while(getline(cin, str)){
            if(str[0] == '#' && str[1] == 'U'){
                if(it != li.begin()){
                    it--;
                }
            }
            else if(str[0] == '#' && str[1] == 'R'){
                if(it != li.end()){
                    it++;
                }
                for(it1 = li.begin(); it1 != it; it1++){
                    cout << *it1;
                }
            }
            else if(str[0] != '#'){
                if(it != li.end()){
                    it1 = it;
                    it1++;
                    while(it1 != li.end()){
                        li.pop_back();
                    }
                }
                for(int i = 0; i < str.length(); i++){
                    li.push_back(str[i]);
                }
                it = li.end();
            }
        }
    }
}
