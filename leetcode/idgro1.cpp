#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[std::rand() % v.size()];
    }
private:
    std::unordered_map<int, int> mp;
    std::vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */