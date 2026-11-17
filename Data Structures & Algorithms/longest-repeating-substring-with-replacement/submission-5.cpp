class Solution {
public:
    int getMaxLength(unordered_map<int,int>&  freq){
        int maxFreq = 0;
        for(auto [letter, count] : freq){
            maxFreq = max(maxFreq, count);
        }
        return maxFreq;
    }
    
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLength = 0;
        unordered_map<int,int>  freq;

        for(int right = 0; right < s.size(); right++){
            freq[s[right]]++;

            
            while((right - left + 1) - getMaxLength(freq) > k){
                freq[s[left]]--;
                left++;
                
            }
            
            maxLength = max(maxLength, right - left + 1);

        }

        return maxLength;
    }
};
