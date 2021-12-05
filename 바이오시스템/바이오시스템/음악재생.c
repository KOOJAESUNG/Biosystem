/*#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

int main()
{
    char key;
    PlaySound(TEXT("wave_file.wav"), NULL , SND_ASYNC || SND_LOOP);
    while (1)
    {
        printf("  종료하려면 아무키나 입력하세요!  ");
        key = getch();

        if (key != 0)
        {
            PlaySound("NULL", 0, 0);
            printf("\n  음악 재생을 종료합니다.");
            Sleep(2000);
            return;
        }
    }
    return 0;
}
*/