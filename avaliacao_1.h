/*
 * avaliacao_1.h

 *
 *  Created on: 12 de set de 2023
 *      Author: 202211250011
 */
#include "stm32f4xx.h"
#include "Utility.h"
#include "LCD_blio.h"


#ifndef AVALIACAO_1_H_
#define AVALIACAO_1_H_

void questao_1(void);
void questao_2(void);
void questao_3(void);
void questao_4(void);
void questao_5(void);
void questao_6(void);
void questao_7(void);
void questao_8(void);
void questao_9(void);
void questao_10(void);
void questao_11(void);
void questao_12(void);
void questao_13(void);
void questao_14(void);
void questao_15(void);
void questao_16(void);
void questao_17(void);
void questao_18(void);
void questao_19(void);
void questao_21(void);
void questao_22(void);
void questao_23(void);
void questao_24(void);
void questao_25(void);


void questao_26(void);
void questao_27(void);


void questao_19(void){

	RCC -> AHB1ENR |= (1 << 0);
	GPIOA -> MODER |= (0b01 << 0);
	GPIOA->OTYPER = 1 << 0;
	Utility_Init();

	while(1){

		GPIOA->ODR ^= 1 << 0;
		Delay_ms(500);

	}

}


void questao_18(void){
	Utility_Init();
		//Ligar o Clock GPIOA e GPIOD
		RCC-> AHB1ENR |= 0b1001;

		//Acender pino PA9 e PA10
		GPIOA -> MODER |= 0b01 << 18;
		GPIOA -> MODER |= 0b01 << 20;

		//Acender pino PD0
		GPIOD -> MODER |= 0b01 << 0;

		while(1){
			GPIOA->ODR &= ~(1<<9);
			GPIOA->ODR |= 1<<10;

			int tempo = 0;
			while(tempo <= 2000){

				GPIOD->ODR |= 1<<0;
				Delay_us(tempo);

				GPIOD->ODR &= ~(1<<0);
				Delay_us(2000-tempo);
				++tempo;
			}

			tempo = 2000;
			while(tempo >=0){
				GPIOD->ODR |= 1<<0;
				Delay_us(tempo);

				GPIOD->ODR &= ~(1<<0);
				Delay_us(2000-tempo);
				--tempo;
			}

			GPIOA->ODR &= ~(1<<10);
			GPIOA->ODR |= 1<<9;

			tempo = 0;
			while(tempo <= 2000){
				GPIOD->ODR |= 1<<0;
				Delay_us(tempo);

				GPIOD->ODR &= ~(1<<0);
				Delay_us(2000-tempo);
				++tempo;
			}

			tempo = 2000;
			while(tempo >=0){
				GPIOD->ODR |= 1<<0;
				Delay_us(tempo);

				GPIOD->ODR &= ~(1<<0);
				Delay_us(2000-tempo);
				--tempo;
			}
		}
	}


void questao_16(void){


	Utility_Init();
	LCD_Init();
	LCD_Clear();

	LCD_Set_Cursor(2, 2);


	LCD_Write_Char('W');






}


void questao_1(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) ;
	GPIOA -> MODER |= (0b01 << 12);
	int periodo = 250;

	while(1){
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(periodo);
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(periodo);
	}

}



void questao_2(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) ;
	GPIOA -> MODER |= (0b01 << 12);

	while(1){
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(1900);
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(100);
	}

}

void questao_3(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) ;
	GPIOA -> MODER |= (0b01 << 12);

	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(1000);
		for(int i=0; i<2;i++){
			GPIOA -> ODR &= ~(1 << 6);
			Delay_ms(50);
			GPIOA -> ODR |= (1 << 6);
			Delay_ms(70);
		}
		Delay_ms(1000);
	}
}

void questao_4(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) ;
	GPIOA -> MODER |= (0b01 << 12);
	int contador = 50;
	int periodo = 1000;
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA -> ODR |= (1 << 6);
		Delay_ms(periodo);
		periodo -= contador;
		if (periodo <= 0) {
			periodo = 1000;
		}

	}
}

