#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  
#include <stdint.h>   

int main() {
    srand((unsigned int)time(NULL));


    printf("■: 사용자가 최종적으로 선택한 문 (성공)\n");
    printf("□: 사용자가 최종적으로 선택한 문 (실패)\n");
    printf("○: 선택된 문\n");
    printf("●: 열리지 않은 문\n");


    int experiments;
    printf("\n몇 번 실험하시겠습니까? ");
    if (scanf_s("%d", &experiments) != 1 || experiments <= 0) {
        printf("올바른 숫자를 입력하세요.\n");
        return 1;
    }

    int success = 0;


    int useSleep = (experiments <= 1000);

    for (int i = 0; i < experiments; i++) {

        int doors[3] = { 0, 0, 0 };
        int car = rand() % 3;
        doors[car] = 1;

        int choice = rand() % 3;
        int reveal;


        do {
            reveal = rand() % 3;
        } while (reveal == choice || doors[reveal] == 1);


        int final_choice;
        for (int j = 0; j < 3; j++) {
            if (j != choice && j != reveal) {
                final_choice = j;
                break;
            }
        }


        if (doors[final_choice] == 1) {
            success++;
        }


        printf("실험 %d   \t ", i + 1);
        for (int j = 0; j < 3; j++) {
            if (j == choice) {
                printf("○ ");
            }
            else if (j == reveal) {
                printf("● ");
            }
            else if (j == final_choice && doors[final_choice] == 1) {
                printf("■ ");
            }
            else if (j == final_choice && doors[final_choice] == 0) {
                printf("□ ");
            }
            else {
                printf("□ ");
            }
            if (useSleep) {
                Sleep(0.9);
            }
        }
        printf("\n");
    }


    printf("\n총 %d번 중 %d번 성공했습니다.\n", experiments, success);
    printf("성공률: %.2f%%\n", (success / (float)experiments) * 100);

    return 0;
}
