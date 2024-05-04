//
// Created by zuo-c on 24-5-3.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

// 每个函数的平均时间复杂度为O(1)
class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> map; //<val-index>
    default_random_engine e;

public:
    RandomizedSet() {

    }

    bool insert(int val) {
        // 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
        if (map.count(val)) {
            return false;
        }
        data.push_back(val);
        map[val] = static_cast<int>(data.size()) - 1;
        return true;
    }

    bool remove(int val) {
        // 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
        if (map.count(val)) {
            int index = map[val];
            data[index] = data.back();
            map[data.back()] = index;

            map.erase(val);
            data.pop_back();
            return true;
        }
        return false;
    }

    int getRandom() {
        // 随机返回现有集合中的一项
        uniform_int_distribution<unsigned> u(0, data.size() - 1);
        int randomIndex = static_cast<int>(u(e));
        return data[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    auto* obj = new RandomizedSet();
    bool param_1 = obj->insert(0);
    bool param_2 = obj->insert(1);
    bool param_3 = obj->remove(0);
    bool param_4 = obj->insert(2);
    bool param_5 = obj->remove(1);
    int param_6 = obj->getRandom();
    cout << param_1 << param_2 << param_3 << param_4 << param_5 << param_6 << endl;
    delete obj;
    return 0;
}