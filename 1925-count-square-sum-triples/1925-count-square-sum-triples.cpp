class Solution {
public:
    int countTriples(int n) {

        unordered_set<int>st;
        for(int i=1;i<=n;i++) st.insert(i*i);

        int res=0;
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                int sqr=a*a+b*b;
                if(st.count(sqr)) res++;
            }
        }

        return res;
    }
};