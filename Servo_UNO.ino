/*
 Name:		Servo_UNO.ino
 Created:	11/14/2019 4:42:07 PM
 Author:	PTL00023-PAN006
*/
#include <Servo.h>
int D = 8;
int E = 9;
int PWM = 3;
int pos = 90;
int direita = 0;
int esquerda = 0;

Servo myservo;											 // Definicao do Servo

void setup() {
	Serial.begin(9600);
	myservo.attach(PWM);
	pinMode(D, INPUT);									// Direita
	pinMode(E, INPUT);									// Esquerda
}

void loop() {
	direita = digitalRead(D);
	esquerda = digitalRead(E);
	if (direita == 1 & esquerda == 0 & pos != 136)		// Logica
	{
		Serial.println("direita");
		for (pos = 45; pos <= 135; pos += 1) {			// Ciclo de posicionamento do servo
			myservo.write(pos);
			Serial.print(".");
			//delay(5);                                  // delay de 60 ms para cada modulação
		}
	}
	if (esquerda == 1 & direita == 0 & pos != 44)
	{
		Serial.println("esquerda");
		for (pos = 135; pos >= 45; pos -= 1) {			 // Ciclo de posicionamento do servo
			myservo.write(pos);
			Serial.print(".");
			//delay(5);
										
		}
	}
	else
	{
		myservo.write(pos);							     // Ultima posiçao do servo
		Serial.println("stand-By at: ");
		Serial.println(pos);
	}
}