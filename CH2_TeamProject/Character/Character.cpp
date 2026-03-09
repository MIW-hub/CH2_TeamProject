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

int ACharacter::GetRandomInt(int Max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, Max - 1);
	return dis(gen);
}

// FDamageResult ACharacter::Attack(ACharacter* Target)
// {
//
// 	int Damage = Stat.Atk;
// 	bool BCritcal = GetRandomInt(100) <= Stat.Critical;
//
// 	if (BCritcal)
// 	{
// 		Damage = static_cast<int>(Damage * 1.5f);
// 	}
//
// 	int FinalDamage = Target->TakeDamage(Damage);
// 	
// 	FDamageResult Result;
//
// 	Result.FDamage = FinalDamage;
// 	Result.Attacker = this;
// 	Result.Target = Target;
// 	Result.BCritcal = BCritcal;
//
// 	return Result;
// }

int ACharacter::TakeDamage(int DamageAmount)
{
	int FinalDamage = DamageAmount - Stat.Def;
	FinalDamage = std::max(FinalDamage, 0);
	
	Stat.Hp -= FinalDamage;

	if (Stat.Hp < FinalDamage) {
		Stat.Hp = 0;
	}
	return FinalDamage;
}


void ACharacter::PlayTurn(ACharacter* Target)
{
	
}

void ACharacter::ShowStat()
{
	cout << "[" << Name << "]" << " HP: " << GetHp()
		<< "/" << GetMaxHp() << " |" << " MP:" << GetMp()
		<< "/" << GetMaxMp() << endl;
}

void ACharacter::Heal(int amount)
{
	int PrevHp = Stat.Hp;
	Stat.Hp += amount;
	Stat.Hp = std::min(Stat.MaxHp, Stat.Hp);

	int ActualHeal = Stat.Hp - PrevHp;

	PrintName();
	cout << ActualHeal << " HP를 회복했습니다...!" << endl;
}

void ACharacter::PrintName()
{
	cout << "[" << Name << "] ";
}

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	
	cout << "-------------------------------------------------" << endl;
	Attacker->PrintName();
	cout << AttackMessage << '\n';

	Target->PrintName();
	cout << "'받은 데미지': " << FDamage << " -> '남은 HP': " << Target->GetHp() << "/" << Target->GetMaxHp() 
		<< " -> '남은 MP': " << Target->GetMp() << "/" << Target->GetMaxMp() << endl;
	cout << "-------------------------------------------------" << endl;
}
