class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map <string, vector<int>> mp;
        for(int i = 0; i < strs.size(); i++){
            string stringSorted = strs[i];
            sort(stringSorted.begin(), stringSorted.end());
            mp[stringSorted].push_back(i);
        }

        vector<vector<string>> results;

        for(auto [key, value] : mp){
            vector<string> res ;
            for(int& index : value){
                res.push_back(strs[index]);
            }

            results.push_back(res);
        }

        return results;
    }
};
