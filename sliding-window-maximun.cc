class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            if (i >= k-1)  ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};