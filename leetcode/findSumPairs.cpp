#include <vector>
#include <unordered_map>

class FindSumPairs {
    std::vector<int> n1, n2;
    std::unordered_map<int, int> mp;
public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int x : n2) {
            ++mp[x];
        }
    }
    
    void add(int index, int val) {
        --mp[n2[index]];
        n2[index] += val;
        ++mp[n2[index]];
    }   

    int count(int tot) {
        int c = 0;
        for (int x : n1) {
            c += mp[tot-x];
        }

        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */