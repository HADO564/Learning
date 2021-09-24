#include<iostream>
#include<string.h>
using namespace std;

struct DynamicArrayList{
        int* current= new int[size];
        int* narray;
        int size=4;
        int length = 0;
      
        bool isEmpty(){
            return length == 0;
        }
        bool isArrayFull(){
            if(length==size)
            {
                expansion();
            }
            return length==size;
        }
        void expansion()
        {   
            size=size*2;
            narray = new int[size];
            for(int i= 0;i<length;i++)
            {
                narray[i]=current[i];
            }
            delete[] current;
            current= narray;

        }
        void shrinking()
        {
            size=size/2;
            narray= new int[size];
            for(int i =0;i<length;i++)
            {
                narray[i]=current[i];
            }
            delete[] current;
            current=narray;
        }
        bool FillGap(int position)
        {
            if(!isEmpty())
            {
                if(position<length)
                {
                    for(int i = position;i<length;i++){
                        current[i-1]=current[i];
                    }
                    length--;
                    return true;
                }
            }
            else{
                cout<<"List is empty"<<endl;
                return false;   
                }
        }
        void MakeRoom(int position){
            if(!isArrayFull())
            {
                for(int i = length;i>=position;i--)
                {
                    current[i]=current[i-1];
                }
            }
        }
        void insertAtposition(int value, int position){
                MakeRoom(position);
                current[position]=value;
                length++;
            
        }
        int Compare(int value)
        {
            int position;
            int i=0;
            while(i<=length)
            {
                if(value>current[i])
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
                current[position]=value;
                length++;
        
            }
            else
            {
                current[0]=value;
                length++;
            }   
        }
        void printList(){
            if(!isEmpty()){
                for(int i =0;i<length;i++){
                    cout<<"Pos:"<<(i+1)<<" val:"<<current[i]<<endl;
                    
                }
            }
        }
        void DeleteValue(int value)
        {
            bool dec;
            for(int i =1;i<=length;i++)
            {
                if(current[i]==value)
                {
                    dec= FillGap(i);
                    if((length<=size/2)&& dec)
                    {
                        shrinking();
                    }
                }
                else if(i==length)
                cout<<"Value Not found"<<endl;
            }
        }
        void DeleteValueAtPosition(int pos)
        {
            if(!isEmpty())
            {
            FillGap(pos);
            if(length<=size/2)
                    {
                        shrinking();
                    }
            }
            else{cout<<"List is empty"<<endl;}
        }
};

int main()
{
struct DynamicArrayList l1;
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



