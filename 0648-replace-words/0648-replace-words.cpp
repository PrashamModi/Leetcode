struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

     void setEnd() {
        flag = true;
     }

     bool isEnd() {
        return flag;
     }
};

class Trie{
    private :
        Node* root;

    public:
        Trie(){
            root = new Node();
        }

        void insert(string word) {
            Node *node = root;
            for(int i = 0; i < word.length(); i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        string search(string word) {
            Node *node = root;
            string ans;

            for(int i = 0; i < word.length(); i++) {
                if(!node->containsKey(word[i])) {
                    return word;
                }
                node = node->get(word[i]);
                ans.push_back(word[i]);
                if(node->isEnd()) return ans;
            }
            return word;
        }

        bool startsWith(string prefix) {
            Node* node = root;
            for(int i = 0; i < prefix.length(); i++) {
                if(!node->containsKey(prefix[i])) {
                    return false;
                }
                node = node->get(prefix[i]);
            }
            return true;
        }

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto it : dictionary) {
            trie.insert(it);
        }
        stringstream ss(sentence);
        string word, ans;

        while(ss >> word) {
            if(!ans.empty()) ans += " ";
            ans += trie.search(word);
        }
        return ans;
    }
};