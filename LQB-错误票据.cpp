#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream> 

using namespace std;

vector<int> se;

int main(){
	int n;
	cin >> n;
	getchar();
	char c[2000];
	while(n--){
		gets(c);
		stringstream ss(c);
		int v;
		while(ss >> v){
			se.push_back(v);
		}	
	}
	int a, b;
	sort(se.begin(), se.end());
	for(int i = 1; i < se.size(); i++){
		if(se[i] - se[i - 1] != 1){
			if(se[i] - se[i - 1] == 0)
				a = se[i];
			else
				b = se[i] - 1;
		}
	}
	cout << b << " " << a << endl;
	return 0;
}
