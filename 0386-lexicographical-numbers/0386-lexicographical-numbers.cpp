class Solution {
public:
void createTree(int currNum, vector<int>& res, int limit){
   if (currNum>limit)return;
   res.push_back(currNum);

   for (int i=0;i<=9;i++){
    int nextNum=currNum*10+i;
    if (nextNum<=limit){
        createTree(nextNum, res, limit);
    }
   }
   return ;
}
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for (int i=1;i<=9;i++){
            createTree(i,res,n);
        }
        return res;
    }
};