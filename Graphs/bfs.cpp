class Solution {
// 994. Rotting Oranges
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    ++fresh;
                }
            }
        }

        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int cnt=0;
        if(q.size()){
            cnt=-1;
        }

        while(!q.empty()){
            int sz=q.size();
            ++cnt;
            for(int i=0;i<sz;i++){
                auto [x,y]=q.front();
                q.pop();
                // cout << x << " " << y << endl;

                for(int i=0;i<4;i++){
                    if((x+dx[i])>=0 && (x+dx[i])<m && (y+dy[i])>=0 && (y+dy[i])<n && grid[x+dx[i]][y+dy[i]]==1){
                        grid[x+dx[i]][y+dy[i]]=2;
                        --fresh;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
            }
        }

        // cout << fresh << " , " << cnt  << endl;
        return (fresh==0)? cnt : -1;
    }
};





class Solution {

// 752. Open the Lock
public:
    int openLock(vector<string>& deadends, string target) {    
        unordered_set<string> dead(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        queue<string> q;

        string start="0000";
        q.push(start);
        visited.insert(start);
        int cnt=-1;
        if(dead.count(start)){return -1;}
        else if(start==target){return 0;}

        while(!q.empty()){
            int sz=q.size();
            ++cnt;
            for(int i=0;i<sz;i++){
                string node=q.front();
                q.pop();

                if(node==target){return cnt;}

                for(int j=0;j<4;j++){
                    int ch=node[j]-'0';
                    
                    int ahead=(ch+1)%10;
                    node[j]=char('0'+ahead);
                    if(!visited.count(node) && !dead.count(node)){
                        visited.insert(node);
                        q.push(node);
                    }
                    
                    int back=(ch-1+10)%10;
                    node[j]=char('0'+back);;
                    if(!visited.count(node) && !dead.count(node)){
                        visited.insert(node);
                        q.push(node);
                    }

                    node[j]=char('0'+ch);
                }
            }
        }

        return -1;

    }
};



class Solution {
// 752. Open the Lock
public:
    bitset<10000> seen;
    int start,target;
    
    vector<int> get_neighbors(int u){
        vector<int> ans;
        int p10[]={1,10,100,1000,10000};

        for(int i=0;i<4;i++){
            int t=(u % p10[i+1]) / p10[i];
            int rem=u-(t*p10[i]);

            int head=(t+1)%10;
            int back=(t-1+10)%10;

            int v1=rem+(head * p10[i]);
            int v2=rem+(back * p10[i]);

            ans.push_back(v1);
            ans.push_back(v2);
        }

        return ans;
    }



    int bfs(){
        if(seen[target]){return 0;}
        if(seen[start]){return -1;}
        
        int cnt=-1;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int sz=q.size();
            ++cnt;
            for(int i=0;i<sz;i++){
                int front=q.front();
                q.pop();
                if(front==target){return cnt;}

                auto neighbors=get_neighbors(front);
                for(auto t:neighbors){
                    if(!seen[t]){
                        seen[t]=1;
                        q.push(t);
                    }
                }
            }
        }

        return -1;
    }


    int openLock(vector<string>& deadends, string targt) {
        for(auto t:deadends){
            seen[stoi(t)]=1;
        }
        start=0;
        target=stoi(targt);
        
        return bfs();
    }
};



#define F first
#define S second
using vi=vector<int>;
using vvi=vector<vector<int>>;
using pii=pair<int,int>;


class Solution {
// 1091. Shortest Path in Binary Matrix
public:
    void init(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        init();
        int m=grid.size();
        int n=grid[0].size();
        queue<pii> q;
        pii start={0,0};

        if(start.F==m-1 && start.S==n-1 && grid[0][0]==0){return 1;}

        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};

        if(grid[0][0]==0){
            q.push(start);
            grid[0][0]=1;
        }
        int cnt=0;

