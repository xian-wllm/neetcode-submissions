class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string& s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int el_2 = st.top(); st.pop();
                int el_1 = st.top(); st.pop();
                int res;

                if(s == "+"){
                    res = el_1 + el_2;
    
                }else if(s == "-"){
                    res = el_1 - el_2 ;
    
                }else if(s == "*"){
                    res = el_1 * el_2 ;
    
                }else{
                    res = el_1 / el_2 ;

                }

                st.push(res);

            }else{
                st.push(stoi(s));
            } 
        }

        return st.top();

        return 0;
    }
};
