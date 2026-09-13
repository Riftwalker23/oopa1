#include <iostream>
using namespace std;
int *findEquilibriumIndices(int *arr, int size, int& count);
int main (){
    int n;
  
    cout<<"Enter the size of array"<<endl;
    while(true){
    cin>>n;
    if(n>0) break;
    
    cout<<"Please enter a valid number"<<endl;
    }
    int *arr =new int[n];
    int count=0;
    int *arr2= findEquilibriumIndices( arr,n, count);

    return 0;
}
int *findEquilibriumIndices(int *arr, int size, int& count){
    int sum=0;
    int sum1=0;
    int *arr1 = new int [size];
      for(int j=0; j<size; j++){
      for(int i=0; i<j; i++){
      sum += arr[i];
      }
       for(int k=size; k>j; k--){
        sum1+=arr[k-1];
       }
       if(sum1==sum){
          count++;
          arr1[count-1] = {j};
      }
      sum =0;
      sum1=0;
       }
     return arr1;
}