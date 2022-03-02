class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            int ptr1 = 0;
            int ptr2 = 0;
            while(ptr1<s.size() && ptr2<t.size()){
                if(s[ptr1] == t[ptr2]){
                    ptr1++;
                    ptr2++;
                }else{
                    ptr2++;
                }
            }
            if(ptr1 == s.size())
                return true;
            return false;
        }
};