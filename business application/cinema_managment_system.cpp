#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
int admintotal = 0;
int bookticket = 0;
int foodcount = 0;
string moviename[50], movietime[50], screentype[50], moviecategory[50], ticketprice[50];
string bookname[50], booktime[50], booktype[50], bookcategory[50], bookprice[50];
string fooditems[50];
void displayheader();
string adminmenu();
void adminoption1();
void adminoption2();
void adminoption3();
void adminoption4();
void adminoption5();
string amenue();
void aoption1();
void aoption2();
void aoption3();
void aoption4();
void aoption5();
void aoption6();
void aoption7();
void aoption8();
void readadmindata()
{
    string text;
    ifstream MyReadFile("admininterface.txt");
    while (getline(MyReadFile, text))
    {
        cout << text << endl;
    }
    cout << endl;
    MyReadFile.close();
}
void readadmindataAgain()
{
    string text;
    ifstream MyReadFile("admininterface.txt");
    while (getline(MyReadFile, text))
    {
        cout << text << endl;
    }
    cout << endl;
    MyReadFile.close();
}
void readbooktickets()
{
    string text;
    ifstream MyReadFile("tickeetbook.txt");
    while (getline(MyReadFile, text))
    {
        cout << text << endl;
    }
    cout << endl;
    MyReadFile.close();
}
void readfooditems()
{
    string text;
    ifstream MyReadFile("fooditems.txt");
    while (getline(MyReadFile, text))
    {
        cout << text << endl;
    }
    cout << endl;
    MyReadFile.close();
}
int main()
{

    string choice;
    string adminName;
    while (true)
    {
        cout << "\t\tEnter your name (admin or audience) or enter anything to close your application.\n\n";
        cout << "Enter your choice...";
        cin >> adminName;

        if (adminName == "admin")
        {
            cout << "\t\tYou have login as an admin.\n";
            cout << "\tPlease wait we are getting you to your main menue.";
            for (int i = 1; i <= 6; i++)
            {
                cout << ".";
                Sleep(1000);
            }
            while (true)
            {
                system("cls");
                displayheader();
                choice = adminmenu();
                if (choice == "1")
                {
                    system("cls");
                    adminoption1();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "2")
                {
                    system("cls");
                    adminoption2();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "3")
                {
                    system("cls");
                    adminoption3();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "4")
                {
                    system("cls");
                    adminoption4();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "5")
                {
                    system("cls");
                    adminoption5();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "6")
                {
                    break;
                }
                else if (choice == "7")
                {
                    system("cls");
                    readadmindata();
                    cout << "Press any key to continue...";
                    getch();
                }
            }
        }

        else if (adminName == "audience")
        {
            cout << "\t\tYou have login as a spectator.\n";
            cout << "\tPlease wait we are getting you to your main menue.";
            for (int i = 1; i <= 6; i++)
            {
                cout << ".";
                Sleep(1000);
            }
            while (true)
            {
                system("cls");
                displayheader();
                choice = amenue();
                if (choice == "1")
                {
                    system("cls");
                    aoption1();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "2")
                {
                    system("cls");
                    aoption2();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "3")
                {
                    system("cls");
                    aoption3();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "4")
                {
                    system("cls");
                    aoption4();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "5")
                {
                    system("cls");
                    aoption5();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "6")
                {
                    system("cls");
                    aoption6();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "7")
                {
                    system("cls");
                    aoption7();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "8")
                {
                    system("cls");
                    aoption8();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "9")
                {
                    break;
                }
                else if (choice == "0")
                {
                    system("cls");
                    readadmindataAgain();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "a")
                {
                    system("cls");
                    readbooktickets();
                    cout << "Press any key to continue...";
                    getch();
                }
                else if (choice == "b")
                {
                    system("cls");

                    readfooditems();
                    cout << "Press any key to continue...";
                    getch();
                }
            }
        }
        else
        {
            cout << "Your appplication has been closed! Thanks for visit.";
            break;
        }
    }
    return 0;
}
void displayheader()
{
    cout << "*************************************************************************\n";
    cout << "*\t\t\tCinema Managment System\t\t\t\t*\n";
    cout << "*************************************************************************\n";
}
string adminmenu()
{
    string choice;
    cout << "\t\t\tWelcome to cinema managment system\n\n\n";
    cout << "Press one to enter the movies of current day.\n\n";
    cout << "Press two to search search movies. \n\n";
    cout << "Press three to update your showtimes. \n\n";
    cout << "Press four to delete your showtime. \n\n";
    cout << "Press five to view complete list of shows of current day. \n\n";
    cout << "Press six to exit to main menue. \n\n";
    cout << "Press seven to load your data from the file.\n\n";
    cout << "Enter your choice...";
    cin >> choice;
    return choice;
}
void adminoption1()
{
    cout << "\t\tYou have pressed option 1 to enter the record of the movies of current day.\n\n";
    cout << "Enter how many movies you want to enter...";
    int enter;
    cin >> enter;
    if (admintotal == 0)
    {
        admintotal = admintotal + enter;
        cout << "\n\n";
        for (int i = 0; i < enter; i++)
        {
            cout << "\t\tEnter the data of " << i + 1 << " movie.\n\n";
            cout << "Enter the name of movie........";
            cin >> moviename[i];
            cout << "Enter the starting and ending time of movie........";
            cin >> movietime[i];
            cout << "Enter the screentype of the movie........";
            cin >> screentype[i];
            cout << "Enter the category of movie.......";
            cin >> moviecategory[i];
            cout << "Enter the ticket price of the movie.......";
            cin >> ticketprice[i];
            cout << "\n\n\n";
        }
        cout << "Congratulaions! Your data have been successfully entered.";
    }
    else
    {
        for (int i = admintotal; i < admintotal + enter; i++)
        {
            cout << "\t\tEnter the data of " << i + 1 << " movie.\n\n";
            cout << "Enter the name of movie....";
            cin >> moviename[i];
            cout << "Enter the starting and ending time of movie....";
            cin >> movietime[i];
            cout << "Enter the screentype of the movie....";
            cin >> screentype[i];
            cout << "Enter the category of movie...";
            cin >> moviecategory[i];
            cout << "Enter the ticket price of the movie...";
            cin >> ticketprice[i];
            cout << "\n\n\n";
        }
        admintotal = admintotal + enter;
        cout << "Congratulaions! Your data have been successfully entered.\n\n";
    }
    fstream file;
    file.open("admininterface.txt", ios::app);
    file << "MovieName\tTime\tScreentype\tcategory\tprice\n";
    for (int i = 0; i < admintotal; i++)
    {
        file << moviename[i] << "\t\t\t" << movietime[i] << "\t\t\t" << screentype[i] << "\t\t\t" << moviecategory[i] << "\t\t" << ticketprice[i];
        file << endl;
    }
    file.close();
}
void adminoption2()
{
    cout << "\t\tYou have entered option 2 to search movies.\n";
    cout << "Please enter the name of the movie to get complete data...";
    string enter;
    cin >> enter;
    for (int i = 0; i < admintotal; i++)
    {
        if (enter == moviename[i])
        {
            cout << "\t\t\tThe data of " << i + 1 << " movie is:\n"
                 << endl;
            cout << "Name:..." << moviename[i] << endl;
            cout << "Starting and Ending time:..." << movietime[i] << endl;
            cout << "Screentype:..." << screentype[i] << endl;
            cout << "Catogery:..." << moviecategory[i] << endl;
            cout << "Ticket Price:...." << ticketprice[i] << endl;
        }
    }
}
void adminoption3()
{
    cout << "\t\tYou have entered option 3 to update your showtimes.\n\n";
    cout << "Please enter the name of movie to update data...";
    string name;
    cin >> name;
    for (int i = 0; i < admintotal; i++)
    {
        if (name == moviename[i])
        {
            cout << "\t\t\t*Your previous data is*\n";
            cout << "\t\t\tThe data of " << i + 1 << " movie is:\n"
                 << endl;
            cout << "Name:..." << moviename[i] << endl;
            cout << "Starting and Ending time:..." << movietime[i] << endl;
            cout << "Screentype:..." << screentype[i] << endl;
            cout << "Catogery:..." << moviecategory[i] << endl;
            cout << "Ticket Price:...." << ticketprice[i] << endl;
            cout << "\n\n\n\n\n\t\t\t*Enter new record*\n";
            cout << "\t\tEnter the data of " << i + 1 << " movie.\n\n";
            cout << "Enter the name of movie........";
            cin >> moviename[i];
            cout << "Enter the starting and ending time of movie........";
            cin >> movietime[i];
            cout << "Enter the screentype of the movie........";
            cin >> screentype[i];
            cout << "Enter the category of movie.......";
            cin >> moviecategory[i];
            cout << "Enter the ticket price of the movie.......";
            cin >> ticketprice[i];
            cout << "\n\n\n\t\t\tCongratulations! Your data has been successfully updated.";
        }
    }
}
void adminoption4()
{
    cout << "\t\t\tYou have entered option 4 to delete showtimes.\n\n";
    cout << "Press 1 to delete complete data of showtime.\n";
    cout << "Press 2 to delete specific data of showtime by movie name.\n";
    int enter;
    cout << "Enter your choice...";
    cin >> enter;
    if (enter == 1)
    {
        admintotal = 0;
        cout << "\t\t\tCongratulations! Your complete data of showtimes has been deleted.";
    }
    else if (enter == 2)
    {
        cout << "Please eneter the name of movie to delete specific showtime...";
        string name;
        cin >> name;
        for (int i = 0; i < admintotal; i++)
        {
            if (name == moviename[i])
            {
                for (int j = i; j < admintotal; j++)
                {
                    moviename[j] = moviename[j + 1];
                    movietime[j] = movietime[j + 1];
                    screentype[j] = screentype[j + 1];
                    moviecategory[j] = moviecategory[j + 1];
                    ticketprice[j] = ticketprice[j + 1];
                }

                cout << "\t\t\tCongratulations! Your data has been successfully deleted.";
            }
        }
    }
}
void adminoption5()
{
    cout << "\t\t\tYou have entered option 5 to view the complete list of the showtimes of current day.\n\n";
    for (int i = 0; i < admintotal; i++)
    {
        cout << "\t\t\tThe data of " << i + 1 << " movie is:\n"
             << endl;
        cout << "Name:..." << moviename[i] << endl;
        cout << "Starting and Ending time:..." << movietime[i] << endl;
        cout << "Screentype:..." << screentype[i] << endl;
        cout << "Catogery:..." << moviecategory[i] << endl;
        cout << "Ticket Price:...." << ticketprice[i] << endl;
    }
}
string amenue()
{
    cout << "\t\t\tWelcome to cinema managment system\n\n\n";
    cout << "Press 1 view complete list of showtimes.\n";
    cout << "Press 2 to search movie by name.\n";
    cout << "Press 3 to book tickets.\n";
    cout << "Press 4 to view the tickets you have booked.\n";
    cout << "Press 5 to cancel the ticket you booked.\n";
    cout << "Press 6 to order food items.\n";
    cout << "Press 7 to view your food order.\n";
    cout << "Press 8 to update your food order.\n";
    cout << "Press 9 to get back to main menue.\n";
    cout << "Press 0 to load admin data from the file.\n";
    cout << "Press a to  load your book tickets from the file.\n";
    cout << "Press b to load your food items from the file.\n";
    string choice;
    cout << "\n\nEnter your choice...";
    cin >> choice;
    return choice;
}
void aoption1()
{
    cout << "\t\t\tYou have pressed 1 to view complete list of showtimes.\n\n";
    for (int i = 0; i < admintotal; i++)
    {
        cout << "\t\t\tThe data of " << i + 1 << " movie is:\n"
             << endl;
        cout << "Name:..." << moviename[i] << endl;
        cout << "Starting and Ending time:..." << movietime[i] << endl;
        cout << "Screentype:..." << screentype[i] << endl;
        cout << "Catogery:..." << moviecategory[i] << endl;
        cout << "Ticket Price:...." << ticketprice[i] << endl;
    }
}
void aoption2()
{
    cout << "\t\t\tYou have pressed 2 to search movie by name.\n\n";
    string enter;
    cout << "Enter the name of movie to search...";
    cin >> enter;
    for (int i = 0; i < admintotal; i++)
    {
        if (enter == moviename[i])
        {
            cout << "\t\t\tThe data of " << i + 1 << " movie is:\n"
                 << endl;
            cout << "Name:..." << moviename[i] << endl;
            cout << "Starting and Ending time:..." << movietime[i] << endl;
            cout << "Screentype:..." << screentype[i] << endl;
            cout << "Catogery:..." << moviecategory[i] << endl;
            cout << "Ticket Price:...." << ticketprice[i] << endl;
        }
    }
}
void aoption3()
{
    cout << "\t\tYou have chose option 3 to book tickets.\n\n";
    cout << "\t\tBe Alert!";
    cout << "You can book tickets according to avaliable data!\n\n";
    cout << "Enter how many tickets you want to book...";
    int enter;
    cin >> enter;
    if (bookticket == 0)
    {
        bookticket = bookticket + enter;
        for (int i = 0; i < enter; i++)
        {
            cout << "\t\tEnter the data of " << i + 1 << " show.\n\n";
            cout << "Enter the name of movie...";
            cin >> bookname[i];
            cout << "Enter the time...";
            cin >> booktime[i];
            cout << "Enter the screentype...";
            cin >> booktype[i];
            cout << "Enter the category...";
            cin >> bookcategory[i];
            cout << "\n\n\t\tCongratulations! Your ticket has been successfully reserved.\n\n";
        }
    }
    else
    {
        for (int i = bookticket; i < bookticket + enter; i++)
        {
            cout << "\t\tEnter the data of " << i + 1 << " show.\n\n";
            cout << "Enter the name of movie...";
            cin >> bookname[i];
            cout << "Enter the time...";
            cin >> booktime[i];
            cout << "Enter the screentype...";
            cin >> booktype[i];
            cout << "Enter the category...";
            cin >> bookcategory[i];
            cout << "\n\n\t\tCongratulations! Your ticket has been successfully reserved.\n\n";
        }
        bookticket = bookticket + enter;
    }
    fstream file;
    file.open("tickeetbook.txt", ios::app);
    file << "MovieName\tTime\tScreentype\tcategory\n";
    for (int i = 0; i < admintotal; i++)
    {
        file << bookname[i] << "\t\t\t" << booktime[i] << "\t\t\t" << booktype[i] << "\t\t\t" << bookcategory[i];
        file << endl;
    }
}
void aoption4()
{
    cout << "\t\t\tYou have entered option 4 to view the complete list of tickets you have booked.\n\n";
    for (int i = 0; i < bookticket; i++)
    {
        cout << "\t\t\tThe data of " << i + 1 << " show you booked is:\n"
             << endl;
        cout << "Name:..." << bookname[i] << endl;
        cout << "Starting and Ending time:..." << booktime[i] << endl;
        cout << "Screentype:..." << booktype[i] << endl;
        cout << "Catogery:..." << bookcategory[i] << endl;
    }
}
void aoption5()
{
    cout << "\t\t\tYou have entered option 5 to delete showtime you have booked.\n\n";
    cout << "Press 1 to delete complete data of showtime.\n";
    cout << "Press 2 to delete specific data of showtime by movie name.\n";
    int enter;
    cout << "Enter your choice...";
    cin >> enter;
    if (enter == 1)
    {
        bookticket = 0;
        cout << "\t\t\tCongratulations! Your complete data of booked showtime has been deleted.";
    }
    else if (enter == 2)
    {
        cout << "Please eneter the name of movie to cancel specific showtime...";
        string name;
        cin >> name;
        for (int i = 0; i < bookticket; i++)
        {
            if (name == bookname[i])
            {
                for (int j = i; j < bookticket; j++)
                {
                    bookname[j] = bookname[j + 1];
                    booktime[j] = booktime[j + 1];
                    booktype[j] = booktype[j + 1];
                    bookcategory[j] = bookcategory[j + 1];
                    bookprice[j] = bookprice[j + 1];
                }

                cout << "\t\t\tCongratulations! Your data has been successfully canceled.";
            }
        }
    }
}
void aoption6()
{
    cout << "\t\t\tYou have entered option six to order food items.\n\n";
    cout << "Enter how many food items you want to order...";
    int enter;
    cin >> enter;
    if (foodcount == 0)
    {
        foodcount = foodcount + enter;
        for (int i = 0; i < enter; i++)
        {
            cout << "\n\nEnter your desired food you want to order...";
            cin >> fooditems[i];
            cout << "\n\n\n";
        }
        cout << "Your order will be delivered shortly. Thanks for order!";
    }
    else
    {
        for (int i = foodcount; i < foodcount + enter; i++)
        {
            cout << "\n\nEnter your desired food you want to order...";
            cin >> fooditems[i];
            cout << "\n\n\n";
        }
        cout << "Your order will be delivered shortly. Thanks for order!";
        foodcount = foodcount + enter;
    }
    fstream file;
    file.open("fooditems.txt", ios::app);
    file << "Items\n";
    for (int i = 0; i < foodcount; i++)
    {
        file << fooditems[i];
        file << endl;
    }
}
void aoption7()
{
    cout << "\t\t\tYou have entered option seven to view your food orders.\n\n\n";
    for (int i = 0; i < foodcount; i++)
    {
        cout << "\t\tThe data of " << i + 1 << " order is given below.\n\n";
        cout << "Name of the food......" << fooditems[i] << "\n\n";
    }
    cout << "\n\n\n";
}
void aoption8()
{
    cout << "\t\t\tYou have entered option eight to update your food order.\n\n";
    string name;
    cout << "Enter the name of the food you want to change...";
    cin >> name;
    for (int i = 0; i < foodcount; i++)
    {
        if (name == fooditems[i])
        {
            cout << "\t\t Your previous order is given below.\n\n";
            cout << "Name of the food..." << fooditems[i];
            cout << "\n\n\n\t\t\t*Enter new order.\n\n\n";
            cout << "Enter the name of food...";
            cin >> fooditems[i];
            cout << "\t\t\tYour order has been successfully updated.";
        }
    }
}
