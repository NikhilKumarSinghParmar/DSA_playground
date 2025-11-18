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
