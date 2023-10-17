class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // Calculating indegree to find the root because
        //root will have a indegree of 0 .
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) indegree[leftChild[i]]++;
            if(rightChild[i] != -1) indegree[rightChild[i]]++;
        }

        int root = -1;
        for(int i = 0; i < n; i++) {
            if(!indegree[i]) {
                // a tree cannot have multiple root nodes
                if(root == -1) root = i;
                else return false;
            }
        }

        if(root == -1) return false;

        //bfs traversal to check if a node doesn't multiple parents .
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(vis[node]) return false;
            vis[node] = 1;
            if(leftChild[node] != -1) q.push(leftChild[node]);
            if(rightChild[node] != -1) q.push(rightChild[node]);
        }
        return accumulate(vis.begin(), vis.end(), 0) == n;
    }
};