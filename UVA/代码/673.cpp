#include<iostream>
#include<string>
#include<stdio.h>
#include<stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	getchar();
	while (n--) {
		string str;
		stack<char> st;
		bool ok = true;
		getline(cin, str);
		if (str.empty()) {
			cout << "Yes" << endl;
			continue;
		} else {
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == '(' || str[i] == '[')
					st.push(str[i]);
				else if (str[i] == ')') {
					if (st.empty())
						st.push(str[i]);
					if (st.top() == '(')
						st.pop();
				} else if (str[i] == ']') {
					if (st.empty())
						st.push(str[i]);
					if (st.top() == '[')
						st.pop();
				}
			}
		}
		cout << (st.empty() ? "Yes" : "No") << endl;
	}
	return 0;
}
