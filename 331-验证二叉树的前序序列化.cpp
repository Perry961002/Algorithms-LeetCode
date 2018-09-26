class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 1)
            return preorder == "#";
        //预处理
        for(int i=0;i< preorder.size();i++){
            if(preorder[i] == ',')
                preorder[i] = ' ';
        }
        istringstream s(preorder);
        string str;
        stack<string> st;
        s >> str;
        while(s){
            while (str == "#" && st.size() > 1 && st.top() == "#"){
			st.pop();
			if(st.top() != "#")
                st.pop();
            }
		st.push(str);
		s >> str;
        }
        return st.size() == 1;
    }
};