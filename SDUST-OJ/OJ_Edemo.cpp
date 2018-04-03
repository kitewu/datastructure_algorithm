#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX_SIZE 30010
using namespace std;

int calroot[MAX_SIZE];
int lch[MAX_SIZE];
int rch[MAX_SIZE];
vector<int> V[MAX_SIZE];
vector<int>::iterator it;
queue<int> Q;
int num;//节点总数
int root;//根节点

//初始化
void Init(){
    memset(calroot, 0, MAX_SIZE * sizeof(int));
    memset(lch, 0, MAX_SIZE * sizeof(int));
    memset(rch, 0, MAX_SIZE * sizeof(int));
    for(int i = 0; i < MAX_SIZE; i++){
        V[i].clear();
    }
    while(!Q.empty()){
        Q.pop();
    }
}

//获得根节点
void getRoot(){
    for(int i = 1; i < num + 1; i++){ //求根节点
        if(calroot[i] == 0){
            root = i;
            break;
        }
    }
}

//求树深
int getTreeDeep(int root, int deep){
    int maxdeep = 0;
    if(V[root].size() == 0){
        return deep;
    }
    for(it = V[root].begin(); it != V[root].end(); it++){
        int t = getTreeDeep(*it, deep + 1);
        if(t >= maxdeep)
            maxdeep = t;
        return maxdeep;
    }
}

void CreateBiTree(int r){
    for(it = V[r].begin(); it != V[r].end(); it++){
        if(it == V[r].begin()){
            lch[r] = *it;
            if(V[*it].size() != 0)
                 Q.push(*it);
        }
    }
}

int main()
{
    cin >> num;
    Init();
    int temp = num;
    temp--;
    while(temp--){
        int pa, ch;
        cin >> pa >> ch;
        V[pa].push_back(ch);
        calroot[ch]++;
    }
    getRoot();
    cout << getTreeDeep(root, 1) << " ";
    memset(calroot, 0, (num + 1) * sizeof(int));
    for(int i = 1; i < num + 1; i++){
        if(V[i].size() != 0){
            for(it = V[i].begin(); it != V[i].end(); it++){
                calroot[*it] = i;
            }
        }
    }
    for(int i = 0; i < num + 1; i++){
        cout << calroot[i] << " ";
    }
}
