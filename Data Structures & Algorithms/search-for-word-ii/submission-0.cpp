struct Node{
    Node* links[26];
    bool flag;

    public:
        bool containsKey(char c){
            return links[c-'a']!=nullptr;
        }
        Node* get(char c){
            return links[c-'a'];
        }
        void put(char c, Node* node){
            links[c-'a'] = node;
        }
        bool setEnd(){
            return flag = true;
        }
        bool getEnd(){
            return flag;
        }
        void clearEnd(){
            flag = false;
        }
};
class Trie{
private:
    Node * root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node * node = root;
        for(int i =0; i<word.size(); i++){
            char c = word[i];
            if(!node->containsKey(c)){
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
        return;
    }
    Node* getRoot(){
        return root;
    }
};
class Solution {
public:
    vector <int> drow = {-1, 0, 1, 0};
    vector <int> dcol = {0, 1, 0, -1};
    bool isValid(int &i, int &j, int &m , int &n){
        bool row = (i>=0)&&(i<m);
        bool col = (j>=0)&&(j<n);
        return row && col;
    }
    vector <string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie();
        for(string&word : words){
            t->insert(word);
        }
        int m = board.size();
        int n = board[0].size();
        vector <vector<bool>> vis(m, vector<bool> (n, false));
        string temp = "";
        for(int i =0; i<m ; i++){
            for(int j = 0; j<n; j++){
                dfs(temp,i, j, t->getRoot(), vis, board);
            }
        }
        return res;
    }

    void dfs(string& temp, int i, int j, Node* root,vector <vector<bool>> &vis, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        if(!root->containsKey(board[i][j])) return ;

        vis[i][j] = true;
        temp.push_back(board[i][j]);
        Node * curr = root->get(board[i][j]);
        if(curr->getEnd()) res.push_back(temp);
        curr->clearEnd();

        for(int nei =0; nei<4; nei++){
            int nr = i + drow[nei];
            int nc = j + dcol[nei];
            if(isValid(nr, nc, m, n)&&!vis[nr][nc]){
                dfs(temp, nr, nc, curr, vis, board);
            }
        }
        
        vis[i][j] = false;
        temp.pop_back();
    }
};
