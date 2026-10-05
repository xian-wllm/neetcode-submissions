class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = ""; 
        for(string s: strs){
            encoded_string += to_string(s.size()) + '#' + s;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        
        vector<string> decoded_string;
        
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            int start = j + 1;
            int end = length + start;
            
            string current_string = "";
            for(int k = start; k < end; k++){
                current_string += s[k];
                 
            }

            decoded_string.push_back(current_string);
            i = end;


        }
      
        return decoded_string;
    }
};
