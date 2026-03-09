#pragma once
#include <vector>
#include <string>

using namespace std;

class ACharacter;

class USkill
{

private:
	

protected:
	ACharacter* Owner;
	string SkillName;
	int MpCost;

public:
	USkill(ACharacter* Owner, string SName,int Cost);
	
	virtual void Play(ACharacter* Target) = 0;
	int GetMpCost() const {return MpCost;}
	string GetSkillName(){return SkillName;}
	

};

