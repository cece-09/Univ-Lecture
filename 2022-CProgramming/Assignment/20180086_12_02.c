#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ReadData(const char*, int*);
void SequenSearch(int*);
void BinarySearch(int*, int);
void SelectSort(int*);
void BubbleSort(int*);
void STD(int*);
void MinMax(int*);
void PrintArr(int*, int);
int Min(int*);
int Max(int*);

//************ main ***************
int main()
{
	const char* FILENAME= "in_12_20180086.txt";
	FILE* fp_w = fopen(FILENAME, "w");
	if (fp_w == NULL)
	{
		printf("file open error\n");
		return 1;
	}

	int num;
	int max;

	printf("Enter the number of elements in the array : ");
	scanf("%d", &num);
	printf("Enter the maximum possible value as the element of the array : ");
	scanf("%d", &max);

	
	//0부터 max까지의 수 중에서 num 만큼을 개수로 하는 배열 생성
	int* arr;
	arr = (int*)malloc(sizeof(int) * num);
	if (arr == NULL)
	{
		printf("not allocated\n");
		return 1;
	} //할당 오류 예외처리

	srand((unsigned)time(NULL));
	int cnt = 0;
	int random = 0;
	int chkSearch, i;
	while (cnt != num)
	{
		chkSearch = 0;
		random = rand() % (max + 1);
		//중복검사 => 중복하지 않는 경우만 배열에 저장
		for (i = 0; i < num; i++)
		{
			if (random == arr[i])
			{
				chkSearch = 1;
				break;
			}
		}
		if (chkSearch == 0)
		{
			*(arr + cnt) = random;
			cnt++;
		}
	}

	//파일에 쓰기
	for (i = 0; i < num; i ++)
	{
		if (i % 5 == 0 && i != 0)
		{
			fprintf(fp_w, "\n");
		}
		fprintf(fp_w, " %3d", arr[i]);
	}

	int state = fclose(fp_w);  //파일 닫기
	if (state != 0)
	{
		printf("file close error\n");
		return 1;
	} //파일 닫기 오류 예외처리
	free(arr); //동적할당 해제


	//******************* 배열 메뉴 **********************
	int menu;
	int chkReadData = 0;
	int chkSorted = 0;
	int* dataArr = (int*)malloc(sizeof(int) * num); //txt 파일에서 읽어와 저장할 배열
	do
	{
		rewind(stdin);

		printf("\n*********************************\n");
		printf("*** List of array instructions ****\n");
		printf("    1. Read data from file\n");
		printf("    2. Sequntial Search\n");
		printf("    3. Binary Search\n");
		printf("    4. Selection Sort\n");
		printf("    5. Bubble Sort\n");
		printf("    6. Standard deviation of array\n");
		printf("    7. Min/Max elements of array\n");
		printf("    8. Print array\n");
		printf("    0. Program Exit\n");
		printf("Choose instruction number : ");
		scanf("%d", &menu);
		

		switch (menu)
		{
		case 1:
			ReadData(FILENAME, dataArr);
			chkReadData = 1;
			chkSorted = 0;
			continue;
		case 2:
			if (chkReadData == 1)
			{
				SequenSearch(dataArr);
			}
			else
			{
				printf("Read data from input file.. Choose 1 !!\n");
			}
			continue;
		case 3:
			if (chkReadData == 1)
			{
				BinarySearch(dataArr, chkSorted);
			}
			else
			{
				printf("Read data from input file.. Choose 1 !!\n");
			}
			continue;
		case 4:
			if (chkReadData == 1)
			{
				SelectSort(dataArr);
				chkSorted = 1;
			}
			else
			{
				printf("Read data from input file.. Choose 1 !!\n");
			}
			continue;
		case 5:
			if (chkReadData == 1)
			{
				BubbleSort(dataArr);
				chkSorted = 1;
			}
			else
			{
				printf("Read data from input file.. Choose 1 !!\n");
			}
			continue;
		case 6:
			if (chkReadData == 1)
			{
				STD(dataArr);
			}
			else {
				printf("Read data from input file.. Choose 1 !!\n");
			}
			continue;

		case 7:
			if (chkReadData == 1)
			{
				MinMax(dataArr);
			}
			else
			{
				printf("Read data from input file.. Choose 1 !!\n");
			}
			continue;
		case 8:
			if (chkReadData == 1)
			{
				PrintArr(dataArr, num);
			}
			else
			{
				printf("Read data from input file.. Choose 1 !!\n");
			}
			continue;
		case 0:
			break;
		default:
			printf("Enter right instruction number!\n"); //메뉴 범위 1~9 예외처리
			continue;
		}

	}while (menu != 0); //0번 입력시 종료

	
	free(dataArr); //동적할당 해제	
	return 0;
}