void questao_5(void){
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
}

void questao_6(void){
	Utility_Init();
		RCC -> AHB1ENR |= (1 << 0) ;
		GPIOA -> MODER |= (0b01 << 12) ;

		int contador = 300;
		int valor_periodo = 10000; // controla o periodo do pulso, para calula a frequencia calcula-se 1/periodo
		while(1){
			GPIOA -> ODR &= ~(1 << 6);
			Delay_us(contador);
			GPIOA -> ODR |= (1 << 6);
			Delay_us(valor_periodo - contador);

			}
}




void questao_7(void){
	Utility_Init();
		RCC -> AHB1ENR |= (1 << 0) ;
		GPIOA -> MODER |= (0b01 << 12) ;

		int contador = 0;
		int cte = 100;
		int valor_periodo = 10000; // controla o periodo do pulso, para calula a frequencia calcula-se 1/periodo
		while(1){
			GPIOA -> ODR &= ~(1 << 6);
			Delay_us(contador);
			GPIOA -> ODR |= (1 << 6);
			Delay_us(valor_periodo - contador);


			contador += cte; // Incrementa o contador com valor do cte
			if (contador == valor_periodo || contador ==0){
				cte = -cte; // Caso o contador seja igual ao valor do periodo ou igual a zero, o sinal do cte é invertido
							// Essa inversão garante que o contador diminua e aumente em looping em formato de uma onda
			}

		}
}


void questao_8(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 2 ) ;
	GPIOA -> MODER |= (0b01 << 12) | (0b01 << 14);

	int valor_periodo = 500; // controla o periodo do pulso, para calula a frequencia calcula-se 1/periodo
	while(1){
		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(valor_periodo/2);
		GPIOA -> ODR |= (1 << 6);
//		Delay_ms(valor_periodo/2);

		GPIOA -> ODR &= ~(1 << 7);
		Delay_ms(valor_periodo/2);
		GPIOA -> ODR |= (1 << 7);
//		Delay_ms(valor_periodo/2);

	}


}


void questao_9(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) ;
	GPIOA -> MODER |= (0b01 << 12) | (0b01 << 14);

	while(1){
		for(int i=0 ; i < 4; i++){
			int j = i << 6;
			GPIOA -> ODR = ~j;
			Delay_ms(1000);
		}
	}


}


void questao_10(void){
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

void questao_11(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) ;
	GPIOA -> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4)| (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12)| (0b01 << 14);

	while(1){
		for(int i=0 ; i < 256; i++){
			GPIOA -> ODR = i;
			Delay_ms(50);
		}
	}

}


//void questao_12(void){
//	Utility_Init();
//	RCC -> AHB1ENR |= (1 << 0) ;
//	GPIOA -> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4)| (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12)| (0b01 << 14);
//
//	while(1){
//		for(int i=1;i<17;i++){
//			if (i==1 | i==16){  GPIOA -> ODR |= (1 << 0);  Delay_ms(250); GPIOA -> ODR &= ~(1 << 0); }
//			else if (i==2 | i==15){ GPIOA -> ODR |= (1 << 1);  Delay_ms(250); GPIOA -> ODR &= ~(1 << 1); }
//			else if (i==3 | i==14){  GPIOA -> ODR |= (1 << 2);  Delay_ms(250); GPIOA -> ODR &= ~(1 << 2); }
//			else if (i==4 | i==13){  GPIOA -> ODR |= (1 << 3);  Delay_ms(250); GPIOA -> ODR &= ~(1 << 3); }
//			else if (i==5 | i==12){  GPIOA -> ODR |= (1 << 4);  Delay_ms(250); GPIOA -> ODR &= ~(1 << 4); }
//			else if (i==6 | i==11){  GPIOA -> ODR |= (1 << 5);  Delay_ms(250); GPIOA -> ODR &= ~(1 << 5);}
//			else if (i==7 | i==10){  GPIOA -> ODR |= (1 << 6);  Delay_ms(250); GPIOA -> ODR &= ~(1 << 6); }
//			else if (i==8 | i==9){ GPIOA -> ODR |= (1 << 7);  Delay_ms(250);  GPIOA -> ODR &= ~(1 << 7); }
//
//		}
//
//	}
//
//}


