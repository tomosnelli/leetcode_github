/*
    74. Search a 2D Matrix
*/

bool searchMatrix(
    int** matrix,
    int matrixSize,
    int* matrixColSize,
    int target
){
    for(int i = 0; i < matrixSize; ++i){
        // binary search

        int left = 0;
        int right = *matrixColSize - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(matrix[i][mid] == target) return true;

            if(matrix[i][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        } 
    }
    return false;
}