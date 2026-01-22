#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.
#include "Character/Character.h"

using namespace std;

class AMonster : public ACharacter
{
public:
	
	AMonster(const string& M_name, int M_Hp, int M_Atk, int M_Def, int M_Critcal);
	virtual ~AMonster() override;
	
	
protected:
	string Name;
	int Hp;
	int Atk;
	int Def;
	int Critcal;
	bool m_Alive;

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

