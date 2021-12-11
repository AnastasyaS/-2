#define LOWLIMIT 0  //limits for the main menu
#define UPLIMIT 7

#define SHOW 1
#define ADD 2
#define REMOVE 3
#define EDIT 4
#define ALPHABETIC_SORT 5
#define SHOW_SHOP_PRODUCTS 6
#define MIN_BASKET 7


#define EXIT 0

#include <iostream>
#include <string>
#include "InputCheck.h"
#include "Keeper.h"

using namespace std;

void printMenu();

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper keeper;

    ///////////////Testing//////////////////////
    keeper.add(new Price("banana", 10.99, "wallmart"), 0);
    keeper.add(new Price("ogre", 200.33, "seven-eleven"), 1);
    keeper.add(new Price("apple", 20.11, "euroSpar"), 2);
    keeper.add(new Price("lemon", 3, "Wendy's"), 3);
    keeper.add(new Price("apple", 20.11, "euroSaa"), 4);


    //keeper.test();
    //cout << keeper.getProduct()[0]->getName()[0] << endl;
    ///////////////Testing//////////////////////






    int position;
    cout << endl << "Hey :)" << endl << endl;
    while (true) {
        printMenu();
        switch (getIntValue(LOWLIMIT, UPLIMIT)) {
            cout << endl;
        case SHOW:
            keeper.showAllInfo();
            break;
        case ADD:
            cout << "Введите позицию, в которую вы хотите добавить товар (min равно 1, max равно "
                << keeper.getSize() + 1 << "):";
            position = getIntValue(1, keeper.getSize() + 1) - 1;
            cout << endl;
            keeper.add(new Price, position);    //добавление нового продукта
            //keeper << new Price;
            break;
        case REMOVE:
            if (keeper.isEmpty()) {
                cout << endl << "Массив пуст.Нечего удалять...." << endl << endl;
                break;
            }
            else {
                cout << "Здесь представлены все продукты:" << endl;
                keeper.showAllInfo();
                cout << "Какой продукт вы хотите удалить? Введите номер:";
                keeper >> keeper.getProduct()[getIntValue(1, keeper.getSize()) - 1];
                break;
            }
        case EDIT:
            cout << "Здесь представлены все продукты:" << endl;
            keeper.showAllInfo();
            cout << "Какой продукт вы хотите отредактировать? Введите номер:";
            keeper.getProduct()[getIntValue(1, keeper.getSize()) - 1]->edit();
            break;
        case ALPHABETIC_SORT:
            if (keeper.isEmpty()) {
                cout << endl << "Массив пуст. Нечего сортировать....." << endl << endl;
                break;
            }
            else {
                keeper.alphabeticSort();
                cout << endl << "Массив был отсортирован в алфавитном порядке" << endl << endl;
            }
            break;
        case SHOW_SHOP_PRODUCTS:
            cout << endl << "Пожалуйста введите название магазина: ";
            keeper.showShopProducts(getStringValue());
            break;
        case MIN_BASKET:
            keeper.minBasket();
            break;
        case EXIT:
           
            cout << endl << "Программа завершена" << endl << endl;
            return 0;
        default:
            cout << endl << "Ведён неверный номер" << endl;
            break;
        }
    }
    return 0;
}

void printMenu() {
    cout << "Что вы хотите сделать:" << endl;
    cout << "1. Показать каждый продукт" << endl <<
        "2. Добавить продукт" << endl <<
        "3. Удалить продукт" << endl <<
        "4. Редактировать продукт" << endl <<
        "5. Отсортировать массив в алфавитном порядке по названию магазинов" << endl <<
        "6. Показать информацию о товарах, которые продаются в магазине" << endl <<
        "7. Создать минимальную корзину" << endl <<
        "0. Выйти с программы" << endl << endl <<
        "Введите номер:";
}
