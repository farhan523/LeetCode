class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int lPtr = 0;
        int rPtr = people.size() - 1;
        sort(people.begin(),people.end());
        while(lPtr <= rPtr){
            if(people[lPtr] + people[rPtr] <= limit){
                count++;
                lPtr++;
                rPtr--;
                continue;
            }
            people[lPtr] >= people[rPtr] ? lPtr++ : rPtr--;
            count++;
                
        }
        return count;
    }
};