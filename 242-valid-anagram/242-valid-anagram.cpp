class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char,int>st;
        for(char x:s){
            auto it = st.find(x);
            if(it == st.end())
                st.insert({x,1});
            else{
                it->second++;
            }
        }
        
        for(char x:t){
            auto it = st.find(x);
            if(it == st.end())
                return false;
            else{
                it->second--;
                if(it->second == 0)
                    st.erase(it);
            }
        }
        if(!st.empty())
            return false;
           return true;
       
    }
};