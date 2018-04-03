#include<iostream>
#include<string>
#include<sstream>
#define maxn 10010
using namespace std;

int in[maxn];
int post[maxn];
int lch[maxn];
int rch[maxn];
int n;

bool input(int *in){
    string line;
    if(!getline(cin, line))
        return false;
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x) in[n++] = x;
    return true;
}

int build(int L1, int R1, int L2, int R2){
    if(L1 > R1) return 0;
    int root = post[R2];
    int p = L1;
    while(in[p] != root)
        p++;
    int cnt = p - L1;//左子树节点个数
    lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
    rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
    return root;
}

int best, best_sum;
void dfs(int u, int sum){
    sum += u;
    if(!lch[u] && !rch[u]){
        if(sum < best_sum || (sum == best_sum && u < best)){
            best = u;
            best_sum = sum;
        }
    }
    if(lch[u]) dfs(lch[u], sum);
    if(rch[u]) dfs(rch[u], sum);
}

int main(){
    while(input(in)){
        input(post);
        build(0, n - 1, 0, n - 1);
        best_sum = 1000000000;
        dfs(post[n - 1], 0);
        cout << best << endl;
    }
    return 0;
}
