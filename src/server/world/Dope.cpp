/*
 * Copyright (C) 2011-2014 EMPulseGaming.LLC <http://www.empulsegaming.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include"Dope.h"

#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

/* Data-types - detailed */
dope::dope()
{
    life    = 1;
    debt    = -5000;
    money   = 2000;
    weed    = 50;
    heroin  = 10;
    cocaine = 200;
    mj      = 20;
    ecstacy = 35;
    acid    = 175;
    cols    = 78;
    rows    = 7;
    fname   = "Default.txt";
}

dope::dope(char *c)
{
    c = fname;
}

dope::~dope() { }

/*Start Up Screen*/
bool dope::Start()
{
    for (int i = 0; i < 80; i++)
    {
        cout << '\xb1';
    }

    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), 3);
    cout << '\xb1' << "\t\t\t\tVERSION #1\t\t\t\t       " << '\xb1';

    for (int j = 0; j < 80; j++)
    {
        cout << '\xb1';
    }

    cout << endl << endl;
    init();

    cout << "\n\n\n\n\n\n\n\t\t1 = Start\t2 = Instructions\t3 = Quit: ";
    cin >> decision;

    if (decision == 1)
    {
        Adventure();
    }
    else if (decision == 2)
    {
        Instruction();
    }
    else
    {
        exit(3);
    }
    return 0;
}

void dope::init()
{
    char buff [256] = " ";
    short count = 0;
    short r     = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    do
    {
        ifile.get(buff, 255);
        ifile.ignore(256, '\n');

        if (ifile.eof())
        {
            break;
        }

        for (count = 0; count < cols; count++)
        {
            grid[r] [count] = buff[count];
        }
        r++;
    }
    while (!ifile.eof());

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void dope::Openfile(char *fname)
{
    ifile.open(fname, ios::in);
}

void dope::Closefile()
{
    ifile.close();
}

/* Instructions - Special stuff */
void dope::Instruction()
{
    system ("cls");
    for (int i = 0; i < 16; i++)
    {
        cout << '\xb1';
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 3);
    }

    cout << endl;
    cout << '\xb1' << " Instructions " << '\xb1';
    cout << endl;

    for (int j = 0; j < 16; j++)
    {
        cout << '\xb1';
    }

    /* Story */
    cout << "\n\n\nIn this game you start as a young thug with $2000 dollars in your pocket, and in debt $5000 dollars."
         << " To make it out in the streets, you must buy drugs in one city till you have enough money to "
         << "afford a new level. When you achieve that \ngoal you will be allowed to the "
         << "next city. But watch out for the COPS, they will try to bust you, every chance they get. "
         << "There are four cities all together: \nDetroit, New York, California, and Miami.\n\n\n";

    return;
}

/* Adventure - where it all begins */
void dope::Adventure()
{
    do
    {
        Status();
        printf("\t\t\t  Cities to Run \n");
        /*Level - Menu*/
        cout << "\t\t\t" << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1'
             << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1'
             << '\xb1' << '\xb1' << '\xb1' << endl;
        cout << "\t\t\t" << '\xb1' << "               " << '\xb1' << endl;
        cout << "\t\t\t" << '\xb1' << " 1. Detroit    " << '\xb1' << endl;
        cout << "\t\t\t" << '\xb1' << " 2. New York   " << '\xb1' << endl;
        cout << "\t\t\t" << '\xb1' << " 3. California " << '\xb1' << endl;
        cout << "\t\t\t" << '\xb1' << " 4. Miami      " << '\xb1' << endl;
        cout << "\t\t\t" << '\xb1' << " 5. Give Up    " << '\xb1' << endl;

        cout << "\t\t\t" << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1'
             << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1' << '\xb1'
             << '\xb1' << '\xb1' << '\xb1' << endl;

        cout << "\t\t\tChoice: ";
        cin >> decision;

        switch (decision)
        {
            case 1:
                if (money < 2000)
                {
                    cout << "Whoa!\nYour money is low... $" << money << "\nLevel Locked!\n";
                    Adventure();
                }
                else
                {
                    Detroit();
                }
                break;
            case 2:
                if (money <= 10000)
                {
                    cout << "Whoa!\nYour money is low... $" << money << "\nLevel Locked!\n";
                    Adventure();
                }
                else
                {
                    Detroit();
                }
                break;
            case 3:
                if (money <= 22000)
                {
                    cout << "This board will be available in version #2...\nLevel Locked!\n";
                    Adventure();
                }
                break;
            case 4:
                if (money <= 33000)
                {
                    cout << "This board will also be available in version #2...\nLevel Locked!\n";
                    Adventure();
                }
                break;
            case 5:
                exit(5);
                break;
            default:
                cout << "Invalid Choice!\n";
                break;
        }
    }
    while (decision < 1 || decision > 4);
}

