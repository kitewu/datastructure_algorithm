#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX=100005;

struct edge{
    int u, v;
    long long cost;
};

bool comp(const edge& e1, const edge& e2){
    return e1.cost<e2.cost;
}

edge es[MAX];
int par[MAX], ran[MAX];
int n, e;

void init(){
    for(int i=0; i<=n; i++){
        par[i]=i;
        ran[i]=0;
    }
}

int fin(int x){
    if(par[x]==x) return x;
    else return par[x]=fin(par[x]);
}

void unite(int x, int y){
    x=fin(x);
    y=fin(y);
    if(x==y) return;

    if(ran[x]<ran[y]) par[x]=y;
    else{
        par[y]=x;
        if(ran[x]==ran[y]) ran[x]++;
    }
}

bool same(int x, int y){
    return fin(x)==fin(y);
}

long long kruskal(int &cnt){
    sort(es, es+e, comp);
    init();
    long long res=0;
    for(int i=0; i<e; i++){
        edge ed=es[i];
        if(!same(ed.u, ed.v)){
            unite(ed.u, ed.v);
            res+=ed.cost;
            ++cnt;
        }
    }
    return res;
}

int main(){
    int t, kase=0;
    scanf("%d", &t);
    while(t--){
        int c;
        scanf("%d%d%d", &n, &e, &c);
        for(int i=0; i<e; i++){
            scanf("%d%d%lld", &es[i].u, &es[i].v, &es[i].cost);
            es[i].cost*=c;
        }
        int cnt=0;
        long long sum=kruskal(cnt);
        if(cnt+1==n)
            printf("Case #%d: %lld\n", ++kase, sum);
        else printf("Case #%d: -1\n", ++kase);
    }
    return 0;
}
