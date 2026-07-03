class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> st(wordList.begin(), wordList.end());
        queue <pair<string, int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord){
                return steps;
            }
            for(int i =0; i<word.size(); i++){
                char original = word[i];
                for(char c='a'; c<='z';c++){
                    word[i] = c;
                    if(st.count(word)>0){
                        st.erase(word);
                        q.push({word, steps+1});
                    }   
                }
                 word[i]=original;
            }
        }
        return 0;
    }
};
