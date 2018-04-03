#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval i1, Interval i2) {
    if(i1.start < i2.start)
        return true;
    else if(i1.start > i2.start)
        return false;
    else
        return i1.end < i2.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(0 == intervals.size())
            return res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i].start > res[res.size()-1].end) {
                res.push_back(intervals[i]);
            } else {
                int pend = max(intervals[i].end, res[res.size()-1].end);
                res[res.size()-1] = Interval(res[res.size()-1].start, pend);
            }
        }
        return res;
    }
};

int main() {
}
