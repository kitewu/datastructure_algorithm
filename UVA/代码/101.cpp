#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int maxn = 30;
vector<int> v[maxn];
int N;

void findPos(int &pos, int &h, int a)
{
    if(v[pos].size() > 0 && v[pos][h] == a)
        return;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < v[i].size(); j++)
            if(v[i][j] == a)
            {
                pos = i;
                h = j;
                return;
            }
}

//a上面的全部归位
void mClear(int pos, int h, int a)
{
    for(int i = h + 1; i < v[pos].size(); i++)
        v[v[pos][i]].push_back(v[pos][i]);
    v[pos].resize(h + 1);
}

//把一个及顶部的移动到另一个顶部
void mMove(int posa, int ha, int posb, int hb, int a)
{
    for(int i = ha; i < v[posa].size(); i++)
        v[posb].push_back(v[posa][i]);
    v[posa].resize(ha);
}

void show()
{
    for(int i = 0; i < N; i++)
    {
        printf("%d:", i);
        for(int j = 0; j < v[i].size(); j++)
        {
            printf(" %d", v[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    while(scanf("%d", &N) == 1)
    {
        for(int i = 0; i < N; i++)
        {
            v[i].clear();
            v[i].push_back(i);
        }
        int a, b;
        string op1, op2;
        while(cin >> op1)
        {
            if(op1 == "quit")
                break;
            cin >> a >> op2 >> b;
            int posa = a;
            int ha = 0;
            int posb = b;
            int hb = 0;
            findPos(posa, ha, a);
            findPos(posb, hb, b);
            if(posa == posb)
                continue;
            if(op1 == "move")
            {
                mClear(posa, ha, a);
                if(op2 == "onto")
                {
                    mClear(posb, hb, b);
                    v[posb].push_back(a);
                    v[posa].pop_back();
                }
                else if(op2 == "over")
                {
                    v[posb].push_back(a);
                    v[posa].pop_back();
                }
            }
            else if(op1 == "pile" && op2 == "onto")
            {
                mClear(posb, hb, b);
                mMove(posa, ha, posb, hb,a);
            }
            else if(op1 == "pile" && op2 == "over")
            {
                mMove(posa, ha, posb, hb,a);
            }

        }
        show();
    }
    return 0;
}
