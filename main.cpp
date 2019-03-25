#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;  //Diese Programm gibt "Hello, World!" auf der Konsole aus.
    int einkommen(100);
    std::cout << einkommen << std::endl;        //Der Wert der Variable Einkommen wird auf das Standart out ausgegeben.
                {
                    int einkommen(300);
                    std::cout << einkommen << std::endl;
                }
    std::cout << einkommen << std::endl;
    return 0;                                   // Das Programm beendet sich mit dem Exit Code 0.
}