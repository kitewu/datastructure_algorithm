//#include<stdio.h>
//int arr[10001];
//
//int main()
//{
//    int a,b;
//    int i;
//    arr[1]=1;
//    arr[2]=2;
//    for(i=3; i<10001; i++)
//    {
//        long long temp=i;
//        int cnt=0;
//        while(1)
//        {
//            if(temp&(0x01))//ÆæÊý
//            {
//                temp*=3;
//                temp+=1;
//                cnt++;
//            }
//            else
//            {
//                cnt++;
//                temp>>=1;
//            }
//            if(temp<i)
//            {
//                arr[i]=cnt+arr[temp];
//                break;
//            }
//        }
//    }
//    int t;
//    while(scanf("%d%d",&a,&b)!=EOF)
//    {
//        if(a>b)
//        {
//            t=a;
//            a=b;
//            b=t;
//        }
//        int max=0;
//        for(i=a; i<=b; i++)
//        {
//            if(max<arr[i])
//            {
//                max=arr[i];
//            }
//        }
//        printf("%d/n",max);
//    }
//    return 0;
//}

#include<iostream>
#include<cstdio>
const int MAX=50050;
using namespace std;
struct Node {
    int parent;
    int lchild;
    int rchild;
    int flag;
} t[MAX];
int main() {
    int n,q;
    while(scanf("%d%d",&n,&q)== 2) {

        for(int i=1; i<=n; i++) {
            t[i].parent=0;
            t[i].lchild=0;
            t[i].rchild=0;
            t[i].flag=0;
        }
        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            t[v].parent=u;
            if(!t[u].lchild) t[u].lchild=v;
            else t[u].rchild=v;
        }
        while(q--) {
            int a,b;
            scanf("%d%d",&a,&b);
            while(t[a].parent) {
                t[a].flag=1;
                a=t[a].parent;
            }
            t[a].flag=1;
            while(!t[b].flag) {
                b=t[b].parent;
            }
            if(t[b].flag)
                printf("%d\n",b);
            for(int i=1; i<=n; i++) {
                t[i].flag=0;
            }
        }

    }
    return 0;
}
