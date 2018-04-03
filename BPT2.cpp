#include <stdio.h>
#include <stdlib.h>

#define MinDegree 4

typedef int ElementType;
typedef int* PtrElementType;
enum Bool {
    False = 0,
    True = 1
};
typedef enum Bool BoolType;


typedef struct TreeNode *PtrBpNode;
typedef struct TreeNode BpNode;
struct TreeNode {
    int Num;
    BoolType IsLeaf;
    PtrElementType Key;
    PtrBpNode *Child;
    PtrBpNode Next;
};

typedef struct Tree *PtrBp;
struct Tree {
    PtrBpNode Root;
};

PtrBpNode BpAllocateNode(BoolType IsLeaf);
void BpSpilitNode(PtrBpNode SpilitNodeP, int ChildIndex);
void BpInsertNonFull(PtrBpNode CurrentNode, ElementType Val);
void BpInsert(PtrBp T, ElementType Val);
void BpMerge(PtrBp T, PtrBpNode CurrentNode, int LeftIndex, int RightIndex);
void BpDelete(PtrBp T, PtrBpNode CurrentNode, ElementType Val);
void ShiftKey(PtrElementType Key, BoolType Direction, int Begin, int End);
void ShiftChild(PtrBpNode *Child, BoolType Direction, int Begin, int End);
int GetIndex(PtrElementType Key, int Size, ElementType Val);
void BpPrintTree(PtrBpNode Root);
void BpCreateTree(PtrBp T);

int main() {
    PtrBp T = (PtrBp)malloc(sizeof(struct Tree));

    T->Root = BpAllocateNode(True);
    BpCreateTree(T);

    //printf("B_Tree after delete 11:\n");
    //BTDelete(T, T->Root, 11);
    //BTPrintTree(T->Root);
    printf("Bp_Tree after delete 16:\n");
    BpDelete(T, T->Root, 16);
    BpPrintTree(T->Root);
    printf("Bp_Tree after delete 18:\n");
    BpDelete(T, T->Root, 18);
    BpPrintTree(T->Root);
    printf("Bp_Tree after delete 20:\n");
    BpDelete(T, T->Root, 20);
    BpPrintTree(T->Root);
    printf("Bp_Tree after delete 19:\n");
    BpDelete(T, T->Root, 19);
    BpPrintTree(T->Root);
    printf("Bp_Tree after delete 0:\n");
    BpDelete(T, T->Root, 0);
    BpPrintTree(T->Root);
    printf("Bp_Tree after delete 5:\n");
    BpDelete(T, T->Root, 5);
    BpPrintTree(T->Root);
    printf("Bp_Tree after delete 2:\n");
    BpDelete(T, T->Root, 2);
    BpPrintTree(T->Root);

    return 0;
}

PtrBpNode BpAllocateNode(BoolType IsLeaf) {
    int i;
    PtrBpNode NewNode = (PtrBpNode)malloc(sizeof(BpNode));

    NewNode->Num = 0;
    if(True == IsLeaf) {
        NewNode->IsLeaf = True;
    } else {
        NewNode->IsLeaf = False;
    }
    NewNode->Key = (PtrElementType)malloc(sizeof(ElementType) * (MinDegree * 2 - 1));
    NewNode->Child =(PtrBpNode*)malloc(sizeof(PtrBpNode) * MinDegree * 2);
    for(i = 0; i < MinDegree * 2; i++) {
        NewNode->Child[i] = NULL;
    }
    NewNode->Next = NULL;

    return NewNode;
}

void BpInsert(PtrBp T, ElementType Val) {
    PtrBpNode NewNode;

    if(MinDegree * 2 - 1 == T->Root->Num) {
        NewNode = BpAllocateNode(False);
        NewNode->Child[0] = T->Root;
        T->Root = NewNode;
        BpSpilitNode(NewNode, 0);
    }

    BpInsertNonFull(T->Root, Val);
}

void BpInsertNonFull(PtrBpNode CurrentNode, ElementType Val) {
    int Index = GetIndex(CurrentNode->Key, CurrentNode->Num, Val);

    if(True == CurrentNode->IsLeaf) {
        ShiftKey(CurrentNode->Key, True, Index, CurrentNode->Num - 1);
        CurrentNode->Key[Index] = Val;
        (CurrentNode->Num)++;
    } else {
        if(MinDegree * 2 - 1 == CurrentNode->Child[Index]->Num) {
            BpSpilitNode(CurrentNode, Index);
            if(CurrentNode->Key[Index] < Val) {
                Index++;
            }
        }

        BpInsertNonFull(CurrentNode->Child[Index], Val);
    }
}

