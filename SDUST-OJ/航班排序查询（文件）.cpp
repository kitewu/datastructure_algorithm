/*
    从文件读取航班
    存到数组里
    排序时将数组拷贝到链表里
    对链表进行基数排序
    将链表的值拷贝到数组里，并删除链表
    查询操作用数组完成，便于时间的二分法查询
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 1001000     //航班最大数
#define MAX_SIZE 30     //航班号及地点名字最大值
#define MAX_PRICE 10000 //最高价
#define MAX_LINENUM     //航班号最大数

long int begin_ = 0; //记录开始时间
long int end_ = 0;   //记录结束时间
FILE* fileInput;     //输入数据
FILE* fileOutput;    //输出排序结果
FILE* read_cmd;      //读指令
FILE* write_cmd;     //写结果
int N; //航班总数
int M; //指令数

/*航班结构体*/
typedef struct{
    char flight_number[MAX_SIZE];   //航班号
    char begin_place[MAX_SIZE];     //起d点站
    char end_place[MAX_SIZE];       //终点站
    char air_date[MAX_SIZE];        //班期1-7
    int begin_time;                 //起飞时间用分钟数表示
    int end_time;                   //到达时间用分钟数表示
    int price;                      //价格
}AirLineNode, *AirLine;

/*链表结构体*/
typedef struct ListNode{
    AirLine data;
    struct ListNode* next;
}ListNode, *List;

AirLine airline[MAX]; //航班数组
List L;  //存放排序结果的链表

/*转换时间函数*/
void getTime(int *time, char t1[]){
    char t2[5];
    int flag = 0;
    for(int x = 0; t1[x] != 0; x++){
        if(x == strlen(t1) - 1){
            t2[flag++] = t1[x];
            t2[flag++] = 0;
            *time += atoi(t2);
        }
        if(t1[x] == ':'){
            t2[flag++] = 0;
            *time = atoi(t2) * 60;
            flag = 0;
        }else
            t2[flag++] = t1[x];
    }
}

/*输入航班 从文件输入*/
void getAirLine(){
    begin_ = clock();
    if(fileInput = fopen("D:\\data.txt","r")){
        fscanf(fileInput, "%d", &N);
        for(int i = 0; i < N; i++){
            airline[i] = new AirLineNode;
            char t1[MAX_SIZE];
            char t2[MAX_SIZE];
            fscanf(fileInput, "%s %s %s %s %s %d", airline[i]->flight_number, airline[i]->begin_place, airline[i]->end_place, t1, t2, &airline[i]->price);
            getTime(&(airline[i]->begin_time), t1);
            getTime(&(airline[i]->end_time), t2);
        }
        fclose(fileInput);
    }
}

/*存文件*/
void Save(){
    List ttt = L->next;
    if(fileOutput = fopen("D:/sorted.txt","w")){
        int len = 0;
        while(ttt){
            List p = ttt;
            airline[len] = ttt->data;
            ttt = ttt->next;
            delete p;
            fprintf(fileOutput, "%s %s %s %d %d %d\n", airline[len]->flight_number, airline[len]->begin_place, airline[len]->end_place, airline[len]->begin_time, airline[len]->end_time, airline[len]->price);
            len++;
        }
        fclose(fileOutput);
    }
    end_ = clock();
    printf("对%d条数据排序用时 ： %ldms\n", N, end_ - begin_);
    begin_ = end_;
}