//***** Read Data Funciton ******
void ReadData(const char* FILENAME, int* data)
{
	FILE* fp_r = fopen(FILENAME, "r");
	if (fp_r == NULL) exit(1);

	int i = 0;
	while (1)
	{
		if (feof(fp_r))
		{
			data[i] = -1;  //마지막 원소
			break;
		}
		fscanf(fp_r, " %3d", &data[i]);
		
		i++;		
	}
	fclose(fp_r);
}


//**** Sequential Search Function ****
void SequenSearch(int* data)
{
	int search;
	printf("Enter data to fine : ");
	scanf("%d", &search);

	int i = 0;
	while (1)
	{
		if (search == data[i])
		{
			printf("%d was found at %d index\n", search, i);
			break;
		}

		if (data[i] == -1)
		{
			printf("%d was not found!\n", search);
			break;
		}

		i++;
	}
}


//**** Binary Search Function ****
void BinarySearch(int* data, int chkSorted)
{
	if (chkSorted == 0)
	{
		printf("Sort first before Binary Search!!\n");
		return;
	}

	int search;
	int num = 0;

	printf("Enter data to fine : ");
	scanf("%d", &search);


	while (1)
	{
		if (data[num] == -1) break;
		num++;
	}

	int low = 0;
	int high = num - 1;
	int mid = low + (high - low) / 2;
	int chkFound = 0;
	while (low <= high)
	{
		mid = low + (high - low);
		if (search > data[mid])
		{
			low = mid + 1;
			continue;
		}
		else if (search < data[mid])
		{
			high = mid - 1;
			continue;
		}
		else if (search == data[mid])
		{
			chkFound = 1;
			printf("%d was found at %d index\n", search, mid);
			break;
		}
	}
	if(chkFound == 0)
	{
		printf("%d was not found!\n", search);
		return;
	}
}

//**** Selection Sort Function ****
void SelectSort(int* data)
{
	int i = 0;
	int tmp, j;
	while (1)
	{
		if (data[i] == -1) break;
		j = i + 1;
		while (1)
		{			
			if (data[j] == -1) break;
			if (data[i] > data[j])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;      //swap
			}
			j++;
		}
		i++;
	}
	printf("Selection Sort is done!!\n");
}

//**** Bubble Sort Function ****
void BubbleSort(int* data)
{
	int i, j, tmp;
	int num = 0;
	while (1)
	{
		if (data[num] == -1) break;
		num++;
	}

	for (i = num - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (data[j] > data[j + 1])
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;      //swap
			}
		}
	}
	printf("Bubble Sort is done!!\n");
}

//Standard Deviation of the Array
void STD(int* data)
{
	double STD;
	double avg;
	double avg_square;
	double sum = 0;
	double sum_square = 0;
	int num = 0;
	
	while (1)
	{
		if (data[num] == -1) break;
		sum += data[num];
		sum_square += pow(data[num], 2);
		num++;
	}

	avg = sum / num;
	avg_square = sum_square / num;
	
	STD = sqrt(avg_square - pow(avg, 2));
	printf("Standard deviation : %.2lf\n", STD);
}

//최소, 최대 각 함수 출력
void MinMax(int* data)
{
	int min, max;
	min = Min(data);
	max = Max(data);
	printf("Min data : %d, Max data : %d\n", min, max);
}

//Min of the Array
int Min(int* data)
{
	int min = data[0];
	int i = 0;
	while (1)
	{
		if (data[i] == -1) break;
		if (data[i] < min)
		{
			min = data[i];
		}
		i++;
	}

	return min;
}

//Max of the Array
int Max(int* data)
{
	int max = data[0];
	int i = 0;
	while (1)
	{
		if (data[i] == -1) break;
		if (data[i] > max)
		{
			max = data[i];
		}
		i++;
	}

	return max;
}

//Print Array Function
void PrintArr(int* data, int num)
{
	int i = 0;
	printf(" Array : %d elements\n", num);
	for (i = 0; i < num; i++)
	{
		if (i % 5 == 0 && i != 0)
		{
			printf("\n");
		}
		printf(" %3d", data[i]);
	}
	printf("\n");
}

