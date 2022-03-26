/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(n == 1)
            return 1;
         int left = 0;
            int right = n,mid,r;
            
        
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                r = guess(mid);
                
                if (r == -1)
                    right = mid-1;
                else if(r == 1)
                    left = mid + 1;
                else
                  return  mid;
            }
        return mid;
    }
};