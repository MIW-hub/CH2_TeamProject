#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.
#include "Character/Character.h"

using namespace std;

class ACharacter;
// 몬스터는 있지만 플레이어 클래스가 없네요.
class ACharacter;
class AMonster : public ACharacter
{
public:
	AMonster(string name ,const FUnitStat& NewStat);
	virtual ~AMonster() override;
	
	
protected:
	//이미 부모에서 정의된 멤버 변수가 있네요. 몬스터에 재정의한 이유는?
	ACharacter* Character;

public:
	string getName() { return Name; }
	int getHp() { return Stat.Hp; }
	int getAtk() { return Stat.Atk; }
	int getDef() { return Stat.Def; }
	int getCri() { return Stat.Critical; }

	void setHP(int hp);
	bool IsDead() { return Stat.Hp <= 0; }
	virtual void Attack(ACharacter* Target) override;
	virtual void TakeDamage(int DamageAmount) override;
	
};

