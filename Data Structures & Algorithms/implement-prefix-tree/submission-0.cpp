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
class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node * node = root;
        for(int i =0; i<word.size(); i++){
            char c = word[i];
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return node->getEnd();
    }
    
    bool startsWith(string word) {
         Node * node = root;
        for(int i =0; i<word.size(); i++){
            char c = word[i];
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return true;
    }
};
