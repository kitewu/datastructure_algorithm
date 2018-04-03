#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int h = n / 3600;
    int min = (n - 3600 * h) / 60;
    int s = n % 60;
    cout << h << ":" << min << ":" << s << endl;
}
