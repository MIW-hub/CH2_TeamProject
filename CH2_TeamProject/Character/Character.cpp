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
	
	 DamageSet.FDamage = Stat.Atk;
	 DamageSet.BCritcal = GetRandomInt() <= Stat.Critical;

	if (DamageSet.BCritcal)
	{	
		DamageSet.FDamage = static_cast<int>(DamageSet.FDamage * 1.5f);		
		
	}
	
	Target->TakeDamage(DamageSet.FDamage);
	

	return DamageSet;	
}

int ACharacter::TakeDamage(int DamageAmount)
{
	int FinalDamage = DamageAmount - Stat.Def;
	FinalDamage = std::max(FinalDamage, 0);
	
	Stat.Hp -= FinalDamage;

	return FinalDamage;
}
