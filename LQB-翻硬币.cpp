#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int len = a.size();
    int i = 0, ans = 0;
    while(i++ < len) {
        if(a[i] != b[i]) {
            a[i+1] = (a[i+1]=='*'?'o':'*');
            ++ans;
        }
    }
    cout << ans << endl;
}
//#include<iostream>
//#include<cstring>
//#include<string>
//
//using namespace std;
//
//int main(){
//    string s1, s2;
//    cin >> s1 >> s2;
//    int len = s1.size();
//    int s[len+1];
//    memset(s, 0, sizeof(s));
//    for(int i=0; i<len; i++)
//        if(s1[i] != s2[i])
//            s[i] = 1;
//    int flag = -1;
//    int count = 0;
//    for(int i=0; i<len; i++){
//        if(s[i] == 1){
//            if(flag == -1)
//                flag = i;
//            else{
//                count += i - flag;
//                flag = -1;
//            }
//        }
//    }
//    cout << count << endl;
//    return 0;
//}