void questao_13(void){
	Utility_Init();
	// |Função responsavel por prototipar um semaforo de transito, tambem a função amarelo piscante do mesmo:


	// Iniciando o clock da porta C sendo 1 << 2:
	RCC -> AHB1ENR |= (1 << 0) ;
	// Habilitando as portas PC0 PC1 e PC2 como saidas:
	GPIOA-> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4) | (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12);

	while (1) {

			GPIOA->ODR |= 1 << 0 | 1 << 3;   // 0-verde1 // 3-vermelho2
			Delay_ms(2000);
			GPIOA->ODR &= ~(1 << 0) ;

			GPIOA -> ODR |= 1 << 1 ; // 1-amarelo1
			Delay_ms(1000);
			GPIOA->ODR &= ~(1 << 1) ;
			Delay_ms(100);
			GPIOA->ODR &= ~(1 << 3) ;


			GPIOA->ODR |= 1 << 5 | 1 << 2;   // 5-verde2 // 2-vermelho1
			Delay_ms(2000);
			GPIOA->ODR &= ~(1 << 5) ;

			GPIOA -> ODR |= 1 << 4 ; // 4-amarelo2
			Delay_ms(1000);
			GPIOA->ODR &= ~(1 << 4) ;
			Delay_ms(100);
			GPIOA->ODR &= ~(1 << 2) ;
	}
}

void questao_14(void){
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) ;

//	GPIOA-> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4) | (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12) | (0b01 << 14);
	GPIOA-> MODER |=  (0b01 << 2) | (0b01 << 4) | (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12) | (0b01 << 14);
	int tam_matriz = 16;
	const uint8_t mask[16]={ 0b00111111, //0
							0b00000110, //1
							0b01011011, //2
							0b01001111, //3
							0b01100110, //4
							0b01101101, //5
							0b01111101, //6
							0b00000111, //7
							0b01111111, //8
							0b01101111, //9
							0b01110111, //A
							0b01111100, //B
							0b00111001, //C
							0b01011110, //D
							0b01111001, //E
							0b01110001}; //F

