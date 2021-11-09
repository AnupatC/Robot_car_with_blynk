#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define in3pin 4 // D1 <-> IN3
#define in4pin 0  // D3 <-> IN4
#define in1pin 16  // D2 <-> IN1
#define in2pin 5  // D4 <-> IN2

char auth[] = "MXOwCHaOdu497lgLwcNuwoO4dIA-Mwis";
char ssid[] = "LAPTOP-DC0B6GUM 2568";
char pass[] = "Sb6/6801";
void setup()
{
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);

 pinMode(in3pin, OUTPUT);
 pinMode(in4pin, OUTPUT);
 pinMode(in1pin, OUTPUT);
 pinMode(in2pin, OUTPUT);
}

void loop()
{
 Blynk.run();
}

void halt()
{
 digitalWrite(in1pin, LOW);
 digitalWrite(in2pin, LOW);
 digitalWrite(in3pin, LOW);
 digitalWrite(in4pin, LOW);
}

void forward()
{
 digitalWrite(in1pin, LOW);
 digitalWrite(in2pin, HIGH);
 digitalWrite(in3pin, HIGH);
 digitalWrite(in4pin, LOW);
}

void reverse()
{
 digitalWrite(in1pin, HIGH);
 digitalWrite(in2pin, LOW);
 digitalWrite(in3pin, LOW);
 digitalWrite(in4pin, HIGH);
}

void right()
{
 digitalWrite(in1pin, LOW);
 digitalWrite(in2pin, HIGH);
 digitalWrite(in3pin, LOW);
 digitalWrite(in4pin, LOW);
}

void left()
{
 digitalWrite(in1pin, LOW);
 digitalWrite(in2pin, LOW);
 digitalWrite(in3pin, HIGH);
 digitalWrite(in4pin, LOW);
}

BLYNK_WRITE(V0)
{
 if (param[0])
 forward();
 else
 halt();
}

BLYNK_WRITE(V1)
{
 if (param[0])
 reverse();
 else
 halt();
}

BLYNK_WRITE(V2)
{
 if (param[0])
 right();
 else
 halt();
}

BLYNK_WRITE(V3)
{
 if (param[0])
 left();
 else
 halt();
}
