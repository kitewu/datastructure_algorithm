#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int value;
    Node *lch, *rch;
    Node(int v) {
        value=v;
        lch = rch = NULL;
    }
};

Node* rebuiled(int pr[], int in[], int len) {
    if(len == 0)
        return NULL;
    int i = 0;
    while(pr[0] != in[i]) i++;
    Node *t = new Node(pr[0]);
    t->lch = rebuiled(pr+1, in, i);
    t->rch = rebuiled(pr+i+1, in+i+1,len-i-1);
    return t;
}

queue<Node*> que;
vector<int> result;

void show(Node* root) {
    if(NULL == root)
        return;
    que.push(root);
    while(!que.empty()) {
        Node *t = que.front();
        result.push_back(t->value);
        que.pop();
        if(t->lch)
            que.push(t->lch);
        if(t->rch)
            que.push(t->rch);

    }
    int i=0;
    for(; i<result.size()-1; i++) {
        cout << result[i] << " ";
    }
    cout << result[i] << endl;
}

int main() {
    int n;
    cin >> n;
    int pr[n];
    int in[n];
    for(int i=0; i<n; i++)
        cin >> pr[i];
    for(int i=0; i<n; i++)
        cin >> in[i];
    Node *tree = rebuiled(pr, in, n);
    show(tree);
    return 0;
}
