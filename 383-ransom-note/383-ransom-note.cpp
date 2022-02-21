class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
             
        unordered_map<char,int>st;
        for(char x:magazine){
            auto it = st.find(x);
            if(it == st.end())
                st.insert({x,1});
            else{
                it->second++;
            }
        }
        
        for(char x:ransomNote){
            auto it = st.find(x);
            if(it == st.end())
                return false;
            else{
                it->second--;
                if(it->second == 0)
                    st.erase(it);
            }
        }
       
           return true;
       
    }
    
};