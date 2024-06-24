class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque < int > dq;
  vector < int > ans;
  int j=0;
  for (int i = 0; i < nums.size(); i++) {
    // if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    // while (!dq.empty() && nums[dq.back()] < nums[i])
    //   dq.pop_back();

    // dq.push_back(i);
    // if (i >= k - 1) ans.push_back(nums[dq.front()]);

    while(!dq.empty() && nums[i]>=nums[dq.back()])
    {
        dq.pop_back();
    }
    dq.push_back(i);

    while((i-j+1>k))
    {
        if (dq.front()==j)
        dq.pop_front();

        j++;
    }
    if (i-j+1==k)
    ans.push_back(nums[dq.front()]);

  }
  return ans;
    }
};