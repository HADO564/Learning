#include<iostream>
using namespace std;

struct staticArrayList{
        int static const size= 5;
        int length = 0;
        int array[size];
        bool isEmpty(){
            return length == 0;
        }
        bool isFull(){
            return length==size;
        }
        void FillGap(int position)
        {
            if(!isEmpty())
            {
                if(position<length)
                {
                    for(int i = position;i<length;i++){
                        array[i-1]=array[i];
                    }
                    length--;
                }
            }
            else
            cout<<"List is empty"<<endl;
        }
        void MakeRoom(int position){
            if(!isFull())
            {
                for(int i = length;i>=position;i--)
                {
                    array[i]=array[i-1];
                }
            }
            else
                {
                    cout<<"List is full"<<endl;
                }
        }
        void insertAtposition(int value, int position){
                MakeRoom(position);
                array[position-1]=value;
                length++;
            
        }
        void insertSorted(int value){
            for(int i = 0; i<length;i++)
            {
                cout << "Haider" << endl;
             if(array[i]>value)
             {
                 MakeRoom(i);
                 array[i]=value;
                 length++;
                 break;
             }
            }
        }
        void printList(){
            if(!isEmpty()){
                for(int i =0;i<length;i++){
                    cout<<"Pos:"<<(i+1)<<" val:"<<array[i]<<endl;
                    
                }
            }
        }
        void DeleteValue(int value)
        {
            for(int i =1;i<length;i++)
            {
                if(array[i]==value)
                {
                    FillGap(i);
                }
                else
                cout<<"Value Not found"<<endl;
            }
        }
        void DeleteValueAtPosition(int pos)
        {
            FillGap(pos);
        }
};

int main()
{
struct staticArrayList l1;
l1.insertSorted(0);

l1.insertSorted(3);
l1.insertSorted(2);
l1.printList();


}


