class Solution 
{
    public:
        char findTheDifference(string s, string t) 
        {
            int ans=0;
            for(auto &x: t)
                ans+=x;                          //int+char=>int+ASCII of char
            for (auto &x: s)
                ans-=x;
            return char(ans);                    //converting ASCII to char
        }
};
