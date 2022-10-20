#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* in_r, * in_w, * out_w; //읽고 쓸 파일 포인터

	in_w = fopen("ch11_in.txt", "w");
	if (in_w == NULL)  //에러처리
	{
		fprintf(stderr, "file open error\n");
		return 1;
	}

	//파일 쓰기
	int i;
	int data[] = { 11, 12, 21, 22, 31, 32, 41, 42, 51, 52 };
	int size = sizeof(data) / sizeof(int);

	for (i = 0; i < size; i++) {
		fprintf(in_w, "%3d %3d", data[i], data[i + 1]);
		if (i != 8) //마지막 줄 입력 후 줄바꿈 없음
		{
			fprintf(in_w, "\n");
		}
		
		i++;
	}

	printf("입력 종료");
	fclose(in_w);

	//데이터 읽기
	in_r = fopen("ch11_in.txt", "r");
	out_w = fopen("ch11_out.txt", "w");
	int tmp1, tmp2, sum;
	while (1)
	{
		if (feof(in_r))
		{
			break;
		}
		
		fscanf(in_r, "%3d %3d", &tmp1, &tmp2);
		sum = tmp1 + tmp2;
		fprintf(out_w, "%3d\n", sum);
				
	}

	fclose(in_r);
	fclose(out_w);
	return 0;
}