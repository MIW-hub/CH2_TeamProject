#pragma once
#include <vector>

using namespace std;

class ACharacter;

class USkill
{

private:
	

protected:
	ACharacter* Owner;


public:
	USkill(ACharacter* Owner);
	virtual void Play(ACharacter* Target) = 0;
	

};

