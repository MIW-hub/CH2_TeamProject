// CH2_TeamProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 파일명: Main.cpp
#include <iostream>
#include <Windows.h>
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"
#include "Character/BattleManager.h"
#include "SKill/USkill.h"
#include "memory.h"

using namespace std;


int main()
{
    FUnitStat PlayerStat = { 120,50,16,5,40 };
    FUnitStat MonsterStat = { 100 ,0, 16, 2, 40 };
   

    unique_ptr<ACharacter> Player = make_unique<APlayer>("나의 용사", PlayerStat);
    unique_ptr<ACharacter> Monster = make_unique<AMonster>("무서운 오크", MonsterStat);
    
    //ACharacter* Player2 = new APlayer()

    auto Manager = make_unique<BattleManager>();

    cout << "[생성] " << Player->GetName() << "가 전장에 나타났습니다! (HP: " << Player->GetHp() << ")" << endl;
    cout << "[생성] " << Monster->GetName() << "가 전장에 나타났습니다! (HP: " << Monster->GetHp() << ")" << endl;

    cout << "===  데스매치 시작!  ===" << endl;

    Manager->RunBattle(Player.get(), Monster.get());
        

    Manager->WaitForPlayerInput();
    return 0;
}