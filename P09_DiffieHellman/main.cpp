#include <iostream>

int exp_rapida (int y, int b, int m){
    int x = 1;
    while((b>0) && (y>1)){
        if((b%2)==0){ // si es par
            y = (y * y) % m;
            b = b / 2;
        }
        else{ // si es impar
            x = (x * y) % m;
            b--;
        }
    }
    return x;
}

int main (){
    int p, alfa;
    int xa, xb, ya, yb;
    int ka, kb;

    std::cout << "> Número primo (p): ";
    std::cin >> p;

    do{
        std::cout << "> Número alfa (alfa<p): ";
        std::cin >> alfa;
    }while(alfa>p);

    std::cout << "> Secreto Xa: ";
    std::cin >> xa;

    std::cout << "> Secreto Xb: ";
    std::cin >> xb;

    ya = exp_rapida(alfa, xa, p);
    yb = exp_rapida(alfa, xb, p);

    std::cout << "[!] Ya: " << ya << std::endl << "[!] Yb: " << yb << std::endl;

    ka = exp_rapida(yb, xa, p);
    kb = exp_rapida(ya, xb, p);

    std::cout << "[!] K: " << ka << std::endl;
}