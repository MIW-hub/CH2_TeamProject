// CH2_TeamProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 파일명: Main.cpp
#include <iostream>
#include <Windows.h>
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

using namespace std;

int main()
{
    FUnitStat PlayerStat = { 200,50,16,5,40 };
    FUnitStat MonsterStat = { 100,50, 16, 2, 40 };

    ACharacter* Player = new APlayer("나의 용사", PlayerStat);
    ACharacter* Monster = new AMonster("무서운 오크", MonsterStat);

    cout << "[생성] " << Player->GetName() << "가 전장에 나타났습니다! (HP: " << Player->GetHp() << ")" << endl;
   /* Player->LogStatus(Player);*/ // 사용시 Player로 수정
    cout << "[생성] " << Monster->GetName() << "가 전장에 나타났습니다! (HP: " << Monster->GetHp() << ")" << endl;

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack(Monster);
        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);
        Monster->Attack(Player);
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        Sleep(1000);
    }

    delete Player;
    delete Monster;
    return 0;
}