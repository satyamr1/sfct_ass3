#ifndef LIST_ADT_H_INCLUDED
#define LIST_ADT_H_INCLUDED

struct path_node {
    int u,v;        // path consists of edges->(u,v)
};

class list{

    path_node** arr;        // List of path_nodes
    int size;
    int sp;                 // New node will be inserted at sp

public:
    list(int n){
        arr = new path_node*[n];
        sp = 0;
        size = n;
    }

    void insert(int i, int j){
        if(sp >= size){
        	cout<<size;
            cout<<"List Overflow";
            return;
        }
        path_node *newNode = new path_node;
	    newNode->u = i;
	    newNode->v = j;
	    arr[sp++] = newNode;
    }
	path_node* del(){       // Deletes the last element and returns the new last element of the list
        if(sp<=0){
            cout<<"Empty List";
            return NULL;
        }
        sp--;
        if(sp-1>=0)return arr[sp-1];
        else return NULL;
	}

	int findMin(graph G){           // Returns the flow of the path, i.e. the flow value of the edge with min flow
        int min = G.getCapacity(arr[0]->u,arr[0]->v);
        for(int i=1;i<sp;i++){
        	if(G.getCapacity(arr[i]->u,arr[i]->v)<min){
        		min = G.getCapacity(arr[i]->u,arr[i]->v);
			}
		}
        return min;
	}

	void updateFlow(graph residualG, graph G){           // Updates the residual graph at each iteration
        int cf = findMin(residualG);
	    for(int i=0;i<sp;i++){
            if(G.getCapacity(arr[i]->u,arr[i]->v) != 0)
                residualG.setFlow(arr[i]->u,arr[i]->v,residualG.getFlow(arr[i]->u,arr[i]->v)+cf);
            else
                residualG.setFlow(arr[i]->v,arr[i]->u,residualG.getFlow(arr[i]->v,arr[i]->u)-cf);

                residualG.setCapacity(arr[i]->u,arr[i]->v,residualG.getCapacity(arr[i]->u,arr[i]->v)-cf);
                residualG.setCapacity(arr[i]->v,arr[i]->u,residualG.getCapacity(arr[i]->v,arr[i]->u)+cf);
		}
	}
	bool isEmpty(){
		return sp==0;   //if sp=0 then list is empty
	}
};
#endif

