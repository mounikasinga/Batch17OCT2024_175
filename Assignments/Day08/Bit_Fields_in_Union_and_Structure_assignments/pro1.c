#include <stdio.h>

typedef struct {
    unsigned int red : 1;
    unsigned int green : 1; 
    unsigned int orange : 1; 
} TrafficLightStatus;
int main() {
    TrafficLightStatus light = {1, 0, 1};
    printf("Traffic Light Status:\n");
    printf("Red: %s\n", light.red ? "On" : "Off");
    printf("Green: %s\n", light.green ? "On" : "Off");
    printf("Orange: %s\n", light.orange ? "On" : "Off");

    return 0;
}

