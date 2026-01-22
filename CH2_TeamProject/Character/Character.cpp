// 파일명: Character.cpp
#include "Character.h"
#include "../Monster.h"

using namespace std;




ACharacter::ACharacter(string M_name, int M_Hp, int M_Atk, int M_Def, int M_Critcal)
{
	Name = M_name;
	Hp = M_Hp;
	Atk = M_Atk;
	Def = M_Def;
	Critcal = M_Critcal;
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
    int FinalDamege = DamageAmount - getDef();
    if (FinalDamege < 0) 
    {
        DamageAmount = 0;
    }
    else {
        if (getRandomInt() < 50) {
            Hp -= FinalDamege * 1.5;
        }
        else {
            Hp -= FinalDamege;
        }
    }
    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
}




