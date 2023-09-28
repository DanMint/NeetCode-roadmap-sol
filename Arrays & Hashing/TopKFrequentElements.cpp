class Solution {
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
        std::vector<int> ans;
        std::unordered_map<int, int> numbers;

        /// Time complexity O(n)
        for (const auto &el : nums) {
            if (numbers.find(el) != numbers.end())
                numbers[el] += 1;
            else
                numbers[el] = 1;
        }


        while (ans.size() != k) {
            std::pair<int, int> max = {0, 0};
            for (const auto &el : numbers) {
                if (el.second > max.second)
                    max = el;
            }
            numbers.erase(max.first);
            ans.push_back(max.first);
        }

        return ans;

    }
};
