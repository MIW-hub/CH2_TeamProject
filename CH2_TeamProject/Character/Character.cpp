// 파일명: Character.cpp
#include "Character.h"
#include "../Monster.h"

using namespace std;

//빈 줄은 적당히 제거



ACharacter::ACharacter(string NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;
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
	Stat.Hp = hp;
}

void ACharacter::Attack(ACharacter* Target)
{
	Target->TakeDamage(Stat.Atk);

	cout << Name << "가 공격합니다!" << Stat.Atk << endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{
	//오타 수정 필요
	int FinalDamege = DamageAmount - getDef();
	if (FinalDamege <= 0)
	{
		//Final Damage를 0으로 만들어야겠죠?...
		FinalDamege = 0;
	}
	else if (FinalDamege > 0) { // 여기만 중괄호 라인 넘기기?
		//크리티컬 스탯을 사용해야 합니다.
		if (getRandomInt() < Stat.Critical) {
			//파이널 데미지를 우선 수정하세요.
			FinalDamege *= 1.5f;
			cout << "치명적인 피해를 입었습니다." << endl;
		}

		
	}
	Stat.Hp -= FinalDamege;
	cout << Name << "가 " << FinalDamege << "의 피해를 입었습니다." << endl;
}






