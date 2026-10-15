class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> pos_time;
        stack<float> st;

        for(int i = 0; i < position.size(); i++){
            
            float time = (float) (target - position[i]) / (float) speed[i];
            pos_time.push_back({position[i], time});
        }


        sort(pos_time.begin(), pos_time.end(),
        [](const pair<int, float>& a, const pair<int,float>& b){
            return a.first > b.first;
        });

        int count = 0;
        for(int i=0; i < pos_time.size(); i++){
            if(!st.empty() && st.top() >= pos_time[i].second){
                
                
                continue;
            }
            count++;
            st.push(pos_time[i].second);
        }

        return st.size();

    }   
};
