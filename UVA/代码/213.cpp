#include<iostream>
using namespace std;
int code[8][1<<8];
int readchar() //跨行读取编码串
{
    while(1)
    {
        int ch=getchar();
        if(ch!='\r'&&ch!='\n')
            return ch;
    }
}
int readint(int len) //读取编码串并转化为十进制数字
{
    int v=0;
    while(len--)
        v=v*2+readchar()-'0';
    return v;
}
int readcode() //读取编码头并对应到code数组
{
    memset(code,0,sizeof(code));
    code[1][0]=readchar();
    for(int len=2; len<=7; len++)
        for(int i=0; i<(1<<len)-1; i++) //不能每位都为1，(1<<len)-1。注意括号位置。
        {
            int ch=getchar();
            if(ch==EOF)    return 0;
            if(ch=='\n'||ch=='\r')    return 1;
            code[len][i]=ch;
        }
    return 1;//读到EOF返回0，结束输入，否则返回1继续输入编码。
}
int main()
{
    while(readcode())
    {
        while(1)
        {
            int len=readint(3);
            if(len==0)    break;
            while(1)
            {
                int v=readint(len);
                if(v==(1<<len)-1)    break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}
