class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // indices, values decreasing
        vector<int> res;
        res.reserve(nums.size() - k + 1);

        for (int i = 0; i < (int)nums.size(); i++) {
            // Remove index that left the window
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};