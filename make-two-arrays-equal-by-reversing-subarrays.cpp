class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = arr.size();
        int m = target.size();

        unordered_map<int,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
         unordered_map<int,int> mp2;
        for(auto it: target){
            mp2[it]++;
        }
        return (mp==mp2);
    }
};