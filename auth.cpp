#include "auth.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

/**
 * Jika username adalah admin, jika benar admin maka return true, jika salah, return false
*/
bool authenticateUser(const string &username)
{
    return (username == "admin");
}

/**
 * Untuk mendapatkan password dari inputan user
*/
string getPasswordInput()
{
    string password;
    char ch;

    cout << "Enter password: ";

    cin >> noskipws;

    while ((ch = cin.get()) != '\n')
    {
        password += ch;
        cout << '*';
    }

    cin >> skipws;

    return password;
}

/**
 * Untuk menampilkan loading indicator(progress loading dari 0 ke 100)
 */
void showLoadingIndicator()
{
    system("clear");

    float progress = 0.0;
    while (progress < 1.0)
    {
        int barWidth = 70;

        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < pos)
                std::cout << "=";
            else if (i == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));

        progress += 0.16;
    }
    std::cout << std::endl;
    system("clear");
}

void setAuth() {
    string username, password;


    while (true)
    {
        cout << "Enter username: ";
        cin >> username;

        if (authenticateUser(username))
        {
            showLoadingIndicator();
            cout << "\nLogin berhasil. Selamat Datang, " << username << "!\n";
            break;
        }
        else
        {
            cout << "\nLogin gagal. username tidak cocok. Silahkan coba lagi 🥹\n";
        }
    }
}