/* Status Bar - players information */
void dope::Status()
{
    system ("cls");
    for (int i = 0; i < 80; i++)
    {
        cout << '\xb1';
    }

    cout << '\xb1' << " DEALER " << '\xb1' << " Life: " << life << " " << '\xb1'
         << " Money: $" << money  << " " << '\xb1' << " Time: ";

    if (money > 4000)
    {
        cout << "Evening " << '\xb1';
    }
    else
    {
        cout << "Morning " << '\xb1';
    }
    if (money <= 0)
    {
        cout << "GAMEOVER!\n";
        exit(0);
    }

    cout << " Health: ";

    if (money < 5000)
    {
        cout << "Poor " << '\xb1' << " Debt: " << debt << " " << '\xb1';
    }
    else
    {
        cout << "Good " << '\xb1' << " Debt: " << debt << " " << '\xb1';
    }

    for (int j = 0;j < 80; j++)
    {
        cout << '\xb1';
    }
    cout << endl << endl << endl;
}

/* City #1 - Rules Are Rules */
void dope::Detroit()
{
    do
    {
        system ("cls");
        Status();

        for(int i = 0; i < 32; i++)
        {
            cout << '\xb1';
        }

        cout << endl;
        cout << '\xb1' << "  Dope Prices      " << '\xb1' << "  Tools   " << '\xb1' << endl;
        cout << '\xb1' << "                   " << '\xb1' << "          " << '\xb1' << endl;
        cout << '\xb1' << " 1. Weed    = $50  " << '\xb1' << "  7. Buy  " << '\xb1' << endl;
        cout << '\xb1' << " 2. Heroin  = $10  " << '\xb1' << "  8. Sell " << '\xb1' << endl;
        cout << '\xb1' << " 3. Cocaine = $200 " << '\xb1' << "  9. Bank " << '\xb1' << endl;
        cout << '\xb1' << " 4. MJ      = $20  " << '\xb1' << " 10. Coat " << '\xb1' << endl;
        cout << '\xb1' << " 5. Ecstasy = $35  " << '\xb1' << " 11. Quit " << '\xb1' << endl;
        cout << '\xb1' << " 6. Acid    = $175 " << '\xb1' << "          " << '\xb1';
        cout << endl;

        for (int j = 0; j < 32; j++)
        {
            cout << '\xb1';
        }

        cout << endl;
        cout << "Tool Choice: ";
        cin >> decision;

        switch (decision)
        {
            case 7:
                Purchase(x, y);
                break;
            case 8:
                Sell(a, b);
                break;
            case 9:
                Bank();
                break;
            case 10:
                Coat();
                break;
            case 11:
                exit(11);
                break;
            default:
                cout << "Invalid Choice!\n";
                break;
        }
    }
    while ((decision < 7) || (decision > 11));

    return;
}

