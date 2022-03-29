#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial12x12.h"
#include "Arial24x23.h"
#include "Arial28x28.h"
#include "font_big.h"
#include "UTouch.h"
#include "stdio.h"

extern SPI_TFT_ILI9341 TFT;
extern UTouch myTouch;
extern float x, y;
extern bool isRunning;

extern int xInt, yInt;
int tecla;

int teclear(float x, float y);

void screenEntries();
void welcome();

void introduction(){
    isRunning=true;
    TFT.fillrect(0,0,240,320,Red);
    TFT.rect(2,2,238,318,White);
    TFT.rect(3,3,237,317,White);
    //TFT.background(Red);    // set background to red
    TFT.fillrect(15,15,225,80,Black);
    TFT.rect(15,15,225,80,White);
    TFT.set_font((unsigned char*) Arial28x28);
    TFT.locate(45,20);
    printf("Ingrese las");
    TFT.locate(43,50);
    printf("dimensiones");

    //Dibujo de la plantación
    
    TFT.fillrect(40,115,200,245,Black);
    TFT.rect(40,115,200,245,Green);


    

    TFT.background(Red);    // set background to red
    TFT.set_font((unsigned char*) Arial24x23);
    TFT.locate(115,247);
    printf("x");
    TFT.locate(15,160);
    printf("y");

    //Draw Demeter
    TFT.line(72,125,72,235,Green);
    TFT.line(104,125,104,235,Green);
    TFT.line(136,125,136,235,Green);
    TFT.line(168,125,168,235,Green);

    TFT.fillrect(67,220,77,235,LightGrey);
    TFT.rect(66,219,78,236,Red);

    //TFT.fillrect(64,218,67,131,LightGrey);

    //Teclas de Next and Back

    TFT.fillrect(140,285,225,305,Black);
    TFT.fillrect(15,285,100,305,Black);
    TFT.rect(140,285,225,305,White);
    TFT.rect(15,285,100,305,White);

    TFT.background(Black);    // set background to red
    TFT.set_font((unsigned char*) Arial12x12); 
    TFT.locate(145,291);
    printf("  Next -->");
    TFT.locate(20,291);
    printf("<-- Back");

    while(isRunning) {

        if (myTouch.DataAvailable()) {
            if(myTouch.Read()) {
                x = myTouch.GetX(); // toma x del touch
                y = myTouch.GetY(); // toma y del touch
                TFT.locate(60,10);
                xInt = (int)x;
                yInt = (int)y;
                //TFT.printf("%d , %d ", xInt, yInt);
                //TFT.locate(110,60);
                if (y >= 1 && x >= 130 && y <= 40 && x <= 143){
                    isRunning=false;
                    welcome();
                } else if (y >= 60 && x >= 130 && y <= 104 && x <= 143){
                    isRunning=false;
                    screenEntries();
                }
            }
        }
    }
}


void screenEntries(){
    //Dibibujo del cuadrado

    TFT.fillrect(0,0,240,320,Red);
    TFT.rect(2,2,238,102,White);
    TFT.rect(3,3,237,101,White);
    TFT.rect(2,106,238,319,White);

    TFT.line(80,106,80,319,White);
    TFT.line(160,106,160,319,White);
    TFT.line(160,106,160,319,White);
    TFT.line(240,106,240,319,White);

    TFT.line(2,160,238,160,White);
    TFT.line(2,214,238,214,White);
    TFT.line(2,268,238,268,White);

    //Los números

    TFT.set_font((unsigned char*) Arial28x28);
    TFT.locate(30,120);
    printf("1");
    TFT.locate(110,120);
    printf("2");
    TFT.locate(190,120);
    printf("3");

    TFT.locate(30,174);
    printf("4");
    TFT.locate(110,174);
    printf("5");
    TFT.locate(190,174);
    printf("6");

    TFT.locate(30,228);
    printf("7");
    TFT.locate(110,228);
    printf("8");
    TFT.locate(190,228);
    printf("9");

    TFT.locate(30,282);
    printf("*");
    TFT.locate(110,282);
    printf("0");
    TFT.locate(190,282);
    printf("#");

     
    while(true) {

        if (myTouch.DataAvailable()) {
            if(myTouch.Read()) {
                x = myTouch.GetX(); // toma x del touch
                y = myTouch.GetY(); // toma y del touch
                TFT.locate(60,10);
                xInt = (int)x;
                yInt = (int)y;
                TFT.printf("%d , %d ", xInt, yInt);
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
    }
}

int teclear(float x, float y)
{
    int a = 0;
    /////////////1
    if (y > 0 && x > 44 && y < 33 && x < 69) {
        return 1;
    }
    /////////////2
    if (y > 33 && x > 44 && y < 66 && x < 69) {
        return 2;
    }
    /////////////3
    if (y > 66 && x > 44 && y < 100 && x < 69) {
        return 3;
    }
    /////////////4
    if (y > 0 && x > 69 && y < 33 && x < 94) {
        return 4;
    }
    /////////////5
    if (y > 33 && x > 69 && y < 66 && x < 94) {
        return 5;
    }
    /////////////6
    if (y > 66 && x > 69 && y < 100 && x < 94) {
        return 6;
    }

    /////////////7
    if (y > 0 && x > 94 && y < 33 && x < 119) {
        return 7;
    }
    /////////////8
    if (y > 33 && x > 94 && y < 66 && x < 119) {
        return 8;
    }
    /////////////9
    if (y > 66 && x > 94 && y < 100 && x < 119) {
        return 9;
    }
    /////////////0
    if (y > 33 && x > 119 && y < 66 && x < 144) {
        return 0;
    }
    /////////////#
    if (y > 66 && x > 119 && y < 100 && x < 144) {
        return 35;
    }
    /////////////*
    if (y > 0 && x > 119 && y < 33 && x < 144) {
        return 42;
    }
    return 219;
}