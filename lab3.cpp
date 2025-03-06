#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val){
    	data=val;
    	next=nullptr;
	}
};


class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue(){
    	front=nullptr;
		back=nullptr;
	}


    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (!front) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) back = nullptr;
        delete temp;
    }


    int top() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }


    int size() {
        int count = 0;
        Node* temp = front;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    int getBack(){
    	if(isEmpty()){
    		cout<<"Queue is emty!"<<endl;
    		return -1;
		}
		return back->data;
	}

    void printQueue(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
            if (temp != nullptr) {
                cout << "->";
            }
        }
        cout << endl;
        }
	};





int main() {
    Queue q;
    q.enqueue(9);
    q.enqueue(5);
    q.enqueue(17);
    q.enqueue(78);
    q.printQueue();
    cout << "Front element: " << q.top() << endl;
    cout <<"Back element: " <<q.getBack()<<endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.top() << endl;
    cout << "Queue size: " << q.size() << endl;


    return 0;
}
