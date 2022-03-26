// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
    public:
        int firstBadVersion(int n)
        {
            if (n == 1)
                return isBadVersion(n);
            int left = 0;
            int right = n;
            int mid;
            while (left < right)
            {
                mid = left + (right - left) / 2;

                if (isBadVersion(mid))
                    right = mid;
                else
                    left = mid + 1;
            }
            return isBadVersion(mid) ? mid : mid + 1;
        }
};