class Solution {
   
    int isVowel(string word, int vowelCount) {
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == 'a' || word[i] == 'A' || word[i] == 'e' ||
                word[i] == 'E' || word[i] == 'i' || word[i] == 'I' ||
                word[i] == 'o' || word[i] == 'O' || word[i] == 'u' ||
                word[i] == 'U') {
                vowelCount++;
                continue ;    
            }
        }
        return vowelCount;
    }

public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3)
            return false;
        int vc=0;
        int vowelCount=isVowel(word,vc);
        cout<<vowelCount<<endl;
        if(vowelCount==0) return false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((word[i] >= '0' && word[i] <= '9')) {
               continue;
            } 
            else if ((word[i] >= 'a' && word[i] <= 'z') ||
                       (word[i] >= 'A' && word[i] <= 'Z')) {
                count++;
                continue;
            }
            else {
                return false;
            }           
        }

        // cout<<count<<endl;
        if(count==vowelCount) return false;

        return true;
    }
};