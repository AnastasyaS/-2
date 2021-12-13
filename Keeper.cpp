#define MAXLIMIT 30
#include "Keeper.h"


void Keeper::add(Price* productPtr, int position)
{
	Price** tmp = Keeper::product;
	Keeper::size++;
	product = new Price * [Keeper::size];
	product[position] = productPtr;	//добавление нового продукта в конец массива
	for (int i = 0, j = 0; i < size; i++) {
		if (i != position) {
			product[i] = tmp[j];
			j++;
		}
		else
			continue;
	}
}

void Keeper::remove(Price* productPtr)
{
	Price** tmp = Keeper::product;
	Keeper::size--;
	product = new Price * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size" потому что я должен проверить все элементы исходного массива
		if (tmp[i] != productPtr) {
			product[i] = tmp[i];
		}
		else {
			i++;
			for (int j = i - 1; i <= size; j++, i++)
				product[j] = tmp[i];
			break;
		}
	}
	delete productPtr;
	cout << endl << "Элемент был удален" << endl << endl;
}

void Keeper::showAllInfo() {
	if (size == 0)		//массив пуст
		cout << endl << "Массив пуст. Пока нечего показывать..." << endl << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
			cout << i + 1 << "." << endl;
			getProduct()[i]->showInfo();
			cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
		}
}

bool Keeper::isEmpty()
{
	if (Keeper::size > 0)
		return false;
	else
		return true;
}


Price& Keeper::operator<<(Price* productPtr)
{
	cout << "Введите позицию, в которую вы хотите добавить товар (min равно 1, max равно "
		<< Keeper::getSize() + 1 << "):";
	int position = getIntValue(1, Keeper::getSize() + 1) - 1;
	Price** tmp = Keeper::product;
	Keeper::size++;
	product = new Price * [Keeper::size];
	product[position] = productPtr;	//добавление нового продукта в конец массива
	for (int i = 0, j = 0; i < size; i++) {
		if (i != position) {
			product[i] = tmp[j];
			j++;
		}
		else
			continue;
	}
	return **product;
}

Price& Keeper::operator>>(Price* productPtr)
{
	Price** tmp = Keeper::product;
	Keeper::size--;
	product = new Price * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size"потому что я должен проверить все элементы исходного массива
		if (tmp[i] != productPtr) {
			product[i] = tmp[i];
		}
		else {
			i++;
			for (int j = i - 1; i <= size; j++, i++)
				product[j] = tmp[i];
			break;
		}
	}
	delete productPtr;
	cout << endl << "Элемент был удален" << endl << endl;
	return **product;
}

void Keeper::alphabeticSort() {	//ЗАДАЧА: выполните функцию - когда два магазина имеют немного одинаковые названия
	for (int i = 0; i < Keeper::getSize(); i++) {
		for (int j = 0; j < Keeper::getSize() - i - 1; j++) {
			char firstCharLine1 = getProduct()[j]->getShopName()[0];	//первый символ строки
			int k = 0;
			while (true) {
				if (firstCharLine1 == ' ' || firstCharLine1 == '.' || firstCharLine1 == ',' || firstCharLine1 == '-') {
					firstCharLine1 = getProduct()[j]->getShopName()[k];
					k++;
				}
				else
					break;
			}
			char firstCharLine2 = getProduct()[j + 1]->getShopName()[0];	//первый символ строки
			k = 0;
			while (true) {
				if (firstCharLine2 == ' ') {
					firstCharLine2 = getProduct()[j + 1]->getShopName()[k];
					k++;
				}
				else
					break;
			}
			if (firstCharLine1 == firstCharLine2) {
				int q = 0;
				for (; product[j]->getShopName()[q] == product[j + 1]->getShopName()[q]; q++) {
					firstCharLine1 = product[j]->getShopName()[q];
					firstCharLine2 = product[j + 1]->getShopName()[q];
				}
				firstCharLine1 = product[j]->getShopName()[q];
				firstCharLine2 = product[j + 1]->getShopName()[q];
			}

			if (firstCharLine1 > firstCharLine2) {
				Price* tmp = *(getProduct() + j);
				*(getProduct() + j) = *(getProduct() + j + 1);
				*(getProduct() + j + 1) = tmp;
			}
		}
	}
}

