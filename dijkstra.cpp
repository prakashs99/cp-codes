// s = start node
// ans[i] = shortest distance from s to i
// g[i] = {j,w} : path from i to j of cost w
 
priority_queue<pii > pq;
pq.push(mp(0,s));
while(!pq.empty()) {
    pii p = pq.top(); pq.pop();
    int u = p.se;
    if(visited[u]) continue;
    int w = -p.fr;
    visited[u] = 1;
    ans[u] = w;
    for(int i=0;i<g[u].size();i++) {
		int v = g[u][i].fr;
		int wgt = g[u][i].se;
		if(!visited[i]) {
	    	pq.push(mp(-(w+wgt),v));
		}
    }
}
