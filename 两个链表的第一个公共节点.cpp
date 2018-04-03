#include<iostream>
#include<stack>
using namespace std;

typedef struct ListNode {
    int value;
    ListNode* next;
    ListNode(int v):value(v), next(NULL) {
    }
} *List;

//方法1，暴力

ListNode* FindFirstCommonNode1(List head1, List head2) {
}

//方法2，借助栈
ListNode* FindFirstCommonNode2(List head1, List head2) {
    if(!head1 || ! head2)
        return NULL;
    stack<ListNode*> s1, s2;
    List p1 = head1, p2 = head2;
    while(p1) {
        s1.push(p1);
        p1 = p1->next;
    }
    while(p2) {
        s2.push(p2);
        p2 = p2->next;
    }
    ListNode *common = NULL;
    while(!s1.empty() && !s2.empty()) {
        if(s1.top() == s2.top()) {
            common = s1.top();
            s1.pop();
            s2.pop();
        } else
            break;
    }
    return common;
}


int getLength(List head) {
    int len = 0;
    List p = head;
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

//方法3
ListNode* FindFirstCommonNode3(List head1, List head2) {
    if(!head1 || ! head2)
        return NULL;

    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int lendiff = len1 - len2;
    List p_long = head1;
    List p_short = head2;
    if(len1 < len2) {
        p_long = head2;
        p_short = head1;
        lendiff = len2 - len1;
    }
    for(int i=0; i<lendiff; i++)
        p_long = p_long->next;
    while(p_long != NULL && p_short != NULL && p_long != p_short) {
        p_long = p_long->next;
        p_short = p_short->next;
    }
    return p_long;
}

int main() {

}
