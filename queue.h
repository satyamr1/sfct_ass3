#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class queue{
	int* arr;
	int tail,head,size;

public:
	queue(int n){
		head = 0;
		tail = 0;
		size = n;
		arr = new int[n];
	}
	void enqueue(int u){        // Inserts the new element at the index stored by tail
		if(tail >= size){
			cout<<"Queue is full";
			return;
		}
		arr[tail++] = u;
	}

	int dequeue(){             // Removes the element pointed by the head
		if(tail == head){
			cout<<"Queue is empty.";
			return NULL;
		}
		return arr[head++];
	}
	bool empty(){
        return head==tail;      // if head=tail, Queue is empty
	}
};

#endif
