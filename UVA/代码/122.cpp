#include<iostream>
#include<string>
#include<queue>
#include<sstream>
using namespace std;

typedef struct Node {
    int v;
    bool have;
    struct Node *lch, *rch;
    Node() : have(false), lch(NULL), rch(NULL), v(0){};
} Node, *Tree;

Tree root;
bool ok = true;

void check(Tree t){
    if(t == NULL)
        return;
    if(!t->have){
        ok = false;
        return;
    }
    check(t->lch);
    check(t->rch);
}

void output() {
    if(!ok){ cout << "not complete" << endl; return; }
    check(root);
    if(!ok){ cout << "not complete" << endl; return; }
    queue<Tree> qu;
    qu.push(root);
    bool flag = false;
    while(!qu.empty()){
        Tree t = qu.front();
        qu.pop();
        if(flag)
            cout << " ";
        flag = true;
        cout << t->v;
        if(t->lch != NULL)
            qu.push(t->lch);
        if(t->rch != NULL)
            qu.push(t->rch);
    }
    cout << endl;
}

void deleteTree(Tree t) {
    if(t == NULL)
        return;
    else {
        deleteTree(t->lch);
        deleteTree(t->rch);
        delete t;
    }
}

void addNode(int n, string &str) {
    Tree p = root;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'L') {
            if(p->lch == NULL) p->lch = new Node();
            p = p->lch;
        } else if(str[i] == 'R') {
            if(p->rch == NULL) p->rch = new Node();
            p = p->rch;
        }
    }
    if(p->have) {
        ok = false;
        return;
    }
    p->v = n;
    p->have = true;
}

bool input() {
    ok = true;
    root = new Node();
    string str;
    while(cin >> str) {
        if(str == "()") {
            output();
            deleteTree(root);
            return true;
        }
        str = str.substr(1, str.size() - 2);
        for(int i = 0; i < str.size(); i++)
            if(str[i] == ',')
                str[i] = ' ';
        stringstream ss(str);
        int num = 0;
        ss >> num >> str;
        addNode(num, str);
    }
    return false;
}

int main() {
    while(input());
    return 0;
}