/*排航班号*/
void SortFlightNumber(){
    List list[26];
    List it[26];
    int re = 0;
    for(int i = 0; i < 26; i++){
        list[i] = new ListNode;
        list[i]->next = NULL;
        it[i] = list[i];
    }
    for(int i = 0; i < N; i++){
        int x = (airline[i]->flight_number)[5] - '0';
        it[x]->next = new ListNode;
        it[x]->next->data = airline[i];
        it[x]->next->next = NULL;
        it[x] = it[x]->next;
    }
    int flag = 0, rec = 0;
    for(int i = 0; i < 26; i++){
        if(list[i]->next != NULL){
            if(flag == 0){
                L = list[i];
                flag = 1;
                rec = i;
            }else{
                it[rec]->next = list[i]->next;
                rec = i;
            }
        }
    }
    for(int aa = 4; aa >= 2; aa--){
        List tt = L->next;
        for(int i = 0; i < 10; i++){
            list[i]->next = NULL;
            it[i] = list[i];
        }
        while(tt){
            int x = (tt->data->flight_number)[aa] - '0';
            it[x]->next = tt;
            it[x] = it[x]->next;
            tt = tt->next;
        }
        for(int i = 0; i < 10; i++)
            it[i]->next = NULL;
        flag = 0;
        rec = 0;
        for(int i = 0; i < 10; i++){
            if(list[i]->next != NULL){
                if(flag == 0){
                    L = list[i];
                    flag = 1;
                    rec = i;
                }else{
                    it[rec]->next = list[i]->next;
                    rec = i;
                }
            }
        }
    }
    for(int xx = 1; xx >= 0; xx--){
        List tt = L->next;
        for(int i = 0; i < 26; i++){
            list[i]->next = NULL;
            it[i] = list[i];
        }
        while(tt){
            int x = (tt->data->flight_number)[xx] - 'A';
            it[x]->next = tt;
            it[x] = it[x]->next;
            tt = tt->next;
        }
        for(int i = 0; i < 26; i++)
            it[i]->next = NULL;
        flag = 0;
        rec = 0;
        for(int i = 0; i < 26; i++){
            if(list[i]->next != NULL){
                if(flag == 0){
                    L = list[i];
                    re = i;
                    flag = 1;
                    rec = i;
                }else{
                    it[rec]->next = list[i]->next;
                    rec = i;
                }
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(i != re)
            delete list[i];
    }
}

/*价格排序*/
void SortPrice(){
    List list[MAX_PRICE];
    List it[MAX_PRICE];
    List tt = L->next;
    for(int i = 0; i < MAX_PRICE; i++){
        list[i] = new ListNode;
        list[i]->next = NULL;
        it[i] = list[i];
    }
    while(tt){
        int x = tt->data->price;
        it[x]->next = tt;
        it[x] = it[x]->next;
        tt = tt->next;
    }
    for(int i = 0; i < MAX_PRICE; i++)
        it[i]->next = NULL;
    int flag = 0;
    int rec = 0;
    for(int i = 0; i < MAX_PRICE; i++){
        if(list[i]->next != NULL){
            if(flag == 0){
                List ttt = L;
                L = list[i];
                delete ttt;
                flag = 1;
                rec = i;
                continue;
            }else{
                it[rec]->next = list[i]->next;
                rec = i;
            }
        }
        delete list[i];
    }
}

/*起飞时间排序*/
void SortBeginTime(){
    List list[1450];
    List it[1450];
    List tt = L->next;
    for(int i = 0; i < 1450; i++){
        list[i] = new ListNode;
        list[i]->next = NULL;
        it[i] = list[i];
    }
    while(tt){
        int x = tt->data->begin_time;
        it[x]->next = tt;
        it[x] = it[x]->next;
        tt = tt->next;
    }
    for(int i = 0; i < 1450; i++)
        it[i]->next = NULL;
    int flag = 0;
    int rec = 0;
    for(int i = 0; i < 1450; i++){
        if(list[i]->next != NULL){
            if(flag == 0){
                List ttt = L;
                L = list[i];
                delete ttt;
                flag = 1;
                rec = i;
                continue;
            }else{
                it[rec]->next = list[i]->next;
                rec = i;
            }
        }
        delete list[i];
    }
}

/*对航班基数排序*/
void RadixSort(){
    SortFlightNumber();  //先排航班号
    SortPrice();         //航班号相同对价格排序
    SortBeginTime();     //按起飞时间排序
    Save();
}

/*起始站搜索*/
void Search_Original(char* data){
    bool have = false;
    for(int j = 0; j < N; j++){
        if(strcmp(airline[j]->begin_place, data) == 0){
            fprintf(write_cmd, "%s %s %s %d %d %d\n", airline[j]->flight_number, airline[j]->begin_place, airline[j]->end_place, airline[j]->begin_time, airline[j]->end_time, airline[j]->price);
            have = true;
        }
    }
    if(!have)
        fprintf(write_cmd, "NO SUCH FLIGHT\n");
}

/*终点站搜搜*/
void Search_Terminal(char* data){
    bool have = false;
    for(int j = 0; j < N; j++){
        if(strcmp(airline[j]->end_place, data) == 0){
            fprintf(write_cmd, "%s %s %s %d %d %d\n", airline[j]->flight_number, airline[j]->begin_place, airline[j]->end_place, airline[j]->begin_time, airline[j]->end_time, airline[j]->price);
            have = true;
        }
    }
    if(!have)
        fprintf(write_cmd, "NO SUCH FLIGHT\n");
}

/*航班号搜索*/
void Search_Flight_Number(char* data){
    bool have = false;
    for(int j = 0; j < N; j++){
        if(strcmp(airline[j]->flight_number, data) == 0){
            have = true;
            fprintf(write_cmd, "%s %s %s %d %d %d\n", airline[j]->flight_number, airline[j]->begin_place, airline[j]->end_place, airline[j]->begin_time, airline[j]->end_time, airline[j]->price);
            break;
        }
    }
    if(!have)
        fprintf(write_cmd, "NO SUCH FLIGHT\n");
}

/*起始时间搜索 二分法*/
void Search_Begin_Tiem(int begin_time, int end_time){
    int low = 0;
    int high = N - 1;
    int mid = 0;
    bool have = false;
    while(low <= high){
        mid = (low + high) / 2;
        if(airline[mid]->begin_time >= begin_time && airline[mid]->begin_time <= end_time){
            have = true;
            break;
        }
        else if(airline[mid]->begin_time > end_time)
            high = mid - 1;
        else if(airline[mid]->begin_time < begin_time)
            low = mid + 1;
    }
    if(have){
        while(mid--){
            if(airline[mid]->begin_time <= begin_time)
                break;
        }
        if(airline[mid]->begin_time < begin_time)
            mid++;
        for(int j = mid; j < N; j++){
            if(airline[j]->begin_time > end_time)
                break;
            fprintf(write_cmd, "%s %s %s %d %d %d\n", airline[j]->flight_number, airline[j]->begin_place, airline[j]->end_place, airline[j]->begin_time, airline[j]->end_time, airline[j]->price);
        }
    }else
        fprintf(write_cmd, "NO SUCH FLIGHT\n");
}

/*测试查找*/
void Search(){
    if((read_cmd = fopen("D:/cmd.txt","r")) && (write_cmd = fopen("D:/find.txt","w"))){
        fscanf(read_cmd, "%d", &M);
        for(int i = 0; i < M; i++){
            char cmd[MAX_SIZE];
            char data[MAX_SIZE];
            fscanf(read_cmd, "%s", cmd);
            if(cmd[0] == 'O'){ //起始站
                fscanf(read_cmd, "%s", data);
                Search_Original(data);
            }
            if(cmd[0] == 'T' && cmd[1] == 'E'){ //终点站
                fscanf(read_cmd, "%s", data);
                Search_Terminal(data);
            }
            if(cmd[0] == 'T' && cmd[1] == 'I'){//按起点时间
                int begin_time = 0;
                int end_time = 0;
                fscanf(read_cmd, "%s", data);
                getTime(&begin_time, data);
                if(begin_time >= 1440)
                    begin_time = 0;
                fscanf(read_cmd, "%s", data);
                getTime(&end_time, data);
                if(end_time >= 1440)
                    end_time = 0;
                Search_Begin_Tiem(begin_time, end_time);
            }
            if(cmd[0] == 'F'){//按航班号
                fscanf(read_cmd, "%s", data);
                Search_Flight_Number(data);
            }
        }
        fclose(read_cmd);
        fclose(write_cmd);
    }
    end_ = clock();
    printf("在%d条数据中检索%d次用时 : %ldms\n", N, M, end_ - begin_);
}

/*主函数*/
int main(){
    getAirLine(); //获得航班信息
    RadixSort();  //排序
    Search();     //查找
}

