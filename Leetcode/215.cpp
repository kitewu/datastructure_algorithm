#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    ///方法3
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0)
            return 0;
        priority_queue<int> myque;
        for(int i=0; i<nums.size(); i++)
            myque.push(nums[i]);
        for(int i=0; i<k-1; i++)
            myque.pop();
        return myque.top();
    }

    ///方法2
    int findKthLargest2(vector<int>& nums, int k) {
        if(nums.size()==0)
            return 0;
        vector<int> minheap;
        ///建K大小的小根堆
        for(int i=0; i<k; i++) {
            minheap.push_back(nums[i]);
            build(minheap);
        }
        for(int i=k; i<nums.size(); i++) {
            if(nums[i] > minheap[0]) {
                minheap[0] = nums[i];
                reBuild(minheap);
            }
        }
        return minheap[0];
    }
    ///重新调整堆
    void reBuild(vector<int>& minheap) {
        int cur = 0;
        while(1) {
            int child = cur*2+1, child2 = cur*2+2;
            if(child < minheap.size() && child2 < minheap.size()) {
                if(minheap[cur]>minheap[child] && minheap[cur]>minheap[child2]) {
                    int index = minheap[child] < minheap[child2] ? child : child2;
                    swap(minheap[cur], minheap[index]);
                    cur = index;
                } else if(minheap[cur] > minheap[child]) {
                    swap(minheap[cur], minheap[child]);
                    cur = child;
                } else if(minheap[cur] > minheap[child2]) {
                    swap(minheap[cur], minheap[child2]);
                    cur = child2;
                } else
                    break;
            } else if(child < minheap.size()) {
                if(minheap[cur] > minheap[child]) {
                    swap(minheap[cur], minheap[child]);
                    cur = child;
                } else
                    break;
            } else
                break;
        }
    }
    ///建立小根堆
    void build(vector<int>& minheap) {
        int cur = minheap.size()-1;
        int parent;
        while(cur) {
            parent = (cur-1)/2;
            if(minheap[cur] < minheap[parent]) { ///当前值小于父节点
                swap(minheap[cur], minheap[parent]);
                cur = parent;
            } else
                break;
        }
    }

    ///方法1
    int findKthLargest1(vector<int>& nums, int k) {
        return findK(nums, nums.size()-k, 0, nums.size()-1);
    }
    int partition(vector<int>& nums, int i, int j) {
        int x = nums[i];
        int m = i;
        int n = i+1;
        while(n<=j) {
            if(nums[n]<x)
                swap(nums[++m], nums[n]);
            ++n;
        }
        swap(nums[i], nums[m]);
        return m;
    }
    int findK(vector<int>& nums, int k, int i, int j) {
        if(i >= j) return nums[i];
        int m = partition(nums, i, j);
        if(m == k) return nums[m];
        else if(m < k)
            return findK(nums, k, m+1, j);
        else
            return findK(nums, k, i, m-1);
    }
};

int main() {
    return 0;
}



