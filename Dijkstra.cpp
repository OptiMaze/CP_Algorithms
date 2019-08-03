// Warning : Adjancency list Declaration must be like " vector< pair<int,int> > g[nax] "

vector<int> dijkstra(int start,int vertices){
    vector<int> dist(vertices,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push(mp(0,start));
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        for(auto it:g[p.se]){
            if(dist[it.fi]>p.fi+it.se){
                dist[it.fi] = p.fi+it.se;
                pq.push(mp(dist[it.fi],it.fi));
            }
        }
    }
    return dist; 
}
