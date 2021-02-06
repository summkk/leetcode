class Solution {
public:
    void dfs(int target, vector<int> & combine, vector<vector<int>> & res, int index,vector<int>& candidates){
        if(index == candidates.size() || target < 0)
            return;
        if(target == 0){
            res.push_back(combine);
            return;
        }            

        for(int i = index;i < candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1])
                continue;//其实可以作为剪枝？但是需要排序
            if(target - candidates[i] >= 0){
                combine.push_back(candidates[i]);
                dfs(target - candidates[i],combine,res,i,candidates);//这里dfs仍在i的位置，可以重复使用i的元素
                combine.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combine;
        sort(candidates.begin(),candidates.end());
        dfs(target,combine,res,0,candidates);
        return res;
    }
};
