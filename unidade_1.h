/*
 * unidade_1.h
 *
 *  Created on: 24 de ago de 2023
 *      Author: 202211250011
 */

#include "stm32f4xx.h"
#include "Utility.h"

#ifndef UNIDADE_1_H_
#define UNIDADE_1_H_


void delay(int numero);

void aula_15_08(void);
void aula_17_08(void);
void aula_22_08(void);
void aula_22_08_2(void);
void aula_24_08(void);
void aula_29_08(void);



void aula_29_08(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 4); // Habilitando clock da porta A e E
	GPIOA -> MODER |= (0b01 << 12);
	GPIOE -> MODER &= ~(0b11 << 8); // configura PE4 como entrada (sempre que habilitar a entrada)
	GPIOE -> PUPDR |= (0b01 <<8); // Liga o resistor de pull up em PE4 (para ligar o pull down seria 0b10)

	while(1){
		int leitura = GPIOE -> IDR & (1 << 4);
		if(leitura){
			GPIOA -> ODR &= ~(1 << 6);

		}else{
			GPIOA -> ODR |= (1 << 6);
		}
	}


//	while(1){
//		int leitura = GPIOE -> IDR & (1 << 4);
//		while (leitura){
//			GPIOA -> ODR &= ~(1 << 6); }
//		while (leitura == 0){
//			GPIOA -> ODR |= (1 << 6); }
//
//	}
}




// Questão de prova, guardar:
void aula_24_08(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 2 ) ;
	GPIOA -> MODER |= (0b01 << 12) | (0b01 << 14);

	int contador = 0;
	int cte = 1;
	int valor_periodo = 600; // controla o periodo do pulso, para calula a frequencia calcula-se 1/periodo
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_us(contador);
		GPIOA -> ODR |= (1 << 6);
		Delay_us(valor_periodo - contador);

		GPIOA -> ODR &= ~(1 << 7);
		Delay_us(valor_periodo - contador);
		GPIOA -> ODR |= (1 << 7);
		Delay_us(contador);

		contador += cte; // Incrementa o contador com valor do cte
		if (contador == valor_periodo || contador ==0){
			cte = -cte; // Caso o contador seja igual ao valor do periodo ou igual a zero, o sinal do cte é invertido
						// Essa inversão garante que o contador diminua e aumente em looping em formato de uma onda
		}

	}


}

void aula_22_08_2(void){

	Utility_Init();
	RCC->AHB1ENR |= (1<<2) ; 				// Liga o clock do GPIOA
	GPIOC->MODER |= (0b01 << 0);

	while(1){
		for (int i=0 ; i < 8 ; i++){
			GPIOC->ODR ^= 1 << 0;		// Alterna o estado do pino PA6
			Delay_ms(50);
		}
		Delay_ms(1000);
	}
};

void aula_22_08(void){

	Utility_Init();
	RCC->AHB1ENR |= (1<<0) ; 				// Liga o clock do GPIOA
	GPIOA->MODER |= (0b01 << 12) ;	    // Pino PA6 e PA7 como Saida

	while(1){
		// ponto ponto ponto
//		GPIOA->ODR |= 1 << 6;		// Nivel alto para o pino PA6
//		Delay_ms(1000);
//		GPIOA->ODR &= ~(1 << 6); 	// Nivel baixo para o pino PA6
//		Delay_ms(1000);

		GPIOA->ODR ^= 1 << 6;		// Alterna o estado do pino PA6
		Delay_ms(1000);

	};

};

void aula_17_08(void){

	// |Função responsavel por prototipar um semaforo de transito, tambem a função amarelo piscante do mesmo:

	// Definindo os tempos de delay:
	int verde_vermelho = 10000000 ;
	int amarelo = verde_vermelho / 3;

	// Iniciando o clock da porta C sendo 1 << 2:
	RCC -> AHB1ENR |= (1 << 2) ;
	// Habilitando as portas PC0 PC1 e PC2 como saidas:
	GPIOC-> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4) ;

	while (1) {

		// Iniciando o ciclo normal do semaforo (3 vezes)
		for (int i = 0; i < 3 ; i++){
			GPIOC->ODR |= 1 << 0; // Nivel alto
			delay(verde_vermelho);
			GPIOC->ODR &= ~(1 << 0); // Nivel baixo

			GPIOC -> ODR |= 1 << 1;
			delay(amarelo);
			GPIOC->ODR &= ~(1 << 1);

			GPIOC -> ODR |= 1 << 2;
			delay(verde_vermelho);
			GPIOC->ODR &= ~(1 << 2);
		}

		// Iniciando o ciclo amarelo piscante do semaforo(3 vezes):
		for (int i = 0; i < 3 ; i++){

			GPIOC -> ODR |= 1 << 1;
			delay(amarelo);
			GPIOC->ODR &= ~(1 << 1);
			delay(amarelo);

		}
	}

};

void aula_15_08(void){

	RCC->AHB1ENR |= (1<<0) ; 				// Liga o clock do GPIOA
	GPIOA->MODER |= (0b01 << 12) | (0b01 << 14) ;	    // Pino PA6 e PA7 como Saida

	while(1){
		// ponto ponto ponto
		GPIOA->ODR |= 1 << 6;		// Nivel alto para o pino PA6
		delay(1000000);
		GPIOA->ODR |= 1 << 7;		// Nivel alto para o pino PA7
		delay(1000000);

		GPIOA->ODR &= ~(1 << 6); 	// Nivel baixo para o pino PA6
		delay(1000000);
		GPIOA->ODR &= ~(1 << 7); 	// Nivel baixo para o pino PA7
		delay(1000000);
	}

};

void delay(int numero){
	int contador = numero;
	while(contador) --contador;
}







#endif /* UNIDADE_1_H_ */
