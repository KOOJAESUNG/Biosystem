#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>
#include<time.h>
#include<stdlib.h> 

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
            return ;
        }
    }
}
int main(void)
{
    float frequency;
    srand(time(NULL));

    do{
        printf("������� ���¸� �������Դϴ�...\n");
        //Sleep(5000);
        frequency = (float)(rand() % 50000) / 1000;
        printf("������� eeg ���ļ��� %f�Դϴ�.\n", frequency);

        if (0 < frequency && frequency < 3.5) {
            printf("����ڴ� ���� ���� ���鿡 �����ֽ��ϴ�.\n");
            music_1();
        }
        else if (3.5 <= frequency && frequency < 7) {
            printf("����ڴ� ���� ���� �����Դϴ�. ���� �������� �����մϴ�.\n");
            music_1();
        }
        else if (7 <= frequency && frequency < 12) {
            printf("����ڴ� ���� �����ִ� �����Դϴ�. ������ ������� �ʽ��ϴ�..\n");

        }
        else if (12 <= frequency && frequency < 30) {
            printf("����ڴ� ���� ���� �����Դϴ�. ��������� ����մϴ�.\n");
            music_1();
        }
        else if (30 <= frequency && frequency <= 50) {
            printf("����ڴ� ���� ���� �����Դϴ�. ������ �������������\n");
            music_1();
        }
        else if (frequency == 0) {
            printf("���α׷��� �����մϴ�.");
            break;
        }
            
    } while (1);
	
}
