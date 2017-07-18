/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        unordered_map<DirectedGraphNode*, int> m;
        m[s] = 1;
        dfs(m, s);
        return m.count(t);
    }
    void dfs(unordered_map<DirectedGraphNode*, int> &m, DirectedGraphNode* s)
    {
        for(int i = 0; i < s->neighbors.size(); i++)
        {
            if(m.find(s->neighbors[i]) == m.end())
                m[s->neighbors[i]] = 1;
            dfs(m, s->neighbors[i]);
        }
    }
};

