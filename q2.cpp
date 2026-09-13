#include <iostream>
using namespace std;
int *findEquilibriumIndices(int *arr, int size, int& count);
int balanceValue(int* arr, int size);
int* createBalancedArray(int *arr, int size, int& newSize);
int main (){
    int n;
    int balance;
    int newsize =0;
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
            cout<<arr2[i]<<" "<<endl;
        }
     }
     balance = balanceValue(arr, n);
     int *ptr = createBalancedArray(arr,  n,  newsize);
     cout<<"Balance value is"<<balance<<endl;
     cout<<"Balanced array value is"<<endl;
     for(int i=0; i<newsize; i++){
     cout<<*(ptr+i)<<endl;
     }
     delete [] arr;
     delete [] arr2;
     delete [] ptr;
    return 0;
}
int *findEquilibriumIndices(int *arr, int size, int& count){
    if(size<=0){return nullptr;}
    int sum=0;
    int sum1=0;
   int index=0;
      for(int j=0; j<size; j++){
      for(int i=0; i<j; i++){
        int *ptr= &arr[i];
      sum += *ptr;
      }
         for(int k=size; k>j+1; k--){
         int *ptr= &arr[k-1];
         sum1+=*ptr;
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
        int *ptr= &arr[i];
      sum += *ptr;
      }
          for(int k=size; k>j+1; k--){
         int *ptr= &arr[k-1];
        sum1+=*ptr;
       }
       if(sum==sum1){
        arr1[index++]=j;
       }
         sum =0;
         sum1=0;

       }
     return arr1;
}
int balanceValue(int* arr, int size){
   int sum =0 , sum1=0;
   int count =0;
   int balance =0;
   bool found = true;
   int balance2=0;
    for(int j=0; j<size; j++){
      for(int i=0; i<j; i++){
        int *ptr= &arr[i];
      sum += *ptr;
      }
       for(int k=size; k>j+1; k--){
         int *ptr= &arr[k-1];
        sum1+=*ptr;
       }
       if(sum==sum1){
        if(found){
        balance = sum;
        found = false;
        }
        balance2=sum1;
       }
      sum =0;
      sum1=0;
       } 
   return balance+balance2;

}
int* createBalancedArray(int *arr, int size, int& newSize){
  int *arr1 = new int[size];
  int *arr2 = new int[size];
  int sum=0; 
  int sum1=0;
  int count=0 ,count1=0;
  int counter3 =0, counter4=0;
  for(int j=0; j<size; j++){
      for(int i=0; i<j; i++){
        int *ptr= &arr[i];
      sum += *ptr;
      }
         for(int k=size; k>j+1; k--){
         int *ptr= &arr[k-1];      
         sum1+=*ptr;
         }
       if(sum==sum1){
        count1++;
       }
      sum =0;
      sum1=0;
       }

  if(count1==0){                  
    newSize=0;
    delete[] arr1;
    delete[] arr2;
    return nullptr;
  }

  for(int j=0; j<size; j++){
    for(int i=0; i<j; i++){
      int *ptr = &arr[i];         
      sum+=*ptr;

    }
    for(int i=size; i>j+1; i--){
      int *ptr = &arr[i-1];       
      sum1+=*ptr;
    }
    if(sum==sum1){
      count++;
      if(count==1){
        for(int i=0; i<j; i++){
          *(arr1+i)=*(arr+i);
          counter3++;
        }
      }
    if(count1==count){
      int k=0;
      for(int i=j+1; i<size; i++){   
        *(arr2+k) = *(arr+i);
        k++;
        counter4++;
      }
    }
    }
    sum=0;
    sum1=0;
  }
 newSize= counter3+counter4;
 int *arr3 = new int[newSize];
 
 for(int i=0; i<counter3; i++){
  *(arr3+i)=*(arr1+i);
 }
 for(int j=0; j<counter4; j++){
  *(arr3+counter3+j) = *(arr2+j);   
 }

 delete[] arr1;                     
 delete[] arr2;

 return arr3;
}