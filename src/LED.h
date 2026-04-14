#ifndef LED_h
#define LED_h
#include <Arduino.h>

/**
 * @class Led
 * @brief classe para controle no bloqueante de um LED.
 * 
 * permite ligar, desligar, ligar por um tempo,
 * piscar continuamente e piscar por quantidade definida
 * 
 * @note o metodo update() deve ser chamado continuamente dentro do loop
 */
class Led
{
    private:
        uint8_t pino;
        bool estado;

        bool apagarNoTempo;
        uint32_t apagarNoMomento;
        bool estadoPiscar;

        uint32_t tempoEspera;
        uint32_t tempoAnteriorPiscar;
        uint32_t repeticoes;

        /**
         * @brief processa o desligamento temporizado
         */
        void funcaoApagarNoTempo();

        /**
         * @brief processa a logica de piscada do LED
         */
        void funcaoPiscar();

    public:
  
    /**
     * @brief constroi um obejeto LED
     * 
     * @param pin numero do pino digital onde o LED esta conectado
     */
        Led(uint8_t pin);     

    /**
     * @brief liga o LED continuamente
     */
        void acender();

     /**
     * @brief liga o LED por um tempo determinado
     * 
     * @param tempoLigado tempo, em milissegundos, que o led ficara ligado
     */   
        void acender(uint32_t tempoLigado);

    /**
     * @brief desliga o LED e cancela modos automaticos
     */
        void apagar();  

    /**
     * @brief 
     */
        void piscar(); 
        void piscar(float freq);
        void piscar(float freq, uint16_t repeticoes);

        void alternar();    

        void setEstado(bool estado);   

        uint8_t getPino();  

        void update();  
};


#endif