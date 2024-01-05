#include <iostream>
#include <string>
#include <iomanip>
#include "menu.h"
#include "operation.h"
#include "utils.h"
#include "auth.h"
#include <stack>
#include <queue>

using namespace std;

struct Ingredient
{
    string name;
    int quantity;
};

class IngredientsManager
{
private:
    stack<Ingredient> ingredientsStack;
    queue<Ingredient> ingredientsQueue;

public:
    void createIngredient()
    {
        Ingredient newIngredient;
        cout << "Masukkan nama resep: ";
        cin >> newIngredient.name;

        cout << "Masukkan jumlah bahan: ";
        cin >> newIngredient.quantity;

        ingredientsStack.push(newIngredient);
        ingredientsQueue.push(newIngredient);

        cout << "Resep telah selesai dibuat." << endl;
    }

    void displayIngredients()
    {
        cout << "Resep Stack:" << endl;
        displayStack(ingredientsStack);

        cout << "Resep Queue:" << endl;
        displayQueue(ingredientsQueue);
    }

private:
    void displayStack(stack<Ingredient> s)
    {
        while (!s.empty())
        {
            cout << s.top().name << " - " << s.top().quantity << " units" << endl;
            s.pop();
        }
    }

    void displayQueue(queue<Ingredient> q)
    {
        while (!q.empty())
        {
            cout << q.front().name << " - " << q.front().quantity << " units" << endl;
            q.pop();
        }
    }
};

int main()
{
    Menu restaurantMenu;
    Operation operation;
    IngredientsManager ingredientsManager;
    int choice;
    string itemName;

    setAuth();
    setArt();
    setData(&restaurantMenu);
    do
    {
        setOptions(&choice);
        switch (choice)
        {
        case 1:
            operation.getMenu(&restaurantMenu);
            break;

        case 2:
            operation.insertMenu(&restaurantMenu);
            break;

        case 3:
            operation.searchMenu(&restaurantMenu);
            break;

        case 4:
            operation.removeMenu(&restaurantMenu);
            break;

        case 5:
            operation.sortMenu(&restaurantMenu);
            break;

        case 6:
            operation.removeLast(&restaurantMenu);
            break;

        case 7:
            ingredientsManager.createIngredient();
            break;

        case 8:
            ingredientsManager.displayIngredients();
            break;

        case 0:
            cout << "Sampai jumpa 😭\n";
            break;

        default:
            cout << "Pilihanmu gk valid.\n";
            break;
        }
        if (choice != 0)
        {
            cout << "\n\n > Tekan Tombol enter utk kembali 👇\n";
            system("read");
            system("clear");
        }

    } while (choice != 0);

    return 0;
}
