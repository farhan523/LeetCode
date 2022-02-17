class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int aliceScore = 0;
        int bobScore = 0;
        int left = 0;
        int right = piles.size() -1;
        sort(piles.begin(),piles.end());
        for(int i=0;i<piles.size();i++){
            if(piles[left] > piles[right] && i % 2 == 0){
                aliceScore += piles[left];
                left++;
            }else if( i % 2 == 0){
                aliceScore += piles[right];
                right--;
            }else if(piles[left] > piles[right]){
                bobScore += piles[left];
                left++;
            }else{
                bobScore += piles[right];
                right--;
            }
        }
        return aliceScore > bobScore ? 1 : 0;
    }
};