#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
//        set<int> s1;
//        set<int> s2;
//        for(int i=0; i<nums1.size(); i++)
//            s1.insert(nums1[i]);
//        for(int i=0; i<nums2.size(); i++)
//            s2.insert(nums2[i]);
//        set<int>::iterator it1 = s1.begin();
//        set<int>::iterator it2 = s2.begin();
//        vector<int> res;
//        while(it1 != s1.end() && it2 != s2.end()) {
//            if(*it1 == *it2) {
//                res.push_back(*it1);
//                it1++;
//                it2++;
//            } else if(*it1 > *it2)
//                it2++;
//            else
//                it1++;
//        }
        return res;
    }
};

int main() {
    return 0;
}
