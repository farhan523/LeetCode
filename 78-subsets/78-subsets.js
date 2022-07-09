/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let ans = [];
    backtrack(nums, 0, [], ans);
    return ans;
};

var backtrack = function(nums, i, cur, ans) {
    if(i>=nums.length) {
        ans.push([...cur]);
        return;
    }
    backtrack(nums, i+1, [...cur, nums[i]], ans);
    backtrack(nums, i+1, [...cur], ans);
}