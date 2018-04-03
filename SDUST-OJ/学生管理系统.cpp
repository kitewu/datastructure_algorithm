#include<cstring>
#include<cstdio>
const int MAX_STU = 2010;
const int MOD = 2337;

typedef struct{
    char name[25];
    int num;
    int chinese;
    int math;
    int english;
}Student, *STU;

int N, P, flag = 0;
STU stu1[MOD], stu2[MAX_STU];

void Init(){
    memset(stu1, 0, sizeof(stu1));
    for(int i = 0; i < N; i++){
        STU t = new Student;
        scanf("%s%d%d%d%d", t->name, &(t->num), &(t->chinese), &(t->math), &(t->english));
        if(t->chinese < 60 || t->math < 60 || t->english < 60)
            stu2[flag++] = t;
        int pos = t->num % MOD;
        if(stu1[pos] == 0)
            stu1[pos] = t;
        else{
            int tt = MOD;
            while(tt--){
                pos++;
                if(pos == MOD)
                    pos = 0;
                if(stu1[pos] == 0){
                    stu1[pos] = t;
                    break;
                }
            }
        }
    }
}

void Show(){
    for(int i = 0; i < flag; i++)
        printf("%s %d %d %d %d\n", stu2[i]->name, stu2[i]->num, stu2[i]->chinese, stu2[i]->math, stu2[i]->english);
}

void Operator(){
    while(P--){
        int x;
        scanf("%d", &x);
        int pos = x % MOD;
        if(stu1[pos] != 0 && stu1[pos]->num == x){
            printf("%s %d %d %d %d\n", stu1[pos]->name, stu1[pos]->num, stu1[pos]->chinese, stu1[pos]->math, stu1[pos]->english);
        }
        else{
            int tt = MOD;
            bool have = false;
            while(tt--){
                pos++;
                if(pos == MOD)
                    pos = 0;
                if(stu1[pos] != 0 && stu1[pos]->num == x){
                    printf("%s %d %d %d %d\n", stu1[pos]->name, stu1[pos]->num, stu1[pos]->chinese, stu1[pos]->math, stu1[pos]->english);
                    have = true;
                    break;
                }
            }
            if(!have)
                printf("NOT FOUND\n");
        }
    }
}

int main()
{
    scanf("%d%d", &N, &P);
    Init();
    Show();
    Operator();
}
