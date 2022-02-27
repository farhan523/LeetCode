class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        int j = low;
        while(j>=low && j<=high){
            if(j % 2 != 0)
                count++;
            j++;
        }
        return count;
    }
};