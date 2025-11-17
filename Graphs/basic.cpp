#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>


class Solution {
// 997 - find judge in town
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){return n;}
        vi indeg(n+1,0);
        vi outdeg(n+1,0);

        for(auto vec:trust){
            outdeg[vec[0]]++;
            indeg[vec[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 && outdeg[i]==0){
                return i;
            }
        }

        return -1;
    }
};




class Solution {
// 1971 - find if path exists in the graph
public:
    vvi adj;
    vb visited;
    int dest;

    bool search(int src){
        if(src==dest){return true;}

        for(auto v:adj[src]){
            if(!visited[v]){
                visited[v]=true;
                if(search(v)){
                    return true;
                };
            }
        }

        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        adj.resize(n);
        visited.resize(n,false);
        dest=destination;

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }        

        visited[source]=true;
        bool found=search(source);

        return found;
    }
};




class Solution {
// 841 keys and rooms
public:
    vb visited;


    void dfs(vvi& rooms,int u){
        visited[u]=true;
        int m=rooms[u].size();

        for(int i=0;i<m;i++){
            if(!visited[rooms[u][i]]){
                dfs(rooms,rooms[u][i]);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        visited.resize(n,false);

        dfs(rooms,0);

        int cnt=0;
        for(auto t:visited){
            if(t){++cnt;}
        }

        return n==cnt;
    }
};





class Solution {
// 547 - number of provinces
public:
    vb visited;
    int n;


    void dfs(vvi& nums,int u){
        visited[u]=true;

        for(int i=0;i<n;i++){
            if(i!=u && nums[u][i] && !visited[i]){
                dfs(nums,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& nums) {
        n=nums.size();
        visited.resize(n,false);

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ++cnt;
                dfs(nums,i);
            }
        }

        return cnt;
    }
};





