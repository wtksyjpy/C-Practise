//
//  queue.h
//  TreeQueue
//
//  Created by Hank on 10/27/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef __TreeQueue__queue__
#define __TreeQueue__queue__

#include<cassert>
template<typename T>class Queue;
template<typename T>class Node{
    T info;
    Node *link;     //在类模板Node中使用指向Node的指针可以不加<T>
public:
    Node(T data=0,Node *l=NULL);
    friend class Queue<T>;
};
template<typename T> Node<T>::Node(T data,Node *l){
    info=data;
    link=l;
}
template<typename T>class Queue{
    Node<T> *front,*rear;    //在其他类中指向Node的指针必须加<T>
public:
    Queue(){rear=front=NULL;}						     //构造一个空链队
    ~Queue();
    bool IsEmpty(){ return front==NULL;}				 //队空否？
    void EnQue(const T &data);						     //进队
    T DeQue();									         //出队
    T GetFront();						 			     //查看队头数据
    void MakeEmpty();					                 //置空队列，与析构逻辑上不同，物理上一样
};

#endif /* defined(__TreeQueue__queue__) */
