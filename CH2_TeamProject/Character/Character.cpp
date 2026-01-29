#include "Character.h"
#include <iostream>
#include <random>

using namespace std;


ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;
	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;

}

ACharacter::~ACharacter()
{
	cout << Name << " 소멸됨" << endl;
}

int ACharacter::GetRandomInt()
{
	static random_device rd;
	static mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	return dis(gen);
}

FDamageSet ACharacter::Attack(ACharacter* Target)
{
	
	 FDamageSet DamageSet;
	
	 int Damage = Stat.Atk;
	 DamageSet.BCritcal = GetRandomInt() <= Stat.Critical;

	if (DamageSet.BCritcal)
	{	
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	DamageSet.FDamage = FinalDamage;
	

	return DamageSet;	
}

int ACharacter::TakeDamage(int DamageAmount)
{
	int FinalDamage = DamageAmount - Stat.Def;
	FinalDamage = std::max(FinalDamage, 0);
	
	Stat.Hp -= FinalDamage;

	return FinalDamage;
}
