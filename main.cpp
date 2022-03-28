#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial12x12.h"
#include "Arial24x23.h"
#include "Arial28x28.h"
#include "font_big.h"
#include "UTouch.h"
#include "stdio.h"

float x = 0, y = 0;
int tecla = 0;
int xInt, yInt;
bool isRunning = false;

// the TFT is connected to SPI pin 5-7
SPI_TFT_ILI9341 TFT(D11, D12, D13, D8, D10, D9, "TFT");
// mosi, miso, sclk, cs, reset, dc ......................ojo reset a 3.3 v
UTouch myTouch(A0, A1, D7, D5, D4);
// PinName tclk, PinName tcs, PinName tdin, PinName dout, PinName irq ojo esta para kl25Z funcional

// Prototipo de funciones

void load();
void welcome();
void tecladoAlfa();
int teclear(float x, float y);

int main()
{

    TFT.claim(stdout); // arranca el stdout de la TFT
    TFT.set_orientation(0);
    TFT.background(Red);   // set background to red
    TFT.foreground(White); // set chars to white
    TFT.cls();             // clear the screen

    // first show the 4 directions
    TFT.set_orientation(2);
    TFT.cls();

    myTouch.InitTouch();
    myTouch.SetPrecision(PREC_LOW);

    // tecladoAlfa();
    welcome();

    /*
    while(true) {

        if (myTouch.DataAvailable()) {
            if(myTouch.Read()) {
                x = myTouch.GetX(); // toma x del touch
                y = myTouch.GetY(); // toma y del touch
                TFT.locate(60,10);
                xInt = (int)x;
                yInt = (int)y;
                TFT.printf("%d , %d  ", xInt, yInt);
                TFT.locate(110,60);
                tecla = teclear(x,y);

                if(tecla==42) {
                    TFT.printf("*  ");
                } else if (tecla==35) {
                    TFT.printf("#  ");
                } else {
                    TFT.printf("%d   ",tecla);
                }
            }
        }
    }*/
}

//////Definición de funviones

int teclear(float x, float y)
{
    int a = 0;
    /////////////1
    if (y > 0 && x > 44 && y < 33 && x < 69)
    {
        return 1;
    }
    /////////////2
    if (y > 33 && x > 44 && y < 66 && x < 69)
    {
        return 2;
    }
    /////////////3
    if (y > 66 && x > 44 && y < 100 && x < 69)
    {
        return 3;
    }
    /////////////4
    if (y > 0 && x > 69 && y < 33 && x < 94)
    {
        return 4;
    }
    /////////////5
    if (y > 33 && x > 69 && y < 66 && x < 94)
    {
        return 5;
    }
    /////////////6
    if (y > 66 && x > 69 && y < 100 && x < 94)
    {
        return 6;
    }

    /////////////7
    if (y > 0 && x > 94 && y < 33 && x < 119)
    {
        return 7;
    }
    /////////////8
    if (y > 33 && x > 94 && y < 66 && x < 119)
    {
        return 8;
    }
    /////////////9
    if (y > 66 && x > 94 && y < 100 && x < 119)
    {
        return 9;
    }
    /////////////0
    if (y > 33 && x > 119 && y < 66 && x < 144)
    {
        return 0;
    }
    /////////////#
    if (y > 66 && x > 119 && y < 100 && x < 144)
    {
        return 35;
    }
    /////////////*
    if (y > 0 && x > 119 && y < 33 && x < 144)
    {
        return 42;
    }
    return 219;
}

void tecladoAlfa()
{
    // Dibibujo del cuadrado

    TFT.fillrect(0, 0, 240, 320, Red);
    TFT.rect(2, 2, 238, 102, White);
    TFT.rect(3, 3, 237, 101, White);
    TFT.rect(2, 106, 238, 319, White);

    TFT.line(80, 106, 80, 319, White);
    TFT.line(160, 106, 160, 319, White);
    TFT.line(160, 106, 160, 319, White);
    TFT.line(240, 106, 240, 319, White);

    TFT.line(2, 160, 238, 160, White);
    TFT.line(2, 214, 238, 214, White);
    TFT.line(2, 268, 238, 268, White);

    // Los números

    TFT.set_font((unsigned char *)Arial28x28);
    TFT.locate(30, 120);
    printf("1");
    TFT.locate(110, 120);
    printf("2");
    TFT.locate(190, 120);
    printf("3");

    TFT.locate(30, 174);
    printf("4");
    TFT.locate(110, 174);
    printf("5");
    TFT.locate(190, 174);
    printf("6");

    TFT.locate(30, 228);
    printf("7");
    TFT.locate(110, 228);
    printf("8");
    TFT.locate(190, 228);
    printf("9");

    TFT.locate(30, 282);
    printf("*");
    TFT.locate(110, 282);
    printf("0");
    TFT.locate(190, 282);
    printf("#");
}

