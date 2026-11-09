class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    int left = 0;
    vector<int> need(26, 0);

    if (s1.size() > s2.size()) {
        return false;
    }

    for (int i = 0; i < s1.size(); i++) {
        need[s1[i] - 'a']++;
    }

    for (int right = 0; right < s2.size(); right++) {

        need[s2[right] - 'a']--;

        if (right - left + 1 > s1.size()) {
            need[s2[left] - 'a']++;
            left++;
        }

        bool valid = true;
        for(int n : need){
            if(n != 0){
                valid = false;
                break;
            }
        }

        if(valid){
            return true;
        }
    }

    return false;
    }
};
