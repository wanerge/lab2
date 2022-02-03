#include "funciones.h"

void problema1()
{
    unsigned int dinero = 0;
    int arreglo_int[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    cout << "Ingrese una cantidad de dinero: ";
    cin >> dinero;
    for (unsigned short int i = 0; i < 10 ; i++) {
        cout << arreglo_int[i] << " : " << dinero/arreglo_int[i] << endl;
        dinero = (dinero%arreglo_int[i]);
    }
    cout << "Faltante: " << dinero << endl;
}

void problema2()
{
    char let;
    short int array_alf[26] = {0};
    for (unsigned char i = 0; i < 200 ; i++ ) {
        let = rand() % 26 + 65;
        cout << let;
        ++array_alf[int(let)-65];
    }
    cout << "\n";
    for (unsigned char i = 0; i < 26 ; i++) {
        cout << char(i+65) << ": " << array_alf[i] << endl;
    }
}

void problema3()
{
    unsigned short int cont = 100;
    char *cadena1 = new char[cont]{0}, *cadena2 = new char[cont]{0};

    cin.ignore();
    cout << "Ingrese la primera cadena: ";
    entrada_caracteres(cadena1, cont);
    cout << "Ingrese la segunda cadena: ";
    entrada_caracteres(cadena2, cont);

    cout << cadena1 << "\n" << cadena2 << endl;

    cont = 0;
    while (true) {
        if (cadena1[cont] == '\0' && cadena2[cont] == '\0') {
            cout << "Las cadenas si son iguales" << endl;
            break;
        }
        else if (cadena1[cont] == '\0' || cadena2[cont] == '\0') {
            cout << "Las cadenas no son iguales" << endl;
            break;
        }
        else if (cadena1[cont] != cadena2[cont]) {
            cout << "Las cadenas no son iguales" << endl;
            break;
        }
        cont++;
    }

    delete [] cadena1;
    delete [] cadena2;
}

void problema4()
{
    unsigned short int num2 = 20;
    long long int num3 = 0;
    char *cadena1 = new char[num2]{0}, signo = 1;

    cin.ignore();
    cout << "Ingrese la cadena de numeros: ";
    entrada_caracteres(cadena1, num2);

    num2 = 0;
    if (cadena1[num2] == '-') {
        num2++;
        signo = 2;
    }
    while (cadena1[num2] != 0) {
        if (cadena1[num2] >= 48 && cadena1[num2] <= 57) {
            num3 *= 10;
            num3 += (cadena1[num2]-48);
        }
        else {
            cout << "La cadena contiene caracteres no validos" << endl;
            signo = 0;
            break;
        }
        num2++;
    }
    if (signo == 2) {
        num3 *= -1;
    }
    if (signo != 0) {
        cout << num3 << endl;
    }

    delete [] cadena1;
}

void problema5()
{
    unsigned short int cont = 0;
    long long int num = 0;
    char *cadena = new char[20]{0};

    cout << "Ingrese un numero: ";
    cin >> num;

    if (num < 0) {
        num *= -1;
        cadena[cont] = '-';
        cont++;
    }

    for (; num > 0 ; num /= 10, cont++ ) {
        cadena[cont] = ((num%10)+48);
    }

    for (int i = 0, temp; i < cont ; i++, cont--) {
        if (cadena[i] != '-') {
            temp = cadena[cont-1];
            cadena[cont-1] = cadena[i];
            cadena[i] = temp;
        }
        else {
            cont++;
        }
    }

    cout << cadena << endl;

    delete [] cadena;
}

void problema6()
{
    char *cadena = new char[100]{0};

    cin.ignore();
    cout << "Ingrese la cadena de caracteres: ";
    entrada_caracteres(cadena, 100);

    cout << endl << "Original: " << cadena << ". " << "En mayuscula: ";

    for (unsigned int i = 0 ; cadena[i] != 0 ; i++ ) {
        if (cadena[i] >= 97 && cadena[i] <= 122) {
            cadena[i] = (cadena[i]-32);
        }
    }

    cout << cadena << endl;

    delete [] cadena;
}

void problema7()
{
    unsigned short int num = 100;
    char *cadena = new char[num]{0}, *cadena2 = new char[27]{0};

    cin.ignore();
    cout << "Ingrese la cadena de caracteres: ";
    entrada_caracteres(cadena, num);

    for (unsigned short int i = 0; cadena[i] != 0 ; i++ ) {
        for (unsigned short int j = 0; j < 26 ; j++) {
            if(cadena[i] == cadena2[j]){
                break;
            }
            else if (cadena2[j] == 0) {
                cadena2[j] = cadena[i];
                break;
            }
        }
    }

    cout << endl << "Original: " << cadena << ". " << "Sin repetidos: " << cadena2 << endl;

    delete [] cadena;
    delete [] cadena2;
}

void problema8()
{
    unsigned short int num = 150;
    char *cadena = new char[num]{0}, *cadena2 = new char[num]{0};

    cin.ignore();
    cout << "Ingrese la cadena de caracteres: ";
    entrada_caracteres(cadena, num);

    cout << "\nOriginal: " << cadena << endl;

    for (unsigned short int i = 0, cont = 0; cadena[i] != 0 ; i++ ) {
        if (cadena[i] >= 48 && cadena[i] <= 57) {
            cadena2[cont] = cadena[i];
            cont++;
            for (unsigned short int j = i; j < num; j++ ) {
                cadena[j] = cadena[j+1];
            }
            i--;
        }
    }

    cout << "Texto: " << cadena << ". Numero: " << cadena2 << endl;

    delete [] cadena;
    delete [] cadena2;
}

void problema9()
{
    int suma = 0, num_aux = 1, val_suma = 0;
    unsigned short int num = 0, num2 = 100;
    char *cadena = new char[num2]{0};

    cout << "Ingrese un numero: ";
    cin >> num;

    cin.ignore();
    cout << "Ingrese la cadena de caracteres: ";
    entrada_caracteres(cadena, num2);

    for (short int i = (num2-1), cont = 0; i > -1 ; i-- ) {
        if (cadena[i] != 0) {
            val_suma += ((cadena[i]-48)*num_aux);
            cont++;
            if (cont == num || i == 0) {
                cont = 0;
                num_aux = 1;
                suma += val_suma;
                val_suma = 0;
            }
            else {
                num_aux *= 10;
            }
        }
    }

    cout << "\nOriginal: " << cadena << "\nSuma: " << suma << endl;

    delete [] cadena;
}

void problema10()
{
    bool carac_inco = false;
    int suma = 0;
    unsigned short int num2 = 50, num_romanos[7] = {1, 5, 10, 50, 100, 500, 1000};
    char *cadena = new char[num2]{0};

    cin.ignore();
    cout << "Ingrese un numero en sistema romano: ";
    entrada_caracteres(cadena, num2);

    cout << "\nEl numero ingresado fue: " << cadena << endl;

    for (unsigned short int i = 0; cadena[i] != 0 ; i++ ) {
        switch (cadena[i]) {
            case 'M':
                cadena[i] = 7;
            break ;

            case 'D':
                cadena[i] = 6;
            break ;

            case 'C':
                cadena[i] = 5;
            break ;

            case 'L':
                cadena[i] = 4;
            break ;

            case 'X':
                cadena[i] = 3;
            break ;

            case 'V':
                cadena[i] = 2;
            break ;

            case 'I':
                cadena[i] = 1;
            break ;

            default:
                carac_inco = true;
            break;
        }
        if (carac_inco == true) {
            cout << "Numero no valido." << endl;
            break;
        }
    }
    if (carac_inco == false) {
        for (unsigned short int i = 0; cadena[i] != 0 ; i++ ) {
            if (cadena[i+1] != 0) {
                if (cadena[i+1] <= cadena[i]) {
                    suma += num_romanos[cadena[i]-1];
                }
                else {
                    suma -= num_romanos[cadena[i]-1];
                }
            }
            else {
                suma += num_romanos[cadena[i]-1];
            }
        }
        cout << "Que corresponde a: " << suma << endl;
    }

    delete [] cadena;
}

void problema11()
{
    unsigned short int num = 0;
    char **sala = new char*[15]{0}, num2 = 0;

    for (int i = 0; i < 15 ;i++ ) {
        *(sala + i) = new char[20]{0};
    }

    iniciar_matriz(sala, 15, 20, '-');
    while (true) {
        system("CLS");
        cout << "     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20" << endl;
        mostrar_matriz(sala, 15, 20, true);
        cout << "Ingrese la fila entre[A-O] o ingrese el 0 para salir: ";
        cin >> num2;
        cout << "Ingrese la columna entre[1-20] o ingrese el 0 para salir: ";
        cin >> num;
        if ((num2 == '0') || (num == 0)) {
            break;
        }
        else {
            if ((num2 >= 'A' && num2 <= 'O') && (num >= 1 && num <= 20)) {
                if (sala[num2-65][num-1] == '+') {
                    sala[num2-65][num-1] = '-';
                }
                else {
                    sala[num2-65][num-1] = '+';
                }
            }
            else {
                cout << "Dato no valido" << endl;
                system("pause");
            }
        }
    }

    for (int i = 0; i < 15 ;i++ ) {
        delete [] *(sala + i);
    }
    delete [] sala;
}

void problema12()
{
    bool eleccion = true;
    unsigned short int num = 0, **cuadrado_mag = NULL, num2;
    cout << "Ingrese el numero de filas del cuadrado: ";
    cin >> num;
    cuadrado_mag = new unsigned short int*[num]{0};
    for (int i = 0; i < num ;i++ ) {
        *(cuadrado_mag + i) = new unsigned short int[num]{0};
    }

    mostrar_matriz(cuadrado_mag, num, num, false);

    for (unsigned short int i = 0; i < num ;i++ ) {
        for (unsigned short int j = 0; j < num ;j++ ) {
            cout << "Ingrese numero para la fila (" << (i+1) << ") y columna (" << (j+1) << "): ";
            cin >> num2;
            for (unsigned short int k = 0; k <= i ;k++) {
                for (unsigned short int l = 0; l < num ;l++ ) {
                    if (cuadrado_mag[k][l] == num2) {
                        eleccion = false;
                        break;
                    }
                }
                if (!eleccion) {
                    break;
                }
            }
            cuadrado_mag[i][j] = num2;
            system("CLS");
            mostrar_matriz(cuadrado_mag, num, num, false);
            if (!eleccion) {
                break;
            }
        }
        if (!eleccion) {
            break;
        }
    }

    if (eleccion) {
        eleccion = validar_cuadrado(cuadrado_mag, num);
    }

    if (eleccion) {
        cout << "La matriz es un cuadrado magico" << endl;
    }
    else {
        cout << "La matriz no es un cuadrado magico" << endl;
    }

    for (int i = 0; i < num ;i++ ) {
        delete [] *(cuadrado_mag + i);
    }
    delete [] cuadrado_mag;
}

void problema13()
{
    unsigned short int **matriz_gal = NULL, filas = 0, columnas, cont = 0, sum = 0;
    filas = rand() % 17 + 4;
    columnas = rand() % 17 + 4;
    matriz_gal = new unsigned short int*[filas]{0};

    for (int i = 0; i < filas ;i++ ) {
        *(matriz_gal + i) = new unsigned short int[columnas]{0};
    }

    for (unsigned short int i = 0; i < filas ;i++ ) {
        for (unsigned short int j = 0; j < columnas ;j++ ) {
            matriz_gal[i][j] = rand() % 16;
        }
    }

    system("CLS");
    mostrar_matriz(matriz_gal, filas, columnas, false);

    for (unsigned short int i = 0; i < filas ;i++ ) {
        for (unsigned short int j = 0; j < columnas ;j++ ) {
            if (i != 0 && j != 0 && i != (filas-1) && j != (columnas-1)) {
                sum = matriz_gal[i][j]+matriz_gal[i-1][j]+matriz_gal[i+1][j]+matriz_gal[i][j-1]+matriz_gal[i][j+1];
                sum /= 5;
                if (sum > 6) {
                    cont++;
                }
            }
        }
    }

    cout << "\nNumero de estrellas encontradas en la imagen: " << cont << endl;

    for (int i = 0; i < filas ;i++ ) {
        delete [] *(matriz_gal + i);
    }
    delete [] matriz_gal;
}

void problema14()
{
    unsigned short int **matriz = NULL, tam = 5;
    matriz = new unsigned short int*[tam]{0};

    for (int i = 0; i < tam ;i++ ) {
        *(matriz + i) = new unsigned short int[tam]{0};
    }

    for (unsigned short int i = 0, cont = 0; i < tam ;i++ ) {
        for (unsigned short int j = 0; j < tam ;j++ ) {
            cont++;
            matriz[i][j] = cont;
        }
    }

    system("CLS");
    cout << "Matriz Original" << endl;
    mostrar_matriz(matriz, tam, tam, false);

    for (unsigned short int i = 1; i < 4 ;i++ ) {
        rotar_matriz(matriz, tam);
        cout << "\nMatriz rotada " << 90*i << endl;
        mostrar_matriz(matriz, tam, tam, false);
    }

    for (int i = 0; i < tam ;i++ ) {
        delete [] *(matriz + i);
    }
    delete [] matriz;
}

void problema15()
{
    unsigned short int *vector1 = new unsigned short int[4]{0}, *vector2 = new unsigned short int[4]{0};

    for (int i = 1; i < 3 ;i++ ) {
        for (int j = 0; j < 4 ;j++ ) {
            switch (j) {
                case 0:
                    cout << "Ingrese la posicion X del vector " << i << ": ";
                break;
                case 1:
                    cout << "Ingrese la posicion Y del vector " << i << ": ";
                break;
                case 2:
                    cout << "Ingrese el ancho del vector " << i << ": ";
                break;
                case 3:
                    cout << "Ingrese el alto del vector " << i << ": ";
                break;
            }
            switch (i) {
                case 1:
                    cin >> vector1[j];
                break;
                case 2:
                    cin >> vector2[j];
                break;
            }
        }
    }

    interseccion_vectores(vector1, vector2);

    delete [] vector1;
    delete [] vector2;
}




void entrada_caracteres(char *cadena, unsigned short longitud)
{
    cin.get(cadena, longitud);
    cin.sync();
}

void iniciar_matriz(char **matriz, unsigned short filas, unsigned short colum, char valor_ini)
{
    for (unsigned short int i = 0; i < filas ;i++ ) {
        for (unsigned short int j = 0; j < colum ;j++ ) {
            matriz[i][j] = valor_ini;
        }
    }
}

template <typename T>
void mostrar_matriz(T **matriz, unsigned short filas, unsigned short colum, bool guia)
{
    int cop_colum = (colum*4)+1;
    cout << "   _";
    for (unsigned short int j = 0; j < (cop_colum-1) ;j++ ) {
        cout << "_";
    }
    for (unsigned short int i = 0; i < filas ;i++ ) {
        if (guia) {
            cout << endl << char(i+65) << "  | ";
        }
        else {
            cout << endl << "   | ";
        }
        for (unsigned short int j = 0; j < colum ;j++ ) {
            cout << matriz[i][j] << " | ";

        }
        cout << endl << "   _";
        for (unsigned short int j = 0; j < (cop_colum-1) ;j++ ) {
            cout << "_";
        }
    }
    cout << endl;
}

bool validar_cuadrado(unsigned short **matriz, unsigned short tam)
{
    bool val = true;
    unsigned short int *fila = NULL, *columna = NULL, diag[2] = {0,0};
    fila = new unsigned short int[tam]{0};
    columna = new unsigned short int[tam]{0};

    for (unsigned short int i = 0; i < tam ;i++ ) {
        for (unsigned short int j = 0; j < tam ;j++ ) {
            fila[i] += matriz[i][j];
            columna[j] += matriz[i][j];
            if (i == j) {
                diag[0] += matriz[i][j];
            }
            if ((i+j) == (tam-1)) {
                diag[1] += matriz[i][j];
            }
        }
    }

    for (unsigned short int i = 0, num_ver = fila[0]; i < tam ;i++ ) {
        if (fila[i] != num_ver || columna[i] != num_ver) {
            val = false;
            break;
        }
    }

    if (diag[0] != fila[0] || diag[1] != fila[0]) {
        val = false;
    }

    delete [] fila;
    delete [] columna;

    return val;
}

template<typename R>
void rotar_matriz(R **matriz, unsigned short int tam)
{
    for (unsigned short int i = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0; i < (tam-i) ;++i ) {
        for (unsigned short int j = i; j < (tam-i-1) ;++j) {
            num1 = i;
            num2 = j;
            for (unsigned short int k = 2; k < tam ;k++) {
                num3 = (tam-num2-1);
                num4 = matriz[num1][num2];
                matriz[num1][num2] = matriz[num3][num1];
                matriz[num3][num1] = num4;
                num2 = num1;
                num1 = num3;
            }
        }
    }
}

void interseccion_vectores(unsigned short int *vector1, unsigned short int *vector2)
{
    bool intersec = true;
    unsigned short int vector3[4] = {0,0,0,0}, vec1_pfinal[2] = {0,0}, vec2_pfinal[2] = {0,0};
    vec1_pfinal[0] = (vector1[0]+vector1[2]);
    vec1_pfinal[1] = (vector1[1]+vector1[3]);
    vec2_pfinal[0] = (vector2[0]+vector2[2]);
    vec2_pfinal[1] = (vector2[1]+vector2[3]);

    if ((vector1[0] <= vector2[0] && vector1[1] <= vector2[1]) && (vec1_pfinal[0] >= vec2_pfinal[0] && vec1_pfinal[1] >= vec2_pfinal[1])) {
        vector3[0] = vector2[0];
        vector3[1] = vector2[1];
        vector3[2] = vector2[2];
        vector3[3] = vector2[3];
    }
    else if ((vector1[0] > vector2[0] && vector1[1] > vector2[1]) && (vec1_pfinal[0] < vec2_pfinal[0] && vec1_pfinal[1] < vec2_pfinal[1])) {
        vector3[0] = vector1[0];
        vector3[1] = vector1[1];
        vector3[2] = vector1[2];
        vector3[3] = vector1[3];
    }
    else if (vector1[0] <= vec2_pfinal[0] && vector1[1] <= vec2_pfinal[1]) {
        if (vector2[0] <= vec1_pfinal[0] && vector2[1] <= vec1_pfinal[1]) {

            if (vector1[0] <= vector2[0]) {
                vector3[0] = vector2[0];
                vector3[2] = vec1_pfinal[0]-vector2[0];
            }
            else {
                vector3[0] = vector1[0];
                vector3[2] = vec2_pfinal[0]-vector1[0];
            }

            if (vector1[1] <= vector2[1]) {
                vector3[1] = vector2[1];
                vector3[3] = vec1_pfinal[1]-vector2[1];
            }
            else {
                vector3[0] = vector1[0];
                vector3[2] = vec2_pfinal[1]-vector1[1];
            }
        }
        else {
            intersec = false;
        }
    }
    else if (vector2[0] <= vec1_pfinal[0] && vector2[1] <= vec1_pfinal[1]) {
        if (vector1[0] <= vec2_pfinal[0] && vector1[1] <= vec2_pfinal[1]) {
            vector3[0] = vec2_pfinal[0]-vector1[0];
            vector3[1] = vec2_pfinal[1]-vector1[1];
            vector3[0] = vec2_pfinal[0]-vector1[0];
            vector3[1] = vec2_pfinal[1]-vector1[1];
        }
        else {
            intersec = false;
        }
    }
    else {
        intersec = false;
    }

    if (!intersec) {
        cout << "Los vectores no se intersecan" << endl;
    }

}