void welcome()
{
    TFT.fillrect(0, 0, 240, 320, Red);

    TFT.fillcircle(120, 185, 100, Black);
    TFT.circle(120, 185, 100, White);

    ///////
    TFT.fillcircle(60, 70, 20, Black);
    TFT.circle(60, 70, 20, White);

    TFT.fillcircle(180, 50, 30, Black);
    TFT.circle(180, 50, 30, White);

    ///////

    TFT.line(120, 185, 20, 185, Green);  // 0
    TFT.line(120, 185, 41, 179, Green);  // 5
    TFT.line(120, 185, 42, 172, Green);  // 10
    TFT.line(120, 185, 43, 165, Green);  // 15
    TFT.line(120, 185, 45, 158, Green);  // 20
    TFT.line(120, 185, 48, 152, Green);  // 25
    TFT.line(120, 185, 51, 145, Green);  // 30
    TFT.line(120, 185, 55, 140, Green);  // 35
    TFT.line(120, 185, 59, 134, Green);  // 40
    TFT.line(120, 185, 50, 115, Green);  // 45
    TFT.line(120, 185, 69, 124, Green);  // 50
    TFT.line(120, 185, 75, 120, Green);  // 55
    TFT.line(120, 185, 80, 116, Green);  // 60
    TFT.line(120, 185, 87, 113, Green);  // 65
    TFT.line(120, 185, 93, 110, Green);  // 70
    TFT.line(120, 185, 100, 108, Green); // 75
    TFT.line(120, 185, 107, 107, Green); // 80
    TFT.line(120, 185, 114, 106, Green); // 85
    TFT.line(120, 185, 120, 85, Green);  // 90
    TFT.line(120, 185, 126, 106, Green); // 95
    TFT.line(120, 185, 133, 107, Green); // 100
    TFT.line(120, 185, 140, 108, Green); // 105
    TFT.line(120, 185, 147, 110, Green); // 110
    TFT.line(120, 185, 153, 113, Green); // 115
    TFT.line(120, 185, 160, 116, Green); // 120
    TFT.line(120, 185, 165, 120, Green); // 125
    TFT.line(120, 185, 171, 124, Green); // 130
    TFT.line(120, 185, 190, 115, Green); // 135
    TFT.line(120, 185, 181, 134, Green); // 140
    TFT.line(120, 185, 185, 140, Green); // 145
    TFT.line(120, 185, 189, 145, Green); // 150
    TFT.line(120, 185, 192, 152, Green); // 155
    TFT.line(120, 185, 195, 158, Green); // 160
    TFT.line(120, 185, 197, 165, Green); // 165
    TFT.line(120, 185, 198, 172, Green); // 170
    TFT.line(120, 185, 199, 179, Green); // 175
    TFT.line(120, 185, 220, 185, Green); // 180
    ////Black
    TFT.line(120, 185, 40, 185, Black); // 0
    TFT.line(120, 185, 41, 179, Black); // 5
    TFT.line(120, 185, 42, 172, Black); // 10
    TFT.line(120, 185, 43, 165, Black); // 15
    TFT.line(120, 185, 45, 158, Black); // 20
    TFT.line(120, 185, 48, 152, Black); // 25
    TFT.line(120, 185, 51, 145, Black); // 30
    TFT.line(120, 185, 55, 140, Black); // 35
    TFT.line(120, 185, 59, 134, Black); // 40

    TFT.line(120, 185, 181, 134, Black); // 140
    TFT.line(120, 185, 185, 140, Black); // 145
    TFT.line(120, 185, 189, 145, Black); // 150
    TFT.line(120, 185, 192, 152, Black); // 155
    TFT.line(120, 185, 195, 158, Black); // 160
    TFT.line(120, 185, 197, 165, Black); // 165
    TFT.line(120, 185, 198, 172, Black); // 170
    TFT.line(120, 185, 199, 179, Black); // 175
    TFT.line(120, 185, 200, 185, Black); // 180

    TFT.fillrect(48, 154, 200, 183, Black);
    TFT.set_font((unsigned char *)Arial28x28);
    TFT.background(Black);
    TFT.locate(49, 157);
    printf("DEMETER");
    TFT.circle(120, 185, 80, White);
    TFT.fillrect(20, 186, 220, 290, Red);
    TFT.line(20, 186, 220, 186, White);

    /// Programación del Botton
    TFT.fillrect(30, 222, 210, 262, Black);
    TFT.rect(32, 224, 208, 260, White);
    TFT.locate(62, 233);
    TFT.set_font((unsigned char *)Arial24x23);
    printf("INICIAR");
    TFT.line(32, 242, 50, 224, White);
    TFT.line(32, 242, 50, 260, White);
    TFT.line(190, 224, 208, 242, White);
    TFT.line(208, 242, 190, 260, White);

    TFT.fillcircle(190, 300, 15, Black);
    TFT.circle(190, 300, 15, White);

    TFT.fillcircle(15, 305, 30, Black);
    TFT.circle(15, 305, 30, White);
    TFT.fillrect(0, 270, 2, 320, Red);

    TFT.rect(2, 2, 238, 318, White);
    TFT.rect(3, 3, 237, 317, White);

    isRunning = true;

    while (isRunning)
    {
        if (myTouch.DataAvailable())
        {
            if (myTouch.Read())
            {
                x = myTouch.GetX(); // toma x del touch
                y = myTouch.GetY(); // toma y del touch
                TFT.locate(60, 10);
                xInt = (int)x;
                yInt = (int)y;
                if (y >= 6 && x >= 104 && y <= 96 && x <= 122)
                {
                    isRunning = false;
                    tecladoAlfa();
                }
            }
        }
    }
}