void Keeper::showShopProducts(string shopName)
{
	bool flag = false;	//флаг равен 1, если найдено совпадение; в противном случае - 0
	if (isEmpty())
		cout << endl << "Массив пуст. Пока нечего показывать..." << endl << endl;
	else
		for (int i = 0; i < Keeper::getSize(); i++) {
			if (product[i]->getShopName() == shopName) {
				flag = true;
				cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
				cout << i + 1 << "." << endl;
				product[i]->showInfo();
				cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
			}
		}
	if (!flag)
		cout << endl << "Введёный магазин не найден" << endl << endl;
}

void Keeper::minBasket()
{
	typedef struct foodItem {
		string foodName, foodCategory;
		int foodPrice;
	} food;

	food foodList[MAXLIMIT];
	int foodNumber, i, f, searchedamount, foundamount, min, minPrice;

	fstream file;
	file.exceptions(ofstream::badbit);
	try {
		file.open("FoodDatabase.txt", std::fstream::in);
	}
	catch (const ofstream::failure& ex) {
		cout << endl << "Произошла ошибка при открытии файла." << endl;
		cout << endl << ex.what() << endl << ex.code() << endl;
	}
	file >> foodNumber;
	for (int i = 0; i < foodNumber; i++) {
		file >> foodList[i].foodName;
		file >> foodList[i].foodCategory;
		file >> foodList[i].foodPrice;
	}

	typedef struct {
		string searchedCategory;
		int thereis;
	} basket;

	basket minBasket[20];
	for (i = 0; i < 20; i++)
		minBasket[i].thereis = 0;
	searchedamount = 0;
	foundamount = 0;
	min = -1;
	string line;
	i = 0;

	printf("\nВведите КОЛИЧЕСТВО желаемых категорий товаров, чтобы создать минимальную корзину:\n");
	int searchedCatNum;	//Количество поисковых категорий
	searchedCatNum = getIntValue(1, 10);
	for (int j = 0; j < searchedCatNum; j++) {
		cout << endl << "Введите " << j + 1 << " категорию:";
		minBasket[i].searchedCategory = getStringValue();
		i++;
		searchedamount++;
	}
	printf("\nПрограмма добавила эти товары в минимальную корзину:\n");
	for (i = 0; i < searchedamount; i++) {
		minPrice = INT_MAX;
		for (f = 0; f < foodNumber; f++) {
			if (minBasket[i].searchedCategory.compare(foodList[f].foodCategory) == 0) {
				minBasket[i].thereis++;
				if (minPrice == INT_MAX)
					foundamount++;
				if (foodList[f].foodPrice < minPrice) {
					minPrice = foodList[f].foodPrice;
					min = f;
				}
			}
			if ((f == foodNumber - 1) && (min >= 0) && (minBasket[i].thereis > 0))
				cout << endl << foodList[min].foodName << " для " << foodList[min].foodPrice << " руб." << endl;
		}
	}
	if (searchedamount > foundamount) {
		printf("\nНе найдено совпадений для следующих категорий:\n");
		for (i = 0; i < searchedamount; i++)
			if (minBasket[i].thereis == 0)
				cout << endl << minBasket[i].searchedCategory << endl << endl;
	}
	file.close();
}




void Keeper::setProduct(Price* product)
{
	this->product = &product;
}


Price** Keeper::getProduct()
{
	return product;
}

int Keeper::getSize()
{
	return Keeper::size;
}

Keeper::Keeper() {
	cout << "Keeper's конструктор " << this << " название" << endl;
	size = 0;
	product = new Price * [size];
}

Keeper::~Keeper()
{
	cout << "Keeper's деструктор " << this << " название" << endl;
	for (int i = 0; i < size; i++) {

		delete product[i];
	}
	product = nullptr;
	size = 0;
}
