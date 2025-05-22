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
StockMaker static stock0(50000, "스미스 무역",90,120,30,100);
StockMaker static stock1(100000, "덕래 게임즈",50,75,50,75);
StockMaker static stock2(200000, "법무법인 쉐턱",10,30,40,80);
StockMaker static stock3(150000, "보산 화학",40,100,30,90);
StockMaker static stock4(300000, "동산 코믹스",30,70,50,80);

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

	while (true) {
		std::cout << "문장";
		std::cin >> num;

		if (std::cin.fail()) {
			std::cout << std::endl << "유효하지 않은 입력입니다." << std::endl << std::endl;
			std::cin.clear(); // 오류 상태 플래그 초기화
			std::cin.ignore(INT_MAX, '\n'); // 잘못된 입력 무시
		}
		else {
			break; // 입력 성공
		}
	}

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

	while (true) {
		std::cout << "문장";
		std::cin >> num;

		if (std::cin.fail()) {
			std::cout << std::endl << "유효하지 않은 입력입니다." << std::endl << std::endl;
			std::cin.clear(); // 오류 상태 플래그 초기화
			std::cin.ignore(INT_MAX, '\n'); // 잘못된 입력 무시
		}
		else {
			break; // 입력 성공
		}
	}

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

//이벤트 주기 카운트 ( 처음시작할때 바로 뉴스가 갱신되게하기위해서 이벤트주기값으로 설정)
int eventCount = 5;
//이벤트 종류 결정하는 변수
int event = (rand() % 10) + 1;
void news()
{
	switch (event)
	{
	case 1:
		std::cout << std::endl << "전세계적 전염병 발발, 보건 당국애서는 청결과 외출에 주의 당부" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "화학 물질에 관련된 정부 차원의 대대적인 감사 진행 예정, 수입 업체도 예외는 아니다" << std::endl;

		break;
	case 3:
		std::cout << std::endl << "동아시아 정상회담개최 예정. 주요 의제는 동아시아 국가 간 관세 조정" << std::endl;
		break;
	case 4:
		std::cout << std::endl << "정부 주도로 미디어 매체의 검열 제도에 대한 재검토 발표. 규제책 강화 예정" << std::endl;

		break;
	case 5:
		std::cout << std::endl << "동산 코믹스, 청소년들의 준법의식 함양을 위한 학습만화 제작 착수. 법무 법인 쉐턱과 협력 예정 " << std::endl;
		break;
	case 6:
		std::cout << std::endl << "중국, 판호 발행 조건 강화. 미디어 산업 총체적 난국" << std::endl;

		break;
	case 7:
		std::cout << std::endl << "국제적인 유가 폭등. 관련 업체는 한숨만" << std::endl;
		break;
	case 8:
		std::cout << std::endl << "동아시아까지 내려온 소말리아 해적. 해상 무역의 적신호 발발" << std::endl;
		break;
	case 9:
		std::cout << std::endl << "보산 화학, 법무법인 쉐턱과 업무 협약 체결." << std::endl;
		break;
	case 10:
		std::cout << std::endl << "덕래 게임즈, 신규 IP 제작 계획 발표. 예상 개발비는 약 1000억 이상 예정" << std::endl;
		break;
	default:
		std::cout << std::endl << "소식이 없습니다" << std::endl;
		break;
	}
	return;
}


void Lobby()
{

		int num=0;
		std::cout<<std::endl<< "숫자를 입력하세요 : 1.내정보 / 2.주식종류,가격 / 3.주식 구매 / 4.주식 판매 / 5.뉴스 확인 :";
		std::cin >> num;

		while (true) {
			std::cout << "문장";
			std::cin >> num;

			if (std::cin.fail()) {
				std::cout << std::endl << "유효하지 않은 입력입니다." << std::endl << std::endl;
				std::cin.clear(); // 오류 상태 플래그 초기화
				std::cin.ignore(INT_MAX, '\n'); // 잘못된 입력 무시
			}
			else {
				break; // 입력 성공
			}
		}

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


	
	eventCount++;
	
	//이벤트 주기 설정 여기서
	if (eventCount >= 5)
	{
		stock0.upPercent = 50;
		stock1.upPercent = 50;
		stock2.upPercent = 50;
		stock3.upPercent = 50;
		stock4.upPercent = 50;
		eventCount = 0;
		std::cout << std::endl << "뉴스가 갱신되었습니다" << std::endl;


		switch (event)
		{
		case 1:
		std::cout << std::endl << "전세계적 전염병 발발, 보건 당국애서는 청결과 외출에 주의 당부" << std::endl;
		stock1.upPercent = 70;
		stock4.upPercent = 70;
		break;
		
		case 2:
		std::cout << std::endl << "화학 물질에 관련된 정부 차원의 대대적인 감사 진행 예정, 수입 업체도 예외는 아니다" << std::endl;
		stock0.upPercent = 35;
		stock3.upPercent = 35;
		break;
			
		case 3:
		std::cout << std::endl << "동아시아 정상회담개최 예정. 주요 의제는 동아시아 국가 간 관세 조정" << std::endl;
		stock0.upPercent = 100;
		break;
	
		case 4:
		std::cout << std::endl << "정부 주도로 미디어 매체의 검열 제도에 대한 재검토 발표. 규제책 강화 예정" << std::endl;
		stock1.upPercent = 10;
		stock4.upPercent = 10;
		break;
	
		case 5:
		std::cout << std::endl << "동산 코믹스, 청소년들의 준법의식 함양을 위한 학습만화 제작 착수. 법무 법인 쉐턱과 협력 예정 " << std::endl;
		stock2.upPercent = 75;
		stock4.upPercent = 75;
		break;
	
		case 6:
		std::cout << std::endl << "중국, 판호 발행 조건 강화. 미디어 산업 총체적 난국" << std::endl;
		stock1.upPercent = 10;
		stock4.upPercent = 10;
		break;
	
		case 7:
		std::cout << std::endl << "국제적인 유가 폭등. 관련 업체는 한숨만" << std::endl;
		stock0.upPercent = 5;
		stock3.upPercent = 30;
		break;
	
		case 8:
		std::cout << std::endl << "동아시아까지 내려온 소말리아 해적. 해상 무역의 적신호 발발" << std::endl;
		stock0.upPercent = 5;
		break;
	
		case 9:
		std::cout << std::endl << "보산 화학, 법무법인 쉐턱과 업무 협약 체결." << std::endl;
		stock2.upPercent = 75;
		stock3.upPercent = 75;
		break;
	
		case 10:
		std::cout << std::endl << "덕래 게임즈, 신규 IP 제작 계획 발표. 예상 개발비는 약 1000억 이상 예정" << std::endl;
		stock1.upPercent = 100;
		break;
	
		default:
			break;
		}
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
