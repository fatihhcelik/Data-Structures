#include <iostream>
#include <stdlib.h>

template <typename T>
class Queue{
private:
    struct Node{
    T data;
    Node *next;
    };
    Node *f,*b; //front and back pointer
public:
    Queue(){
        f = NULL;
        b = NULL;
    }

    ~Queue(){
        delete [] f;
    }

    bool isEmpty(){
        return b == NULL;//If back pointer points to NULL, queue is empty.
    }

    void enqueue(T value){
        Node *temp = new Node;
        temp -> data = value;

        if(f == NULL && b == NULL){
            //There is no element in the queue.
            f = temp;
            b = temp;
            temp -> next = NULL;
        }
        else{
            //If queue has got elements.
            //We have to add new element back of the queue.
            b -> next = temp;
            b = temp; //Now, back is temp;
            b -> next = NULL;
        }
    }

    void print(){
        Node *iter = new Node;
        iter = f;//Go from front to back because back -> next is equal NULL.
        while(iter != NULL){
            std::cout << iter -> data << std::endl;
            iter = iter -> next;
        }
        delete iter;
    }

    int length(){
        if(isEmpty()){
            std::cout << "EMPTY!" << std::endl;
            exit(1);
        }
        int counter = 0;
        Node *iter = new Node;
        iter = f;//Go from front to back because back -> next is equal NULL.
        while(iter != NULL){
            counter++;
            iter = iter -> next;
        }
        delete iter;
        return counter;
    }

    void dequeue() {
        Node *temp = new Node;
        temp = f;
        //Delete from front of the queue.
        if(isEmpty()){
            std::cout << "EMPTY!" << std::endl;
            exit(1);
        }
        if(f == b){
            //There is one element in the queue.
            f = NULL;
            b = NULL;
        }
        else{
           f = f -> next;
        }
        delete temp;
    }

    T get_front(){
        if(isEmpty()){
            std::cout << "EMPTY!" << std::endl;
            exit(1);
        }

        return (f -> data);
    }

};

int main(){
    Queue <int> qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.print();
    std::cout << "Length of the queue -> " << qu.length() << std::endl;
    std::cout << "isEmpty() -> " << qu.isEmpty() << std::endl;
    std::cout << "-----------------------" << std::endl;
    qu.dequeue();
    qu.print();
    std::cout << "front -> data " << qu.get_front() << std::endl;
}
