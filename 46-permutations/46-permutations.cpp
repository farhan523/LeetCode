class Solution {
vector<vector<int>> res;
    void heapPermutation(vector<int>& a, int size, int n)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1) {
        res.push_back(a);
        return;
    }
 
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n);
 
        // if size is odd, swap 0th i.e (first) and
        // (size-1)th i.e (last) element
        if (size % 2 == 1)
            swap(a[0], a[size - 1]);
 
        // If size is even, swap ith and
        // (size-1)th i.e (last) element
        else
            swap(a[i], a[size - 1]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        heapPermutation(nums,nums.size() , nums.size());
        return res;
    }
};