#include <allegro.h>
#include <string>
#include <conio.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winalleg.h>
#include <fstream>

#define ancho 1024
#define alto 740

MIDI *musicaInicio;
MIDI *musicaJuego;
SAMPLE *sonido_InicioJuego;
SAMPLE *sonido_InicioNivel;
SAMPLE *sonido_LadrilloRoto;
SAMPLE *sonido_RebotePelota;
SAMPLE *sonido_Revivir;
SAMPLE *sonido_VidaExtra;
SAMPLE *sonido_RebotaParedes;
SAMPLE *sonido_RebotaBase;
SAMPLE *sonido_VidaPerdida;
SAMPLE *sonido_gameover;

BITMAP  *buffer;
BITMAP  *logo;
BITMAP  *panel;
BITMAP  *recuadro;
BITMAP  *fondo1;
BITMAP  *fondo2;
BITMAP  *fondo3;
BITMAP  *fondo4;
BITMAP  *fondo5;
BITMAP  *gameover;
BITMAP  *lad1;
BITMAP  *lad2;
BITMAP  *lad3;
BITMAP  *lad4;
BITMAP  *lad5;
BITMAP  *lad6;
BITMAP  *lad7;
BITMAP  *ladd;
BITMAP  *base;
BITMAP  *base2;
BITMAP  *base3;
BITMAP  *base4;



int retardo =100;
int vida=3;
int level=1;
int score=0;
bool juegoIniciado=false;
bool fin = false;
bool nuevoNivel=false;
int dirY=1;
int dirX=1;
int velocidad=3;
int velocidadInicial=3;
int fondoN=1;
bool muerte=false;
int secuenciaMuerte=1;
bool musica=true;
bool efectos=true;
bool existeArchivo=false;
int highScore=0;

int baseX=255;
int bolax=295;
int bolaY=650;

int mapa[63];

int puntIzq;
int puntDer;

int colBola;
int filaBola;
int elemento;

int fila[]=(20,50,80,110,140,170,200);

using namespace std;

int main()
{
    if(inicializo() ==1) return 1;

}
END_OF_MAIN();

int inicializo()
{
    allegro_init();
    install_keyboard();

    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0){
        allegro_message("Error ! Inicializando sitema de sonido\n\n\n", allegro_errno);
        return 1;
    }

    inicializo_pantalla();

    return 0;
}

void inicializo_pantalla()
{
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT, ancho, alto, 0, 0);
    buffer=create_bitmap(ancho, alto);
    logo=load_bitmap("img/logo.bmp", NULL);
    panel=load_bitmap("img/panel1.bmp", NULL);


}
