class Solution {
public:
    bool hasMatch(string s, string p) {
    int ind = p.find("*");
    string p1 = p.substr(0, ind), p2 = p.substr(ind+1, p.size()-ind-1);
    if(p1.size() + p2.size()  == 0) return true;
    ind = 0;
    if(p1.size()) {
        ind = s.find(p1);
        if(ind < 0) return false;
    }
    if(p2.size()) ind = s.find(p2, ind + p1.size());
    return (ind >= 0);
    
}
};