class Node{
    public:
    bool flag = false;
    Node *links[10];
    bool containsKey(char ch){ return links[ch - '0'] != NULL; }
    void setEnd(){ flag = true; }
    bool isEnd(){ return flag; }
    Node* get(char ch){ return links[ch - '0'];}
    void put(char ch, Node* node){ links[ch - '0'] = node; }
};

class Trie{
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    int commonPrefix(string word) {
        int cnt = 0;
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsKey(word[i])){
                return cnt;
            }
            cnt++;
            node = node->get(word[i]);
        }
        return cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int it : arr1) {
            trie.insert(to_string(it));
        }
        int ans = 0;
        for(int it : arr2){
            int curr = trie.commonPrefix(to_string(it));
            ans = max(ans, curr);
        }
        return ans;
    }
};