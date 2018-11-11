graph FF(graph G, int source, int sink, bool UseBFS){
	list path(G.getE());    // Will store the path returned by BFS/DFS
	graph augG(G.getV());   // Defining Residual Graph
	augG.copy(G);           // Initially augmented graph is the given graph
	if(UseBFS){             // Running for path given by BFS
		path = bfs(augG,source,sink);
		while(!path.isEmpty()){     //Till no path found
			path.updateFlow(augG, G);  // Update the residual graph
			path = bfs(augG,source,sink);
		}
	}
	else {
		path = dfs(augG,source,sink);
		while(!path.isEmpty()){     //Till no path found
			path.updateFlow(augG, G);  // Update the residual graph
			path = dfs(augG,source,sink);
		}
	}
	return augG;
}
