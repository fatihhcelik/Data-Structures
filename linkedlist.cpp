#include <iostream>

template <typename T>
class List{
struct Node{
T data;
Node *next;
};

private:
    Node *head,*tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }

    ~List(){
        delete [] head;
    }

    void append(T value){
        Node *temp = new Node;
        temp -> data = value;
        temp -> next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;            
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }

    void insert_begin(T value){
        Node *temp = new Node;
        temp -> data = value;
        temp -> next = head;
        head = temp;
    }

    void insert_position(T value,int position){
        //It will crash if you try to insert to first or last node.
        //Use it for these operations insert_begin() and append().
        Node *curr = new Node;
        Node *pre = new Node;
        Node *temp = new Node;//Node that will be appended.
        temp -> data = value;
        curr = head;
        for(int i=1;i<position;i++){
            pre = curr;
            curr = curr -> next;
        }
        pre -> next = temp;//Pre points to new node.
        temp -> next = curr;//New node points to current node.
    }

    T pop(){
        Node *iter = new Node;
        Node *pre = new Node;
        iter = head;
        while(iter -> next != NULL){
            pre = iter;
            iter = iter -> next;
        }
        tail = pre;
        tail -> next = NULL;
        T value = iter -> data;
        delete iter;

        return value;
    }

    void delete_from_last(){
        Node *iter = new Node;
        Node *pre = new Node;
        iter = head;
        while(iter -> next != NULL){
            pre = iter;
            iter = iter -> next;
        }
        tail = pre;
        tail -> next = NULL;
        T value = iter -> data;
        delete iter;
    }

    void delete_head(){
        Node *temp = new Node;
        temp = head;
        head = head -> next;
        delete temp;
    }

    void print(){
        Node *temp = new Node;
        temp = head;
        while(temp != NULL){
            std::cout << temp -> data << std::endl;
            temp = temp -> next;
        }
        delete temp;
    }

    int length(){
        Node *iter = new Node;
        iter = head;
        int len = 0;
        while(iter != NULL){
            len++;
            iter = iter -> next;
        }
        return len;
    }

};
int main(){
    List <int> obj;
    obj.append(1);
    obj.append(2);
    obj.append(3);
    obj.append(4);
    obj.insert_begin(99);
    obj.insert_begin(88);
    obj.insert_position(1230,3);
    obj.print();
    std::cout << "--------------" << std::endl;
    std::cout << "Lenght = " << obj.length() << std::endl;
    std::cout << "Popped = " << obj.pop() << std::endl;
    obj.print();
    std::cout << "--------------" << std::endl;
    obj.delete_from_last();
    obj.print();
    std::cout << "--------------" << std::endl;
    obj.delete_head();
    obj.print();
    std::cout << "--------------" << std::endl;
}

