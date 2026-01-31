class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res='#';
        for(auto &c:letters){
            if(c>target){
                res=c;
                break;
            }
        }

        return res=='#'?letters[0]:res;
    }
};