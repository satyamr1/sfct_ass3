#ifndef BFS_INCLUDED
#define BFS_H_INCLUDED

list bfs(graph G, int source, int sink){
    int e = G.getE();
    list path(e);       // Path will store the path obtained from source to sink
    if(source==sink)return path;
    int n = G.getV();
	queue Q(n);
	int* visited;
	visited = new int[n];   // visited array stores the parent node of a node(parent node- Node that visited a particular node for the first time during traversal is it's parent node)
	for(int i=0;i<n;i++)visited[i]=-1;  // initially no node has a parent
	Q.enqueue(source);
	while(!Q.empty()){
        int x = Q.dequeue();
        for(int i=0;i<n;i++){
            if(G.getCapacity(x,i)!=0){
                if(visited[i]==-1){
                    visited[i]=x;
                    if(i==sink){
                        int z = sink;
                        while(z!=source){
                            path.insert(visited[z],z);      //obtaining the path using the visited array(by recursively getting the parent of a node).
                            z = visited[z];                 // visited[z] is the parent node of z
                        }
                        return path;
                    }
                    Q.enqueue(i);
                }
            }
        }
	}
    return path;
}

#endif
