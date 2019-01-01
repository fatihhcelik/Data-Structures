#include <iostream>
const int len = 128; //Hash table size

class Hash{
public:
    int key,data; //Only for int's.
    Hash(int key,int data){
        this -> key = key;
        this -> data = data;
    }
};

class HashMap{
public:
    Hash **arr;
    HashMap(){
        arr = new Hash*[len];
        //Create array of hash keeps every hashes with their key and data.
        for(int i=0;i<len;i++){
            arr[i] = NULL;
        }
    };

    ~HashMap(){
        for(int i=0;i<128;i++){
            if(arr[i] != NULL){
                delete arr[i];
            }
        }
        delete[] arr;
    }

    int hash_function(int key){
        return key % len;
    }

    void insert(int key,int data){
        int new_key = hash_function(key);
        while(arr[new_key] != NULL){ //Linear Probing
            //This means location is not empty.
            //I'll shift my key.
            if(arr[new_key] -> key == key){
                //Hash table doesn't have exact same two key.(or more)
                //If there is,I overwrite it.
                break;
            }
            new_key++;
        }
        arr[new_key] = new Hash(key,data);

    }

    void remove(int key){
        for(int i=0;i<128;i++){
            if(arr[i] != NULL){
                if(arr[i] -> key == key){
                    arr[i] = NULL; //Delete
                }
            }
        }
    }

    int get_value(int key){
        for(int i=0;i<128;i++){
            if(arr[i] != NULL){
                if(arr[i] -> key == key){
                    return arr[i] -> data;
                }
            }
        }
    }

    void print(){
        for(int i=0;i<128;i++){
            if(arr[i] != NULL){
                std::cout << "Key : " << arr[i] -> key << " " << "Value : " << arr[i] -> data << std::endl;
            }

        }
    }

};


int main()
{
    HashMap obj;
    obj.insert(13,342);
    obj.print();
    obj.remove(13);
    obj.print();
    obj.insert(254,532);
    obj.print();
    std::cout << obj.get_value(254) << std::endl;
    obj.remove(254);
    std::cout << "------LINEAR PROBING-------" << std::endl;
    obj.insert(345,123); //345 % 128 = 89
    obj.insert(89,567);  //These are exact same location
    obj.print();
    obj.remove(345);
    obj.remove(89);
    std::cout << "------SAME KEY PROBLEM-------" << std::endl;
    obj.insert(345,123);
    obj.insert(345,567);
    obj.print();
    //And we just see last added element..
}
//I know,this might not be meaningful implementation and might have some situations not considered so it's just for learning. If you want
//to add something or warn me about wrong implementation, please open issue.
