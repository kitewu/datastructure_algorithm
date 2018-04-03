#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cctype>
#define MAX 30100
using namespace std;

typedef struct{
    char data[40];
    char name[100];
    int c, r;
} Node;

int n, q;


int getPos(char* node){
    int len = strlen(node);
    char t[6];
    int flag = 0;
    int sum = 0;
    for(int i = 5; i < len; i++){
        if(isdigit(node[i])){
            t[flag++] = node[i];
        }else if(node[i] == '-'){
            t[flag++] = 0;
            sum += atoi(t);
            flag = 0;
        }
    }
    return sum % MAX;
}

void PutNode(Node** My, Node* node){
    int pos = getPos(node->data);
    while(true){
        if(My[pos] == 0){
            My[pos] = node;
            break;
        }else{
            pos++;
            if(pos == MAX)
                pos = 0;
        }
    }
}

//´´½¨
void CreateMap(Node** My){
    getchar();
    while(n--){
        Node* node = new Node;
        scanf("%s%s%d%d", node->data, node->name, &(node->r), &(node->c));
        PutNode(My, node);
    }
}

//²Ù×÷
void OperatorMap(Node** My){
    scanf("%d", &q);
    getchar();
    while(q--){
        char t[40];
        gets(t);
        int pos = getPos(t);
        int tt = MAX + 1;
        while(tt--){
            if(My[pos] != 0){
                if(strcmp(My[pos]->data, t) == 0){
                    printf("%s %d %d\n", My[pos]->name, My[pos]->r, My[pos]->c);
                    break;
                }
            }
            else{
                pos++;
                if(pos == MAX)
                    pos = 0;
            }
        }
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        Node* My[MAX] = {0};
        CreateMap(My);
        OperatorMap(My);
    }
}
