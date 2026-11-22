class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(const string& str : strs){
            vector<int> count(26, 0);

            for(char c : str){
                count[c - 'a']++;
            }
            
            string key = "";

            for(int freq : count){
                key += "#" + to_string(freq);
            }

            mp[key].push_back(str);

        }

        vector<vector<string>> results;
        for(auto& [key, words] : mp){
            results.push_back(words);
        }

        return results;

        
    }
};
