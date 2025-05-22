#include<iostream>
#include <string>

class Stock
{
public:
	int count = 0;
	int64_t price = 0;
	std::string name;

	//상승 확률
	float upPercent = 50;
	//주가 증가 폭
	float priceIncreaseMax = 0;
	float priceIncreaseMin = 0;
	//주가 감소 폭
	float priceDeclineMax = 0;
	float priceDeclineMin = 0;


	bool Buy(int& p_money)
	{
		if (p_money >= price)
		{
			p_money -= price;
			count++;
			return true;
		}
		else
		{
			std::cout << std::endl << "소지금이 부족합니다";
			return false;
		}


	}

	bool Sell(int& p_money)
	{
		if (count > 0)
		{
			p_money += price;
			count--;
			return true;
		}
		else
		{
			std::cout << std::endl << "주식 개수가 부족합니다";
			return false;
		}


	}
};

