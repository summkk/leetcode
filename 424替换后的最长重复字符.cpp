class Solution {
public:
//滑动窗口
    int characterReplacement(string s, int k) {
        int left = 0,right = 0,res = 0;
        int hash_map[26];
        memset(hash_map,0,sizeof(hash_map));
        if(s.length() == 0)
            return 0;
        for(;right < s.length();right++){
            hash_map[s[right]-'A']++;//新加入的字母计数加一
            res = max(res,hash_map[s[right]-'A']);
            if(right - left + 1 > res + k){//不满足条件，滑动
                hash_map[s[left] - 'A']--;
                left = left + 1;
            }
        }
        return right-left;
    }
};