double dope::Purchase(short x, short y)
{
    strcpy (final, "\n\n1.) Weed  ");
    strcat (final, "2.) Heroin  ");
    strcat (final, "3.) Cocaine  ");
    strcat (final, "4.) MJ  ");
    strcat (final, "5.) Ecstasy  ");
    strcat (final, "6.) Acid  ");
    system ("cls");

    for (int i = 0; i < 12; i++)
    {
        cout << '\xb1';
    }

    cout << endl;
    cout << '\xb1' << " Purchase " << '\xb1';
    cout << endl;

    for (int j = 0; j < 12; j++)
    {
        cout << '\xb1';
    }

    cout << final << endl;
    cout << "Press 0 to quit\n\n";

    if (weed1 == 1)
    {
        cout << "Need to purchase weed...\n";
    }

    if (heroin1 == 1)
    {
        cout << "Need to purchase heroin...\n";
    }

    if (cocaine1 == 1)
    {
        cout << "Need to purchase cocaine...\n";
    }

    if (mj1 == 1)
    {
        cout << "Need to purchase mj...\n";
    }

    if (ecstasy1 == 1)
    {
        cout << "Need to purchase ecstasy...\n";
    }

    if (acid1 == 1)
    {
        cout << "Need to purchase acid...\n";
    }

    cout << "What kind do you want: ";
    cin >> x;

    if (a == 0)
    {
        exit(0);
    }

    cout << "How many: ";
    cin >> y;

    switch (x)
    {
        case 1:
            money =  money - weed * (y);
            money--;

            weed1 = 1;
            weed1 = weed1 + 1 * y;
            weed1++;

            if (y > 5)
            {
                cout << "Too Much!\n";
            }
            Detroit();
            break;
        case 2:
            money =  money - heroin * (y);
            money--;

            heroin1 = 1;
            heroin1 = heroin1 + 1 * y;
            heroin1++;

            if (y > 5)
            {
                cout << "Too Much!\n";
            }
            Detroit();
            break;
        case 3:
            money =  money - cocaine * (y);
            money--;

            cocaine1 = 1;
            cocaine1 = cocaine1 + 1 * y;
            cocaine1++;

            if (y > 5)
            {
                cout << "Too Much!\n";
            }
            Detroit();
            break;
        case 4:
            money =  money - mj * (y);
            money--;

            mj1 = 1;
            mj1 = mj1 + 1 * y;
            mj1++;

            if (y > 5)
            {
                cout << "Too Much!\n";
            }
            Detroit();
            break;
        case 5:
            money =  money - ecstasy * (y);
            money--;

            ecstasy1 = 1;
            ecstasy1 = ecstasy1 + 1 * y;
            ecstasy1++;

            if (y > 5)
            {
                cout << "Too Much!\n";
            }
            Detroit();
            break;
        case 6:
            money =  money - acid * (y);
            money--;

            acid1 = 1;
            acid1 = acid1 + 1 * y;
            acid1++;

            if (y > 5)
            {
                cout << "Too Much!\n";
            }
            Detroit();
            break;
    }
    return total;
}

/* Lists all drugs that you have bought, and quantities.
   Then lets the user sell out of his stash. */
double dope::Sell (short a, short b)
{
    system ("cls");
    for (int i = 0; i < 8; i++)
    {
        cout << '\xb1';
    }

    cout << endl;
    cout << '\xb1' << " Sell " << '\xb1';
    cout << endl;

    for(int j = 0; j < 8; j++)
    {
        cout << '\xb1';
    }

    strcpy(final, "\n\n1.) Weed  ");
    strcat(final, "2.) Heroin  ");
    strcat(final, "3.) Cocaine  ");
    strcat(final, "4.) MJ  ");
    strcat(final, "5.) Ecstasy  ");
    strcat(final, "6.) Acid  ");

    cout << final << endl;
    cout << "Press 0 to quit\n\n";
    cout << "What do you want to sell: ";
    cin >> a;
    cout << "How many: ";
    cin >> b;

    if (a == 0)
    {
        exit(0);
    }

    debt =  debt + weed * (b);
    debt--;

    if (b > 5)
    {
        cout << "Too Much!\n";
    }
    Detroit();

  return total1;
}

/* Player can deposit cash into a secret account. And withdraw if needed;
   The most you can deposit is $3,000 dollars. If you deposit over that amount,
   cops will come and suspect that something is wrong. And you may get busted. */
void dope::Bank()
{
    do
    {
        system ("cls");
        for (int a = 0; a < 18; a++)
        {
            cout << '\xb1';
        }

        cout << endl;
        cout << '\xb1' << " Secret Account " << '\xb1';
        cout << endl;

        for (int b = 0; b < 18; b++)
        {
            cout << '\xb1';
        }
        cout << endl << endl;

        /* Main Data - A little something to keep the game cool */
        cout << " \n1.Deposit\t2. Exit: ";
        cin >> decision;

        switch (decision)
        {
            case 1:
                D_Calc(d);
                break;
            case 2:
                exit(2);
                break;
            default:
                cout << "Invalid Choice!\n";
                break;
        }
    }
    while ((decision < 1) || (decision > 2));
    return;
}

