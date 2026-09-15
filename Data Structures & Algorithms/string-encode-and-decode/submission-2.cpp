class Solution {
public:

    string encode(vector<string>& strs) {
        string base = "";
        for(auto e: strs){
            base += to_string(e.size()) + "#" + e;
        }

        return base;
    }

    vector<string> decode(string s) {
        vector<string> tab;
        int i = 0;
        while(i < s.size()){
            int slash = s.find("#", i);
            int len = stoi(s.substr(i , slash - i));
            tab.push_back(s.substr(slash + 1, len));
            i = slash + len + 1;
        }

        return tab;
    }
};
