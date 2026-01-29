#pragma once

#include <string>

using namespace std;

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
		this->MaxMp - MaxMp;

		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};
struct FDamageSet
{
	int FDamage; 
	bool BCritcal = false;

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
	virtual FDamageSet Attack(ACharacter* Target);
	virtual int TakeDamage(int DamageAmount);

	const string& GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
	int GetAtk() { return Stat.Atk; }
	int GetDef() { return Stat.Def; }
	int GetCri() { return Stat.Critical; }
	bool IsDead() { return Stat.Hp <= 0; }
	
	
protected:
	int GetRandomInt();

};