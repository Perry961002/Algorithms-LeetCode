class Solution {
public:
    //返回s的根节点
    string findParent(string s, unordered_map<string,string>& hash){
        if(hash[s] != s){
            s = findParent(hash[s], hash);
        }
        return s;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> owner;//记录<email, uesr>
        unordered_map<string, string> parents;//记录<email, father email>
        unordered_map<string, set<string>> unions;//记录<邮箱, 并查集>
        //初始化
        for(auto itr : accounts){
            for(int j=1;j<itr.size();j++){
                owner[itr[j]] = itr[0];
                parents[itr[j]] = itr[j];
            }
        }
        //find和union操作
        for(auto account : accounts){
            //每个账户的首个邮箱的祖先邮箱
            string fatherEmail = findParent(account[1], parents);
            for(int i=2;i<account.size();i++){
                //同一个人的邮箱应该有同一个祖先邮箱
                parents[findParent(account[i], parents)] = fatherEmail;
            }
        }
        for(auto account : accounts){
            for(int i=1;i<account.size();i++){
                //将属于同一个祖先的邮箱并入他们祖先的并查集中
                unions[findParent(account[i], parents)].insert(account[i]);
            }
        }
        //将账户合并
        vector<vector<string>> res;
        for(auto p : unions){
            vector<string> emails;
            emails.push_back(owner[p.first]);//先装入用户
            for(auto email : p.second){
                emails.push_back(email);
            }
            res.push_back(emails);
        }
        return res;
    }
};