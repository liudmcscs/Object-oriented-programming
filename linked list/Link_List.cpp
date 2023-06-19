#include <iostream>
#include "Link_List.h"
using namespace std;

template<typename T>
Link_List<T>::Link_List()
{
    size=0;
    head=NULL;
    tail=NULL;
}

template<typename T>
Link_List<T>::Link_List(const Link_List<T> &a)
{
    size=a.size;
    head=NULL;
    tail=NULL;
    Int_Node<T> *ptr;
    ptr=a.head;
    while(ptr!=NULL)
    {
        insert_node(ptr->value);
        ptr=ptr->next;
    }
}

template<typename T>
ostream &operator<<(ostream &m, const Link_List<T> &n)
{
    Int_Node<T>*k;
    k=n.head;
    while(k!=NULL)
    {
        m << k->value << " ";
        k = k->next;
    }
    return m;
}

template<typename T>
istream &operator>>(istream &in, Link_List<T> &n)
{
    T a;
    in>>a;
    n.insert_node(a);
    return in;
}

template<typename T>
Link_List<T>::~Link_List()
{
    Int_Node<T> *temp,*b;
    b=head;
    while(b!=NULL)
    {
        temp=b->next;
        delete b;
        b=temp;
    }
}

template<typename T>
int Link_List<T>::getSize() const
{
    return size;
}

template<typename T>
const Link_List<T> & Link_List<T>::operator=(const Link_List<T> &m)
{
    Int_Node<T> *ptr;
    Int_Node<T> *cur,*temp;
    size=m.size;
    cur = head;
    while(cur!=NULL)
    {
        temp=cur->next;
        delete cur;
        cur=temp;
    }
    head=m.head;
    ptr=m.head;
    while(ptr!=NULL)
    {
        insert_node(ptr->value);
        ptr=ptr->next;
    }
    return *this;
}

template<typename T>
bool Link_List<T>::operator==(const Link_List<T> &m) const
{
    Int_Node<T> *cur,*temp,*mcur,*mtemp;
    cur=head;
    mcur=m.head;
    while(cur->next!=NULL&&mcur->next!=NULL)
    {
        if(cur->value!=mcur->value)
        {
            return 0;
        }
        cur=cur->next;
        mcur=mcur->next;
    }
    if(cur->next==NULL && mcur->next==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template<typename T>
T &Link_List<T>::operator[](int index)
{
    int i;
    Int_Node<T> *b;
    b=head;
    for(i=0;i<index;i++)
    {
        b=b->next;
    }
    return b->value;
}

template<typename T>
T Link_List<T>::operator[](int index) const
{
    int i,bb;
    Int_Node<T> *b;
    b=head;
    for(i=0;i<index;i++)
    {
        b=b->next;

    }
    bb=b->value;
    return bb;
}

template<typename T>
bool Link_List<T>::insert_node(T value)
{
    Int_Node<T> *b;
    if(head==NULL)
    {
        b=new Int_Node<T>;
        head=b;
        tail=b;
        b->value=value;
        b->pre=NULL;
        b->next=NULL;
    }
    else
    {
        b= new Int_Node<T>;
        b->next=tail->next;
        tail->next=b;
        b->value=value;
        b->pre=tail;
        tail=b;
    }
    return true;
}

template<typename T>
bool Link_List<T>::delete_node()
{
    Int_Node<T> *temp;
    temp=tail->pre;
    delete tail;
    tail=temp;
    tail->next=NULL;
    return true;
}

template<typename T>
bool Link_List<T>::insert_node(int index, T value)
{
    int i;
    Int_Node<T> *b,*c;
    b =head;
    for(i=1;i<=index;i++)
    {
        if(i>=2)
        {
        b=b->next;
        }
    }
    c=new Int_Node<T>;
    if(b->next!=NULL)
    {
        c->next=b->next;
        b->next=c;
        c->pre=b;
        c->value=value;
    }
    else
    {
        c->next=NULL;
        c->value=value;
        c->pre=b;
        b->next=c;
    }
    int ii,bb;
    Int_Node<T> *ba;
    ba=head;
    for(ii=1;ii<=index;ii++)
    {
        if(i>=2)
        {
            ba=ba->next;
        }
    }
    bb=ba->value;
    return bb;
}

template<typename T>
bool Link_List<T>::delete_node(int index)
{
    int i;
    Int_Node<T> *b, *c;
    b =head;
    for(i=1;i<=index;i++)
    {
        if(i>=2)
        {
            b=b->next;
        }
    }
    if(index==1)
    {
        b=b->next;
        head=b;
        b->pre=NULL;
    }
    else if(b->next==NULL)
    {
        b=b->pre;
        b->next=NULL;
    }
    else
    {
        c=b;
        b=c->pre;
        b->next=c->next;
        b->next->pre=b;
    }
    return true;
}