void BpSpilitNode(PtrBpNode SpilitNodeP, int ChildIndex) {
    int i;
    PtrBpNode NewNode, SubNode = SpilitNodeP->Child[ChildIndex];

    if(True == SubNode->IsLeaf) {
        NewNode = BpAllocateNode(True);
        for(i = 0; i < MinDegree - 1; i++) {
            NewNode->Key[i] = SubNode->Key[i + MinDegree];
        }
        NewNode->Num = MinDegree - 1;
        SubNode->Num = MinDegree;
        NewNode->Next = SubNode->Next;
        SubNode->Next = NewNode;
    } else {
        NewNode = BpAllocateNode(False);
        for(i = 0; i < MinDegree - 1; i++) {
            NewNode->Key[i] = SubNode->Key[i + MinDegree];
        }
        for(i = 0; i < MinDegree; i++) {
            NewNode->Child[i] = SubNode->Child[i + MinDegree];
        }
        NewNode->Num = SubNode->Num = MinDegree - 1;
    }

    ShiftKey(SpilitNodeP->Key, True, ChildIndex, SpilitNodeP->Num - 1);
    ShiftChild(SpilitNodeP->Child, True, ChildIndex + 1, SpilitNodeP->Num);
    SpilitNodeP->Key[ChildIndex] = SubNode->Key[MinDegree - 1];
    SpilitNodeP->Child[ChildIndex + 1] = NewNode;
    (SpilitNodeP->Num)++;
}

void ShiftKey(PtrElementType Key, BoolType Direction, int Begin, int End) {
    int i;

    if(True == Direction) {
        for(i = End; i >= Begin; i--) {
            Key[i + 1] = Key[i];
        }
    } else {
        for(i = Begin; i <= End; i++) {
            Key[i - 1] = Key[i];
        }
    }
}

void ShiftChild(PtrBpNode *Child, BoolType Direction, int Begin, int End) {
    int i;

    if(True == Direction) {
        for(i = End; i >= Begin; i--) {
            Child[i + 1] = Child[i];
        }
    } else {
        for(i = Begin; i <= End; i++) {
            Child[i - 1] = Child[i];
        }
    }
}

int GetIndex(PtrElementType Key, int Size, ElementType Val) {
    int i;

    for(i = 0; i < Size; i++) {
        if(Key[i] >= Val) {
            break;
        }
    }

    return i;
}

