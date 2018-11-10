#include <cstring>

struct graph_node {
    int u,v,c,f;
};
class graph{
    graph_node **am;               //Adjacency matrix
    int v;                         //Number of vertices in the graph
    int e;                         //Number of edges

public:
    graph(int n){
        v = n;
        am = new graph_node* [n];       //Initializing Adjacency Matrix
        for(int i=0;i<n;i++){
            am[i] = new graph_node[n];
            for(int j=0;j<n;j++){
                am[i][j].c = 0;
                am[i][j].f = 0;
            }
        }
    }
    int getV(){                 //Returns number of vertices in the graph
        return v;
    }
    int getE(){                 //Returns number of edges in the graph
        return e;
    }
    void setE(int n){           //Sets the number of edges in the graph
        e = n;
    }
    void printGraph(int n){     //prints the result
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<am[i][j].f<<" ";
            if(i<n-1)cout<<endl;
        }
    }

    void addEdge(int i, int j, int capacity, int flow){       //Adds an edge between given two vertices with given capacity and flow
        if(i<0 || j<0 || i>=v || j>=v){
            cout<<"Invalid source or destination";
            return;
        }
        am[i][j].c = capacity;
        am[i][j].f = flow;
    }

    int getCapacity(int i, int j){
        return am[i][j].c;
    }

    int setCapacity(int i, int j, int cp){
        am[i][j].c = cp;
    }
    int getFlow(int i, int j){
        return am[i][j].f;
    }

    int setFlow(int i, int j, int flow){
        return am[i][j].f = flow;
    }
    void modify(graph G){           // Function to add dummy nodes
        int n = G.getV();
        int v_added = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(G.getCapacity(i,j)!=0 && G.getCapacity(j,i) != 0 && i<j){ // parallel edge
                    addEdge(i, n+v_added, G.getCapacity(i,j), 0);
                    addEdge(n+v_added, j, G.getCapacity(i,j), 0);
                    v_added++;      // v_added keeps the track of new node to be added
                }
                else {
                    addEdge(i, j, G.getCapacity(i,j), 0);
                }
            }
        }
		e = G.getE()+n;     // One extra edge for a new node
    }
    void copy(graph G){     //Duplicate the given graph
        e = G.getE();
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                addEdge(i, j, G.getCapacity(i,j), 0);
            }
        }
    }
    void revert(int n){         //Obtain the graph with initial number of nodes from the graph with dummy nodes
    	for(int i=0;i<n;i++) for(int j=n;j<v;j++)
            if(am[i][j].f != 0) for(int z=0;z<v;z++)
                if(am[j][z].f != 0) am[i][z]=am[j][z];
	}
	int getFlowValue(int n){    //Calculates the total flow value
		int sum=0;
		for(int i=0;i<n;i++){
			sum += am[0][i].f;      //Total flow is the total outflow from source node
		}
		return sum;
	}
};
