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






class Solution {
// 433. Minimum Genetic Mutation
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(!bank.size() && start!= end){return -1;}

        string str="ACGT";
        int m=bank[0].size();
        int n=str.size();
        unordered_set<string> st(bank.begin(),bank.end());
        queue<pair<string,int>> q;
        q.push({start,0});

        while(!q.empty()){
            auto [node,val]=q.front();
            q.pop();
            if(node == end){
                return val;
            }

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    char t=node[i];
                    node[i]=str[j];

                    if(st.count(node)){
                        q.push({node,val+1});
                        st.erase(node);
                    }

                    node[i]=t;
                }
            }
        }

        return -1;
    }
};





class Solution {
// 127. Word Ladder
public:
    int ladderLength(string begin, string end, vector<string>& list) {
        unordered_set<string> st(list.begin(),list.end());
        queue<string> q;

        q.push(begin);
        int cnt=0;

        while(!q.empty()){
            ++cnt;
            int n=q.size();
            for(int i=0;i<n;i++){
                string word = q.front();
                q.pop();
                // cout << word << " : " << cnt << endl;

                if(word==end){return cnt;}

                int n=word.size();
                for(int i=0;i<n;i++){
                    char ch=word[i];
                    for(int j=0;j<26;j++){
                        word[i]='a'+j;
                        if(st.count(word)){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i]=ch;
                }
            }
        }

        return 0;
    }
};





class Solution {
// 2115. Find All Possible Recipes from Given Supplies
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> rec(recipes.begin(),recipes.end());
        unordered_map<string,int> mp;
        unordered_map<string,vector<string>> adj;
        queue<string> q;

        int n=recipes.size();
        for(int i=0;i<n;i++){
            string recipe=recipes[i];
            for(auto ingredient:ingredients[i]){
                mp[recipe]++;
                adj[ingredient].push_back(recipe);
            }
        }

        for(auto t:supplies){
            q.push(t);
        }

        recipes.clear();

        while(!q.empty()){
            string ingredient=q.front();
            q.pop();

            for(auto recipe:adj[ingredient]){
                mp[recipe]--;
                if(mp[recipe]==0){
                    q.push(recipe);
                    if(rec.count(recipe)){
                        recipes.push_back(recipe);
                    }
                }
            }

        }

        return recipes;
    }
};




class Solution {
// 733. Flood Fill
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int m=image.size();
       int n=image[0].size();
       int original_color=image[sr][sc];
       if(original_color==color){
        return image;
       }
       int dx[4]={-1,0,1,0};
       int dy[4]={0,-1,0,1};
        queue<pair<int,int>> q;
       
       q.push({sr,sc});
        image[sr][sc]=color;

       while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                if((x+dx[i])>=0 && (x+dx[i])<m && (y+dy[i])>=0 && (y+dy[i])<n && image[x+dx[i]][y+dy[i]]==original_color){
                    image[x+dx[i]][y+dy[i]]=color;
                    q.push({x+dx[i],y+dy[i]});
                }
            }
       }

       return image;
    }
};
