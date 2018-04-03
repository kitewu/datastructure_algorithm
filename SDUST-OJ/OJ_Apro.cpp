#include<iostream>
#include<cstdio>
#include<string>
#include<list>
#include<cstring>
#include <algorithm>
#define MAX 30
using namespace std;
//初始化
void Init(int* weight, char* flag, int &sum, string *Huffmancode, list<int> *child){
    memset(weight, 0, MAX * sizeof(int));
    memset(flag, 0, MAX * sizeof(char));
    for(int i = 0; i < MAX; i++){
        Huffmancode[i] = "";
    }
    for(int i = 0; i < MAX; i++){
        child[i].clear();
    }
    sum = 0;
}

//构建数组
void createArray(int* weight, char* flag, string &str, int &sum){
    int len = str.length();
    for(int i = 0; i < len; i++){
        if(weight[str[i] - 'A'] == 0)
            sum++;
        flag[str[i] - 'A'] = str[i];
        weight[str[i] - 'A']++;
    }
}

//选择数
void select(int* weight, int &posmin, int &posmid){
    int minW = 10000, midW = 10000;
    for(int i = 0; i < 26; i++){
        if(weight[i] != 0){
            if((weight[i] < minW) || ((weight[i] == minW) && (posmin < i))){
                midW = minW;
                posmid = posmin;
                minW = weight[i];
                posmin = i;
                continue;
            }
            if((weight[i] < midW) || ((weight[i] == midW) && (posmid < i))){
                midW = weight[i];
                posmid = i;
            }
        }
    }
    if(posmin > posmid){
        posmin = posmin ^ posmid;
        posmid = posmin ^ posmid;
        posmin = posmin ^ posmid;
    }
}

int func(int* weight){
    for(int i = 0; i < 26; i++){
        if(weight[i] != 0){
            return i;
        }
    }
}

//构建树和求哈夫曼编码
void createHuffmanTreeAndHuffmanCode(int* weight, int sum, string* Huffmancode, list<int> *child){
    if(sum == 0){
        Huffmancode[func(weight)] += '0';
        return;
    }
    while(sum--){
        int posmin = 0, posmid = 0;
        select(weight, posmin, posmid);
        //修改数组
        weight[posmin] = weight[posmin] + weight[posmid];
        weight[posmid] = 0;
        //当前两个字符加0和1
        Huffmancode[posmin] += '0';
        Huffmancode[posmid] += '1';
        //两个字符的孩子加0和1
        for(list<int>::iterator it = child[posmin].begin(); it != child[posmin].end(); it++){
            Huffmancode[*it] += '0';
        }
        child[posmin].push_back(posmid);
        for(list<int>::iterator it = child[posmid].begin(); it != child[posmid].end(); it++){
            Huffmancode[*it] += '1';
            child[posmin].push_back(*it);
        }
        child[posmid].clear();
    }
}

//输出结果
void show(string* Huffmancode, char* flag, string str){
    for(int i = 0; i < 26; i++){
        if(flag[i] != 0){
            printf("%c: %s\n", flag[i], Huffmancode[i].c_str());
        }
    }
    int len = str.length();
    long int all = 0;
    for(int i = 0; i < len; i++){
        all += Huffmancode[str[i] - 'A'].length();
    }
    if(all < 50){
        printf("%d ", all);
        for(int i = 0; i < len; i++){
            printf("%s", Huffmancode[str[i] - 'A'].c_str());
        }
        printf("\n");
    }
}

int main()
{
    string str;
    int N = 1;
    while(cin >> str){
        int weight[MAX];
        char flag[MAX];
        string Huffmancode[MAX];
        list<int> child[MAX];
        int sum;

        printf("Case #%d:\n", N++);
        Init(weight, flag, sum, Huffmancode,child);
        createArray(weight, flag, str, sum);
        createHuffmanTreeAndHuffmanCode(weight, --sum, Huffmancode, child);
        show(Huffmancode, flag, str);
    }
}
