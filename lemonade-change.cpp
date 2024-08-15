class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> change;
        int n  = bills.size();
        for(int i=0;i<n-1;i++){
            change[bills[i]]++;
            if(bills[i+1]==10)change[5]--;
            else if(bills[i+1]==20){
                if(change[10]){
                    change[10]--,change[5]--;
                }
                else {
                    change[5]-=3;
                }
            }
            if(change[5]<0) return false;
        }
        for(auto it: change){
            if(it.second<0) return false;
        }
        
        return true;
    }
};