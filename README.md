#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    string isbn;
    bool issued;
};

int main()
{
    Book books[20];
    int totalBooks = 0;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Fine Calculation\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        cin.ignore();

        switch(choice)
        {
            case 1:
            {
                if(totalBooks >= 20)
                {
                    cout << "Library Full\n";
                    break;
                }

                cout << "Enter Book Title: ";
                getline(cin, books[totalBooks].title);

                cout << "Enter Author Name: ";
                getline(cin, books[totalBooks].author);

                cout << "Enter ISBN: ";
                getline(cin, books[totalBooks].isbn);

                books[totalBooks].issued = false;
                totalBooks++;

                cout << "Book Added Successfully\n";
                break;
            }

            case 2:
            {
                if(totalBooks == 0)
                {
                    cout << "No Books Available\n";
                    break;
                }

                cout << "\nBOOK LIST\n";

                for(int i = 0; i < totalBooks; i++)
                {
                    cout << "\nBook " << i + 1 << endl;
                    cout << "Title  : " << books[i].title << endl;
                    cout << "Author : " << books[i].author << endl;
                    cout << "ISBN   : " << books[i].isbn << endl;

                    if(books[i].issued)
                        cout << "Status : Issued\n";
                    else
                        cout << "Status : Available\n";
                }

                break;
            }

            case 3:
            {
                string key;
                bool found = false;

                cout << "Enter Title, Author or ISBN: ";
                getline(cin, key);

                for(int i = 0; i < totalBooks; i++)
                {
                    if(books[i].title == key ||
                       books[i].author == key ||
                       books[i].isbn == key)
                    {
                        cout << "\nBook Found\n";
                        cout << "Title  : " << books[i].title << endl;
                        cout << "Author : " << books[i].author << endl;
                        cout << "ISBN   : " << books[i].isbn << endl;
                        found = true;
                    }
                }

                if(!found)
                {
                    cout << "Book Not Found\n";
                }

                break;
            }

            case 4:
            {
                string isbn;
                bool found = false;

                cout << "Enter ISBN to Issue Book: ";
                getline(cin, isbn);

                for(int i = 0; i < totalBooks; i++)
                {
                    if(books[i].isbn == isbn)
                    {
                        found = true;

                        if(books[i].issued)
                        {
                            cout << "Book Already Issued\n";
                        }
                        else
                        {
                            books[i].issued = true;
                            cout << "Book Issued Successfully\n";
                        }
                    }
                }

                if(!found)
                {
                    cout << "Book Not Found\n";
                }

                break;
            }

            case 5:
            {
                string isbn;
                bool found = false;

                cout << "Enter ISBN to Return Book: ";
                getline(cin, isbn);

                for(int i = 0; i < totalBooks; i++)
                {
                    if(books[i].isbn == isbn)
                    {
                        found = true;

                        if(!books[i].issued)
                        {
                            cout << "Book Already Available\n";
                        }
                        else
                        {
                            books[i].issued = false;
                            cout << "Book Returned Successfully\n";
                        }
                    }
                }

                if(!found)
                {
                    cout << "Book Not Found\n";
                }

                break;
            }

            case 6:
            {
                int lateDays;
                double fine;

                cout << "Enter Number of Late Days: ";
                cin >> lateDays;

                if(lateDays <= 0)
                {
                    fine = 0;
                }
                else
                {
                    fine = lateDays * 5;
                }

                cout << "Fine Amount = Rs. " << fine << endl;
                break;
            }

            case 7:
            {
                cout << "Program Ended\n";
                break;
            }

            default:
            {
                cout << "Invalid Choice\n";
            }
        }

    } while(choice != 7);

    return 0;
} 
