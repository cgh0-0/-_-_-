#include"poketmon.h"
#include"player.h"
#include<iostream>
#include<random>
#include<chrono>
#include<thread>
static player guest;
void strat()
{
	std::cout << "Welcome to Poketmon battle!" << std::endl << std::endl;
	
	std::cout << "Please chose your poketmon number." << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "1. pickachu" << std::endl;
	std::cout << "2. turttle" << std::endl;
	std::cout << "3. paili" << std::endl;
	std::cout << "---------------" << std::endl;
	//여기 번호로 고르지 말고 ㅣ이름 쓰면 그거랑 같은지 확인해서 고르고 싶음
	//그리고 없는 이름이면 try catch로 다시 리턴시켜서 다시 쓰게 하고 싶음 


	//객체를 꼭 한번씩 다 추가해줘야 되나?
	pickachu pica;
	turtle tur;
	paili pai;
	int a;
	std::cin >> a;
	if (a == 1)
	{
		guest.picked = pica;
		std::cout << "You chosed pickachu." << std::endl;//이거를 
		//"You chosed"+poketmon name+"."으로 바꿀 방향 생각해보기
	}
	else if (a == 2)
	{
		guest.picked = tur;
		std::cout << "You chosed turtle." << std::endl;

	}
	else if (a == 3)
	{
		guest.picked = pai;
		std::cout << "You chosed paili." << std::endl;
	}
	
}
void asking()
{
	std::cout << "Wanna going to battle, with your poketmon?(yes/no)" << std::endl;
	std::string yesorno;
	std::cin >> yesorno;
	if (yesorno == "no")
	{
		std::cout << "main home loading..." << std::endl << std::endl << std::endl;
		strat();
		asking();
		return;
	}
	else
	{
		std::cout << "Okay.. You're poketmon will go to battle" << std::endl << std::endl << std::endl;
	}
}

void battle(poketmon& other)
{



	//난수 생성 구간
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 3);




	bool turnoff = false;
	int count = 3;
	while (turnoff != true)
	{
		if (guest.picked.HP == 0)
		{
			std::cout << "You're poketmon fall down." << std::endl;
			std::cout << "You're false..." << std::endl;
			return;
		}
		else if (other.HP == 0)
		{
			std::cout << "Other's poketmon fall down." << std::endl;
			std::cout << "You're win!!!." << std::endl;

			return;
		}
		std::cout << "---You're turn----" << std::endl;
		std::cout << "1.Attack \n2.heal\n3.special attack" << std::endl;
		int pick;
		std::cin >> pick;
		switch (pick)
		{
		case 1:
			guest.picked.attack(other);
			break;
		case 2:
			guest.picked.heal(guest);
			break;
		case 3:
			guest.picked.specialattack(other);
			break;
		}
		if (guest.picked.HP == 0)
		{
			std::cout << "Other's poketmon fall down." << std::endl;
			std::cout << "You're win!!!." << std::endl;

			return;
		}
		//여기서 난수 생성.
		//생성에 따라 옵션 1, 옵션2, 옵션 3으로 나뉨
		int randomNumber = dist(gen);
		switch (dist)
		{
		case 1:
			other.attack(guest.picked);
			break;
		case 2:
			guest.picked.heal(other);
			break;
		case 3:
			other.specialattack(guest.picked);
			break;
		}
		
		if (other.HP == 0)
		{
			std::cout << "Other's poketmon fall down." << std::endl;
			std::cout << "You're win!!!." << std::endl;

			return;
		}
		
	}
}
