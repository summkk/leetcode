/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
思路：直接dfs搜索
优化：题解中巧妙的避开了flags用数组做标记，
将题目给定的数组nums 划分成左右两个部分，左边的表示已经填过的数，右边表示待填的数，我们在回溯的时候只要动态维护这个数组即可。
每次交换标记了的数（当前的数i）和现在数组左右分界的位置
注意这样返回的是非字典序
时间：2021.3.1
提交次数：1
*/
class Solution {
public:
    
    void dfs(vector<int> nums,vector<int>& cnt,vector<int>& flags,vector<vector<int>>& res,int deep){
        if(deep == nums.size()){
            res.push_back(cnt);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(flags[i] == 0){
                cnt.push_back(nums[i]);
                flags[i] = 1;
                dfs(nums,cnt,flags,res,deep+1);
                cnt.pop_back();
                flags[i] = 0;
            }
        }
        return;            
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cnt;
        vector<vector<int>> res;
        vector<int> flags(nums.size(),0);
        dfs(nums,cnt,flags,res,0);
        return res;
    }
};
