#include<iostream>
using namespace std;

typedef struct List{
    int value;
    struct LNode* next;
}LNode, *List;

List Merge(List L1, List L2){
    List L3 = new LNode;
    if(!L1 && !L2)
        return L3;
    if(!L1){
        L3->
    }


    List p1 = L1;
    List p2 = L2;
    List p3 = L3;
    while(p1 && p2){
        if(p1->data <= p2->data){
            p3->next = p1;
            p1 = p1->next;
        }else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
}

int main()
{
    return 0;
}
//#include<iostream>
//using namespace std;
//
//typedef struct LNode{
//    int value;
//    struct LNode* next;
//}LNode, *List;
//
//List Merge(List L1, List L2){
//    List L3 = new LNode;
//    if(!L1 && !L2)
//        return L3;
//    if(!L1){
//        L3->
//    }
//        return L1;
//
//
//    List p1 = L1;
//    List p2 = L2;
//    List p3 = L3;
//    while(p1 && p2){
//        if(p1->data <= p2->data){
//            p3->next = p1;
//            p1 = p1->next;
//        }else {
//            p3->next = p2;
//            p2 = p2->next;
//        }
//        p3 = p3->next;
//    }
//}
//
//int main()
//{
//    return 0;
//}
