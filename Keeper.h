#pragma once
#include "Price.h"
#include <fstream>
class Keeper
{
private:
	int size;	//размер динамического массива указателей
	Price** product;
	void setProduct(Price* product);
public:
	void add(Price* productPtr, int position);
	void remove(Price* productPtr);
	Price** getProduct();
	int getSize();
	void showAllInfo();
	bool isEmpty();

	void alphabeticSort();
	void showShopProducts(string shopName);
	void minBasket();	//дополнительные функциональные возможности

	Price& operator<<(Price* productPtr);
	Price& operator>>(Price* productPtr);


	Keeper();
	~Keeper();
};

