/*
   �������ܣ����ض�ά�����Ƿ����ĳֵ�����ڷ���0�����򷵻�-1
   �������ԣ��д��������������д��ϵ���һ������
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
        while (i < row && j >= 0) { // �±겻�������У���С��
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








