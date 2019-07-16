#define sensorPin1 8
#define sensorPin2 9
#define sensorPin3 10
#define sensorPin4 11  
void setup() {  
  pinMode(sensorPin1,INPUT);
  pinMode(sensorPin2,INPUT);
  pinMode(sensorPin3,INPUT);
  pinMode(sensorPin4,INPUT);
  Serial.begin(9600);  
}  
  
void loop() {  
  int x1=digitalRead(sensorPin1);
  int x2=digitalRead(sensorPin2);
  int x3=digitalRead(sensorPin3);
  int x4=digitalRead(sensorPin4);//若有障碍输出低电平，若无障碍输出高电平
  if(x1*x2*x3*x4==0)
  {
    Serial.println("Dangerous!!!");
  }
  else
  {
    Serial.println("Safe!!!");
  }
  delay(500);//每隔0.5s检测一次
}  
