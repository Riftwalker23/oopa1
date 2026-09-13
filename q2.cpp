#include <iostream>
using namespace std;
int *findEquilibriumIndices(int *arr, int size, int& count);
int main (){
    int n;
  
     cout<<"Enter the size of array"<<endl;
      cin>>n;
    int *arr =new int[n];
        cout << "Enter " << n << " integers:" << endl;
         for (int i = 0; i < n; i++) cin >> arr[i];
    int count=0;
    int *arr2= findEquilibriumIndices( arr,n, count);
     if(count==0){
        cout<<"No equlibrium indices found"<<endl;
     }
     else{
        cout<<"Equlibrium indicies"<<endl;
        for(int i=0; i<count; i++){
            cout<<arr2[i]<<" ";
        }
     }
     delete [] arr;
     delete [] arr2;
    return 0;
}
int *findEquilibriumIndices(int *arr, int size, int& count){
    if(size<=0){return nullptr;}
    int sum=0;
    int sum1=0;
   int index=0;
      for(int j=0; j<size; j++){
      for(int i=0; i<j; i++){
      sum += arr[i];
      }
       for(int k=size; k>j+1; k--){
        sum1+=arr[k-1];
       }
       if(sum==sum1){
        count++;
       }
      sum =0;
      sum1=0;
       }
       if(count==0){
        return nullptr;
       }
        int *arr1 = new int [count];
       for(int j=0; j<size; j++){
      for(int i=0; i<j; i++){
      sum += arr[i];
      }
       for(int k=size; k>j+1; k--){
        sum1+=arr[k-1];
       }
       if(sum==sum1){
        arr1[index++]=j;
       }
         sum =0;
         sum1=0;

       }
     return arr1;
}