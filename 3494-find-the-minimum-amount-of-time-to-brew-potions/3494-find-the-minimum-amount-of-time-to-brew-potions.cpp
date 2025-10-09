// class Solution {
//     bool possible(vector<long long>&time,vector<int>&skill,vector<int>&mana,long long mid,int k){
//         vector<long long>temp=time;
//         if(mid<time[0]) return false;
//         temp[0]=mid+(skill[0]*mana[k]);
//         int j=1;
//         if(j<time.size() && temp[0]<time[j]) return false;
//         j++;
//         for(int i=1;i<time.size();i++){
//             temp[i]=temp[i-1]+(skill[i]*mana[k]);
//             if(j<time.size() && temp[i]<time[j] ) return false;
//             j++;
//         }
//         return true;
//     }
//     long long bs(vector<long long>&time,vector<int>&skill,vector<int>&mana,int k){
//         long long l=time[0],h=time[time.size()-1];
//         long long res=-1;
//         while(l<=h){
//             long long mid=(l+h)/2;
//             if(possible(time,skill,mana,mid,k)){
//                 res=mid;
//                 h=mid-1;
//             }
//             else{
//                 l=mid+1;
//             }
//         }

//         return res;
//     }
// public:
//     long long minTime(vector<int>& skill, vector<int>& mana) {
//         int n=skill.size();
//         int m=mana.size();
//         vector<long long>time(n);
//         time[0]=skill[0]*mana[0];
//         for(int i=1;i<n;i++){
//             time[i]=time[i-1]+skill[i]*mana[0];
//         }
//         for(int i=1;i<m;i++){
//             long long req=bs(time,skill,mana,i);
//             cout<<req<<" "<<endl;
//             if(req==-1) req=time[n-1];
//             time[0]=req+(skill[0]*mana[i]);
//             for(int j=1;j<n;j++){
//                 time[j]=time[j-1]+(skill[j]*mana[i]);
//             }
//         }

//         return time[n-1];
//     }
// };

class Solution {

    public:
        long long minTime(vector<int>& skill, vector<int>& mana) {
            int n=skill.size();
            int m=mana.size();
            vector<long long>time(n,0);
            for(int i=0;i<m;i++){
                time[0]+=skill[0]*mana[i];
                for(int j=1;j<n;j++){
                    time[j]=max(time[j],time[j-1])+1ll*skill[j]*mana[i];
                }
                for(int j=n-1;j>0;j--){
                    time[j-1]=time[j]-skill[j]*mana[i];
                }
            }

            return time[n-1];
        }

};