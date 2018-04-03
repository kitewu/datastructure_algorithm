#include<stdio.h>
int main()
{
    int x=1, y=0;
    if(!x)
        y++;
    else if(x ==0 ){
        if(x){
            y+=2;
        }else{
            y+=3;
        }
    }
    printf("%d\n", y);
}
