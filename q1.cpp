#include <iostream>
using namespace std;
int** createGrid(int rows, int cols){

cout<<"Enter the number of rows"<<endl;
cin>>rows;
cout<<"Emter the number of columns"<<endl;
cin>>cols;
int **grid = new int* [rows];
for(int i =0; i<rows; i++){
    *(grid+i)=new int[cols];
}

 return grid;   
}
void inputGrid(int** grid, int rows, int cols){
    int num;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>num;
            if(num>=0 && num>=4){
                cout<<"Enter the number again"<<endl;
                cin>>num;
            }
            *((*grid+i)+j) =num;
        }
    }
}
void displayGrid(int** grid, int rows, int cols){
 cout<<"The Grid entered by user is:"<<endl;
 for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        cout<<grid[i][j];
    }
 }
}
int countCells(int** grid, int rows, int cols, int value){
     int block=0;
     int victims=0;
     int supply=0;
     int emergency=0;
     int zero=0;
    
     for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            value = *((*grid+i)+j);
            if(value==0) zero++;
            if(value==1) block++;
            if(value==2) victims++;
            if(value==3) supply++;
            if(value==4) emergency++;
        }
     }
     int arr[5]={zero,block,victims,supply,emergency};
     return arr[5];
}
void findFirstCell(int** grid, int rows, int cols, int value, int& row, int& col){
    bool outer=false;
    for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        value = grid[i][j];
        if(value==4){
            row =i;
            col=j;
            break;
             outer = true;
        }

    }
    if(outer){
        break;
    }
    }


}
bool isValidMove(int** grid, int** visited, int rows, int cols, int r, int c){
    
}
int countReachable(int** grid, int** visited, int rows, int cols, int r, int c);
int countAccessibleVictims(int** grid, int** visited, int rows, int cols);

int countIsolatedVictims(int** grid, int** visited, int rows, int cols);
void analyzeSupplyPoints(int** grid, int** visited, int rows, int cols);
int** createVictimReport(int** grid, int** visited, int rows, int cols, int& count);
int** createEvacuationGrid(int** grid, int** visited, int rows, int cols);
int largestConnectedRegion(int** grid, int rows, int cols);
void deleteGrid(int** grid, int rows);
int main (){


    return 0;
}