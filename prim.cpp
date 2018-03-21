// pq = {edge,node}
// s = start node
// g[i] = {j,w} : path from i to j of cost w

priority_queue<pii > pq;
pq.push(mp(0,s));
int ans = 0;
while(!pq.empty()) {
	pii p = pq.top(); pq.pop();
	int cost = -p.fr;
	u = p.se;
	if(visited[u]) continue;
	ans += cost;
	visited[u] = 1;
	for(int i=0;i<g[u].size();i++) {
	    int v = g[u][i].fr;
	    int w = g[u][i].se;
	    if(!visited[v]) {
			pq.push(mp(-w,v));
	    }
	}
}
