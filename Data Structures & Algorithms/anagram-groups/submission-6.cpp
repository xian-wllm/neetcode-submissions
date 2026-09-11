class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {

            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            string key;

            for (int n : count) {
                key += "#" + to_string(n);
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& e : groups) {
            result.push_back(e.second);
        }

        return result;
    }
};