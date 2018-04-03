#include<stdio.h>

//a右移的方式 ，如果输入负数，如0x80000000，最终会变成0xFFFFFFFF，陷入死循环 
int numOf1(int a){
	int count = 0;
	while(a){
		if(a & 1)
			count++;
		a = a >> 1;
	} 
	return count;
}

//方式2，将i不断左移与a比较，如果a是32位，需要比较32次 
int numOf1_2(int a){
	unsigned int i = 1;
	int count = 0;
	while(i){
		if(a & i)
			count++;
		i = i << 1;
	}
	return count;
} 

//方式3，把一个整数减去1，再和原来整数相与，会把该整数最右一个1变成0.
//那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的运算 
int numOf1_3(int a){
	int count = 0;
	while(a){
		++count;
		a = (a - 1) & a;
	}
	return count;
} 

int main(){
	int a;
	scanf("%d", &a);
	int result = numOf1_3(a);	
	printf("%d\n", result);
}
