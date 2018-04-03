#include<iostream>
using namespace std;

const int maxn = 1005;

class Priority_queue {
public:
    Priority_queue():len(0) {}

    ///添加元素
    int Push(int num) {
        if(len >= maxn-1)
            return -1;
        m_queue[++len] = num;

        int j = len;
        while(j != 1) {
            int p = j/2;
            if(m_queue[p] > num) {
                m_queue[j] = m_queue[p];
                m_queue[p] = num;
            }
            j/=2;
        }
    }

    ///队首元素
    int Front() {
        if(len == 0)
            return -1;
        return m_queue[1];
    }

    ///删除队首元素
    int Pop() {
        if(len > 0) {
            m_queue[1] = m_queue[len];
            --len;
            int i=1;
            while(i*2 <= len) {
                int j = i*2;
                int index, minx;
                if(i*2+1 <= len) {
                    if(m_queue[j] < m_queue[j+1]) {
                        minx = m_queue[j];
                        index = j;
                    } else {
                        minx = m_queue[j+1];
                        index = j+1;
                    }
                } else {
                    index=j;
                }
                if(m_queue[i] > minx) {
                    int temp = m_queue[i];
                    m_queue[i] = m_queue[index];
                    m_queue[index] = temp;
                }
                i = index;
            }
            return 0;
        }
        return -1;
    }

    ///返回队的长度
    int size() {
        return len;
    }
private:
    int m_queue[maxn];
    int len;
};

int main() {
    int n, t;
    cin >> n;
    Priority_queue que;
    for(int i=0; i<n; i++) {
        cin >> t;
        que.Push(t);
    }
    for(int i=0; i<que.size(); i++) {
        while(que.size() != 0) {
            cout << que.Front() << " ";
            que.Pop();
        }
    }
}

//int main() {
//    int n;
//    cin >> n;
//    int arr[maxn];
//    int t;
//    for(int i=0; i<n; i++) {
//        cin >> t;
//        arr[i] = t;
//        int j = i;
//        while(j) {
//            int p = j/2;
//            if(arr[p] > t) {
//                arr[j] = arr[p];
//                arr[p] = t;
//            }
//            j/=2;
//        }
//    }
//    for(int i=0; i<n; i++)
//        cout << arr[i] << " ";
//    return 0;
//}
