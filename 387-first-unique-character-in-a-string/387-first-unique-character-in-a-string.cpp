class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(char x:s){
            auto it  = mp.find(x);
            if(it == mp.end())
                mp.insert({x,1});
            else
                it->second++;
        }
          for(int i=0;i<s.size();i++){
              if(mp.find(s[i])->second == 1)
                  return i;
          }
        return -1;
    }
};