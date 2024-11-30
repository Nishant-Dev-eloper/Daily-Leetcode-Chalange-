/*
    2097. Valid Arrangement of Pairs
    Solved
    Hard
    Topics
    Companies
    Hint
    You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.
    
    Return any valid arrangement of pairs.
    
    Note: The inputs will be generated such that there exists a valid arrangement of pairs.
    
     
    
    Example 1:
    
    Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
    Output: [[11,9],[9,4],[4,5],[5,1]]
    Explanation:
    This is a valid arrangement since endi-1 always equals starti.
    end0 = 9 == 9 = start1 
    end1 = 4 == 4 = start2
    end2 = 5 == 5 = start3
    Example 2:
    
    Input: pairs = [[1,3],[3,2],[2,1]]
    Output: [[1,3],[3,2],[2,1]]
    Explanation:
    This is a valid arrangement since endi-1 always equals starti.
    end0 = 3 == 3 = start1
    end1 = 2 == 2 = start2
    The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
    Example 3:
    
    Input: pairs = [[1,2],[1,3],[2,1]]
    Output: [[1,2],[2,1],[1,3]]
    Explanation:
    This is a valid arrangement since endi-1 always equals starti.
    end0 = 2 == 2 = start1
    end1 = 1 == 1 = start2
     
    
    Constraints:
    
    1 <= pairs.length <= 105
    pairs[i].length == 2
    0 <= starti, endi <= 109
    starti != endi
    No two pairs are exactly the same.
    There exists a valid arrangement of pairs.
    
    Seen this question in a real interview before?
    1/5
    Yes
    No
    Accepted
    63.8K
    Submissions
    95.4K
    Acceptance Rate
    66.9%
    Topics
    Companies
    Hint 1
    Hint 2
    Hint 3
    We have to find an Eulerian path of this graph. Hierholzer’s algorithm can be used.
    

*/


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;

        unordered_map<int,int> indegree,outdegree;

        for(auto& edge:pairs){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        // find starting node of euler's path-->
        int starting_Node=pairs[0][0];
        for(auto& it:adj){
            int node=it.first;
            if(outdegree[node] -indegree[node] ==1){
                starting_Node=node;
                break;
            }
        }
        
        // DFS-->
        vector<int> EulersPath;
        stack<int>st; // to perform dfs
        st.push(starting_Node);

        while(!st.empty()){
            int curr =st.top();

            if(!adj[curr].empty()){
                int nbr =adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            }
            else{
                EulersPath.push_back(curr);
                st.pop();
            }
        }
        reverse(EulersPath.begin(),EulersPath.end());

        vector<vector<int>>res;
        for(int i=0;i<EulersPath.size()-1;i++){
            res.push_back({EulersPath[i],EulersPath[i+1]});

        }
        return res;

        
    }
};
