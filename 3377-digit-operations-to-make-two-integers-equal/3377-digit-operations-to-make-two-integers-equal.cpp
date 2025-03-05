vector<int> isPrime;

void generatePrimes() {
    if (!isPrime.empty()) return;
    isPrime.resize(1e5 + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= 1e5; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= 1e5; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

class Solution {
public:
    int minOperations(int n, int m) {
        generatePrimes();
        if (isPrime[n] || isPrime[m])return -1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_set<string>visited;
        pq.push({n,n});
        visited.insert(to_string(n));
        while(!pq.empty()){
            auto [steps,currNum]=pq.top();
            if (currNum==m)return steps;
            pq.pop();            
            string s=to_string(currNum);
            for (int i=0;i<s.size();i++){
                string original=s;
                if (s[i]<'9'){
                    s[i]++;
                    int newNum=stoi(s);
                    int newStep=steps+newNum;
                    if (!visited.count(s) && !isPrime[newNum]){                        
                        pq.push({newStep,newNum});
                        visited.insert(s);
                    }
                }
                s=original;
                if (s[i]>'0' && !(i == 0 && s[i] == '1')){
                    s[i]--;
                    int newNum=stoi(s);
                    int newStep=steps+newNum;
                    if (!visited.count(s) && !isPrime[newNum]){                         
                        pq.push({newStep,newNum});
                        visited.insert(s);
                    }
                }
                s=original;
            }
        }

        return -1;
        
    }
};