int xdir[4] = {0,1,0,-1}, ydir[4] = {1,0,-1,0};
int dist[21][21];
queue<pii> todo;

void process(pii x) {
	F0R(i,4) { // easily iterate through adjacent points
		pii y = {x.f+xdir[i],x.s+ydir[i]};
		if (y.f < 0 || y.f > 20 || y.s < 0 || y.s > 20) continue; // ignore this point if it's outside of grid
		if (dist[y.f][y.s] == MOD) { // test whether point has been visited or not
		    dist[y.f][y.s] = dist[x.f][x.s]+1;
		    todo.push(y); // push point to queue
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	F0R(i,21) F0R(j,21) dist[i][j] = MOD;
	dist[10][10] = 0; todo.push({10,10}); // initialize queue, distances
	while (todo.size()) {
	    process(todo.front());
	    todo.pop(); // pop point from queue
	}
	cout << dist[4][5]; // 11
}
