#include <iostream>
#include <vector>

class Heap{
public:
    std::vector <int> arr;
    ~Heap(){
        arr.clear(); //I'm not sure about that.(Memory leak?)
    }

    int leftChild(int parentIndex){
        int childIndex = 2 * parentIndex + 1;
        if(childIndex < arr.size())
            return childIndex;
        else
            return -1;
    }

    int rightChild(int parentIndex){
        int childIndex = 2 * parentIndex + 2;
        if(childIndex < arr.size())
            return childIndex;
        else
            return -1;
    }

    int parent(int childIndex){
        int parentIndex = (childIndex-1)/2; //Int, such as 1.5 -> 1
        if(childIndex == 0)
            return -1;
        else
            return parentIndex;
    }

    void heapifyToRoot(int newIndex){
        if(newIndex == 0)
            return;
        if(arr[newIndex] < arr[parent(newIndex)]){
            std::swap(arr[newIndex],arr[parent(newIndex)]);
            heapifyToRoot(parent(newIndex));
        }
    }

    void heapifytoBottom(int index){
        int left = leftChild(index);
        int right = rightChild(index);

        if(left > arr.size() || right > arr.size())
            return;
        if(arr[left] > arr[right]){ //Choose small one to swap.
            std::swap(arr[index],arr[right]);
            heapifytoBottom(right);
        }
        else if(arr[left] < arr[right]){
            std::swap(arr[index],arr[left]);
            heapifytoBottom(left);
        }
    }

    void deleteMin(){
        if(arr.size() > 0){
            std::swap(arr[0],arr[arr.size()-1]);
            arr.pop_back();
            heapifytoBottom(0);
        }
    }

    void insert(int value){
        arr.push_back(value);
        heapifyToRoot(arr.size()-1);
        //Heapify just provides right heap structure,
        //This is NOT heapsort.
        //Heap structure means every parent must be smaller than it's child.
    }

    void display(){
        for(int i=0;i<arr.size();i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n" ;
    }
};
int main(){
    Heap h1;
    h1.insert(6);
    h1.insert(45);
    h1.insert(47);
    h1.insert(53);
    h1.insert(14);
    h1.insert(78);
    h1.insert(18);
    h1.display();
    h1.deleteMin();
    h1.display();
}
