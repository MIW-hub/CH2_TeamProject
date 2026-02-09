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

FDamageResult ACharacter::Attack(ACharacter* Target)
{

	int Damage = Stat.Atk;
	bool BCritcal = GetRandomInt() <= Stat.Critical;

	if (BCritcal)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	
	FDamageResult Result;

	Result.FDamage = FinalDamage;
	Result.Attacker = this;
	Result.Target = Target;
	Result.BCritcal = BCritcal;

	return Result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	int FinalDamage = DamageAmount - Stat.Def;
	FinalDamage = std::max(FinalDamage, 0);
	
	Stat.Hp -= FinalDamage;

	return FinalDamage;
}


void ACharacter::DoAction(ACharacter* Target)
{
	const int AttackRate = 70;
	const int SkillMp = 10;
	bool BSkill = GetRandomInt() <= AttackRate;

	if (BSkill) 
	{
		if (Stat.Mp > SkillMp) {
			UseSkill(Target);
		}
		else {
			cout << "스킬을 사용할 Mp가 없습니다." << endl;
			Attack(Target);
		}
	}
	else {
		Attack(Target);
	}
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
