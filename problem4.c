/*
   基础功能：返回二维数组是否存在某值，存在返回0，否则返回-1
   数组特性：行从左到右依次增大，列从上到下一次增大
*/

// main.c
    int mat[4][4] = { {1, 2, 8, 9},
                    {2, 4, 9, 12},
                    {4, 7, 10, 13},
                    {6, 8, 11, 15}
                  };
    printf("%d ", findVal(mat, 4, 4, 0));
	
// function
int findVal(int (*mat2D)[4], int row, int col, int target)
{
    int ret = -1;
    if (mat2D != NULL && row > 0 && col > 0) {
            int i = 0;
            int j = col - 1;
        while (i < row && j >= 0) { // 下标不断增大行，缩小列
            if(target == mat2D[i][j]) {
                return 1;
            } else if (target < mat2D[i][j]){
                j--;
            } else {
                i++;
            }
        }
    }
    return ret;
}








