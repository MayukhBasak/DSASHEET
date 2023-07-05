#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int s, int e){
    // choose pivot index
    int pivotIndex= s;
    int pivotElement= arr[s];
    // step2: find right position for pivot element and place it there
    int count= 0;
    for(int i= s+1; i<= e; i++){
        if(arr[i]<= pivotElement){
            count++;
        }
    }
    // jab mai bahar aaya mere paas pivot k righht index ready hai
    int rightIndex= s+count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex= rightIndex;
    // step3:
    int i= s;
    int j= e;
    while(i< pivotIndex && j> pivotIndex){
        while(arr[i]<= arr[pivotIndex]){
            i++;
        }
        while(arr[j]> arr[pivotIndex]){
            j--;
        }
        // you found the elements to swap
        // no need to swap
        if(i< pivotIndex && j> pivotIndex){
            swap(arr[i], arr[j]);
        }
        return pivotIndex;

    }

}
void quickSort(int arr[], int s, int e){
    // base case: single element already sorted and s>= e: invalid array
    if(s>= e){
    // we can do: s>e || s== e
        return;
    }
    // partiiton login
    int p= partition(arr, s, e);
    // recursive call
    // left call
    quickSort(arr, s, p-1);
    // right call
    quickSort(arr, p+1, e);
}
int main(){
   int arr[]= {8, 1, 3, 4, 20, 50, 30};
   int n= 7;
   int s= 0;
   int e= n-1;
   quickSort(arr, s, e);
   for(int i= 0; i< n; i++){
    cout<<arr[i]<<" ";
   }cout<<endl;
   int brr[]= {8, 1, 3, 4, 20, 50, 50, 50,30, 30, 4};
   int n2= 11;
   s= 0;
   e= n2-1;
   quickSort(brr, s, e);
    for(int i= 0; i< n2; i++){
    cout<<brr[i]<<" ";
   }cout<<endl;
   return 0;
}