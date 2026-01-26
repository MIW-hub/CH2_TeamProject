// 파일명: Character.h
#pragma once
#include <iostream>
//주석 정리하세요
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.
#include <random>

using namespace std;

class AMonster;
class ACharacter
{
public:
	//M_ 접두사는 옛날 스타일, 멤버 변수에서 한정되서 쓰고 파라미터에서도 잘 쓰지 않습니다.
	//변수 이름이 겹칠시 this-> 로 멤버 변수를 구분하면 됩니다.
    ACharacter(string name, int Hp, int Atk, int Def, int Critcal);
    
    virtual ~ACharacter();

   
protected:
    string Name;
    int Hp;
    int Atk;
    int Def;
    int Critcal; // 오타 수정
    

public:
    virtual void Attack(ACharacter* Target);
    virtual void TakeDamage(int DamageAmount);
    
	//코딩 스타일 통일. 응용반 문서 참고하세요.
	string getName() { return Name; }
	int getHp() { return Hp; }
	int getAtk() { return Atk; }
	int getDef() { return Def; }
	int getCri() { return Critcal; }

    void setHP(int hp);
    bool IsDead() { return Hp <= 0;}
	//이 함수는 private로
private:
    int getRandomInt();

};