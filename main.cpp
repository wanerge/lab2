#include "funciones.h"

int main()
{
    unsigned short int problem = 0;
    do {
        system("CLS");
        cout << "Ingrese el problema a revisar(1-18): ";
        cin >> problem;
        switch (problem) {
            case 1:
                problema1();
            break;

            case 2:
                problema2();
            break;

            case 3:
                problema3();
            break;

            case 4:
                problema4();
            break;

            case 5:
                problema5();
            break;

            case 6:
                problema6();
            break;

            case 7:
                problema7();
            break;

            case 8:
                problema8();
            break;

            case 9:
                problema9();
            break;

            case 10:
                problema10();
            break;

            case 11:
                problema11();
            break;

            case 12:
                problema12();
            break;

            case 13:
                problema13();
            break;

            case 14:
                problema14();
            break;

            case 15:
                problema15();
            break;

            case 16:
            break;

            case 17:
            break;

            case 18:
            break;
        }
        if (problem != 0) {
            system("pause");
        }
    } while (problem != 0);

    return 0;
}
