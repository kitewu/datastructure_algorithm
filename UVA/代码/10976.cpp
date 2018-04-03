#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int k;
    while(~scanf("%d", &k)){
        vector<int> v1, v2;
        int t = k << 1;
        for(int i = k + 1; i <= t; i++){
            if(i * k % (i - k) == 0){
                v1.push_back(i * k / (i - k));
                v2.push_back(i);
            }
        }
        int len = v1.size();
        printf("%d\n", len);
        for(int i = 0; i < len; i++){
            printf("1/%d = 1/%d + 1/%d\n", k, v1[i], v2[i]);
        }
    }
    return 0;
}
