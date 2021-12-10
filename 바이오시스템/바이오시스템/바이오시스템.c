#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <mmsystem.h>

//Dataset�� �ٲٷ��� �Ʒ� ��ȣ������� �ٸ� ���Ϸ� ��ü�Ͻÿ�. ex)"Data1_FP1.txt"=>"Data2_FP1.txt" , "Data2_FP2.txt"=>"Data2_FP2.txt"
#define eeg1 "Data1_FP1.txt"
#define eeg2 "Data1_FP2.txt"

#pragma comment(lib,"winmm.lib")

int music_1() {

	int key;
	PlaySound(TEXT("wave_file.wav"), NULL, SND_ASYNC || SND_LOOP);
	while (1)
	{
		printf("  �����Ϸ��� �ƹ�Ű�� �Է��ϼ���!  ");
		key = getch();

		if (key != 0)
		{
			PlaySound("NULL", 0, 0);
			printf("\n  ���� ����� �����մϴ�.\n");
			Sleep(2000);
			return;
		}
	}
}
int music_2() {

	int key;
	PlaySound(TEXT("wave_file.wav"), NULL, SND_ASYNC || SND_LOOP);
	while (1)
	{
		printf("  �����Ϸ��� �ƹ�Ű�� �Է��ϼ���!  ");
		key = getch();

		if (key != 0)
		{
			PlaySound("NULL", 0, 0);
			printf("\n  ���� ����� �����մϴ�.\n");
			Sleep(2000);
			return;
		}
	}
}
int music_3() {

	int key;
	PlaySound(TEXT("wave_file.wav"), NULL, SND_ASYNC || SND_LOOP);
	while (1)
	{
		printf("  �����Ϸ��� �ƹ�Ű�� �Է��ϼ���!  ");
		key = getch();

		if (key != 0)
		{
			PlaySound("NULL", 0, 0);
			printf("\n  ���� ����� �����մϴ�.\n");
			Sleep(2000);
			return;
		}
	}
}
int music_4() {

	int key;
	PlaySound(TEXT("wave_file.wav"), NULL, SND_ASYNC || SND_LOOP);
	while (1)
	{
		printf("  �����Ϸ��� �ƹ�Ű�� �Է��ϼ���!  ");
		key = getch();

		if (key != 0)
		{
			PlaySound("NULL", 0, 0);
			printf("\n  ���� ����� �����մϴ�.\n");
			Sleep(2000);
			return;
		}
	}
}

void main()
{
	FILE* fpt;
	int i;

	double data_1[256];
	double data_2[256];
	double data_3[256];
	int count;
	count = 0;

	fpt = fopen(eeg1, "r");
	if (fpt == NULL) {
		printf("File open error");
		exit(1);
	}
	for (i = 0; i < 256; i++)
		fscanf(fpt, "%lf", &data_1[i]);
	//for (i = 0; i < 256; i++)printf("%lf\n", data_1[i]); //FP1 sensor value���� ������ �ּ��� �����Ͻÿ�.
	fclose(fpt);


	fpt = fopen(eeg2, "r");
	if (fpt == NULL) {
		printf("File open error");
		exit(1);
	}
	for (i = 0; i < 256; i++)
		fscanf(fpt, "%lf", &data_2[i]);
	//for (i = 0; i < 256; i++)printf("%lf\n", data_2[i]); //FP2 sensor value���� ������ �ּ��� �����Ͻÿ�.
	fclose(fpt);

	for (i = 0; i < 256; i++) {
		data_3[i] = (data_1[i] + data_2[i])/2;
	}
	//for (i = 0; i < 256; i++) printf("%lf\n", data_3[i]); //FP1-FP2 value���� ������ �ּ��� �����Ͻÿ�.

	for (i = 0; i < 256; i++) {
		if (data_3[i] >= -1 && data_3[i] <= 1) {
			count++;
		}
	}
	//printf("%d", count);
	int frequency = count / 2;
	frequency = 30;
	printf("������� ���� ���ļ��� %d�Դϴ�.\n", frequency);
	
	if (0 < frequency && frequency < 3.5) {
		printf("����ڴ� ���� ���� ���鿡 �����ֽ��ϴ�. ������ ������� �ʽ��ϴ�.\n");
	
	}
	else if (3.5 <= frequency && frequency < 7) {
		printf("����ڴ� ���� ���� �����Դϴ�. ��������� ����� ���� �������� �����մϴ�.\n");
		music_1();
	}
	else if (7 <= frequency && frequency < 12) {
		printf("����ڴ� ���� �����ִ� �����Դϴ�. ���� ������ ���� Ŭ���������� ����մϴ�.\n");
		music_1();
	}
	else if (12 <= frequency && frequency < 50) {
		printf("����ڴ� ���� �������Դϴ�. ��������� ����մϴ�.\n");
		music_1();
	}
	else if (frequency == 0) {
		printf("���α׷��� �����մϴ�.");

	}

}

