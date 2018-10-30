#include <iostream>
#include <stdlib.h>

template <typename T>
class Stack{
public:
    int size,top;
    T *arr;
    Stack(int size){
        this -> size = size;
        top = -1; //Point to ground.
        arr = new T[size]; //Create stack.
    }

    ~Stack(){
        delete [] arr;
    }

    void push(T data){
        arr[++top] = data;
        //increase the top and Append the data
        //Now top, point to new data that appended.
    }

    void pop(){
        if(top < 0){
            std::cout << "Stack doesn't have elements";
            exit(0);
        }
        top--;
    }

    T get_pop(){
        if(top < 0){
            std::cout << "Stack doesn't have elements";
            exit(0);
        }
        T get = arr[top];
        top--;
        return get;
    }

    bool isEmpty(){
        if(top < 0){
            return true;//Stack is empty.
        }
        else
            return false;//Stack is NOT empty.
    }

    void print(){
        for(int i=0;i<=top;i++){
            std::cout << arr[i] << std::endl;
        }
    }



};

int main(){
    Stack <int> s(5);
    s.push(10);
    s.push(20);
    s.push(25);
    s.print();
    std::cout << s.isEmpty() << std::endl;//0
    s.pop();
    s.pop();
    std::cout << s.get_pop() << std::endl;//10 (Last element)
    std::cout << s.isEmpty() << std::endl; //1



}
