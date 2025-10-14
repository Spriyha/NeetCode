//Find the index of an element in an sorted array.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>&arr,int &target){
    int n = arr.size();
    int s = 0, e = n-1;
    while(s<=e){
        int mid = s+((e-s)/2);
        if(arr[mid]==target){
            return mid;
        }
        else if (arr[mid]>target){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}


int main(){
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int index = binarySearch(arr,target);
    cout<<"Index of target element is "<<index<<endl;
    return 0;
}

