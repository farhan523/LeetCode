class Solution {
    
   
      
    
public:
    bool detectCapitalUse(string word) {
         int cnt=0;
        int loc;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                cnt++;
                loc = i;
            }
        }
        if(cnt == word.length() || cnt == 0 || (cnt==1 && loc==0))
            return true;
        return false;    
        
    }
};