while(1){
	for(int i=0; i<tam_matriz ; i++){
		GPIOA->ODR = mask[i];
		Delay_ms(500);
	}
	for(int i=tam_matriz; i>0; i--){
		GPIOA->ODR = mask[i];
		Delay_ms(500);
	}

}
}
//void questao_15(void){
//	Utility_Init();
//	RCC -> AHB1ENR |= (1 << 0);
//	RCC -> AHB1ENR |= (1 << 4);
//	GPIOE->MODER |= (0b01 << 8) | (0b01 << 10) ;
//	GPIOA-> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4) | (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12);
//
//
//	RCC -> AHB1ENR |= (1 << 4);
//	GPIOE->ODR |= 1 << 5;
//	GPIOE->ODR |= 1 << 4;
//
//	while(1);
//
//
//	const uint8_t mask[16]={ 0b00111111, //0
//							0b00000110, //1
//							0b01011011, //2
//							0b01001111, //3
//							0b01100110, //4
//							0b01101101, //5
//							0b01111101, //6
//							0b00000111, //7
//							0b01111111, //8
//							0b01101111, //9
//							0b01110111, //A
//							0b01111100, //B
//							0b00111001, //C
//							0b01011110, //D
//							0b01111001, //E
//							0b01110001}; //F
//
//
//
//	while(1){
//		for(int seg2 = 0; seg2 < 16; seg2++){
//		for(int seg1 = 0; seg1 < 16; seg1++){
//			for(int i = 0; i > 100000; i++){
//			GPIOE->ODR = (0b01 << 4);
//			GPIOA->ODR = mask[seg1];
//
//			GPIOE->ODR = (0b01 << 5);
//			GPIOA->ODR = mask[seg2];
//				}
//
//			}
//		}
//		for(int seg2 = 15; seg2 >= 0; seg2--){
//			for(int seg1 = 15; seg1 >= 0; seg1--){
//				for(int i = 0; i > 10000; i++){
//
//				GPIOE->ODR = (0b01 << 4);
//				GPIOA->ODR = mask[seg1];
//
//
//				GPIOE->ODR = (0b01 << 5);
//				GPIOA->ODR = mask[seg2];
//
//				}
//
//			}
//		}
//	}
//
//}
//void questao_15(void){
//	Utility_Init();
//	RCC -> AHB1ENR |= (1 << 0);
//	RCC -> AHB1ENR |= (1 << 4);
//	GPIOE->MODER |= (0b01 << 8) | (0b01 << 10) ;
//	GPIOA-> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4) | (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12);
//
//
//	RCC -> AHB1ENR |= (1 << 4);
//	GPIOE->ODR |= 1 << 5;
//	GPIOE->ODR |= 1 << 4;
//
//	while(1);
//
//
//	const uint8_t mask[16]={ 0b00111111, //0
//							0b00000110, //1
//							0b01011011, //2
//							0b01001111, //3
//							0b01100110, //4
//							0b01101101, //5
//							0b01111101, //6
//							0b00000111, //7
//							0b01111111, //8
//							0b01101111, //9
//							0b01110111, //A
//							0b01111100, //B
//							0b00111001, //C
//							0b01011110, //D
//							0b01111001, //E
//							0b01110001}; //F
//
//
//
//	while(1){
//		for(int seg2 = 0; seg2 < 16; seg2++){
//		for(int seg1 = 0; seg1 < 16; seg1++){
//			for(int i = 0; i > 100000; i++){
//			GPIOE->ODR = (0b01 << 4);
//			GPIOA->ODR = mask[seg1];
//
//			GPIOE->ODR = (0b01 << 5);
//			GPIOA->ODR = mask[seg2];
//				}
//
//			}
//		}
//		for(int seg2 = 15; seg2 >= 0; seg2--){
//			for(int seg1 = 15; seg1 >= 0; seg1--){
//				for(int i = 0; i > 10000; i++){
//
//				GPIOE->ODR = (0b01 << 4);
//				GPIOA->ODR = mask[seg1];
//
//
//				GPIOE->ODR = (0b01 << 5);
//				GPIOA->ODR = mask[seg2];
//
//				}
//
//			}
//		}
//	}
//
//}


void questao_15(void){
	const uint8_t mask[16]={ 0b00111111, //0
	0b00000110, //1
	0b01011011, //2
	0b01001111, //3
	0b01100110, //4
	0b01101101, //5
	0b01111101, //6
	0b00000111, //7
	0b01111111, //8
	0b01101111, //9
	0b01110111, //A
	0b01111100, //B
	0b00111001, //C
	0b01011110, //D
	0b01111001, //E
	0b01110001}; //F

	RCC->AHB1ENR |= (0b1 << 2); //liga o clock gpioa e gpiob
	RCC->AHB1ENR |= (0b1 << 3);
	GPIOE->MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4) | (0b01 << 6) | (0b01 << 8) | (0b01 << 10) |  (0b01 << 12);
	GPIOC->MODER |= (0b01 << 0) | (0b01 << 2);

	Utility_Init();
	while(1){
	for(int seg2 = 0; seg2 < 16; seg2++){
	for(int seg1 = 0; seg1 < 16; seg1++){
	for(int i = 0; i < 10; i++){
	GPIOC->ODR =(0b01 << 0);
	GPIOE->ODR = mask[seg1];
	Delay_us(800);
	GPIOC->ODR =(0b01 << 1);
	GPIOE->ODR = mask[seg2];
	Delay_us(800);
	}
	Delay_ms(100);
	}
	}

	for(int seg2 = 15; seg2 >= 0; seg2--){
	for(int seg1 = 15; seg1 >= 0; seg1--){
	for(int i = 0; i < 100; i++){
	GPIOC->ODR =(0b01 << 0);
	GPIOE->ODR = mask[seg1];
	Delay_us(500);
	GPIOC->ODR =(0b01 << 1);
	GPIOE->ODR = mask[seg2];

	}
	Delay_ms(100);
	}
	}


	}
	}



