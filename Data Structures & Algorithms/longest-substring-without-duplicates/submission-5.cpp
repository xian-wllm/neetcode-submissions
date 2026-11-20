class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> seen;
        int length = 0;

        for(int right = 0; right < s.size(); right++){

            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);

            length = max(length, right - left + 1);  
        }

        return length;

    }
};
