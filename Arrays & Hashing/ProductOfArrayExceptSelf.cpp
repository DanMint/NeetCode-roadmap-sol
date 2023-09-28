class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> answer;

        int product = 1;
        std::pair<bool, int> zeroEnc = {false, 0};
        for (const auto &el : nums) {
            if (el == 0) {
                zeroEnc.first = true;
                zeroEnc.second += 1;
            }
            else
                product *= el;
        }

        /// Here we check if there is more then one zero. If more then one zero then all is zero.
        if (zeroEnc.first && zeroEnc.second > 1) {
            answer.resize(nums.size(), 0);
            return answer;
        }


        for (const auto &el : nums) {
            if (el == 0) {
                answer.push_back(product);
                continue;
            }
            else if (el != 0 && zeroEnc.first) {
                answer.push_back(0);
                continue;
            }
            else
                answer.push_back(product / el);
        }

        return answer;

    }
};
