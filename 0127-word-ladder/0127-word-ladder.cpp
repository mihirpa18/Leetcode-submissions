class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        set<string>st;
        for(auto &s:wordList){
            st.insert(s);
        }
        st.erase(beginWord);

        while(!q.empty()){
            auto [s,d] = q.front();
            q.pop();

            if(s == endWord) return d;
            
            for(int i=0;i<s.size();i++){
                char og = s[i];
                for(char c='a';c<='z';c++){
                    s[i] = c;
                    if(st.find(s) != st.end()){
                        st.erase(s);
                        q.push({s,d+1});
                    }
                }
                s[i] = og;
            }
        }

        return 0;
    }
};