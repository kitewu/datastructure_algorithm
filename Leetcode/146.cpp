#include <iostream>
#include <map>
#include <list>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        map<int, list<int>::iterator>::iterator it = hash.find(key);
        if(it != hash.end()){
            list<int>::iterator pos = it->second();
            int res = cache.get(pos);
            return it->second;

        }
        return -1;
    }

    void put(int key, int value) {

    }

private:
    map<int, list<int>::iterator> hash;
    list<int> cache;
    int size;
};

int main() {
    return 0;
}

