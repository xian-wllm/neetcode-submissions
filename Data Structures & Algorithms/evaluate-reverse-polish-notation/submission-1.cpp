class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string& s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int el_2 = stoi(st.top()); st.pop();
                int el_1 = stoi(st.top()); st.pop();
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

                st.push(to_string(res));

            }else{
                st.push(s);
            } 
        }

        return stoi(st.top());

        return 0;
    }
};
