#include <iostream>
#include <cstdio>
#include <cstring>
int main()
{
    int n, q;
    int len;
    while(scanf("%d%d",&n, &q)!= EOF){
        len = n + 20;
        int *T = new int[len];
        memset(T, 0, len * sizeof(int));
        while(--n){
            int u, v;
            scanf("%d%d",&u, &v);
            T[v] = u;
        }
        while(q--){
            int a, b;
            scanf("%d%d",&a, &b);
            bool *parent = new bool[len];
            memset(parent, false, len * sizeof(bool));
            while(a != 0){
                parent[a] = true;
                a = T[a];
            }
            while(b != 0){
                if(parent[b] == true){
                    printf("%d\n", b);
                    break;
                }
                else b = T[b];
            }
            delete[] parent;
        }
        delete[] T;
    }
}
