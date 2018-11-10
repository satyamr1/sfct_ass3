#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

list dfs(graph G, int source, int sink){
    int e = G.getE();
    list path(e);       // Path will store the path obtained from source to sink
    if(source==sink)return path;
    int n = G.getV();
    bool *visited = new bool[n];        // visited array keeps the track of visited nodes
	for(int i=0;i<n;i++)visited[i]=0;   //Initially no node has been visited
    int currNode = source;
    int j = 0;
	while(true){
        visited[currNode] = 1;          //mark the node visited
        while((G.getCapacity(currNode, j) == 0 || visited[j]==1) && j<n)j++;    // Get the unvisited adjacent node of a particular node
        if(j<n){    // Insert the node in list
            path.insert(currNode, j);
            if(j == sink)return path;
            currNode = j;
        }
        else {      // no unvisited adjacent node found
            if(path.isEmpty())return path;      // No path found
            path_node* n1 = path.del();         // Backtrack to the previously visited node
            if(n1 != NULL)currNode = n1->v;
            else currNode = source;
        }
        j=0;
	}
}

#endif
