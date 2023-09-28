class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char, int> str1;
        std::unordered_map<char, int> str2;

        for(const auto &el : s) {
            if (str1.find(el) != str1.end())
                str1[el] += 1;
            else
                str1[el] = 1;
        }

        for(const auto &el : t) {
            if (str2.find(el) != str2.end())
                str2[el] += 1;
            else
                str2[el] = 1;
        }

        if (str1.size() != str2.size())
            return false;

        bool ans = true;
        for (const auto &el : str1) {
            if (str1.find(el.first) != str1.end()) {
                if (el.second != str2[el.first]) {
                    ans = false;
                    break;
                }
            }
        }

        return ans;
    }
};
