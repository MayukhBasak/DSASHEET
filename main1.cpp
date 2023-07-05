#include<bits/stdc++.h>
using namespace std;
void merge(int* arr, int s, int e){
    int m= s+(e-s)/2;
    int l1= m-s+1;
    int l2= e-m;
    int* left= new int[l1];
    int* right= new int[l2];
    int k= s;
    for(int i= 0; i< l1; i++){
        left[i]= arr[k];
        k++;
    }
    for(int j= 0; j< l2; j++){
        right[j]= arr[k];
        k++;
    }
    int i= 0;
    int j= 0;
    k= s;
    while(i< l1 && j< l2){
        if(left[i]< right[j]){
            arr[k]= left[i];
            i++;
            k++;
        }
        else{
            arr[k]= right[j];
            j++;
            k++;
        }
    }
    while(i< l1){
        arr[k]= left[i];
        k++;
        i++;
    }
    while(i< l1){
        arr[k]= left[i];
        k++;
        i++;
    }

     
}
void mergeSort(int* arr, int s, int e){
    // base case
    // single element
    if(s== e){
        return;
    }
    int m= s+(e-s)/2;
    // recursion solve kar dega
    // left wala part recursion solve kar diya
    mergeSort(arr, s, m);
    // right wala part recursion solve kar diya
    mergeSort(arr, m+1, e);
    // now merge 2 sorted arrays
    merge(arr, s, e);


}
int main(){
   int arr[]= {4, 5, 13, 2, 12};
   int n= 5;
   int s= 0;
   int e= n-1;
   mergeSort(arr, s, e);
   for(int i= 0; i< n; i++){
    cout<<arr[i]<<" ";
    }cout<<endl;

   return 0;
}