#define INA1 2
#define INB1 3 
#define PWM1 4
#define INA2 5
#define INB2 6
#define PWM2 7
/*
*   2 - turn
*   1 - speed
*
*/
int     speed = 0;
bool    angle = 0,
        isturning = 0,
        direction = true;

void setup()
{
    pinMode(INA2, OUTPUT);
    pinMode(INA2, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(PWM1, OUTPUT);
    pinMode(PWM2, OUTPUT);
    Serial.begin(115200);
}

void set_dir(bool dir) {direction = dir;}
void set_speed(int sp) 
{
    if(sp > 0 && sp < 256)
        speed = sp;
    else
        speed = (sp > 256)?255:0;
}
    
String command = "";

void loop()
{
    while(!Serial.available());    
    command = Serial.readStringUntil('\n');
//      Parser
    speed = command[1];
    direction = command[2]>>1;
    isturning = command[2]>>1;
    angle = command[2]>>1;
//      OCHEN' LIPKA
    analogWrite(PWM1, speed);
    digitalWrite(INA1, direction);
    digitalWrite(INB1, !direction);
    analogWrite(PWM1, isturning?200:0);
    digitalWrite(INA2, angle);
    digitalWrite(INB2, !angle);
}