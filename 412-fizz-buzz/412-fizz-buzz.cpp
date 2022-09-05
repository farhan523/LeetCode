class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>str;
        
        for(int i = 1 ; i <= n ; i++){
            string s ="";
        
            if(!(i%3))s+="Fizz";
            if(!(i%5))s+="Buzz";
            if(s.empty())s+= to_string(i);
            
            str.push_back(s);
        }
        return str;
    }
};