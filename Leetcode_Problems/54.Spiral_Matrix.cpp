// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minr = 0 , minc = 0;
   int maxr = m-1 , maxc = n-1;
   int tne = n*m;
   int count = 0;
   vector<int> v;
   while(minr<=maxr && minc<=maxc){
    //right
    for(int j=minc;j<=maxc && count<tne;j++){
        v.push_back(matrix[minr][j]);
         count++;
    }
    minr++;
    //if(minr>maxr || minc>maxc) break;
    //down 
    for(int i =minr;i<=maxr && count<tne;i++){
         v.push_back(matrix[i][maxc]);
        count++;
    }
    maxc--;
   // if(minr>maxr || minc>maxc) break;
    //left
    for(int j =maxc;j>=minc && count<tne;j--){
         v.push_back(matrix[maxr][j]);
         count++;
    }
    maxr--;
   // if(minr>maxr || minc>maxc) break;
    //up
    for(int i=maxr;i>=minr && count<tne;i--){
         v.push_back(matrix[i][minc]);
         count++;
    }
    minc++;
   }
    return v;
    }
};