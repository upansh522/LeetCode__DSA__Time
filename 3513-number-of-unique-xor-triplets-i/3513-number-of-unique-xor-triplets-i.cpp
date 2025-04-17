class Solution {
public:
int intToBinary(int num){
    int cnt=0;
    while(num>0){
        cnt++;
        num/=2;
    }
    return cnt;

}
    int uniqueXorTriplets(vector<int>& nums) {
        if (nums.size()<3)return nums.size();
        int num=*max_element(nums.begin(),nums.end());
        int block=intToBinary(num);
        return pow(2,block) ;
    }
};