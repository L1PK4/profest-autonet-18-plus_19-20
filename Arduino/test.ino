#define INA1 2
#define INB1 3 
#define PWM1 4
#define INA2 5
#define INB2 6
#define PWM2 7

void setup()
{
    pinMode(INA2, OUTPUT);
    pinMode(INA2, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(PWM1, OUTPUT);
    pinMode(PWM2, OUTPUT);
}

void loop()
{
    // CW
    analogWrite(PWM2, 200);
    analogWrite(PWM1, 200);

    digitalWrite(INA2, HIGH);
    digitalWrite(INB2, LOW);
    delay(500);
  
    //STOP
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, LOW);
    delay(500);

    // CCW
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, HIGH);
    delay(500);

    //STOP
    digitalWrite(INA2, HIGH);
    digitalWrite(INB2, HIGH);
    delay(500);

    // CW
    digitalWrite(INA1, HIGH);
    digitalWrite(INB1, LOW);
    delay(500);

    //STOP
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, LOW);
    delay(500);

    // CCW
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, HIGH);
    delay(500);

    //STOP
    digitalWrite(INA1, HIGH);
    digitalWrite(INB1, HIGH);
    delay(500);
}