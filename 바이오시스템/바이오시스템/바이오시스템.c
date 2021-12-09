#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <mmsystem.h>


#define eeg1 "output_1.txt"
#define eeg2 "output_2.txt"

#pragma comment(lib,"winmm.lib")

int music_1() {

	int key;
	PlaySound(TEXT("wave_file.wav"), NULL, SND_ASYNC || SND_LOOP);
	while (1)
	{
		printf("  종료하려면 아무키나 입력하세요!  ");
		key = getch();

		if (key != 0)
		{
			PlaySound("NULL", 0, 0);
			printf("\n  음악 재생을 종료합니다.\n");
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
	//for (i = 0; i < 256; i++)printf("%lf\n", data_1[i]);
	fclose(fpt);


	fpt = fopen(eeg2, "r");
	if (fpt == NULL) {
		printf("File open error");
		exit(1);
	}
	for (i = 0; i < 256; i++)
		fscanf(fpt, "%lf", &data_2[i]);
	//for (i = 0; i < 256; i++)printf("%lf\n", data_2[i]);
	fclose(fpt);

	for (i = 0; i < 256; i++) {
		data_3[i] = data_1[i] - data_2[i];
	}
	//for (i = 0; i < 256; i++) printf("%lf\n", data_3[i]);

	for (i = 0; i < 256; i++) {
		if (data_3[i] >= -1 && data_3[i] <= 1) {
			count++;
		}
	}
	printf("%d", count);
	int frequency = count / 2;
	printf("사용자의 eeg 주파수는 %d입니다.\n", frequency);

	if (0 < frequency && frequency < 3.5) {
		printf("사용자는 현재 깊은 수면에 빠져있습니다.\n");
		music_1();
	}
	else if (3.5 <= frequency && frequency < 7) {
		printf("사용자는 현재 수면 상태입니다. 깊은 수면으로 유도합니다.\n");
		music_1();
	}
	else if (7 <= frequency && frequency < 12) {
		printf("사용자는 현재 깨어있는 상태입니다. 음악을 재생하지 않습니다..\n");

	}
	else if (12 <= frequency && frequency < 30) {
		printf("사용자는 현재 집중 상태입니다. 백색소음을 재생합니다.\n");
		music_1();
	}
	else if (30 <= frequency && frequency <= 50) {
		printf("사용자는 현재 긴장 상태입니다. 마음을 가라앉혀보세요\n");
		music_1();
	}
	else if (frequency == 0) {
		printf("프로그램을 정지합니다.");

	}

}

