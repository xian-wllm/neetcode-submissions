class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> comp1 (26, 0);
        vector<int> comp2(26, 0);

        if(s.size()!= t.size()) return false; 
        for(int i=0; i < s.size(); i++){
            int letter_to_index = s[i] - 'a';
            comp1[letter_to_index]++;
            letter_to_index = t[i] - 'a';
            comp2[letter_to_index]++;

        } 

        for(int i=0; i<26; i++){
            if(comp1[i]!=comp2[i]) return false;
        }

        return true;
    }
};