void questao_17(void){
	Utility_Init();
		RCC -> AHB1ENR |= (1 << 0) ;
		GPIOA -> MODER |= (0b01 << 0) ;

			while(1){

				for(int i=500; i<=2500; i+=10){
					GPIOA -> ODR |= (1 << 0);
					Delay_us(i);
					GPIOA -> ODR &= ~(1 << 0);
					Delay_us(20000-i);

				}

				for(int i=2500; i>=500; i-=10){
					GPIOA -> ODR |= (1 << 0);
					Delay_us(i);
					GPIOA -> ODR &= ~(1 << 0);
					Delay_us(20000-i);

				}

		}}



void questao_26(void){
	// PE3 K1     -    PE4 K0
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 4); // Habilitando clock da porta A e E
	GPIOA -> MODER |= (0b01 << 0);
	GPIOE -> MODER &= ~(0b11 << 8)  &  ~(0b11 << 6); // configura PE4 como entrada (sempre que habilitar a entrada)
	GPIOE -> PUPDR |= (0b01 << 8)  | (0b01 << 6); // Liga o resistor de pull up em PE4 (para ligar o pull down seria 0b10)

	while(1){
		int leitura_k0 = GPIOE -> IDR & (1 << 4);
		int leitura_k1 = GPIOE -> IDR & (1 << 3);

		int i = 500;
		int j = 2500;
		while( (!leitura_k0) & (i<=2500) ){
			leitura_k0 = !leitura_k0;
			i +=10;
			GPIOA -> ODR |= (1 << 0);
			Delay_us(i);
			GPIOA -> ODR &= ~(1 << 0);
			Delay_us(20000-i); }

		while( (!leitura_k1) & (i>=500) ){
			leitura_k1 = !leitura_k1;
			j -=10;
			GPIOA -> ODR |= (1 << 0);
			Delay_us(j);
			GPIOA -> ODR &= ~(1 << 0);
			Delay_us(20000-j); }

		}}







void questao_27(void){
	// PE3 K1     -    PE4 K0      -     PA0 KUP
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 4);
	GPIOA-> MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 4) | (0b01 << 6)| (0b01 << 8)| (0b01 << 10)| (0b01 << 12) | (0b01 << 14);

	GPIOA -> MODER &= ~(0b11 << 0)  ; // configura PA0 como entrada (sempre que habilitar a entrada)
	GPIOA -> PUPDR |= (0b10 << 0) ; // Liga o resistor de pull down em PA0

	GPIOE -> MODER &= ~(0b11 << 8)  &  ~(0b11 << 6); // configura PE4 como entrada (sempre que habilitar a entrada)
	GPIOE -> PUPDR |= (0b01 << 8)  | (0b01 << 6); // Liga o resistor de pull up em PE4 (para ligar o pull down seria 0b10)

	const uint8_t mask[16]={ 0b00111111, //0
							0b00000110, //1
							0b01011011, //2
							0b01001111, //3
							0b01100110, //4
							0b01101101, //5
							0b01111101, //6
							0b00000111, //7
							0b01111111, //8
							0b01101111, //9
							0b01110111, //A
							0b01111100, //B
							0b00111001, //C
							0b01011110, //D
							0b01111001, //E
							0b01110001}; //F

while(1){
	int leitura_k0 = GPIOE -> IDR & (1 << 4);
	int leitura_k1 = GPIOE -> IDR & (1 << 3);
	int leitura_kup = GPIOA -> IDR & (1 << 0);

	if(leitura_kup){ // 1
		GPIOA->ODR = mask[1] << 1;
	}

	if(!leitura_k0){ // 2
		GPIOA->ODR = mask[2] << 1;
	}

	if(!leitura_k1){ // 3
		GPIOA->ODR = mask[3] << 1;

	}



}
}









