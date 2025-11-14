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



class kosaraju{
private:
    int n,m;
    vi order;
    vi comp;
    vb used;
    vvi adj;
    vvi radj;
    vvi sscs;

public:
    void init(){
        cin >> n >> m;

        adj.resize(n,{});
        radj.resize(n,{});

        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        
    }


    void dfs1(int u){
        for(auto v:adj[u]){
            if(!used[v]){
                used[v]=true;
                dfs1(v);
            }
        }
        order.push_back(u);
    }


    void dfs2(int u){
        comp.push_back(u);
        for(auto v:radj[u]){
            if(!used[v]){
                used[v]=true;
                dfs2(v);
            }
        }
    }


    void kosaraju_algorithm(){
        used.assign(n,false);

        for(int i=0;i<n;i++){
            if(!used[i]){
                used[i]=true;
                dfs1(i);
            }
        }


        used.assign(n,false);

        for(int i=n-1;i>=0;i--){
            int u=order[i];
            if(!used[u]){
                used[u]=true;
                dfs2(u);
                sscs.push_back(comp);
                comp.clear();
            }
        }    
    }


    void main(){
        init();

        kosaraju_algorithm();

        cout << "STRONG CONNECTED COMPONENTS: " << endl;

        for(auto ssc:sscs){
            for(auto t:ssc){
                cout << t << " " ;
            }cout << endl;
        }
    }

    /*
    input : 
        8 10
        0 1
        1 2
        2 0
        2 3
        3 4
        4 5
        5 3
        6 5
        6 7
        7 6
    output:
        STRONG CONNECTED COMPONENTS: 
        6 7 
        0 2 1 
        3 5 4 
    */

};







void solve() {
    // cout << "hello world." << endl;
    kosaraju obj;
    obj.main();
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








