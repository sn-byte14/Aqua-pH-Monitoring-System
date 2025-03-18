#define SensorPin A0  // pH sensor connected to Analog Pin A0
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    pinMode(SensorPin, INPUT);
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop() {
    int sensorValue = analogRead(SensorPin);
    float voltage = sensorValue * (5.0 / 1023.0); // Convert sensor value to voltage
    float pH = 7 + ((2.5 - voltage) * 3.5); // Convert voltage to pH value

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("pH Value: ");
    lcd.print(pH);

    Serial.print("pH Value: ");
    Serial.println(pH);

    delay(2000); // Wait for 2 seconds before next reading
}
