#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n ;
int cache[100], S[100];

int lis2(int start){
    int& ret = cache[start];
    if(ret!= -1) return ret;
    ret = 1;
    for(int next = start +1; next<n ; next++ )
      if(S[start]<S[next]) 
        ret = max(ret, 1+lis2(start+1));
    return ret; 
}

int n ; 
int cache[101], S[100];

int lis3(int start){
    int& ret = cache[start+1];
    if(ret!= -1) return ret;
    ret = 1;
    for(int next = start +1; next<n ; next++ )
      if(start ==-1||S[start]<S[next]) 
        ret = max(ret, 1+lis2(start+1));
    return ret; 
}