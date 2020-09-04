    // DFS implementation.
// traverse all stones considering index as id
// visit each id if not visited
// Number of visited stones is the answer.

// time - O(N^2)
// space - O(N)
/*
class Solution {
public:
    int dfs(vector<vector<int>>&stones,int index,vector<bool> &visited){
        visited[index]=true;
        int result=0;
        for(int i=0;i<stones.size();i++)
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                result+=dfs(stones,i,visited)+1;
        return result;
    }
    int removeStones(vector<vector<int>>&stones) {
        vector<bool> visited(stones.size());
        int result=0;
        
        for(int i=0;i<stones.size();i++){
            if(!visited[i])
            result+=dfs(stones,i,visited);
        }
        return result;
    }
};
*/

    //Union find solution.
// Time  - O(N)
// Space - O(N)
class Solution {
public:
    unordered_map<int,int> parent;
    int islands = 0;
    int removeStones(ve``ctor<vector<int>>& stones) {
        //try to employ union find strategy and find the no of connected components
        // so each component can have all of its stones removed but one
        // hence count = no of stones - no of components.
        for(auto stone:stones)
            union_find(stone[0],stone[1]+10000);
        return stones.size() - islands;
        
    }
    
    // find operation using path compression
    int find(int x)
    {
        if(parent.find(x)==parent.end())
        {
            parent[x] = x;
            islands++;
            return x;
        }
        while(parent[x]!=x)
        {
            int par = parent[x];
            parent[x] = parent[par];
            x = par;
        }
        return x;
    }
    
    void union_find(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);
        
        if(parx!=pary)
        {
            parent[parx] = pary;
            islands--;
        }
    }
 