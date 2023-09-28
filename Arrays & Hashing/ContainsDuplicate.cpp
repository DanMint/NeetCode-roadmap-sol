class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int,bool> noDuplicate;
        bool found = false;

        for (const auto &el : nums) {
            if (noDuplicate.find(el) != noDuplicate.end()) {
                found = true;
                break;
            }
            noDuplicate[el] = true;
        }

        return found;
    }
};
