#include<iostream>
#include "StockMaker.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <atomic>

void myInfo();
void Check();
void Buy();
void Sell();
void news();
void Lobby();


//주식 생성
StockMaker static stock0(1000000, "스미스 무역",90,150,30,90);
StockMaker static stock1(100, "덕래 게임즈",70,100,50,90);
StockMaker static stock2(1000, "법무법인 쉐턱",10,30,40,80);
StockMaker static stock3(10000, "보산 화학",50,90,60,70);
StockMaker static stock4(1000000000, "동산 코믹스",30,70,50,80);

//플레이어 생성
Player static player;




void myInfo()
{
	std::cout << std::endl;
	std::cout << "돈:" << player.money << std::endl;
	std::cout << stock0.name << " 가격:" << stock0.price << " 개수:" << stock0.count << std::endl;
	std::cout << stock1.name << " 가격:" << stock1.price << " 개수:" << stock1.count << std::endl;
	std::cout << stock2.name << " 가격:" << stock2.price << " 개수:" << stock2.count << std::endl;
	std::cout << stock3.name << " 가격:" << stock3.price << " 개수:" << stock3.count << std::endl;
	std::cout << stock4.name << " 가격:" << stock4.price << " 개수:" << stock4.count << std::endl;
	std::cout << std::endl;
	return;
}

void Check()
{
	std::cout << std::endl;
	std::cout <<stock0.name <<" 가격:"<<stock0.price<<" 개수:"<<stock0.count << std::endl;
	std::cout <<stock1.name <<" 가격:"<<stock1.price<<" 개수:"<<stock1.count << std::endl;
	std::cout <<stock2.name <<" 가격:"<<stock2.price<<" 개수:"<<stock2.count << std::endl;
	std::cout <<stock3.name <<" 가격:"<<stock3.price<<" 개수:"<<stock3.count << std::endl;
	std::cout <<stock4.name <<" 가격:"<<stock4.price<<" 개수:"<<stock4.count << std::endl;
	std::cout << std::endl;
	return;
}



void Buy()
{
	std::cout << std::endl;
	std::cout <<"1."<<stock0.name <<" 가격:"<<stock0.price<<" 개수:"<<stock0.count << std::endl;
	std::cout <<"2."<<stock1.name <<" 가격:"<<stock1.price<<" 개수:"<<stock1.count << std::endl;
	std::cout <<"3."<<stock2.name <<" 가격:"<<stock2.price<<" 개수:"<<stock2.count << std::endl;
	std::cout <<"4."<<stock3.name <<" 가격:"<<stock3.price<<" 개수:"<<stock3.count << std::endl;
	std::cout <<"5."<<stock4.name <<" 가격:"<<stock4.price<<" 개수:"<<stock4.count << std::endl;
	std::cout << std::endl;

	int num=0;

	std::cout << "어떤 주식을 구매할지 결정하세요 ( 숫자로 입력해 주세요 ):";
	std::cin >> num;
	std::cout << std::endl;
	bool isBought=false;

	switch (num)
	{
		case 1:
			isBought=stock0.Buy(player.money);
			break;
		case 2:
			isBought = stock1.Buy(player.money);
			break;
		case 3:
			isBought = stock2.Buy(player.money);
			break;
		case 4:
			isBought = stock3.Buy(player.money);
			break;
		case 5:
			isBought = stock4.Buy(player.money);
			break;
		default:
			std::cout << std::endl << "숫자를 잘못 입력하였습니다" << std::endl;
			isBought = false;
			break;
	}



	if (isBought==false)
	{
		Buy();
	}
	return;
}
void Sell( )
{
	std::cout << std::endl;
	std::cout << "1." << stock0.name << " 가격:" << stock0.price << " 개수:" << stock0.count << std::endl;
	std::cout << "2." << stock1.name << " 가격:" << stock1.price << " 개수:" << stock1.count << std::endl;
	std::cout << "3." << stock2.name << " 가격:" << stock2.price << " 개수:" << stock2.count << std::endl;
	std::cout << "4." << stock3.name << " 가격:" << stock3.price << " 개수:" << stock3.count << std::endl;
	std::cout << "5." << stock4.name << " 가격:" << stock4.price << " 개수:" << stock4.count << std::endl;

	int num = 0;

	std::cout << "어떤 주식을 판매할지 결정하세요 ( 숫자로 입력해 주세요 ):";
	std::cin >> num;
	std::cout << std::endl;
	bool isSell = false;

	switch (num)
	{
	case 1:
		isSell = stock0.Sell(player.money);
		break;
	case 2:
		isSell = stock1.Sell(player.money);
		break;
	case 3:
		isSell = stock2.Sell(player.money);
		break;
	case 4:
		isSell = stock3.Sell(player.money);
		break;
	case 5:
		isSell = stock4.Sell(player.money);
		break;
	default:
		std::cout << std::endl << "숫자를 잘못 입력하였습니다" << std::endl;
		isSell = false;
		break;
	}



	if (isSell == false)
	{
		Sell();
	}
	return;
}

