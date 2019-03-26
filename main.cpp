#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;  //Diese Programm gibt "Hello, World!" auf der Konsole aus.
    int einkommen(100);
    std::cout << einkommen << std::endl;        //Der Wert der Variable Einkommen wird auf das Standart out ausgegeben.
                {
                    int einkommen(300);
                    std::cout << einkommen << std::endl;
                }
                char issigned;                  //Char gibt die möglichkeit ein zeichen aus der Ascii Tabelle anzuzeigen indem man eine Zahl eingibt.
                unsigned char notsigned;

    issigned = 254;
    notsigned = 254;
    std::cout << issigned << std::endl;
    std::cout << notsigned << std::endl;

    std::cout << sizeof(char32_t)  << std::endl;        //gibt den vom System genutzen Speicherplatz für den eingegebenen Datentyp aus.
    return 0;                                   // Das Programm beendet sich mit dem Exit Code 0.
}