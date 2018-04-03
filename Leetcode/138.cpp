#include<iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;

        ///假设：l1代表原链表中的节点；l2代表新链表中的节点
        RandomListNode *new_head, *l1, *l2;

        ///第一步：在每一个l1后面创建一个l2，并让l1指向l2，l2指向下一个l1；
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l2->random = l1->random;
            l1->next = l2;
        }

        ///第二步：给l2的random赋值，l1的random的next指向的就是l2的random的目标；
        new_head = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random != NULL) l1->next->random = l1->random->next;
        }

        ///第三步：需要将整个链表拆成两个链表，具体做法是让l1
        ///的next指向后面的后面;l2的next也指向后面的后面。
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL)
                l2->next = l2->next->next;
        }
        return new_head;
    }
};

int main() {
    return 0;
}