void news()
{
	Lobby();
	return;
}


void Lobby()
{

		int num=0;
		std::cout<<std::endl<< "숫자를 입력하세요 : 1.내정보 / 2.주식종류,가격 / 3.주식 구매 / 4.주식 판매 / 5.뉴스 확인 :";
		std::cin >> num;

		switch (num)
		{
			case 1:
				myInfo();
				break;
			case 2:
				Check();
				break;
			case 3:
				Buy();
				break;
			case 4:
				Sell();
				break;
			case 5:
				news();
				break;
			default:
				std::cout << std::endl << "숫자를 잘못 입력하였습니다"<<std::endl;
				break;


		}
	

}


// 주기적으로 실행될 함수
void StockUpdate() 
{
	srand(time(NULL));
	float rate0=0;
	float rate1=0;
	float rate2=0;
	float rate3=0;
	float rate4=0;


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***** 주가가 변동되었습니다 *****";
	std::cout << std::endl;


	//1~50 상승 51~100 하락

	//stock0
	if (stock0.upPercent>(rand() % 100)+1)
	{	
		int min = std::min(stock0.priceIncreaseMin, stock0.priceIncreaseMax);
		int max = std::max(stock0.priceIncreaseMin, stock0.priceIncreaseMax);

		rate0 = 1+((min + (rand() % (max - min + 1))) * 0.01f);
		stock0.price *= rate0;
		if (stock0.price <= 0)
		{
			stock0.price = 1;
		}
		std::cout << stock0.name << " 가격:" << stock0.price <<" +"<< (rate0-1)*100<<"%" << std::endl;
	}
	else
	{
		int min = std::min(stock0.priceDeclineMin, stock0.priceDeclineMax);
		int max = std::max(stock0.priceDeclineMin, stock0.priceDeclineMax);
		rate0 = (min + (rand() % (max - min + 1))) * 0.01f;
		stock0.price *= rate0;
		if (stock0.price <= 0)
		{
			stock0.price = 1;
		}
		std::cout << stock0.name << " 가격:" << stock0.price <<" -"<< (1-rate0)*100<<"%" << std::endl;
	}



	//stock1
	if (stock1.upPercent > (rand() % 100) + 1)
	{
		int min = std::min(stock1.priceIncreaseMin, stock1.priceIncreaseMax);
		int max = std::max(stock1.priceIncreaseMin, stock1.priceIncreaseMax);

		rate0 = 1 + ((min + (rand() % (max - min + 1))) * 0.01f);
		stock1.price *= rate0;
		if (stock1.price <= 0)
		{
			stock1.price = 1;
		}
		std::cout << stock1.name << " 가격:" << stock1.price << " +" << (rate0 - 1) * 100 << "%" << std::endl;
	}
	else
	{
		int min = std::min(stock1.priceDeclineMin, stock1.priceDeclineMax);
		int max = std::max(stock1.priceDeclineMin, stock1.priceDeclineMax);
		rate0 = (min + (rand() % (max - min + 1))) * 0.01f;
		stock1.price *= rate0;
		if (stock1.price <= 0)
		{
			stock1.price = 1;
		}
		std::cout << stock1.name << " 가격:" << stock1.price << " -" << (1 - rate0) * 100 << "%" << std::endl;
	}

	

	//stock2
	if (stock2.upPercent > (rand() % 100) + 1)
	{
		int min = std::min(stock2.priceIncreaseMin, stock2.priceIncreaseMax);
		int max = std::max(stock2.priceIncreaseMin, stock2.priceIncreaseMax);

		rate0 = 1 + ((min + (rand() % (max - min + 1))) * 0.01f);
		stock2.price *= rate0;
		if (stock2.price <= 0)
		{
			stock2.price = 1;
		}
		std::cout << stock2.name << " 가격:" << stock2.price << " +" << (rate0 - 1) * 100 << "%" << std::endl;
	}
	else
	{
		int min = std::min(stock2.priceDeclineMin, stock2.priceDeclineMax);
		int max = std::max(stock2.priceDeclineMin, stock2.priceDeclineMax);
		rate0 = (min + (rand() % (max - min + 1))) * 0.01f;
		stock2.price *= rate0;
		if (stock2.price <= 0)
		{
			stock2.price = 1;
		}
		std::cout << stock2.name << " 가격:" << stock2.price << " -" << (1 - rate0) * 100 << "%" << std::endl;
	}


	//stock3
	if (stock3.upPercent > (rand() % 100) + 1)
	{
		int min = std::min(stock3.priceIncreaseMin, stock3.priceIncreaseMax);
		int max = std::max(stock3.priceIncreaseMin, stock3.priceIncreaseMax);

		rate0 = 1 + ((min + (rand() % (max - min + 1))) * 0.01f);
		stock3.price *= rate0;
		if (stock3.price <= 0)
		{
			stock3.price = 1;
		}
		std::cout << stock3.name << " 가격:" << stock3.price << " +" << (rate0 - 1) * 100 << "%" << std::endl;
	}
	else
	{
		int min = std::min(stock3.priceDeclineMin, stock3.priceDeclineMax);
		int max = std::max(stock3.priceDeclineMin, stock3.priceDeclineMax);
		rate0 = (min + (rand() % (max - min + 1))) * 0.01f;
		stock3.price *= rate0;
		if (stock3.price <= 0)
		{
			stock3.price = 1;
		}
		std::cout << stock3.name << " 가격:" << stock3.price << " -" << (1 - rate0) * 100 << "%" << std::endl;
	}

	//stock4
	if (stock4.upPercent > (rand() % 100) + 1)
	{
		int min = std::min(stock4.priceIncreaseMin, stock4.priceIncreaseMax);
		int max = std::max(stock4.priceIncreaseMin, stock4.priceIncreaseMax);

		rate0 = 1 + ((min + (rand() % (max - min + 1))) * 0.01f);
		stock4.price *= rate0;
		if (stock4.price <= 0)
		{
			stock4.price = 1;
		}
		std::cout << stock4.name << " 가격:" << stock4.price << " +" << (rate0 - 1) * 100 << "%" << std::endl;
	}
	else
	{
		int min = std::min(stock4.priceDeclineMin, stock4.priceDeclineMax);
		int max = std::max(stock4.priceDeclineMin, stock4.priceDeclineMax);
		rate0 = (min + (rand() % (max - min + 1))) * 0.01f;
		stock4.price *= rate0;
		if (stock4.price <= 0)
		{
			stock4.price = 1;
		}
		std::cout << stock4.name << " 가격:" << stock4.price << " -" << (1 - rate0) * 100 << "%" << std::endl;
	}

	

	std::cout << std::endl;
	std::cout << std::endl << "숫자를 입력하세요 : 1.내정보 / 2.주식종류,가격 / 3.주식 구매 / 4.주식 판매 / 5.뉴스 확인 :";
	
}

// 타이머 스레드 함수
void StockUpdateTimer(std::atomic<bool>& running, int intervalSeconds)
{
	while (running) {
		std::this_thread::sleep_for(std::chrono::seconds(intervalSeconds));
		if (running) {
			StockUpdate();
		}
	}
}



int main()
{
	srand(time(NULL));
	std::atomic<bool> running(true);
	int interval = 3; // 스레드 간격

	// StockUpdate 타이머를 별도 스레드로 실행
	std::thread stockThread(StockUpdateTimer,std::ref(running), interval);

	// 종료 신호 보내고 스레드 정리
	//running = false;
	//stockThread.join();

	
	
	
	while (true)
	{
		Lobby();
	}
	
}
