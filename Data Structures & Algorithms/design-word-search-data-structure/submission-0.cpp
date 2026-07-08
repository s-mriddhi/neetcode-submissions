class Node{
    Node* links[26] = {nullptr};
    bool flag = false;

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
};
class WordDictionary {
     Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int index, Node* root){
        if(index==word.size()) return root->getEnd();

        for(int i = index ; i<word.size(); i++){
            char ch = word[i];
            if(ch=='.'){
                for(char c ='a'; c<='z'; c++){
                    if(root->containsKey(c)){
                        Node* child = root->get(c);
                        if(dfs(word, i+1, child)) return true;
                    }    
                }
                return false;
            }
            else if(!root->containsKey(ch)) return false;
            else{
                root = root->get(ch);
            }
        }
        return root->getEnd();
    }
};
