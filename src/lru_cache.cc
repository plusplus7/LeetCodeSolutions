#include <iostream>
#include <map>
#include <list>
#include <utility>

using namespace std;

class LRUCache{
public:
    typedef list< pair<int, int> >::iterator list_iterator_t;
    typedef map<int, list_iterator_t>::iterator map_iterator_t;

    LRUCache(int capacity) {
        m_capacity = capacity; 
        m_map.clear();
        m_data.clear();
    }
    int get(int key) {
        map_iterator_t finder = m_map.find(key);
        if (finder == m_map.end()) 
            return -1;
        else {
            m_data.splice(m_data.begin(), m_data, finder->second);
            return finder->second->second;
        }
    }                    
    void set(int key, int value) {
        map_iterator_t finder = m_map.find(key);
        if (finder != m_map.end()) {
            m_data.erase(finder->second);
            m_map.erase(finder);
        } else {
            if (__builtin_expect(m_map.size() == m_capacity, 1)) {
                list_iterator_t last = m_data.end();
                last--;
                m_map.erase(last->first);
                m_data.pop_back();
            }
        }
        m_data.push_front(make_pair(key, value));
        m_map[key] = m_data.begin();
    }
private:
    int m_capacity;
    map<int, list_iterator_t> m_map;
    list< pair<int, int> > m_data;
};

int main() {
    LRUCache a(3);
    const int l_len = 20;
    int line[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int result[] = {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0};
    
    for (int i=0; i<l_len; i++) {
        if (a.get(line[i]) == -1) {
            if (result[i] != 0) {
                cout<<"Fault!"<<endl;
                break;
            }
            a.set(line[i], 1);
        }
    }
}
