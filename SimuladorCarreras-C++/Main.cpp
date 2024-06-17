#include "iostream"
#include "conio.h"
#define N 5

using namespace System;
using namespace std;

void Consola() {
    Console::SetWindowSize(105, 40);
    Console::CursorVisible = false;
}
void Ubica(int x, int y) {
    Console::SetCursorPosition(x, y);
}
void Color(int c) {
    switch (c) {
    case 1:Console::ForegroundColor = ConsoleColor::Black;       break;
    case 2:Console::ForegroundColor = ConsoleColor::DarkBlue;    break;
    case 3:Console::ForegroundColor = ConsoleColor::DarkGreen;   break;
    case 4:Console::ForegroundColor = ConsoleColor::DarkRed;     break;
    case 5:Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    case 6:Console::ForegroundColor = ConsoleColor::DarkYellow;  break;
    case 7:Console::ForegroundColor = ConsoleColor::Gray;        break;
    case 8:Console::ForegroundColor = ConsoleColor::DarkGray;    break;
    case 9:Console::ForegroundColor = ConsoleColor::Blue;        break;
    case 10:Console::ForegroundColor = ConsoleColor::Green;      break;
    case 11:Console::ForegroundColor = ConsoleColor::Cyan;       break;
    case 12:Console::ForegroundColor = ConsoleColor::Red;        break;
    case 13:Console::ForegroundColor = ConsoleColor::Magenta;    break;
    case 14:Console::ForegroundColor = ConsoleColor::Yellow;     break;
    case 15:Console::ForegroundColor = ConsoleColor::White;      break;
    }
}
void Imprimir_Carro(int n) {
    for (int i = 0; i < n; i++) {
        cout << (char)220;
    }
}
void Borrar_Carro(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}




void LineaMeta(int ubi) {
    for (int i = 1; i < 39; i++) {
        if (i % 2 == 0) {
            Ubica(ubi - 1, i); Color(1); cout << (char)219;
            Ubica(ubi, i); Color(15); cout << (char)219;
        }
        else {
            Ubica(ubi - 1, i); Color(15); cout << (char)219;
            Ubica(ubi, i); Color(1); cout << (char)219;
        }
    }

}
void Borde() {
    Ubica(0, 0); Color(14); cout << (char)201;
    Ubica(0, 39); Color(14); cout << (char)200;
    Ubica(104, 0); Color(14); cout << (char)187;
    Ubica(104, 39); Color(14); cout << (char)188;
    for (int i = 1; i < 80; i++) {
        Ubica(i, 0); Color(14); cout << (char)205;
        Ubica(i, 39); Color(14); cout << (char)205;
    }
    for (int i = 81; i < 104; i++) {
        Ubica(i, 0); Color(14); cout << (char)205;
        Ubica(i, 39); Color(14); cout << (char)205;
    }
    for (int i = 1; i < 39; i++) {
        Ubica(0, i); Color(14); cout << (char)186;
        Ubica(104, i); Color(14); cout << (char)186;
    }
    Ubica(80, 0); Color(14); cout << (char)203;
    Ubica(80, 39); Color(14); cout << (char)202;
    for (int i = 1; i < 39; i++) {
        Ubica(80, i); Color(14); cout << (char)186;
    }

}
float Ran(int r) {
    switch (r) {
    case 1: return 1.0 + rand() / (RAND_MAX + 2.0); break;      //Velocidad
    case 2: return 2 + rand() % (2 - 5); break;                 //Tamaño
    case 3: return 2 + rand() % (3 - 15); break;                //Nro Color
    case 4: return 5 + rand() % (5 - 20); break;                //Nro de Vueltas
    case 5: return 5 + rand() % (5 - 33); break;                //Posi Y
    }
}



