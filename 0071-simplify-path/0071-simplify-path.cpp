class Solution {
public:
    string simplifyPath(string path) {
        stack<char>st;
        string res="";
        int i=0,n=path.size();
        while(i<n){
            if(path[i]=='/'){
                if(st.empty()) st.push('/');
                else if(!st.empty() && st.top()!='/') st.push('/');
                while(i<n && path[i]=='/'){
                    i++;
                }
                i--;
            }
            else if(path[i]=='.'){
                int count=0;
                int start=i;
                while(i<n && path[i]=='.'){
                    count++;
                    i++;
                }
                i--;
                if(count==1){
                    if(i+1>=n || path[i+1]=='/'){}
                    else{
                        st.push('.');
                    }
                }
                if(count==2){
                    if(i+1>=n || path[i+1]=='/'){
                        if(!st.empty()) st.pop();
                        while(!st.empty() && st.top()!='/'){
                            st.pop();
                        }
                    }
                    else{
                        for(int i=0;i<count;i++) st.push('.');
                    }
                }
                else if(count>2){
                    while(count>0){
                        st.push(path[i]);
                        count--;
                    }
                }

            }

            else {
                while(i<n && path[i]!='/'){
                    st.push(path[i]);
                    i++;
                }
                i--;
            }     
            i++;
        }
        
        if(!st.empty() && st.top()=='/') st.pop();
        if(st.empty()) st.push('/');
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};