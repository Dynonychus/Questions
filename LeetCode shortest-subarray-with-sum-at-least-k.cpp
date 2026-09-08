class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX;

        int n=0;
        int a=0;
        int b=0;
        int i=0;

        deque<pair<int, int>> deq = {};

        n = (nums.size());

        for(i=0;i<n;i++) {
            a += nums[i];
            
            if(a >= k)
            ans = min(ans, i + 1);

            while(!deq.empty() && (a - deq[0].first) >= k) {
                b = deq[0].second;

                deq.pop_front();

                ans = min(ans, i - b);
            }

            while(!deq.empty() && deq[deq.size() - 1].first >= a)
            deq.pop_back();

            deq.push_back({a, i});
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
