// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.
#include <random>

using namespace std;

class AMonster;
class ACharacter
{
public:
    ACharacter(string M_name, int M_Hp, int M_Atk, int M_Def, int M_Critcal);
    
    ~ACharacter();

   
protected:
    string Name;
    int Hp;
    int Atk;
    int Def;
    int Critcal;
  
public:
    
    virtual void Attack(ACharacter* Target);
    virtual void TakeDamage(int DamageAmount);
    
	string getName() { return Name; }
	int getHp() { return Hp; }
	int getAtk() { return Atk; }
	int getDef() { return Def; }
	int getCri() { return Critcal; }




    void setHP(int hp);
    bool IsDead() { return Hp <= 0;}
    int getRandomInt();

};