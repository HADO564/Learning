#include<iostream>
#include<string.h>
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
                array[position]=value;
                length++;
            
        }
        int Compare(int value)
        {
            int position;
            int i=0;
            while(i<=length)
            {
                if(value>array[i])
                {
                    i++;
                }
                else
                {
                    return i;
                    break;
                }
            }
        }
        void insertSorted(int value){
            int position;
            if(!isEmpty()){
                position=Compare(value);
                MakeRoom(position);
                array[position]=value;
                length++;
        
            }
            else
            {
                array[0]=value;
                length++;
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
            for(int i =1;i<=length;i++)
            {
                if(array[i]==value)
                {
                    FillGap(i);
                    break;
                }
                else if(array[0]==value)
                {
                    FillGap(0);
                    break;
                }
                else if(i==length)
                {
                cout<<"Value Not found"<<endl;
                }
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
char dec ='1';
int val;
int pos;
do{
cout<<"Press \"A\" to add to list by position"<<endl<<"Press \"B\" to add to list automatically sorted"<<endl<<"Press \"C\" to delete an item from the list"<<endl<<"Press \"D\" to delete item from a position in the array"<<endl<<"Press \"E\" to print list"<<endl<<"Press \"Q\" to quit"<<endl;
cin>>dec;
dec=toupper(dec);
switch(dec)
{
    case 'A':
        cout<<"Enter the value and its position respectively"<<endl;
        cin>>val>>pos;
        l1.insertAtposition(val,pos);
        break;
    case 'B':
        cout<<"Enter the value"<<endl;
        cin>>val;
        l1.insertSorted(val);
        break;
    case 'C':
        cout<<"Enter the value"<<endl;
        cin>>val;
        l1.DeleteValue(val);
        break;
    case 'D':
        cout<<"Enter the position"<<endl;
        cin>>pos;
        l1.DeleteValueAtPosition(pos);
        break;
    case 'E':
        cout<<"The values will be printed"<<endl;
        l1.printList();
        cout<<endl;
        break;
    case 'Q':
        cout<<"Program will exit now"<<endl;
        break;
    default:
        cout<<"Invalid input. Please enter again"<<"\n"<<endl;
}
}while(dec != 'Q');
return 0;

}


