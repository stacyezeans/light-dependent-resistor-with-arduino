/** declare variables**/
int sensor = A2;
int val;
int volt;
int led = 11;
int buzz = 9;
String b = "What's the time?";

void setup()
{
    Serial.begin(9600); // set arduino port
    Serial.println("****************This displays when it's day and switches ON the light when it's night*********************");
    pinMode(sensor, INPUT); // set up sensor
    pinMode(led, OUTPUT);   // set up LED
    pinMode(buzz, OUTPUT);  // set up buzz
}

void loop()
{
    val = analogRead(sensor); // read the sensor
    volt = (val * 5) / 1023;  // calculate the voltage (5v=1023 in arduino)

    while (!Serial.available())
    {
    } // while nothing is being typed, do nothing

    // execute the function when something is typed
    if (Serial.available())
    {
        Serial.println(b);
        dayNightCheck();
    }
    while (!Serial.available())
    {
    } // while nothing is typed, do nothing
}
// declare new function to check if it's day or night time
void dayNightCheck()
{
    // if the voltage is less than 0.8,
    if (volt < 0.8)
    {
        Serial.println("It's night!");
        digitalWrite(led, 1); // switch on the bulb
        delay(500);
        digitalWrite(buzz, 1); // switch on the buzz
    }
    else
    {
        digitalWrite(led, 0);  // switch off the led
        digitalWrite(buzz, 0); // switch off the buzz
        Serial.println("its day");
        delay(500); // delay for 0.5sec
    }
}