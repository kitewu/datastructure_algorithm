#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;
bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '(' || c == ')')
        return true;
    return false;
}
int prior(char c)
{
    if(c == '+' || c == '-')
        return 0;
    if(c == '*' || c == '/' || c == '%')
        return 1;
    if(c == '^')
        return 2;
    if(c == '(' || c == ')')
        return -1;
    return -1;
}
int main()
{
    string str;//原始字符
    while(cin >> str){
        vector<string> out;//存放转化后用于输出的字符
        stack<char> st1;//存放操作符

        for(size_t i = 0; i < str.length();){
            if(!isOperator(str[i])){//不是操作符
                char temp[20];//临时存放操作数字符串
                int flag = 0;
                for(; !isOperator(str[i]) && i < str.length(); i++){
                    temp[flag++] = str[i];
                }
                temp[flag++] = 0;
                string tempstr(temp,strlen(temp));
                out.push_back(tempstr);
            }else{
                if('(' == str[i])
                    st1.push(str[i]);
                else if(')' == str[i]){
                    while(!st1.empty() && (st1.top() != '(')){
                        char c = st1.top();
                        char cc[2];
                        cc[0] = c;
                        cc[1] = 0;
                        string tempstr(cc,1);
                        out.push_back(tempstr);
                        st1.pop();
                    }
                    st1.pop();
                }else{//其它操作符
                    if(!st1.empty()){//栈非空，先比较
                        if(prior(str[i]) > prior(st1.top()))//高于栈顶元素,入栈
                            st1.push(str[i]);
                        else{//相等或小于
                            while((!st1.empty()) && (prior(str[i]) <= prior(st1.top()))){//一直弹到比栈顶高
                                char c = st1.top();
                                char cc[2];
                                cc[0] = c;
                                cc[1] = 0;
                                string tempstr(cc,1);
                                out.push_back(tempstr);
                                st1.pop();
                            }
                            st1.push(str[i]);
                        }
                    }else{//栈为空，直接入栈
                        st1.push(str[i]);
                    }
                }
                i++;
            }
        }
        while(!st1.empty()){
            char c = st1.top();
            char cc[2];
            cc[0] = c;
            cc[1] = 0;
            string tempstr(cc,1);
            out.push_back(tempstr);
            st1.pop();
        }

        cout << out[0];
        for(size_t i = 1; i < out.size(); i++){
            string str1 = out[i];
            string str = out[i-1];
            if((isdigit(str1[0]) && isdigit(str[0])) || (isOperator(str1[0]) && isdigit(str[0])))
                cout << " ";
            cout << str1;
        }
        cout << endl;

        //求值
        stack<double> st2;
        for(size_t i = 0; i < out.size(); i++){
            string str = out[i];
            if(!isOperator(str[0])){
                const char* p = str.c_str();
                double ff = atof(p);
                st2.push(ff);
            }else{
                double a = st2.top();
                st2.pop();
                double b = st2.top();
                st2.pop();
                char c = str[0];
                switch(c){
                case '+':
                    st2.push(b + a);
                    break;
                case '-':
                    st2.push(b - a);
                    break;
                case '*':
                    st2.push(b * a);
                    break;
                case '/':
                    st2.push(b / a);
                    break;
                case '%':
                    st2.push((int)b % (int)a);
                    break;
                case '^':
                    st2.push(pow(b,a));
                    break;
                }
            }
        }
        cout << "The answer is " << st2.top() << "." << endl << endl;
    }
}


