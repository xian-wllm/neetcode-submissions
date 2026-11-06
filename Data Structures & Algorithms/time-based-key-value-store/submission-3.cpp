class TimeMap {
public:
    map<string, vector<pair<string, int>>> mp;
    int count = 0;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});

    }
    
    string get(string key, int timestamp) {
        cout << count << endl;
        if(mp.contains(key)){
            
            int left = 0;
            int right = mp[key].size() - 1;
            int result = -1;
            
            while(left <= right){
                int mid = left + (right - left) / 2 ;
            
                if(mp[key][mid].second == timestamp){
                    return mp[key][mid].first;
                }
            
                else if(mp[key][mid].second < timestamp){
                    result = mid;
                    left = mid +1 ;
            
                }else{
                    right = mid - 1;
                }
            }
            
            if(result == -1){
                return "";
            }
            else{
                return mp[key][result].first;
            }

        }else{
            return "";
        }

    }
};
