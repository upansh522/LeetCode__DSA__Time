class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int> heap;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int i=0,j=1;
        while(j<n)
        {
            while(j<n && heap.size()<k)
            {
                heap.push(abs(nums[i]-nums[j]));
                if (j<n-1)
                {
                    j++;
                }
                else {
                    i++;
                    j=i+1;
                }
            }

            heap.push(abs(nums[i]-nums[j]));
            if(heap.top()==abs(nums[i]-nums[j])){
                i++;
                j=i+1;
            }
            else {
                if (j<n-1)
                {
                    j++;
                }
                else {
                    i++;
                    j=i+1;
                }
            }
            while(heap.size()>k)
            {
                heap.pop();
            }
        }

        return heap.top();
    }
};