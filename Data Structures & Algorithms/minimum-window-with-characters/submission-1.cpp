class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int minLength = INT_MAX;
        int best_left = 0;
        int best_right = 0;
        vector<int> need(128,0);
        
        for(char c : t){
            need[c]++;
        }

        for(int right = 0; right < s.size(); right++){
            
            need[s[right]]--;
        
            int valid = true;
            for(int n : need){
                if(n > 0){
                    valid = false;
                    break;
                }
            }

            while(valid && left <= right){
                if(right - left + 1 < minLength){
                    minLength = min(minLength, right - left + 1);
                    best_left = left;
                    best_right = right;
                }
                need[s[left]]++;
                left++;

                for(int n : need){
                    if(n > 0){
                        valid = false;
                        break;
                    }
                }
            }
        }

        if(minLength == INT_MAX){
            return "";
        }


        return s.substr(best_left, minLength);
    }
};
