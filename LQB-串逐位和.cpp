#include<iostream>
using namespace std;
int f(char s[], int begin, int end) {
    int mid;
    if(end - begin == 1)
        return s[begin] - '0';
    mid = (end + begin) / 2;
    return f(s, begin, mid) + f(s, mid, end);  //МоїХ
}

int main() {
    char s[] = "4725873285783245723";
    int sum=0;
    for(int i=0; i<strlen(s); i++){
        sum+=s[i]-'0';
    }
    cout<< sum<< endl;
    printf("%d\n",f(s,0,strlen(s)));
    return 0;
}
