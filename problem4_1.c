/*
   基础功能：返回二维数组是否存在某值，存在返回0，否则返回-1；
   扩展功能：如果存在，重复出现的次数，位置坐标
   数组特性：行从左到右依次增大，列从上到下一次增大
*/

typedef struct findRet {
    int found;
    int count;
    int row;
    int col;
} struFindRet, *struPstFindRet;

int findVal(int (*mat2D)[4], int row, int col, int target, struPstFindRet struFind)
{
    int ret = -1;
    if (mat2D != NULL && row > 0 && col > 0) {
            int i = 0;
            int j = col - 1;
        while (i < row && j >= 0) { // 下标不断增大行，缩小列
            if(target == mat2D[i][j]) {
                if (struFind->count == 0) {
                    struFind->found = 0;
                    struFind->row = i;
                    struFind->col = j;
                    ret = 0;
                }
                struFind->count += 1;
                j--; // 继续在更小范围内查找
                i++; // 直到查找完所有，结束
            } else if (target < mat2D[i][j]){
                j--;
            } else {
                i++;
            }
        }
    }
    return ret;
}

// main.c
int main()
{
	// Test Data
    int mat[4][4] = { {1, 2, 8, 9},
                      {2, 4, 9, 12},
                      {4, 7, 10, 13},
                      {6, 8, 11, 15}
                    };
    struFindRet struFind;
    struFind.found = -1;
    struFind.count = 0;
    struFind.row = -1;
    struFind.col = -1;
    printf("found=%d, count=%d, row=%d, col=%d \n", struFind.found, struFind.count, struFind.row, struFind.col);
    printf("%d \n", findVal(mat, 4, 4, 4, &struFind));
    printf("found=%d, count=%d, row=%d, col=%d \n", struFind.found, struFind.count, struFind.row, struFind.col);

    return 0;
}