#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct{
    char name[30];
    double math, english, political, all;
}STU;

//比较
bool compare(STU* stu1, STU* stu2){
    if(stu1->all < stu2->all)
        return true;
    if(stu1->all == stu2->all && (strcmp(stu1->name, stu2->name) > 0))
        return true;
    return false;
}

//快速排序
void ssssssss(STU** stu, int l, int r){
    if (l < r){
        int i = l, j = r;
        STU* maxx = stu[l];
        while (i < j){
            while(i < j && compare(stu[j], maxx))
                j--;
            if(i < j)
                stu[i++] = stu[j];
            while(i < j && compare(maxx, stu[i]))
                i++;
            if(i < j)
                stu[j--] = stu[i];
        }
        stu[i] = maxx;
        ssssssss(stu, l, i - 1);
        ssssssss(stu, i + 1, r);
    }
}

//输出
void Print(STU** stu, int n){
    for(int i = 0; i < n; i++)
        printf("%s %.1lf %.1lf %.1lf %.1lf\n",stu[i]->name, stu[i]->math, stu[i]->english, stu[i]->political, stu[i]->all);
}

int main()
{
    int num;
    while(scanf("%d", &num) != EOF){
        double W1, W2, W3;
        scanf("%lf%lf%lf", &W1, &W2, &W3);
        getchar();
        STU* stu[num + 10];
        for(int i = 0; i < num; i++){
            stu[i] = new STU;
            scanf("%s%lf%lf%lf", stu[i]->name, &(stu[i]->math), &(stu[i]->english), &(stu[i]->political));
            stu[i]->all = stu[i]->math * W1 + stu[i]->english * W2 + stu[i]->political * W3;
        }
        ssssssss(stu, 0, num - 1);
        Print(stu, num);
    }
}
