#pragma once
#include "Stock.h"

class StockMaker :public Stock
{
public:
	// »ý¼ºÀÚ 
	StockMaker(int _price, std::string _name, float _priceIncreaseMin, float _priceIncreaseMax, float _priceDeclineMin, float _priceDeclineMax
	)
	{
		price = _price;
		name = _name;
		priceIncreaseMax = _priceIncreaseMax;
		priceIncreaseMin = _priceIncreaseMin;
		priceDeclineMax = _priceDeclineMax;
		priceDeclineMin = _priceDeclineMin;
	}
};

