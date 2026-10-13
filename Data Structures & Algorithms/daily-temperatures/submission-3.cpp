const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> output(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++){
            
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                
                int j = st.top();
                st.pop();

                output[j] = i - j;
            }
            
            st.push(i);
        }

        return output;
    }
};