int main() {
    Consola();
    Borde();
    int limite = 73, vueltas, contador = 1;
    int cont0 = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
    bool carrera = true;
    string carros[N];
    carros[0] = "MC QUEEN";
    carros[1] = "DINOCO";
    carros[2] = "DOC HUDSON";
    carros[3] = "CHICK HICKS";
    carros[4] = "MATE";

    //Inicio Y
    int y0 = 5, y1 = 12, y2 = 19, y3 = 26, y4 = 33;
    srand(time(nullptr));

    float X[N], Y[N], dX[N], tam[N], color[N];
    color[0] = 12;      //Cuchau
    color[1] = 11;      //El Rey
    color[2] = 2;       //Doc Hucson
    color[3] = 10;      //Chick Hicks
    color[4] = 6;      //Mate
    for (int i = 0; i < N; i++) {
        X[i] = 2;
        Y[i] = Ran(5);
        dX[i] = Ran(1);
        tam[i] = Ran(2);
        vueltas = Ran(4);

        Ubica(X[i], Y[i]); Color(color[i]); Imprimir_Carro(tam[i]);
        LineaMeta(limite);

    }

    while (1) {
        Borde();
        for (int i = 0; i < N; i++) {
            Ubica(X[i], Y[i]); Color(1); Borrar_Carro(tam[i]);
            X[i] = X[i] + dX[i];
            Ubica(X[i], Y[i]); Color(color[i]); Imprimir_Carro(tam[i]);
            if (X[0] > limite) {
                Ubica(30, 20); Color(color[0]); cout << "GANADOR: MCQUEEN - CUCHAU" << endl; _getch();
                for (int i = 0; i < N; i++) {
                    X[i] = 2; dX[i] = Ran(1);
                    Y[i] = Ran(5);
                }

                Console::Clear();
                cont0++;
            }
            else if (X[1] > limite) {
                Ubica(30, 20); Color(color[1]); cout << "GANADOR: DINOCO - EL REY" << endl; _getch();
                for (int i = 0; i < N; i++) {
                    X[i] = 2; dX[i] = Ran(1);
                    Y[i] = Ran(5);
                }

                Console::Clear();
                cont1++;
            }
            else if (X[2] > limite) {
                Ubica(10, 20); Color(color[2]); cout << "GANADOR: DOC HUDSON - CONDUCES COMO SI ARREGLARAS LAS CARRETERAS" << endl; _getch();
                for (int i = 0; i < N; i++) {
                    X[i] = 2; dX[i] = Ran(1);
                    Y[i] = Ran(5);
                }

                Console::Clear();
                cont2++;
            }
            else if (X[3] > limite) {
                Ubica(15, 20); Color(color[3]); cout << "GANADOR: CHICK HICKS - LA COPA PISTON ES MIA" << endl; _getch();
                for (int i = 0; i < N; i++) {
                    X[i] = 2; dX[i] = Ran(1);
                    Y[i] = Ran(5);
                }

                Console::Clear();
                cont3++;
            }
            else if (X[4] > limite) {
                Ubica(15, 20); Color(color[4]); cout << "GANADOR: MATE - ME LLAMO MATE. ALGO ASI COMO TO-MATE" << endl; _getch();
                for (int i = 0; i < N; i++) {
                    X[i] = 2; dX[i] = Ran(1);
                    Y[i] = Ran(5);
                }
                Console::Clear();
                cont4++;
            }
        }

        LineaMeta(limite);
        if (cont0 + cont1 + cont2 + cont3 + cont4 == vueltas) {
            Console::Clear();
            carrera = false;
        }


        //Tabla posiciones
        Ubica(84, 2); Color(14); cout << "CORREDORES -  VEL";
        Ubica(81, 4); Color(color[0]); cout << (char)175 << " " << carros[0] << " - " << dX[0];
        Ubica(81, 5); Color(color[1]); cout << (char)175 << " " << carros[1] << " - " << dX[1];
        Ubica(81, 6); Color(color[2]); cout << (char)175 << " " << carros[2] << " - " << dX[2];
        Ubica(81, 7); Color(color[3]); cout << (char)175 << " " << carros[3] << " - " << dX[3];
        Ubica(81, 8); Color(color[4]); cout << (char)175 << " " << carros[4] << " - " << dX[4];
        Ubica(81, 14); Color(14); cout << "=======================";
        Ubica(89, 16); Color(14); cout << "VUELTAS";

        Ubica(81, 18); Color(color[0]); cout << (char)175 << " " << carros[0] << " - " << cont0;
        Ubica(81, 19); Color(color[1]); cout << (char)175 << " " << carros[1] << " - " << cont1;
        Ubica(81, 20); Color(color[2]); cout << (char)175 << " " << carros[2] << " - " << cont2;
        Ubica(81, 21); Color(color[3]); cout << (char)175 << " " << carros[3] << " - " << cont3;
        Ubica(81, 22); Color(color[4]); cout << (char)175 << " " << carros[4] << " - " << cont4;

        Ubica(81, 37); Color(14); cout << "=======================";
        Ubica(84, 38); Color(14); cout << "Nro de Vueltas: " << cont0 + cont1 + cont2 + cont3 + cont4;



        _sleep(1);
    }


    system("pause>0");
    return 0;
}

