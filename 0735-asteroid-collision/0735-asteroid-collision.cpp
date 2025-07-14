class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        stack<pair<int,int>>st;
        for(auto it: asteroids){
            if(it<0){
                int num=(-1*it);
                 if(!st.empty() && st.top().first==0 && num==st.top().second){
                        st.pop();
                        continue;
                    }
                while(!st.empty() && st.top().first==0){
                    int top=st.top().second;
                    if(top>num){
                        break;
                    }
                    else if(top<num){
                        st.pop();
                    }
                   
                }
                if(st.empty() || st.top().first==1){
                    st.push({1,it});
                }
            }
            else{
                st.push({0,it});
            }
        }

        while(!st.empty()){
            res.push_back(st.top().second);
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};