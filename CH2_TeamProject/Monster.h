#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.


using namespace std;
class ACharacter;
class AMonster : public ACharacter
{
public:
	
	AMonster(string M_name, int M_Hp, int M_Atk, int M_Def, int M_Critcal) : ACharacter(M_name, M_Hp, M_Atk, M_Def, M_Critcal) {}
	
	~AMonster();
protected:
	string Name;
	int Hp;
	int Atk;
	int Def;
	int Critcal;


public:
	string getName() { return Name; }
	int getHp() { return Hp; }
	int getAtk() { return Atk; }
	int getDef() { return Def; }
	int getCri() { return Critcal; }

	void setHP(int hp);
	bool IsDead() { return Hp <= 0; }
	int getRandomInt();
	virtual void Attack(ACharacter* Target) override;
	virtual void TakeDamage(int DamageAmount) override;
	
};

