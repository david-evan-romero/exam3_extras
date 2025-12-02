#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> lruList; // Stores {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache; // Key -> Iterator

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        // Move to front (Most Recently Used)
        lruList.splice(lruList.begin(), lruList, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move to front
            cache[key]->second = value;
            lruList.splice(lruList.begin(), lruList, cache[key]);
            return;
        }
        
        if (cache.size() == capacity) {
            // Evict Least Recently Used (back)
            int keyToRemove = lruList.back().first;
            lruList.pop_back();
            cache.erase(keyToRemove);
        }
        
        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};
