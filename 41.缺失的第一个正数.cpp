//遍历一次数组把大于等于1的和小于数组大小的值放到原数组对应位置
//再遍历一次数组查当前下标是否和值对应
//如果不对应那这个下标就是答案，否则遍历完都没出现那么答案就是数组长度加1。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i = 0;i < nums.size();i++){
            //[2，1]不能从1开始计数交换
            while(nums[i] >= 1 && nums[i] <= nums.size() && nums[i]-1 != i){
                //不判断 如[1,1]会炸
                if(nums[i] == nums[nums[i]-1])
                    break;
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int j = 0;j < nums.size();j++){
            if(nums[j]-1 != j )
                return j+1;
        }
        return nums.size()+1 ;
    }
};
