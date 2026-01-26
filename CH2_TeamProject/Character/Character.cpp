#include "Character.h"
#include <iostream>
#include <random>

using namespace std;


ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

int ACharacter::GetRandomInt()
{
	static random_device rd;
	static mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	return dis(gen);
}

void ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	
	if (GetRandomInt() <= Stat.Critical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}
	
	Target->TakeDamage(Damage);	
	cout << Name << "가 공격합니다!" << Stat.Atk << endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{
	int FinalDamage = DamageAmount - Stat.Def;
	FinalDamage = std::max(FinalDamage, 0);
	
	Stat.Hp -= FinalDamage;
	cout << Name << "가 " << FinalDamage << "의 피해를 입었습니다." << endl;
}
