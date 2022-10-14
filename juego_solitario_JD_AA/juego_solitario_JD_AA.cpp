#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#include "List.h"
#include <random>

using namespace std;
int revolver_baraja(vector<string> &ar_baraja, stack<string> &baraja_revuelta) {
    random_device rd;
    mt19937 g(rd());
    shuffle(ar_baraja.begin(), ar_baraja.end(), g);
    for (int i = 0; i < 52; i++) {
        baraja_revuelta.push(ar_baraja[i]);
    }
    return 0;
}
int llenar_pilas(stack<string> &pila_1, stack<string> &pila_2, stack<string> &pila_3, stack<string> &pila_4, stack<string> &pila_5, stack<string> &pila_6, stack<string> &pila_7, stack<string> &baraja_revuelta) {
    for (int i = 1; i <= 34; i++) {
        if (i == 1) {
            pila_1.push(baraja_revuelta.top());
            baraja_revuelta.pop();
        }
        else if (i > 1 && i < 4) {
            pila_2.push(baraja_revuelta.top());
            baraja_revuelta.pop();
        }
        else if (i > 4 && i < 8) {
            pila_3.push(baraja_revuelta.top());
            baraja_revuelta.pop();
        }
        else if (i > 8 && i < 13) {
            pila_4.push(baraja_revuelta.top());
            baraja_revuelta.pop();
        }
        else if (i > 13 && i < 19) {
            pila_5.push(baraja_revuelta.top());
            baraja_revuelta.pop();
        }
        else if (i > 19 && i < 26) {
            pila_6.push(baraja_revuelta.top());
            baraja_revuelta.pop();
        }
        else if (i > 26 && i < 34) {
            pila_7.push(baraja_revuelta.top());
            baraja_revuelta.pop();
        }
    }

    return 0;
}
stack<string> rellenar_espacios(stack<string> pila) {
    int sizeofpila = pila.size();
    int cuantos_respecto_filas = 7 - sizeofpila;
    stack<string> cartas;
    for (int i = 0; i < sizeofpila; i++) {
        cartas.push(pila.top());
        pila.pop();
    }
    for (int i = 0; i < cuantos_respecto_filas; i++) {
        pila.push("   ");
    }
    for (int i = 0; i < sizeofpila;i++) {
        pila.push(cartas.top());
        cartas.pop();
    }
    return pila;
}
stack<string> vuelta_pila(stack<string> pila) {
    stack<string> pila_tem;
    int size = pila.size();
    while(size > 0) {
        pila_tem.push(pila.top());
        pila.pop();
        size--;
    }
     return pila_tem;
}
void desplagar_baraja(stack<string> pila_1, stack<string> pila_2, stack<string> pila_3, stack<string> pila_4, stack<string> pila_5, stack<string> pila_6, stack<string> pila_7, stack<string> baraja_revuelta, string tab) {
    pila_1 = vuelta_pila(pila_1);
    pila_2 = vuelta_pila(pila_2);
    pila_3 = vuelta_pila(pila_3);
    pila_4 = vuelta_pila(pila_4);
    pila_5 = vuelta_pila(pila_5);
    pila_6 = vuelta_pila(pila_6);
    pila_7 = vuelta_pila(pila_7);
    pila_1 = rellenar_espacios(pila_1);
    pila_2 = rellenar_espacios(pila_2);
    pila_3 = rellenar_espacios(pila_3);
    pila_4 = rellenar_espacios(pila_4);
    pila_5 = rellenar_espacios(pila_5);
    pila_6 = rellenar_espacios(pila_6);
    pila_7 = rellenar_espacios(pila_7);
    
    int i = 0;
    cout << "MAZO: " << baraja_revuelta.top() << endl;
    cout << "G1" << "   " << "G2" << "   " << "G3" << "   " << "G4" << "   " << "G5" << "   " << "G6" << "   " << "G7" << endl << endl;
    while(i <= 7) {
        if (i == 1) {
            cout << pila_1.top() << tab << pila_2.top() << tab << pila_3.top() << tab << pila_4.top() << tab << pila_5.top() << tab << pila_6.top() << tab << pila_7.top() << tab << endl;
            pila_1.pop();pila_2.pop();pila_3.pop();pila_4.pop();pila_5.pop();pila_6.pop();pila_7.pop();
        }
        else if (i == 2) {
            cout << pila_1.top() << tab << pila_2.top() << tab << pila_3.top() << tab << pila_4.top() << tab << pila_5.top() << tab << pila_6.top() << tab << pila_7.top() << tab << endl;
            pila_1.pop();pila_2.pop();pila_3.pop();pila_4.pop();pila_5.pop();pila_6.pop();pila_7.pop();
        }
        else if (i == 3) {
            cout << pila_1.top() << tab << pila_2.top() << tab << pila_3.top() << tab << pila_4.top() << tab << pila_5.top() << tab << pila_6.top() << tab << pila_7.top() << tab << endl;
            pila_1.pop();pila_2.pop();pila_3.pop();pila_4.pop();pila_5.pop();pila_6.pop();pila_7.pop();
        }
        else if (i == 4) {
            cout << pila_1.top() << tab << pila_2.top() << tab << pila_3.top() << tab << pila_4.top() << tab << pila_5.top() << tab << pila_6.top() << tab << pila_7.top() << tab << endl;
            pila_1.pop();pila_2.pop();pila_3.pop();pila_4.pop();pila_5.pop();pila_6.pop();pila_7.pop();
        }
        else if (i == 5) {
            cout << pila_1.top() << tab << pila_2.top() << tab << pila_3.top() << tab << pila_4.top() << tab << pila_5.top() << tab << pila_6.top() << tab << pila_7.top() << tab << endl;
            pila_1.pop();pila_2.pop();pila_3.pop();pila_4.pop();pila_5.pop();pila_6.pop();pila_7.pop();
        }
        else if (i == 6) {
            cout << pila_1.top() << tab << pila_2.top() << tab << pila_3.top() << tab << pila_4.top() << tab << pila_5.top() << tab << pila_6.top() << tab << pila_7.top() << tab << endl;
            pila_1.pop();pila_2.pop();pila_3.pop();pila_4.pop();pila_5.pop();pila_6.pop();pila_7.pop();
        }
        else if (i == 7) {
            cout << pila_1.top() << tab << pila_2.top() << tab << pila_3.top() << tab << pila_4.top() << tab << pila_5.top() << tab << pila_6.top() << tab << pila_7.top() << tab << endl;
            pila_1.pop();pila_2.pop();pila_3.pop();pila_4.pop();pila_5.pop();pila_6.pop();pila_7.pop();
        }
        i++;
    }
}
stack<string> vaciar_pilas(stack<string> pila) {
    int size = pila.size();
    while(size > 0) {
        pila.pop();
        size--;
    }
    return pila;
}
int numero_carta(const char carta[], bool& dos_digitos) {
    int num;
    if (carta[1] == *"N" || carta[1] == *"R") {
        if (carta[0] == *"J") {
            num = 11;
        }
        else if (carta[0] == *"Q") {
            num = 12;
        }
        else if (carta[0] == *"K") {
            num = 13;
        }
        else if (carta[0] == *"A") {
            num = 1;
        }
        else {
            num = stoi(&carta[0]);
        }
    }
    else {
        dos_digitos = true;
        num = 10;
    }
    return num;
}
char carta_color(const char carta[], bool dos_digitos) {
    if (dos_digitos) {
        return carta[2];
    }
    else {
        return carta[1];
    }
}
void movimiento(stack<string> &pila_seleccionada, stack<string> &pila_a_mover, int &contador) {
    const char* carta_enviar = pila_seleccionada.top().c_str();;
    const char* carta_recibir = pila_a_mover.top().c_str();;
    string color_enviar, color_recibir;
    int num_enviar, num_recibir;
    bool dos_digitos_enviar = false, dos_digitos_recibir = false;
    num_enviar = numero_carta(carta_enviar, dos_digitos_enviar);
    num_recibir = numero_carta(carta_recibir, dos_digitos_recibir);
    color_enviar = carta_color(carta_enviar, dos_digitos_enviar);
    color_recibir = carta_color(carta_recibir, dos_digitos_recibir);

    if (num_enviar < num_recibir && color_enviar != color_recibir) {
        pila_a_mover.push(pila_seleccionada.top());
        pila_seleccionada.pop();
        contador++;
    }
    else {
        cout << "No se puede hacer el movimiento" << endl;
    }

}
int main()
{
    int i = 52;
    stack<string> baraja_revuelta;
    stack<string> pila_1, pila_2, pila_3, pila_4, pila_5, pila_6, pila_7;
    vector<string> ar_baraja = {"AN ", "AR ", "AR ", "AN ", "2N ", "2R ", "2R ", "2N ", "3N ", "3R ", "3R ", "3N ", "4N ", "4R ", "4R ", "4N ", "5N ", "5R ", "5R ", "5N ", "6N ", "6R ", "6R ", "6N ", "7N ", "7R ", "7R ", "7N ", "8N ", "8R ", "8R ", "8N ", "9N ", "9R ", "9R ", "9N ", "10N","10R","10R","10N", "JN ", "JR ", "JR ", "JN ", "QN ", "QR ", "QR ", "QN ", "KN ", "KR ", "KR ", "KN " };
    string R, R2;
    string tab = "  ";

    cout << "JUEGO SOLITARIO" << endl;
    cout << "Presiona \"R\" para revolver la baraja..." << endl;
    cin >> R;

    if (R == "R") {
        system("cls");
        revolver_baraja(ar_baraja, baraja_revuelta);
        llenar_pilas(pila_1, pila_2, pila_3, pila_4, pila_5, pila_6, pila_7, baraja_revuelta);
        desplagar_baraja(pila_1, pila_2, pila_3, pila_4, pila_5, pila_6, pila_7, baraja_revuelta, tab);
        do{
            cout << "Se revuelve de nuevo? \"si\" o \"no\" " << endl;
            cin >> R;
            if (R == "si") {
                system("cls");
                pila_1 = vaciar_pilas(pila_1);
                pila_2 = vaciar_pilas(pila_2);
                pila_3 = vaciar_pilas(pila_3);
                pila_4 = vaciar_pilas(pila_4);
                pila_5 = vaciar_pilas(pila_5);
                pila_6 = vaciar_pilas(pila_6);
                pila_7 = vaciar_pilas(pila_7);
                revolver_baraja(ar_baraja, baraja_revuelta);
                llenar_pilas(pila_1, pila_2, pila_3, pila_4, pila_5, pila_6, pila_7, baraja_revuelta);
                desplagar_baraja(pila_1, pila_2, pila_3, pila_4, pila_5, pila_6, pila_7, baraja_revuelta, tab);
            }
        } while (R != "no");
        system("cls");
        desplagar_baraja(pila_1, pila_2, pila_3, pila_4, pila_5, pila_6, pila_7, baraja_revuelta, tab);
        int pila1 = 0, pila2 = 0, pila3 = 0, pila4 = 0, pila5 = 0, pila6 = 0, pila7 = 0;
        //Intercambio de baraja
        do {
            cout << "Elija la columna de la carta a mover" << endl;
            cout << "Ejemplo: \"G1\"" << endl;
            cout << "Si desea escojer del mazo ingrese \"G0\"" << endl;
            cin >> R;
            cout << "Elija la columna donde quiere mover la carta" << endl;
            cout << "Ejemplo: \"G2\"" << endl;
            cin >> R2;
                if (R == "G0") {
                    if (R2 == "G1") {
                        movimiento(baraja_revuelta, pila_1, pila1);
                    }
                    else if (R2 == "G2") {
                        movimiento(baraja_revuelta, pila_2, pila2);
                    }
                    else if (R2 == "G3") {
                        movimiento(baraja_revuelta, pila_3, pila3);
                    }
                    else if (R2 == "G4") {
                        movimiento(baraja_revuelta, pila_4, pila4);
                    }
                    else if (R2 == "G5") {
                        movimiento(baraja_revuelta, pila_5, pila5);
                    }
                    else if (R2 == "G6") {
                        movimiento(baraja_revuelta, pila_6, pila6);
                    }
                    else if (R2 == "G7") {
                        movimiento(baraja_revuelta, pila_7, pila7);
                    }
                }
                else if (R == "G1") {
                    if (R2 == "G1") {
                        movimiento(pila_1, pila_1, pila1);
                    }
                    else if (R2 == "G2") {
                        movimiento(pila_1, pila_2, pila2);
                    }
                    else if (R2 == "G3") {
                        movimiento(pila_1, pila_3, pila3);
                    }
                    else if (R2 == "G4") {
                        movimiento(pila_1, pila_4, pila4);
                    }
                    else if (R2 == "G5") {
                        movimiento(pila_1, pila_5, pila5);
                    }
                    else if (R2 == "G6") {
                        movimiento(pila_1, pila_6, pila6);
                    }
                    else if (R2 == "G7") {
                        movimiento(pila_1, pila_7, pila7);
                    }
                }
                else if (R == "G2") {
                    if (R2 == "G1") {
                        movimiento(pila_2, pila_1, pila1);
                    }
                    else if (R2 == "G2") {
                        movimiento(pila_2, pila_2, pila2);
                    }
                    else if (R2 == "G3") {
                        movimiento(pila_2, pila_3, pila3);
                    }
                    else if (R2 == "G4") {
                        movimiento(pila_2, pila_4, pila4);
                    }
                    else if (R2 == "G5") {
                        movimiento(pila_2, pila_5, pila5);
                    }
                    else if (R2 == "G6") {
                        movimiento(pila_2, pila_6, pila6);
                    }
                    else if (R2 == "G7") {
                        movimiento(pila_2, pila_7, pila7);
                    }
                }
                else if (R == "G3") {
                    if (R2 == "G1") {
                        movimiento(pila_3, pila_1, pila1);
                    }
                    else if (R2 == "G2") {
                        movimiento(pila_3, pila_2, pila2);
                    }
                    else if (R2 == "G3") {
                        movimiento(pila_3, pila_3, pila3);
                    }
                    else if (R2 == "G4") {
                        movimiento(pila_3, pila_4, pila4);
                    }
                    else if (R2 == "G5") {
                        movimiento(pila_3, pila_5, pila5);
                    }
                    else if (R2 == "G6") {
                        movimiento(pila_3, pila_6, pila6);
                    }
                    else if (R2 == "G7") {
                        movimiento(pila_3, pila_7, pila7);
                    }
                }
                else if (R == "G4") {
                    if (R2 == "G1") {
                        movimiento(pila_4, pila_1, pila1);
                    }
                    else if (R2 == "G2") {
                        movimiento(pila_4, pila_2, pila2);
                    }
                    else if (R2 == "G3") {
                        movimiento(pila_4, pila_3, pila3);
                    }
                    else if (R2 == "G4") {
                        movimiento(pila_4, pila_4, pila4);
                    }
                    else if (R2 == "G5") {
                        movimiento(pila_4, pila_5, pila5);
                    }
                    else if (R2 == "G6") {
                        movimiento(pila_4, pila_6, pila6);
                    }
                    else if (R2 == "G7") {
                        movimiento(pila_4, pila_7, pila7);
                    }
                }
                else if (R == "G5") {
                if (R2 == "G1") {
                    movimiento(pila_5, pila_1, pila1);
                }
                else if (R2 == "G2") {
                    movimiento(pila_5, pila_2, pila2);
                }
                else if (R2 == "G3") {
                    movimiento(pila_5, pila_3, pila3);
                }
                else if (R2 == "G4") {
                    movimiento(pila_5, pila_4, pila4);
                }
                else if (R2 == "G5") {
                    movimiento(pila_5, pila_5, pila5);
                }
                else if (R2 == "G6") {
                    movimiento(pila_5, pila_6, pila6);
                }
                else if (R2 == "G7") {
                    movimiento(pila_5, pila_7, pila7);
                }
}
                else if (R == "G6") {
                if (R2 == "G1") {
                    movimiento(pila_6, pila_1, pila1);
                }
                else if (R2 == "G2") {
                    movimiento(pila_6, pila_2, pila2);
                }
                else if (R2 == "G3") {
                    movimiento(pila_6, pila_3, pila3);
                }
                else if (R2 == "G4") {
                    movimiento(pila_6, pila_4, pila4);
                }
                else if (R2 == "G5") {
                    movimiento(pila_6, pila_5, pila5);
                }
                else if (R2 == "G6") {
                    movimiento(pila_6, pila_6, pila6);
                }
                else if (R2 == "G7") {
                    movimiento(pila_6, pila_7, pila7);
                }
                }
                else if (R == "G7") {
                if (R2 == "G1") {
                    movimiento(pila_7, pila_1, pila1);
                }
                else if (R2 == "G2") {
                    movimiento(pila_7, pila_2, pila2);
                }
                else if (R2 == "G3") {
                    movimiento(pila_7, pila_3, pila3);
                }
                else if (R2 == "G4") {
                    movimiento(pila_7, pila_4, pila4);
                }
                else if (R2 == "G5") {
                    movimiento(pila_7, pila_5, pila5);
                }
                else if (R2 == "G6") {
                    movimiento(pila_7, pila_6, pila6);
                }
                else if (R2 == "G7") {
                    movimiento(pila_7, pila_7, pila7);
                }
                }
                if (pila1 == 5 || pila2 == 5 || pila3 == 5 || pila4 == 5 || pila5 == 5 || pila6 == 5 || pila7 == 5) {
                    cout << "Felicidades están tan solo que es buenísimo en solitario...… VICTORIA" << endl;
                }
            system("cls");
            desplagar_baraja(pila_1, pila_2, pila_3, pila_4, pila_5, pila_6, pila_7, baraja_revuelta, tab);
            cout << "Desea realizar otro movimiento \"si\" o \"no\"" << endl;
            cin >> R;
        } while (R != "no");
    }
    else {
        system("cls");
        cout << "Tu te pierdes del solitario -_- ..." << endl;
    }
    return 0;
}
