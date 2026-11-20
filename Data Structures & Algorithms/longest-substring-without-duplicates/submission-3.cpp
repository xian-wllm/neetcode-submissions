class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;

        int left = 0;
        int max_length = 0;

        for(int right = 0; right < s.size(); right++){
            
            if(mp.count(s[right])){
                int targetIndex = mp[s[right]] + 1;
                for(; left< targetIndex; left++){
                    mp.erase(s[left]);
                }   
            }

            mp[s[right]] = right;
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
