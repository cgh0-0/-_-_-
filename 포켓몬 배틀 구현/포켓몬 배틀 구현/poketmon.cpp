#include<iostream>
#include<algorithm>
#include"poketmon.h"

void poketmon::attack(poketmon& a)
{
	this->HP -= a.damage;
}
void poketmon::damaged(poketmon& a)
{
	*a.HP-=this.damage;
}
void poketmon::healing(poketmon& self)
{
	*self.HP += self.heal;
}
void poketmon::specialattack(poketmon& other)
{

}


	pickachu::pickachu()
	{
		HP = new int(75);//체력바는 계속 업데이트 되어야 하니까 
		damage = 15;
		specialskilldamage = 27;
		
	}
	pickachu::~pickachu()
	{
		delete HP;
	}


	turtle::turtle()
	{
		HP = new int(100);
		damage = 10;
		specialskilldamage = 19;
	}
	turtle::~turtle()
	{
		delete HP;
	}

	paili::paili()
	{
		HP = new int(64);
		damage = 18;
		specialskilldamage = 25;
	}
	paili::~paili()
	{
		delete HP;
	}
