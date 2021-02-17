// Problem 5, �滻�ո� ����1����������һ���ռ�
/* �Ż�ǰ
int ReplaceBlank(char *strIn, char *strOut, int maxLenOfOut)
{
    if (strIn == NULL) {
        printf("strIn is NULL! \n");
        return -1;
    }
    int len = 0; //�ַ�����������ĩβ\0
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

    int p1 = len - 1; //�ӵ�����һ���ַ���ʼ
    int p2 = sizeLen - 1;
    strOut[sizeLen] = '\0';

    while (p1 != p2) {
        // Ų��p1
        int preP1 = p1;
        while (p1 >= 0 && strIn[p1] != ' ') {
            p1--;
        }
        int tmpLen = preP1 - p1;

        // ��p2��ǰ��
        while (preP1 != p1) {
            strOut[p2--] = strIn[preP1--];  // ������ʵ�����Ż�����һ��whileѭ����
        }
        p1--; //�����ƶ����ո�ǰһ���ַ�

        // p2ǰ��%20
        strOut[p2--] = '0';
        strOut[p2--] = '2';
        strOut[p2--] = '%';

    }

    while(p1 >= 0) { // �����һ�����ʷǿո�
        strOut[p2--] = strIn[p1--]; //����һ���ǿո񵥴ʿ�����ȥ
    }

    return 0;
}
*/


// Problem 5, �滻�ո� ������һ���ռ䣬�Ż�����һ��ѭ��
int ReplaceBlank(char *strIn, char *strOut, int maxLenOfOut)
{
    if (strIn == NULL) {
        printf("strIn is NULL! \n");
        return -1;
    }
    int len = 0; //�ַ�����������ĩβ\0
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

    int p1 = len - 1; //�ӵ�����һ���ַ���ʼ
    int p2 = sizeLen - 1;
    strOut[sizeLen] = '\0';

    while (p1 != p2) {
        // Ų��p1
        while (p1 >= 0 && strIn[p1] != ' ') {
            strOut[p2--] = strIn[p1--]; // p2��ǰ��
        }
        p1--; //�����ƶ����ո�ǰһ���ַ�

        // p2ǰ��%20
        strOut[p2--] = '0';
        strOut[p2--] = '2';
        strOut[p2--] = '%';

    }

    while(p1 >= 0) { // �����һ�����ʷǿո�
        strOut[p2--] = strIn[p1--]; //����һ���ǿո񵥴ʿ�����ȥ
    }

    return 0;
}

//����������
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