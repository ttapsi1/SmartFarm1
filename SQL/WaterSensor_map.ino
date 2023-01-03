
#define INTERVAL_CHECK 500
const int WATER_PIN = A0;

void setup(void)
{
    // need not for analog pin
    // pinMode(WATER_PIN, INPUT);    

    Serial.begin(115200);
}

void loop(void)
{
    unsigned long currentMillis;
    static unsigned long previousMillis = 0;
    int level;

    currentMillis = millis();
    if(currentMillis - previousMillis >= INTERVAL_CHECK) {
        previousMillis = currentMillis;
        level = analogRead(WATER_PIN);
        level = constrain(level, 350, 700);
        level = map(level, 350, 700, 0, 100);
        Serial.println("Read val : " + String(level));
//        Serial.println(level);
    }
}
