class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0,tens=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fives++;
            }
            else if(bills[i]==10){
                if(fives==0) return false;
                fives--;
                tens++;
            }
            else{
                if(tens==0 && fives<3) return false;
                if(fives==0) return false;

                if(tens==0){
                    fives-=3;
                }
                else{
                    tens--;
                    fives--;
                }

            }
        }

        return true;
    }
};