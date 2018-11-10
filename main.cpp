#include <fstream>
#include <string>
#include<iostream>
#include<chrono>                            //including library to calculate execution time
using namespace std;
using namespace std::chrono;
#include"graph.h"
#include"list_adt.h"
#include"queue.h"
#include"bfs.h"
#include"dfs.h"
#include"FF.h"



int main () {
    string line;
    ifstream myfile ("input_flownet.txt");    //Input file
    if (myfile.is_open())
    {
        int n=0,i=0,j=0,k=0,e=0,z;
        while(getline(myfile,line)) n++;    // counting number of nodes in the graph
        graph G(n);
        z=n;
        myfile.clear();                     //clearing the reading buffer
        myfile.seekg(0, ios::beg);          //pointing to the starting of file again
        while(!myfile.eof()){               //loop to build the graph from the given input file
            if(i==n)break;
            myfile>>k;
            G.addEdge(i,j,k,0);
            if(k!=0)e++;             		//e stores the number of edges and hence excludes the self loops and -1 weights
            if(i>j && G.getCapacity(j,i) != 0 && k!=0){
            	z++;                        //z = total number of nodes including dummy nodes
			}
            j++;
            if(j==n){i++;j=0;}
        }
        myfile.close();                     //close the reading buffer
        G.setE(e);
    	graph newG(z);                      //Graph with no parallel edges
    	newG.modify(G);

		auto start = high_resolution_clock::now();

		graph FlownetByBFS = FF(newG, 0, G.getV()-1, 1);                    //FF to get Flow network output using BFS

		auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        FlownetByBFS.revert(n);                                         //Adjusting flow of the dummy nodes in given nodes
		cout<<"BFS (maximum flow value: "<<FlownetByBFS.getFlowValue(n)<<"; "<<"runtime: "<<duration.count()<<"ms)"; //Print total cost and execution time of FF algo with BFS
		FlownetByBFS.printGraph(n);

		start = high_resolution_clock::now();

		graph FlownetByDFS = FF(newG, 0, G.getV()-1, 0);               //FF to get Flow network output using DFS

		stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

		cout<<endl<<"DFS (maximum flow value: "<<FlownetByDFS.getFlowValue(n)<<"; "<<"runtime: "<<duration.count()<<"ms)"; //Print total cost and execution time of FF algo with BFS
		FlownetByDFS.revert(n);
		FlownetByDFS.printGraph(n);
      }
    else cout << "Unable to open file";                 //Input file not found
    return 0;
}