/* User deposits - following restrictions */
void dope::D_Calc (double d)
{
    system("cls");
    for (i = 0; i < 11; i++)
    {
        cout << '\xb1';
    }

    cout << endl;
    cout << '\xb1' << " Deposit " << '\xb1';
    cout << endl;

    for (j = 0; j < 11; j++)
    {
        cout << '\xb1';
    }

    cout << endl << endl;
    double num1 = 0;

    cout << "How much money would you like to deposit: ";
    cin >> d;

    num1 = d * 1;

    if ((d < 1) || (d > 2000)) /* Restriction */
    {
        printf ("Whoa!\nLets be realistic.\n");
        Sleep (800);
        D_Calc(d);
    }
    else
    {
        cout << num1 << " dollars have been deposited into your Secret Account.\n";
        money = money - num1;
        money--;
    }

    if (d == 10000) /* Restriction */
    {
        cout << "Your Account is too the Max!\nPlease create another account.\n";
    }

    return;
}

/* If user does not purchase any dope, then coat will be filled with garbage.
Simply just purchase then check. */
void dope::Coat()
{
    system ("cls");
    if (weed1 == 0)
    {
        cout << "\nNeed to purchase weed...\n";
    }
    //weed1 = 0;
    if (a == 1)
    {
        weed1 = weed1 - 1 * b;
        if (weed1 == 100)
        {
            cout << "Need to sell weed!\n";
        }
        else
        {
            cout << "\nBuy More!\n";
        }
        weed1--;
    }

    for (int i = 0; i < 8; i++)
    {
        cout << '\xb1';
    }

    cout << endl;
    cout << '\xb1' << " Coat " << '\xb1';
    cout << endl;

    for (int j = 0; j < 8; j++)
    {
        cout << '\xb1';
    }

    cout << "\n\nWeed: " << weed1 << endl;

    //heroin1 = 0;
    if (heroin1 == 0)
    {
        cout << "\nNeed to purchase heroin...\n";
    }

    if (a == 2)
    {
        heroin1 = heroin1 - 1 * b;
        if (heroin1 == 100)
        {
            cout << "Need to sell more heroin!\n";
        }
        else
        {
            cout << "Buy More!\n";
        }
        heroin1--;
    }
    cout << "Heroin: " << heroin1 << endl;

    //cocaine1 = 0;
    if (cocaine1 == 0)
    {
        cout << "\nNeed to purchase cocaine...\n";
    }

    if (a == 3)
    {
        cocaine1 = cocaine1 - 1;
        if (cocaine1 == 100)
        {
            cout << "Need to sell more cocaine!\n";
        }
        else
        {
            cout << "Buy More!\n";
        }
        cocaine1--;
    }
    cout << "Cocaine: " << cocaine1 << endl;

    //mj1 = 0;
    if (mj1 == 0)
    {
        cout << "\nNeed to purchase mj...\n";
    }

    if (a == 4)
    {
        mj1 = mj1 - 1;
        if (mj1 == 100)
        {
            cout << "Need to sell more MJ!\n";
        }
        else
        {
            cout << "Buy More!\n";
        }
        mj1--;
    }
    cout << "MJ: " << mj1 << endl;

    //ecstasy1 = 0;
    if (ecstasy1 == 0)
    {
        cout << "\nNeed to purchase ecstasy...\n";
    }

    if (a == 5)
    {
        ecstasy1 = ecstasy1 - 1;
        if (ecstasy1 == 100)
        {
            cout << "Need to sell more ecstasy!\n";
        }
        else
        {
            cout << "Buy More!\n";
        }
        ecstasy1--;
    }
    cout << "Ecstasy: " << ecstasy1 << endl;

    //acid1 = 0;
    if (acid1 == 0)
    {
        cout << "\nNeed to purchase acid...\n";
    }

    if (a == 6)
    {
        acid1 = acid1 - 1;
        if (acid1 == 100)
        {
            cout << "Need to sell more acid!\n";
        }
        else
        {
            cout << "Buy More!\n";
        }
        acid1--;
    }
    cout << "Acid: " << acid1 << endl;

    Sleep (5000);
    Detroit();
}
