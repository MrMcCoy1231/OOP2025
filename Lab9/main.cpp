#include <cstdio>
#include <tuple>

template<typename K, typename V>
class Map {
    struct Entry {
        K key;
        V value;
        int index;
    } data[100];

    int count = 0;

    int find(const K& key) {
        for (int i = 0; i < count; i++)
            if (data[i].key == key)
                return i;
        return -1;
    }

public:

    V& operator[](const K& key) {
        int i = find(key);
        if (i != -1)
            return data[i].value;
        data[count] = { key, V(), count };
        return data[count++].value;
    }

    void Set(const K& key, const V& value) {
        int i = find(key);
        if (i != -1)
            data[i].value = value;
        else
            data[count++] = { key, value, count };
    }

    bool Get(const K& key, V& value) {
        int i = find(key);
        if (i == -1)
            return false;
        value = data[i].value;
        return true;
    }

    int Count() {
        return count;
    }

    void Clear() {
        count = 0;
    }

    bool Delete(const K& key) {
        int i = find(key);
        if (i == -1)
            return false;

        for (int j = i; j < count - 1; j++) {
            data[j] = data[j + 1];
            data[j].index = j;
        }
        count--;
        return true;
    }

    bool Includes(const Map<K, V>& map) {
        for (int i = 0; i < map.count; i++) {
            if (find(map.data[i].key) == -1)
                return false;
        }
        return true;
    }

    struct Iterator {
        Entry* ptr;
        Iterator(Entry* p) : ptr(p) {}
        
        bool operator!=(const Iterator& other) {
            return ptr != other.ptr;
        }
        void operator++() {
            ptr++;
        }

        auto operator*() {
            return std :: tuple<K, V, int>{ptr->key,ptr->value, ptr->index};
        }
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + count);
    }
};

int main() {
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }


    return 0;
}
