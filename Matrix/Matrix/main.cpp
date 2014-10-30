//
//  main.cpp
//  Matrix
//
//  Created by Hank on 8/8/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T1,typename T2> void inverse(T1 *mat1,T2 *mat2,int a,int b);
template <typename T1,typename T2>void multi(T1 *mat1,T2 *mat2,T2 *result,int a,int b,int c);
template <typename T>void output(T *mat,char*s,int a,int b);

int main(){
    int middle[6][3], result[6][4];
    int matrix1[3][6]={8,10,12,23,1,3,5,7,9,2,4,6,34,45,56,2,4,6};
    int matrix2[3][4]={3,2,1,0,-1,-2,9,8,7,6,5,4};
    char *s1="result";
	char *s2="middle";
	inverse(matrix1,middle,6,3);
    //ÏÔÊ½£ºinverse<int[6],int[3]> (matrix1,middle,6,3);
    multi(middle,matrix2,result,6,3,4);
    //ÏÔÊ½£ºmulti <int[3],int[4]> (middle,matrix2,result,6,3,4);
    output(matrix1,"matrix1",3,6);
	output(middle,s2,6,3);
	output(matrix2,"matrix2",3,4);
	output(result,s1,6,4);
	return 0;
}
template <typename T1, typename T2>void inverse(T1 *mat1,T2 *mat2,int a,int b){
    int i,j;
    for (i=0;i<b;i++)
        for (j=0;j<a;j++)
            mat2[j][i]=mat1[i][j];
    return;
}
template <typename T1,typename T2>void multi(T1 *mat1,T2 *mat2,T2 *result,int a,int b,int c){
    
    int i,j,k;
    for (i=0;i<a;i++){
        for (j=0;j<c;j++){
            result[i][j] = 0;
            for (k=0;k<b;k++)
                result[i][j]+=mat1[i][k]*mat2[k][j];
        }
    }
    return;
}
template <typename T>void output(T *mat,char *s,int a,int b){
    int i,j;
	cout<<s<<endl;
    for (i=0;i<a;i++){
        for (j=0;j<b;j++)
            cout<<setw(6)<<mat[i][j];
        cout<<endl;
    }
    return;
}