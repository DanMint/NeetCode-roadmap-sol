class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<bool> used(nums.size(), false);
        unordered_map<int,int> freq;
        for (int & num : nums) {
            auto search = freq.find(num);
            if (search != freq.end())
                search->second = search->second + 1;
            else
                freq.emplace(num, 1);
        }

        vector<int> answer;
        for (auto &el : freq) {
            int toFind = target - el.first;
            auto search = freq.find(toFind);
            if (search != freq.end()) {
                answer.push_back(el.first);
                answer.push_back(toFind);
                break;
            }
        }

        vector<int> pos;
        int toFind = answer[0];
        int toFind2 = answer[1];
        for (int i = 0; i < nums.size(); i ++) {
           if (toFind == nums[i]) {
               pos.push_back(i);
               used[i] = true;
               break;
           }
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (toFind2 == nums[i] && used[i] == false) {
                pos.push_back(i);
                break;
            }
        }
        return pos;
    }

};