void questao_21(void){
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
}

void questao_22(void){
	// PE3 K1     -    PE4 K0
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 4); // Habilitando clock da porta A e E
	GPIOA -> MODER |= (0b01 << 12) | (0b01 << 14);
	GPIOE -> MODER &= ~(0b11 << 8)  &  ~(0b11 << 6); // configura PE4 como entrada (sempre que habilitar a entrada)
	GPIOE -> PUPDR |= (0b01 << 8)  | (0b01 << 6); // Liga o resistor de pull up em PE4 (para ligar o pull down seria 0b10)

	while(1){
		int leitura_k0 = GPIOE -> IDR & (1 << 4);
		int leitura_k1 = GPIOE -> IDR & (1 << 3);
		if(leitura_k0){
			GPIOA -> ODR &= ~(1 << 6);

		}else{
			GPIOA -> ODR |= (1 << 6);
		}

		if(leitura_k1){
			GPIOA -> ODR &= ~(1 << 7);

		}else{
			GPIOA -> ODR |= (1 << 7);
		}
}
}




void questao_23(void)
{
	Utility_Init();
    RCC->AHB1ENR |= (1 << 4);
    RCC->AHB1ENR |= 1;
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);
    GPIOA->MODER |= (0b01 << 12) | (0b01 << 10);
    GPIOA->MODER &= ~(0b11 << 14);
    while (1) {
        if ((GPIOE->IDR & (1 << 4)) == 0) {
		Delay_ms(50);
		if ((GPIOE->IDR & (1 << 4)) == 0) {
			GPIOA->ODR ^= (1 << 6);
			while ((GPIOE->IDR & (1 << 4)) == 0) {
				Delay_ms(50);  }}} }}



void questao_24(void){
Utility_Init();

RCC->AHB1ENR |= (1 << 4);
GPIOE->MODER &= ~(0b11 << 8) | ~(0b11 << 6);
GPIOE->PUPDR |= (0b01 << 8) | (0b01 << 6);

RCC->AHB1ENR |= 1;
GPIOA->MODER |= (0b01 << 12);
GPIOA->ODR |= (1 << 6);

while(1){

if(!(GPIOE->IDR & (1 << 3))){
GPIOA->ODR |= (1 << 6);
Delay_ms(250);}

else if(!(GPIOE->IDR & (1 << 4))){
if(!(GPIOE->IDR & (1 << 3))){
while(1){
GPIOA->ODR &= ~(1 << 6);
if((GPIOE->IDR & (1 << 4)) || (GPIOE->IDR & (1 << 3))){GPIOA->ODR |= (1 << 6); break; }}}}}}



void questao_25(void){
Utility_Init();

RCC->AHB1ENR |= (1 << 4);
GPIOE->MODER &= ~(0b11 << 8) | ~(0b11 << 6);
GPIOE->PUPDR |= (0b01 << 8) | (0b01 << 6);

RCC->AHB1ENR |= 1;
GPIOA->MODER |= (0b01 << 12);
GPIOA->ODR |= (1 << 6);

int check = 0;

while(1){

if(GPIOE->IDR & (1 << 4)){check = 0;}

if(check == 0){

if(!(GPIOE->IDR & (1 << 3))){
GPIOA->ODR |= (1 << 6);
Delay_ms(250);}

else if(!(GPIOE->IDR & (1 << 4))){
for(int i = 0;  i <= 1000; i++ ){
Delay_ms(1);
if(GPIOE->IDR & (1 << 4)){break;}
if(!(GPIOE->IDR & (1 << 3))){

while(1){
GPIOA->ODR &= ~(1 << 6);
if((GPIOE->IDR & (1 << 4)) || (GPIOE->IDR & (1 << 3))){GPIOA->ODR |= (1 << 6); break;}

}}
check = 1;}
}
}
}
}


#endif /* AVALIACAO_1_H_ */
