#include<iostream>
#include<string.h>
using namespace std;

struct DynamicArrayList{//Structure/Class for Dynamic Array list
        int* current= new int[size];//pointer for the current array
        int* narray;//pointer to the newer array. Used in expansion and shrinking
        int size=4;//value has been assigned to avoid garbage values
        int length = 0;
      
        bool isEmpty(){//Same function from static list
            return length == 0;
        }
        bool isArrayFull(){//modified function. Always returns false as length will never equal size at the end of the function
            if(length==size)
            {
                expansion();
            }
            return length==size;
        }
        void expansion()//Function to dynamically expand the list
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
        void shrinking()//Function to dynamically shrink list
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
        bool FillGap(int position)//Same filling function
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
                else
                {
                length--;
                return true;
                }
            }
            else{
                cout<<"List is empty"<<endl;
                return false;   
                }
        }
        void MakeRoom(int position){//Same function to make space for insertion
            if(!isArrayFull())
            {
                for(int i = length;i>=position;i--)
                {
                    current[i]=current[i-1];
                }
            }
        }
        void insertAtposition(int value, int position){//Same function to allow insertion at any position
                MakeRoom(position);
                current[position]=value;
                length++;
            
        }
        int Compare(int value)//Same function for insertion of value in a sorted manner
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
        void insertSorted(int value){//Same function from static list
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
        void DeleteValue(int value)//deletion of value
        {
            bool dec;
            for(int i =1;i<=length;i++)
            {
                if(current[i]==value)
                {
                    dec= FillGap(i);
                    if((length<=size/2)&& dec)//shrinks if the conditions are satisfied
                    {
                        shrinking();
                    }
                }
                else if(current[0]==value)//deletion at front end
                {
                    dec= FillGap(0);
                    if((length<=size/2)&& dec)//shrinks if the conditions are satisfied
                    {
                        shrinking();
                    }
                }
                else if(i==length)//in case value is not found
                cout<<"Value Not found"<<endl;
            }
        }
        void DeleteValueAtPosition(int pos)//deletion at any position
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

int main()//general purpose main function allowing user to make decisions
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



