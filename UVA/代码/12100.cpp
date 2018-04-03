#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
using namespace std;

bool findM(list<int> &ll)
{
    for(list<int>::iterator it = ll.begin(); it != ll.end(); it++)
        if(*it > *ll.begin())
            return true;
    return false;
}

int main()
{
    int N;
    scanf("%d", &N);
    while(N--){
        int n, pos;
        list<int> ll;
        scanf("%d%d", &n, &pos);
        int temp;
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            ll.push_back(temp);
        }
        int wait_time = 1;
        while(1){
            if(findM(ll)){
                ll.push_back(*ll.begin());
                ll.erase(ll.begin());
                if(pos == 0)
                    pos = ll.size() - 1;
                else
                    pos--;
            }else{
                if(pos == 0){
                    cout << wait_time << endl;
                    break;
                }else{
                    ll.erase(ll.begin());
                    wait_time++;
                    pos--;
                }
            }
        }
    }
}
