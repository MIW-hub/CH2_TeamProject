// 파일명: Character.cpp
#include "Character.h"
#include "../Monster.h"

using namespace std;

//빈 줄은 적당히 제거


ACharacter::ACharacter(string M_name, int M_Hp, int M_Atk, int M_Def, int M_Critcal)
{
	Name = M_name;
	Hp = M_Hp;
	Atk = M_Atk;
	Def = M_Def;
	Critcal = M_Critcal;

    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}



//cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

int ACharacter::getRandomInt()
{
    static random_device rd;
      
    static mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, 100);

    return dis(gen);
}

void ACharacter::setHP(int hp)
{
    this->Hp = hp;
}

void ACharacter::Attack(ACharacter* Target)
{
    Target->TakeDamage(Atk);

    cout << Name << "가 공격합니다!" << Atk << endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{
    //오타 수정 필요
    int FinalDamege = DamageAmount - getDef();
    if (FinalDamege < 0) 
    {
        //Final Damage를 0으로 만들어야겠죠?...
        DamageAmount = 0;
    }
    else { // 여기만 중괄호 라인 넘기기?
        //크리티컬 스탯을 사용해야 합니다.
        if (getRandomInt() < 50) {
            //파이널 데미지를 우선 수정하세요.
            Hp -= FinalDamege * 1.5;
        }
        else {
            Hp -= FinalDamege;
        }
        
        //그다음 if else 밖에서 finaldamage를 빼주면 됩니다.
    }
    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
}




