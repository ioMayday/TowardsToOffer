// Problem 5, 替换空格， 方法1，另外申请一个空间
/* 优化前
int ReplaceBlank(char *strIn, char *strOut, int maxLenOfOut)
{
    if (strIn == NULL) {
        printf("strIn is NULL! \n");
        return -1;
    }
    int len = 0; //字符个数，不含末尾\0
    int blankCnt = 0;
    while (strIn[len] != '\0') {
        if (strIn[len] == ' ') {
            blankCnt++;
        }
        len++;
    }
    //len++;

    int sizeLen = len + blankCnt * 2;

    if (sizeLen > maxLenOfOut - 1 || strIn == NULL || strOut == NULL) {
        return -1;
    }

    int p1 = len - 1; //从倒数第一个字符开始
    int p2 = sizeLen - 1;
    strOut[sizeLen] = '\0';

    while (p1 != p2) {
        // 挪动p1
        int preP1 = p1;
        while (p1 >= 0 && strIn[p1] != ' ') {
            p1--;
        }
        int tmpLen = preP1 - p1;

        // 往p2往前搬
        while (preP1 != p1) {
            strOut[p2--] = strIn[preP1--];  // 代码其实可以优化到上一个while循环中
        }
        p1--; //往左移动到空格前一个字符

        // p2前加%20
        strOut[p2--] = '0';
        strOut[p2--] = '2';
        strOut[p2--] = '%';

    }

    while(p1 >= 0) { // 如果第一个单词非空格
        strOut[p2--] = strIn[p1--]; //将第一个非空格单词拷贝过去
    }

    return 0;
}
*/


// Problem 5, 替换空格 多申请一个空间，优化后，少一个循环
int ReplaceBlank(char *strIn, char *strOut, int maxLenOfOut)
{
    if (strIn == NULL) {
        printf("strIn is NULL! \n");
        return -1;
    }
    int len = 0; //字符个数，不含末尾\0
    int blankCnt = 0;
    while (strIn[len] != '\0') {
        if (strIn[len] == ' ') {
            blankCnt++;
        }
        len++;
    }

    int sizeLen = len + blankCnt * 2;

    if (sizeLen > maxLenOfOut - 1 || strIn == NULL || strOut == NULL) {
        return -1;
    }

    int p1 = len - 1; //从倒数第一个字符开始
    int p2 = sizeLen - 1;
    strOut[sizeLen] = '\0';

    while (p1 != p2) {
        // 挪动p1
        while (p1 >= 0 && strIn[p1] != ' ') {
            strOut[p2--] = strIn[p1--]; // p2往前搬
        }
        p1--; //往左移动到空格前一个字符

        // p2前加%20
        strOut[p2--] = '0';
        strOut[p2--] = '2';
        strOut[p2--] = '%';

    }

    while(p1 >= 0) { // 如果第一个单词非空格
        strOut[p2--] = strIn[p1--]; //将第一个非空格单词拷贝过去
    }

    return 0;
}

//主函数调用
int main()
{
    printf("Hello world!\n");
    #define MAX_SIZE 256
    char strIn[] = "We are happy.";
    //char strIn[] = " We    are happy. ";
    //char strIn[] = "Wearehappy.";
    //char *strIn = NULL;
    //char strIn[] = "";
    //char strIn[] = " ";
    //char strIn[] = "    ";

    char strOut[MAX_SIZE] = {0};
    int ret = ReplaceBlank(strIn, strOut, MAX_SIZE);
    if (ret == 0) {
        printf("%s\n", strIn);
        printf("%s\n", strOut);
    } else {
        printf("error\n");
    }

    return 0;
}