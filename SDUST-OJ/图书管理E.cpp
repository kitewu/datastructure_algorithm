#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 30001;
int num=0;
int n;

struct Book{
    string id,s;
    int r,c;
} book[maxn];

/*交换函数*/
void swaps(Book *x, Book *y){
    Book temp = *x;
    *x = *y;
    *y = temp;
}

/*快速排序*/
void sssss(int m,int n){
    int i, j, k;
    string key;
    if(m < n){
        k = (m + n) / 2;
        swaps(&book[m], &book[k]);
        key = book[m].id;
        i = m + 1;
        j = n;
        while(i <= j){
            while((i <= n) && (book[i].id <= key))
                i++;
            while((j >= m) && (book[j].id > key))
                j--;
            if(i < j)
                swaps(&book[i], &book[j]);
        }
        swaps(&book[m], &book[j]);
        sssss(m, j - 1);
        sssss(j + 1, n);
    }
}

/*二分查找*/
int fffff(Book Array[], int start, int end, string key){
    int left, right;
    int mid;
    left = start;
    right = end;
    while(left <= right){
        mid = (left + right) / 2;
        if(key == Array[mid].id)
            return mid;
        else if(key < Array[mid].id)
            right = mid - 1;
        else if(key > Array[mid].id)
            left = mid+1;
    }
}

void Create(){
    for(int i = 1; i <= n; i++){
        cin >> book[num].id >> book[num].s >> book[num].r >> book[num].c;
        num++;
    }
    sssss(0, n - 1);
}

void Operator(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        string str;
        cin >> str;
        int x = fffff(book, 0, n - 1, str);
        cout << book[x].s << " " << book[x].r << " " << book[x].c << endl;
    }
}
int main()
{
    while(scanf("%d",&n) != EOF){
        Create();
        Operator();
    }
}
