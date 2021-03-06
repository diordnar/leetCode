#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
using namespace std;

// 146. LRU缓存机制
// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作：
// 获取数据 get 和 写入数据 put 。

// 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，
// 它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

// 进阶:
// 你是否可以在 O(1) 时间复杂度内完成这两种操作？
// 示例:
// LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // 返回  1
// cache.put(3, 3);    // 该操作会使得密钥 2 作废
// cache.get(2);       // 返回 -1 (未找到)
// cache.put(4, 4);    // 该操作会使得密钥 1 作废
// cache.get(1);       // 返回 -1 (未找到)
// cache.get(3);       // 返回  3
// cache.get(4);       // 返回  4

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/lru-cache
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class LRUCache
{
public:
    LRUCache(int capacity) : cap(capacity)
    {
    }

    int get(int key)
    {
        if (hash.find(key) != hash.end())
        {
            put(key, hash[key]->second);
            return hash[key]->second;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (hash.find(key) != hash.end())
        {
            cache.erase(hash[key]);
        }
        else if (cache.size() >= cap)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        hash[key] = cache.begin();
    }

private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
};

class LRUCache2
{
public:
    LRUCache2(int capacity) : cap(capacity)
    {
    }
    int get(int key)
    {
        if (umap.find(key != umap.end()))
        {
            put(key, umap[key]->second);
            return umap[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (umap.find(key) != umap.end())
        {
            cache.erase(umap[key]);
        }
        else if (cache.size() >= cap)
        {
            umap.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        umap[key] = cache.begin();
    }

private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 返回  1
    cache.put(3, 3);              // 该操作会使得密钥 2 作废
    cout << cache.get(2) << endl; // 返回 -1 (未找到)
    cache.put(4, 4);              // 该操作会使得密钥 1 作废
    cout << cache.get(1) << endl; // 返回 -1 (未找到)
    cout << cache.get(3) << endl; // 返回  3
    cout << cache.get(4) << endl; // 返回  4

    return 0;
}
