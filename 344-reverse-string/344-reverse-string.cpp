class Solution {
public:
    void reverseString(vector<char>& s) {
        int i =0;
        int j =s.size() - 1;
        char temp;
        while(j-i > 0){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};