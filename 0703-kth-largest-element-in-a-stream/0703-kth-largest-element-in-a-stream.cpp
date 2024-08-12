class KthLargest {
public:
   priority_queue<int,vector<int>,greater<int>> min_heap;
int k;
    KthLargest(int k, vector<int> &arr) {
        this->k=k;
for (int i=0;i<arr.size();i++)
{
    min_heap.push(arr[i]);
    if (min_heap.size()>k)
    {
        min_heap.pop();
    }
}
    }

    int add(int num) {
        min_heap.push(num);
        if(min_heap.size()>k)
        {
            min_heap.pop();
        }
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */