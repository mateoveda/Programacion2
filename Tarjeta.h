#include <iostream>
#include <string>
using namespace std;

class Tarjeta{
private:
    int limite;
    string tipo_t;

public:
    Tarjeta();

    void tarjeta_oro();
    void tarjeta_black();

    void setLimite(int);
    void setTipoT(string);

    int getLimite();
    string getTipoT();
};
