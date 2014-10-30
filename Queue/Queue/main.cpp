//
//  main.cpp
//  Queue
//
//  Created by Hank on 10/24/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include "queue.h"


int main(int argc, const char * argv[]) {
    // insert code here...
   	int i;
    Queue<char> que;                             //缺省为18元素队列，可用17
    char str1[]="abcdefghijklmnop";//17个元素，包括串结束符
    que.MakeEmpty();
    for(i=0;i<17;i++) que.EnQue(str1[i]);
    if(que.IsFull()) cout<<"队满";
    cout<<"共有元素："<<que.Length()<<endl;
    for(i=0;i<17;i++) cout<<que.DeQue();           //先进先出
    cout<<endl;
    if(que.IsEmpty()) cout<<"队空";
    cout<<"共有元素："<<que.Length()<<endl;
    return 0;
}
