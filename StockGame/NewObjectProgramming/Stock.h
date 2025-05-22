#include<iostream>
#include <string>

class Stock
{
public:
	int count = 0;
	int64_t price = 0;
	std::string name;

	//��� Ȯ��
	float upPercent = 50;
	//�ְ� ���� ��
	float priceIncreaseMax = 0;
	float priceIncreaseMin = 0;
	//�ְ� ���� ��
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
			std::cout << std::endl << "�������� �����մϴ�";
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
			std::cout << std::endl << "�ֽ� ������ �����մϴ�";
			return false;
		}


	}
};

