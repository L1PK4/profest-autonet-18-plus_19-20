#define INA1 2
#define INB1 3 
#define PWM1 4
#define INA2 5
#define INB2 6
#define PWM2 7

int     speed = 0,
        angle = 0;
bool    direction = true;

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
}

void loop()
{
    String command = "";
    while(!Serial.available());    
    command = Serial.read();
    analogWrite(PWM1, speed);
    digitalWrite(INA1, direction);
    digitalWrite(INB1, !direction);
    
}