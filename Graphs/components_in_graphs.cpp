
/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vb             vector<bool>
#define vi             vector <int>
#define vvi            vector<vi>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


void init(){
    fast_io;
    #ifndef ONLINE_JUDGE
        string input_file,output_file;
        input_file="input.txt";
        output_file="output.txt";

        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    #endif 
}

const int N = 200005;


class bridge_in_graph{
private:
    int n, m, timer, initial_point;
    vb visited;
    vi tm, low, parent;
    vvi adj,bridges;

public:
    void init(){
        cin >> n >> initial_point >> m;

        timer = 0;
        visited.assign(n, false);
        tm.assign(n, 0);
        low.assign(n, 0);
        parent.assign(n, -1);
        adj.assign(n, {});

        for(int i=0;i<m;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int u){
        visited[u] = true;
        tm[u] = low[u] = ++timer;

        for(int v : adj[u]){

            if(!visited[v]){
                parent[v] = u;
                dfs(v);

                low[u] = min(low[u], low[v]);

                if(low[v] > tm[u]){
                    bridges.push_back({u,v});
                }
            }
            else if(v != parent[u]){
                low[u] = min(low[u], tm[v]);
            }
        }
    }

    bridge_in_graph(){
        init();
        dfs(initial_point);

        cout << "number of bridges : " << bridges.size() << endl;
        for(auto &b : bridges){
            cout << b[0] << "----" << b[1] << endl;
        }
    }
};




void solve() {
    bridge_in_graph obj;
}





int32_t main()
{    
    init();
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}







