const int trigPin = 12;
const int echoPin = 14;

// define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034

long duration;
float distanceCm;

bool monitor()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distanceCm = duration * SOUND_VELOCITY / 2;

    return distanceCm <= 75.0;
}