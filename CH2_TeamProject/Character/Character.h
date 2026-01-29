#pragma once

#include <string>

using namespace std;

struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    int Critical;
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