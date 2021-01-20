const int pump_interval_pin = A7;  // Analog input pin that the potentiometer is attached to
const int pump_out_pin = 5; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int interval = 10000;          //interval in milliseconds
int pump_speed = 255;
int pump = 0;
int pause = 0;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
 
  pump = map(analogRead(pump_interval_pin), 0, 4064, 0, interval);
  pause = map(analogRead(pump_interval_pin), 0, 4064, interval,0);

  Serial.print("Pump interval = ");
  Serial.print(map(analogRead(pump_interval_pin), 0, 4064, 0, 100)); //output in %
  Serial.print("\t pump time = ");
  Serial.print(pump);
  Serial.print("\t pause = ");
  Serial.println(pause);
  
  analogWrite(pump_out_pin, 0);
  delay(pause);
  analogWrite(pump_out_pin, pump_speed);
  delay(pump);
} 
