#include "LED.h"


/**
 * @class Led
 * @brief classe para controle no bloqueante de um LED.
 * 
 * permite ligar, desligar, ligar por um tempo,
 * piscar continuamente e piscar por quantidade definida
 * 
 * @note o metodo update() deve ser chamado continuamente dentro do loop
 */

Led::Led(uint8_t pin) :
   pino(pin),
   estado(LOW),
   apagarNoTempo(false),
   apagarNoMomento(false),
   estadoPiscar(false),
   tempoEspera(0),
   tempoAnteriorPiscar(0),
   repeticoes(0)

{
    
    pinMode(pino, OUTPUT);
}

void Led::acender()
{
    estado = HIGH;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::acender(uint32_t tempoLigado)
{
    estado = HIGH;
    apagarNoTempo = true;
    apagarNoMomento = millis() + tempoLigado;
    estadoPiscar = false;
}

void Led::apagar()
{
    estado = LOW;
    apagarNoTempo = false;
    estadoPiscar = false;
}


void Led::alternar()
{
    estado = !estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}
 
void Led::piscar(float freq)
{
if(freq == 0)
 {
  return;
 }
estadoPiscar = true;
tempoEspera = (1000.0f / (2.0f * freq));
tempoAnteriorPiscar = millis();
estado = HIGH;
apagarNoTempo = false;
repeticoes = -1;
}

void Led ::piscar(float freq, uint16_t repeticoes)
{
if(freq == 0)
 {
  return;
 }
estadoPiscar = true;
tempoEspera = (1000.0f / (2.0f * freq));
tempoAnteriorPiscar = millis();
estado = HIGH;
this->repeticoes = repeticoes * 2;
apagarNoTempo = false;
}

void Led::update()
{
    if(estadoPiscar)
    {
      funcaoPiscar() ;
    }
    if(apagarNoTempo)
    {
       funcaoApagarNoTempo();
    }
    digitalWrite(pino, estado);
}
 void Led::funcaoApagarNoTempo()
 {
     if(millis() >= apagarNoMomento)
        {
            estado = LOW;
            apagarNoTempo = false;
        }
 }

 void Led::funcaoPiscar()
 {
   static u_int32_t antes = 0;

        if(millis() - antes >= tempoEspera) 
        {
            estado = !estado;
            antes = millis();
           if(repeticoes > 0) 
           {
            repeticoes --;
            if(repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
           }
        }
 }
 
