class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string aux;
        for(string s : words){
            aux = s;
            reverse(s.begin(),s.end());
            if(s == aux)
                return s;
        }
        return "";
    }
};