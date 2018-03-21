q.push(mp(0,0));
visited[0] = 1;
int ans ;
while(!q.empty()) {
	pii pp = q.front(); q.pop();
	int u = pp.fr;
	int cost = pp.se;

	// If destination is reached

	if(u==n) {
		ans = cost;
		break;
	}

	// Moves

	if(u+1<=n) {
	    if(!visited[u+1]) {
		    q.push(mp(u+1,cost+1));
		    visited[u+1] = 1;
		}
	}
	if(u+p[u]<=n && u+p[u]>=0) {
		if(!visited[u+p[u]]) {
		    visited[u+p[u]] = 1;
		    q.push(mp(u+p[u],cost+1));
		}
	}
}
