void solve(){
    ll n,x;
    cin>>n>>x;
    vt v(n);
    ran(v) cin>>i;
    priority_queue<pair<ll,ll>> pq;
    map<ll,ll> m;
    for(int i=0;i<n;i++){
        m[v[i]]++;
        pq.push({m[v[i]],v[i]});
        auto ff = pq.top();
        cout<<ff.S<<" "<<ff.F<<endl;
    }
}
