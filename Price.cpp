#include "Price.h"

string Price::getName()
{
	return this->name;
}

string Price::getShopName()
{
	return this->shopName;
}

void Price::showInfo()
{
	cout << "Наименование товара: " << Price::name << endl;
	cout << "Цена товара: " << Price::price << endl;
	cout << "Название магазина для товара: " << Price::shopName << endl;
}

void Price::edit()
{
	cout << "Наименование продукта: " << Price::name << endl;
	cout << "Введите новое наименование для продукта: ";
	this->name = getStringValue();
	cout << "Цена продукта: " << Price::price << endl;
	cout << "Введите новую цену для продукта: ";
	this->price = getDoubleValue(0, DBL_MAX);
	cout << "Название магазина товара: " << Price::shopName << endl;
	cout << "Введите новое название магазина: ";
	this->shopName = getStringValue();
}

Price::Price()
{
	cout << "Конструктор цены" << this << "название" << endl;
	cout << endl << "Пожалуйста введите наименование товара: ";
	Price::name = getStringValue();
	cout << endl << "Пожалуйста, введите цену товара: ";
	Price::price = getDoubleValue(0, DBL_MAX);
	cout << endl << "Пожалуйста, введите название магазина товара: ";
	Price::shopName = getStringValue();
}

Price::Price(string name, double price, string shopName)
{
	cout << "Конструктор цены с параметрами " << this << " название" << endl;
	this->name = name;
	this->shopName = shopName;
	this->price = price;
}

Price::~Price()
{
	cout << "Удалить прайс " << this << " название" << endl;

}