        while(!q.empty()){
            int sz=q.size();
            ++cnt;

            for(int i=0;i<sz;i++){
                auto [x,y]=q.front();
                q.pop();
                
                // cout << x << " , " << y << endl;
                if(x==m-1 && y==n-1){return cnt;}

                for(int j=0;j<8;j++){
                    int a=x+dx[j];
                    int b=y+dy[j];
                    // cout << a << " " << b << endl;
                    if(a>=0 && a<m && b>=0 && b<n && grid[a][b]==0){
                        grid[a][b]=1;
                        q.push({a,b});
                    }
                }
            }
        }

        return -1;
    }
};





#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vvi vector<vi>

class Solution {
// 542. 01 Matrix
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vvi ans(m,vi(n));
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        queue<pair<pii,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push(make_pair(make_pair(i,j),0));
                    // cout << i << " , " << j << endl;
                }
            }
        }

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            pii xy=front.F;
            int val=front.S;

            int x=xy.F;
            int y=xy.S;

            // cout << x << " , " << y << " : " <<  val << endl;

            ans[x][y]=val;

            for(int i=0;i<4;i++){
                int a=x+dx[i];
                int b=y+dy[i];

                if(a>=0 && a<m && b>=0 && b<n && mat[a][b]==1){
                    mat[a][b]=0;
                    q.push(make_pair(make_pair(a,b),val+1));
                }    
            }   
        }

        return ans;
    }
};




#define vi vector<int>
#define vvi vector<vi>

class Solution {
// 2101. Detonate the Maximum Bombs
public:
    vvi adj;
    vector<bool> visited;

    bool in_range(int x1,int y1,int val,int x2,int y2){
        return (1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2)) <=  1LL*val*val ;
    }


    int dfs(int u){
        visited[u]=1;
        int ans=1;

        for(auto v:adj[u]){
            if(!visited[v]){
                ans += dfs(v);
            }
        }

        return ans;
    }



    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        adj.resize(n,{});
        visited.resize(n);

        for(int i=0;i<n;i++){
            int x1=bombs[i][0];
            int y1=bombs[i][1];
            int val1=bombs[i][2];

            for(int j=i+1;j<n;j++){
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                int val2=bombs[j][2];

                if(in_range(x1,y1,val1,x2,y2)){
                    adj[i].push_back(j);
                }
                if(in_range(x2,y2,val2,x1,y1)){
                    adj[j].push_back(i);
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            visited.assign(n,false);
            int temp=dfs(i);

            maxi=max(maxi,temp);
        }      

        return maxi;
    }
};






#define vi vector<int>
#define vvi vector<vi>

class Solution {
// 815. Bus Routes
public:
    unordered_map<int,vi> group;
    unordered_set<int> visited;

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){return 0;}
        
        int n=routes.size();

        for(int i=0;i<n;i++){
            for(auto t:routes[i]){
                group[t].push_back(i);
            }
        }

        queue<int> q;
        q.push(source);
        int cnt=-1;

        while(!q.empty()){
            int sz=q.size();
            ++cnt;

            for(int i=0;i<sz;i++){
                int front=q.front();
                q.pop();

                if(front==target){return cnt;}

                for(auto grp:group[front]){
                    if(!visited.count(grp)){
                        visited.insert(grp);
                        for(auto t:routes[grp]){
                            q.push(t);
                        }
                    }
                }
            }
        }

        return -1;
    }
};




class Solution {
// 1293. Shortest Path in a Grid with Obstacles Elimination
public:
    int solve(vector<vector<int>>& grid,int k){
		// At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
		
		// queue stores (x,y,current path length,number of obstacles we can still remove)
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();
			
			// Exit if current position is outside of the grid
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                continue;
            }
			
			// Destination found
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return t[2];

            if(grid[x][y]==1){
                if(t[3]>0) // If we encounter an obstacle and we can remove it
                    t[3]--;
                else
                    continue;
            }
			
			// The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
			// Then we don't need to continue on our current path
            if(vis[x][y]!=-1 && vis[x][y]>=t[3])
                continue;
            vis[x][y]=t[3];
            
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
            
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    }
};
