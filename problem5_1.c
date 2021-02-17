// Problem 5, 替换空格， 方法2，只一个空间上操作
int ReplaceBlank(char *strIn, char *strOut, int maxLenOfOut)
{
    int len = 0; //字符个数，不含末尾\0
    int blankCnt = 0;

    if (strIn == NULL || strOut == NULL) {
        return -1;
    }

    while (strIn[len] != '\0') {
        strOut[len] = strIn[len];
        if (strIn[len] == ' ') {
            blankCnt++;
        }
        len++;
    }

    int sizeLen = len + blankCnt * 2;
    if (sizeLen > maxLenOfOut - 1) {
        return -1;
    }

    int p1 = len - 1; //从倒数第一个字符开始
    int p2 = sizeLen - 1;
    strOut[sizeLen] = '\0';

    while (p1 != p2) {
        // 挪动p1
        while (p1 >= 0 && strOut[p1] != ' ') {
            strOut[p2--] = strOut[p1--]; // p2往前搬
        }
        p1--; //往左移动到空格前一个字符

        // p2前加%20
        strOut[p2--] = '0';
        strOut[p2--] = '2';
        strOut[p2--] = '%';

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