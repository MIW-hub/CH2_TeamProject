#pragma once

#include <string>

using namespace std;

class ACharacter;
struct FDamageResult
{
	ACharacter* Attacker;
	ACharacter* Target;
	int FDamage;
	bool BCritcal;
	void PrintMessage(const string& AttackMessage);
};

struct FUnitStat
{
	int MaxHp;
	int MaxMp;

	int Atk;
	int Def;
	int Critical;

	int Mp = 0;
	int Hp = 0;

	FUnitStat() {

	}

	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;

		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};


class ACharacter
{
public:
    ACharacter(const string& NewName, const FUnitStat& NewStat);
    virtual ~ACharacter();
   
protected:
    string Name;  
    FUnitStat Stat;	

	
	
private:
	

public:
	string DamageText;
	virtual FDamageResult Attack(ACharacter* Target);
	virtual int TakeDamage(int DamageAmount);
	virtual void UseSkill(ACharacter* Target) = 0;
	void DoAction(ACharacter* Target);

	const string& GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
	int GetMp() { return Stat.Mp; }
	int GetAtk() { return Stat.Atk; }
	int GetDef() { return Stat.Def; }
	int GetCri() { return Stat.Critical; }
	bool IsDead() { return Stat.Hp <= 0; }
	void Heal(int amount);
	void PrintName();
	int GetMaxHp() const { return Stat.MaxHp; }
	int GetMaxMp() const { return Stat.MaxMp; }
protected:
	int GetRandomInt();

};