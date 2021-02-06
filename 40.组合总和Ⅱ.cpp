class Solution {
public:
    void dfs(int target,vector<int> &combine,int index,vector<int> & candidates,vector<vector<int>> & res){
        if(target == 0){
            res.push_back(combine);
            return;
        }
        if(index == candidates.size() || target < 0)
            return;

        for(int i = index;i < candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1])
                continue;//仅在i = index时可以重复使用i数字，避免解集重复
            if(target - candidates[i] >= 0){
                combine.push_back(candidates[i]);
                dfs(target - candidates[i],combine,i+1,candidates,res);//从下一个位置开始，避免重复
                combine.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combine;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        dfs(target,combine,0,candidates,res);
        return res;
    }
};
