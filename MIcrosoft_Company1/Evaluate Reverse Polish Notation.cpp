class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i]=="+"){
                int e1 = st.top();
                st.pop();
                int e2 = st.top();
                st.pop();
                st.push(e2+e1);
                // cout << st.top() << endl;;
            }
            else if(tokens[i]=="-"){
                int e1 = st.top();
                st.pop();
                int e2 = st.top();
                st.pop();
                st.push(e2-e1);
                // cout << st.top() << endl;
            }
            else if(tokens[i]=="*"){
                int e1 = st.top();
                st.pop();
                int e2 = st.top();
                st.pop();
                st.push(e2*e1);
                // cout << st.top() << endl;
            }
            else if(tokens[i]=="/"){
                int e1 = st.top();
                st.pop();
                int e2 = st.top();
                st.pop();
                st.push(e2/e1);
                // cout << st.top() << endl;
            }
            else{
                int ans = stoi(tokens[i]);
                st.push(ans);
                // cout << st.top() << endl;
            }
        }
            return st.top();
    }
};