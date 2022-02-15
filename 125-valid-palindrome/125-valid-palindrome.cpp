class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for(int i = 0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z' ||  s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                char ch = tolower(s[i]);
                tmp.push_back(ch);
            }
        }
        cout<<tmp;
        int j = 0;
        for(int k = tmp.size()-1 ;k>=0 && j<=k;k--){
            if(tmp[k] != tmp[j])
                return false;
            j++;
        }
        return true;
    }
};