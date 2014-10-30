//
//  queue.h
//  Queue
//
//  Created by Hank on 10/24/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef Queue_queue_h
#define Queue_queue_h
//【例7.10】顺序存储方式的循环队列类模板。
#include<cassert>
#include<iostream>
using namespace std;

template<typename T>class Queue{
    int rear,front;									//队尾与队头
    T *elements;									//存放队列元素的容器
    int maxSize;                     				//队列最多可容纳元素个数+1
public:
    Queue(int ms=18);
    ~Queue(){delete[] elements;}
    bool IsEmpty() const {return front==rear;}			 //判队空
    bool IsFull() const {return (rear+1)%maxSize==front;} //判队满
    int Length() const {return  (rear-front+maxSize)%maxSize;}
    //求队中元素数，注意求余算法
    void EnQue(const T &data);						 //进队
    T DeQue();									 //出队
    T GetFront();									 //取队头数据
    void MakeEmpty(){front=rear=0;}				 //队置空（初始态）
};
template<typename T> Queue<T>::Queue(int ms){
    maxSize=ms;
    elements=new T[maxSize];
    rear=front=0;
    assert(elements!=NULL);						 //断言：分配成功
}
template<typename T> void Queue<T>::EnQue(const T &data){  //进队
    assert(!IsFull());								 //断言：队列不满，不满才能进队
    rear=(rear+1)%maxSize;							 //队尾指针加1
    elements[rear]=data;
}
template<typename T>T Queue<T>::DeQue(){
    assert(!IsEmpty());
    front=(front+1)%maxSize;						 //队头指针加1
    return elements[front];  					//注意front指向现在队头的前一位置
}
template<typename T>T Queue<T>::GetFront(){
    assert(!IsEmpty());
    return elements[(front+1)%maxSize];				 //注意加1才能返回队头数据
}

#endif
