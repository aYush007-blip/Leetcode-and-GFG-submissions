class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>> q;
        set<string> words(wordList.begin() , wordList.end());
        q.push({beginWord , 1});
        words.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;
            for(int i=0;i<word.size();i++){
                char orig = word[i];
                for(char j='a' ; j<='z';j++){
                    word[i]=j;
                    if(words.find(word) != words.end()){
                        q.push({word , step+1});
                        words.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
        
    }
};