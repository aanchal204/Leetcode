/**

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
https://leetcode.com/problems/clone-graph/

 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return node;
        map<UndirectedGraphNode *, UndirectedGraphNode*>mp;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        UndirectedGraphNode * newnode = new UndirectedGraphNode(node->label);
        mp[node] = newnode;
        while(!q.empty()){
            UndirectedGraphNode *curr = q.front();
            q.pop();
            vector<UndirectedGraphNode *> adj = curr->neighbors;
            for(int i=0;i<adj.size();i++){
                if(mp[adj[i]] == NULL){
                    newnode = new UndirectedGraphNode(adj[i]->label);
                    mp[adj[i]] = newnode;
                    q.push(adj[i]);
                }
                mp[curr]->neighbors.push_back(mp[adj[i]]);
            }
        }
        return mp[node];
    }
};