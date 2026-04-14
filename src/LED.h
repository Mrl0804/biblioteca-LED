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
     * @brief liga e desliga o LED a cada meio segundo
     */
        void piscar(); 

     /**
      * @brief liga e desliga o LED conforme a frequencia decidida
      * 
      * @param freq float frequencia
      *  */   
        void piscar(float freq);

     /** 
      * @brief liga e desliga o LED conforme a frequencia e a repeticao definida
      * 
      * @param freq float frequencia
      * 
      * @param repeticoes int repeticoes
     */ 
        void piscar(float freq, uint16_t repeticoes);

        /** 
         * @brief alterna o estado do LED (HIGH) ou (LOW)
        */
        void alternar();    

        /**
         * @brief setar o estado do LED
         * 
         * @param estado 
         */
        void setEstado(bool estado);   
       
        /**
         *@brief pega o pino
         */
        uint8_t getPino();  

        /**
         *@brief atualiza a saida do LED 
         */
        void update();  
};


#endif