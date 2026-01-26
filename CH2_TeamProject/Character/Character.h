// 파일명: Character.h
#pragma once
#include <iostream>
//주석 정리하세요
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.
#include <random>

using namespace std;

class AMonster;
struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    int Critical;
};
class ACharacter
{
public:
	
    ACharacter(string NewName, const FUnitStat& NewStat);
    
    virtual ~ACharacter();

   
protected:
    string Name;  
    FUnitStat Stat;
   

public:
    virtual void Attack(ACharacter* Target);
    virtual void TakeDamage(int DamageAmount);
	//코딩 스타일 통일. 응용반 문서 참고하세요.
	string getName(){return Name; }
	int getHp(){return Stat.Hp;}
	int getAtk(){return Stat.Atk;}
	int getDef(){return Stat.Def;}
	int getCri(){return Stat.Critical;}
int getRandomInt();
    void setHP(int hp);
    bool IsDead() { return Stat.Hp <= 0;}
	//이 함수는 private로
private:
    

};