void BpDelete(PtrBp T, PtrBpNode CurrentNode, ElementType Val) {
    int Index = GetIndex(CurrentNode->Key, CurrentNode->Num, Val);
    PtrBpNode Precursor, SubNode, Successor;

    if(Index < CurrentNode->Num && Val == CurrentNode->Key[Index]) {

        if(True == CurrentNode->IsLeaf) {
            ShiftKey(CurrentNode->Key, False, Index + 1, CurrentNode->Num - 1);
            (CurrentNode->Num)--;
            return;
        } else {
            Precursor = CurrentNode->Child[Index];
            Successor = CurrentNode->Child[Index + 1];

            if(Precursor->Num >= MinDegree) {
                if(True == SubNode->IsLeaf) {
                    CurrentNode->Key[Index] = Precursor->Key[SubNode->Num - 2];
                } else {
                    CurrentNode->Key[Index] = Precursor->Key[SubNode->Num - 1];
                }

                BpDelete(T, Precursor, Precursor->Key[SubNode->Num - 1]);
            } else if(Successor->Num >= MinDegree) {
                CurrentNode->Key[Index] = Successor->Key[0];
                if(True == SubNode->IsLeaf) {
                    SubNode->Key[SubNode->Num - 1] = CurrentNode->Key[Index];
                }

                BpDelete(T, Successor, Successor->Key[0]);
            } else {
                BpMerge(T, CurrentNode, Index, Index + 1);

                BpDelete(T, Precursor, Val);
            }
        }
    } else {
        if(True == CurrentNode->IsLeaf) {
            return;
        } else {
            if(Index > 0) {
                Precursor = CurrentNode->Child[Index - 1];
            }
            SubNode = CurrentNode->Child[Index];
            if(Index < CurrentNode->Num) {
                Successor = CurrentNode->Child[Index + 1];
            }
            if(SubNode->Num >= MinDegree) {
                BpDelete(T, SubNode, Val);
            } else {
                if(Index > 0 && Precursor->Num >= MinDegree) {
                    ShiftKey(SubNode->Key, True, 0, SubNode->Num - 1);
                    SubNode->Key[0] = CurrentNode->Key[Index - 1];

                    if(True == SubNode->IsLeaf) {
                        CurrentNode->Key[Index - 1] = Precursor->Key[Precursor->Num - 2];
                    } else {
                        CurrentNode->Key[Index - 1] = Precursor->Key[Precursor->Num - 1];
                        ShiftChild(SubNode->Child, True, 0, SubNode->Num);
                        SubNode->Child[0] = Precursor->Child[Precursor->Num];
                    }
                    (SubNode->Num)++;
                    (Precursor->Num)--;

                    BpDelete(T, SubNode, Val);
                } else if(Index < CurrentNode->Num && Successor->Num >= MinDegree) {
                    if(True == SubNode->IsLeaf) {
                        SubNode->Key[SubNode->Num] = Successor->Key[0];
                    } else {
                        SubNode->Key[SubNode->Num] = CurrentNode->Key[Index];
                    }
                    CurrentNode->Key[Index] = Successor->Key[0];
                    SubNode->Child[SubNode->Num + 1] = Successor->Child[0];
                    (SubNode->Num)++;

                    ShiftKey(Successor->Key, False, 1, Successor->Num - 1);
                    ShiftChild(Successor->Child, False, 1, Successor->Num);
                    (Successor->Num)--;

                    BpDelete(T, SubNode, Val);
                } else {
                    if(Index > 0) {
                        BpMerge(T, CurrentNode, Index - 1, Index);
                        BpDelete(T, Precursor, Val);
                    } else {
                        BpMerge(T, CurrentNode, Index, Index + 1);
                        BpDelete(T, SubNode, Val);
                    }
                }
            }
        }
    }
}

void BpMerge(PtrBp T, PtrBpNode CurrentNode, int LeftIndex, int RightIndex) {
    int i;
    PtrBpNode LeftNode = CurrentNode->Child[LeftIndex];
    PtrBpNode RightNode = CurrentNode->Child[RightIndex];

    if(True == LeftNode->IsLeaf) {
        for(i = 0; i < MinDegree - 1; i++) {
            LeftNode->Key[i + MinDegree - 1] = RightNode->Key[i];
        }
        LeftNode->Num = MinDegree * 2 - 2;
        LeftNode->Next = RightNode->Next;
    } else {
        for(i = 0; i < MinDegree - 1; i++) {
            LeftNode->Key[i + MinDegree] = RightNode->Key[i];
        }
        for(i = 0; i < MinDegree; i++) {
            LeftNode->Key[i + MinDegree] = RightNode->Key[i];
        }
        LeftNode->Key[MinDegree - 1] = CurrentNode->Key[LeftIndex];
        LeftNode->Num = MinDegree * 2 - 1;
    }

    ShiftKey(CurrentNode->Key, False, LeftIndex + 1, CurrentNode->Num - 1);
    ShiftChild(CurrentNode->Child, False, RightIndex + 1, CurrentNode->Num);
    (CurrentNode->Num)--;

    if(CurrentNode == T->Root && 0 == CurrentNode->Num) {
        T->Root = LeftNode;
    }
}

void BpPrintTree(PtrBpNode Root) {
    int i;

    if(NULL == Root) {
        return;
    }

    putchar('[');
    for(i = 0; i < Root->Num; i++) {
        printf("%d", Root->Key[i]);
        if(i != Root->Num - 1) {
            putchar(' ');
        }
    }
    putchar(']');
    printf("%d ", Root->IsLeaf);
    printf("%d", Root->Num);
    putchar('\n');

    for(i = 0; i <= Root->Num; i++) {
        BpPrintTree(Root->Child[i]);
    }
}

void BpCreateTree(PtrBp T) {
    int i;
    int a[] = {12,1,9,2,0,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17,20,21,23};

    for(i = 0; i < 23; i++) {
        BpInsert(T, a[i]);
        BpPrintTree(T->Root);
        printf("The End\n");
    }
}
