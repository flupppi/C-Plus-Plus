

//
// Created by Felix Kalchschmid on 26.03.2019.
//
#include <iostream>
#include <windows.h>
using namespace std;


wstring tetromino[7];
int nFieldWidth = 12;       //FieldWidth und Field heigth stellen die Abmaße eines Tetris Feld da.
int nFieldHeight = 18;
unsigned char *pField = nullptr;    //Dies wird Benötigt um die Ceerfelder
// sowie die einzelnen Buchstaben anzeigen zu können.

int nScreenWidth = 80;      //Console Screen Size X (columns)
int nScreenHeight = 30;     //Console Screen Size Y (rows)

/*Rotation - Wie kann man die Steine drehen?
 * Die Rotation funktioniert anhand der Anordnung des Arrays im Speicher.
 * Man muss die die einzelnen Speicherstellen je nach drehung durch eine
 * Berechnung jagen und bekommt so den korrekten neuen Platz.
 * px und py sind hier die Position x bzw. y
 */
int Rotate(int px, int py, int r) {
    switch (r % 4) {
        case 0: return py * 4 + px;         //0 degrees
        case 1: return 12 + py - (px * 4);  //90 degrees
        case 2: return 15 - (py * 4) - px;  //180 degrees
        case 3: return 3 - py + (px * 4);   //270 degrees
    }
    return 0;
}
//------------------------------------------------------------------------------------------------
int main() {
    // Create assets - Wie kann man einen Tetromino aus Buchstaben erstellen?
    tetromino[0].append(L"..X.");   //'append' bedeutet 'hinzufügen'
    tetromino[0].append(L"..X.");  //Hier wird ein Tetromino in einem Vier mal vier Array gebaut.
    tetromino[0].append(L"..X.");  // Es gibt 1 und 0 also hier X und .
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L"....");

    tetromino[2].append(L"..X.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"..XX");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"..X.");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L".X..");
    tetromino[5].append(L"....");

    tetromino[6].append(L"....");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L"..X.");
//-----------------------------------------------------------------------------------------------------------------------
    pField = new unsigned char[nFieldWidth*nFieldHeight]; // Create play field buffer
    for (int x = 0; x < nFieldWidth; x++) //Board Boundary
        for (int y = 0; y < nFieldHeight; y++)
            pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight -1) ? 9 : 0;
    /*Das Ziel ist es ein Spielfeld zu erstellen.
     *Der Code sagt: Solange x < der Breite des Feldes -> weiter addieren
     *               Solange y < der Höhe des Feldes -> weiter addieren
     *               Die Abfrage geht jetzt jeden Punkt in dem Spielfeld durch und Prüft ihn darauf,
     *               ob er im Spielfeld ist, oder ob er sich am rand oder Boden befindet.
     *               Ist er im Spielfeld bekommt er den Char Wert 0 zugewiesen, ist er am rand der Wert 9.
     */
//-------------------------------------------------------------------------------------------------------------------------
    /* Konsole als Ausgabe verwenden.
     *
     */
    wchar_t * screen = new wchar_t[nScreenWidth*nScreenHeight];
    for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;
//-------------------------------------------------------------------------------------------------------------------------
//Game Loop
    bool bGameOver = false;

    while (!bGameOver)
    {
        //Draw Field
        for (int x = 0; x < nFieldWidth; x++)
            for (int y = 0 ; y < nFieldHeight; y++)
                screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y*nFieldWidth + x ]];
    }
    // Display Frame
    WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);


    return 0;
};

#include "Tetris.h"

