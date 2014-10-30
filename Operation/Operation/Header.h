//
//  Header.h
//  Operation
//
//  Created by Hank on 10/4/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef Operation_Header_h
#define Operation_Header_h

#include <cassert>
using namespace std;
template<typename T>class Stack;
template<typename T>class Node{                  //¡¥’ªΩ·µ„¿‡ƒ£∞Â
    T info;
    Node<T> *link;
public:
    Node(T data=0,Node<T> *next=NULL){
        info=data;
        link=next;
    }
    friend class Stack<T>;
};
template<typename T>class Stack{                  //¡¥’ª¿‡ƒ£∞Â£¨ŒﬁÕ∑Ω·µ„¡¥±Ì
    Node<T> *top;                              //’ª∂•÷∏’Î
public:
    Stack(){top=NULL;}
    ~Stack();
    void Push(const T &data);                      //—π’ª
    T Pop();                                    //µØ≥ˆ
    T GetTop();                                 //»°’ª∂•‘™Àÿ
    void MakeEmpty();                           //«Âø’’ª
    bool IsEmpty(){return top==NULL;}
};
template<typename T> Stack<T>::~Stack(){MakeEmpty();}
template<typename T>void Stack<T>::MakeEmpty(){
    Node<T> *temp;
    while(top!=NULL){temp=top;top=top->link;delete temp;}
}
template<typename T> void Stack<T>::Push(const T &data){
    top=new Node<T>(data,top);
}
template<typename T> T Stack<T>::Pop(){
    assert(!IsEmpty());
    Node<T> *temp=top;
    T data=temp->info;
    top=top->link;                             //∂™∆˙’ª∂•Ω·µ„
    delete temp;                               // Õ∑≈’ª∂•Ω·µ„
    return data;                                //∑µªÿ’ª∂• ˝æ›
}
template<typename T> T Stack<T>::GetTop(){
    assert(!IsEmpty());
    return top->info;
}

#endif
