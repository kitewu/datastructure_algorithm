#include<iostream>
#include<string> 
using namespace std;

struct Node{
	string value;
	Node* lch;
	Node* rch;
	Node(){}
	Node(string v){
		value = v;
		lch = rch = NULL;
	}
};

class Solution {
public:
	
	string result; 
	
    bool isScramble(string s1, string s2) {
    	if(s1.size() <= 1)
    		return s1 == s2;
        Node* root = new Node(s1);
        splitString(root);
        reverseTree(root->lch);
        reverseTree(root->rch);
        result = "";
        dsfTree(root);
        return result == s2;
    }
    
    //遍历 
    void dsfTree(Node* root){
    	if(root->lch == NULL || root->rch == NULL){
    		result += root->value;
			return; 
		}
    	dsfTree(root->lch);
    	dsfTree(root->rch);
	}
    
    //反转
	void reverseTree(Node* root){
		if(root->lch == NULL || root->rch == NULL)
			return; 
		Node* t = root->lch;
		root->lch = root->rch;
		root->rch = t;
		reverseTree(root->lch);
        reverseTree(root->rch);
	} 
    
    //递归建立树 
    void splitString(Node* root){
    	if(root->value.size() == 1)
    		return;
    	int mid = root->value.size() / 2;
    	root->lch = new Node(root->value.substr(0, mid));
    	root->rch = new Node(root->value.substr(mid, root->value.size()));
    	splitString(root->lch);
    	splitString(root->rch);
	}
};

int main(){
	Solution s;
	cout << s.isScramble("great", "rgtae");
}
