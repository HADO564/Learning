#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class list
{
    public:
    node *start;
    node *last;
    int length=0;
    node *ploc;
    node *loc;
    list(){
        start=NULL;
        last=NULL;
        length=0;
    }
    bool isEmpty()
    {
        return *start==NULL
    }
    void PrintList()
    {
        if(!isEmpty())
        {
            node *temp = start;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
        else
        cout<<"List is empty"<<endl;
    }
    void Search(int value)
    {
        loc=start;
        ploc=null;
        if(!isEmpty())
        while(loc!=NULL && value>loc->data)
        {
            ploc=loc;
            loc=loc->next;
        }
        else
        {
        cout<<"List is empty"<<endl;
        return;
        }
        if(loc!=NULL && loc->data!=value)
        loc=null;
    }
    void InsertAtFront(int value)
    {
        node *newNode = new node;
        newNode->data=value;
        if(isEmpty())
        {
            start=newNode;
            last=newNode;
        }
        else{
            newNode->next=start;
            start=newNode;
        }
        length++;
    }
    void InsertValue(int value)
    {
        Search(value);
        if(loc==NULL)
        {
            if(ploc==NULL)
            InsertAtFront(value);
            else
            {
                node *newNode=new node;
                newNode->data=value;
                newNode->next=ploc->next;
                ploc->next=newNode;
                if(ploc==last)
                    last=newNode;
                length++;
            }
        }
        else{
            cout<<"Duplication not allowed"<<endl;
        }
    }
    void DeleteValue(int value)
    {
        if(!isEmpty())
        {
            Search(value);
            if(loc!=Null)
            {
                if(start==last)
                {
                    start=null;
                    last=null;
                }
                else if(ploc==Null)
                {
                    delete start;
                    start=loc->next;
                    loc=start;
                    
                }
                else if(loc->next==NULL)
                {
                    delete last;
                    last=ploc;
                    ploc->next=NULL;
                }
                else
                {
                    ploc->next=loc->next;
                    delete loc;
                    
                }
                length--;

            }
            else{
                cout<<"Value Not Found"<<endl;
            }
    
        }
    }
    void destroyList()
    {
        node* temp;
        while(start!=NULL)
        {
            temp=start;
            start=start->next;
            delete temp;
        }
        last=NULL;

    }
}


