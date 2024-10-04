/*
10/03/2024
Luke Reicherter
KU ID: 3135060
EECS 348: Lab 04
Lab Session: Thursday 11:00 AM
Description: This program will take a user's temperature input and convert it to a different unit.
It will also display some temperature and weather info.
*/
#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    //Converts celsius to fahrenheit
    return(((celsius*9)/5) + 32); 
}
float celsius_to_kelvin(float celsius) {
    //Converts celsius to kelvin
    return (celsius + 273.15);
}
float fahrenheit_to_celsius(float fahrenheit) {
    //Converts fahrenheit to celsius
    return ((((fahrenheit - 32) * 5)/9));
}
float fahrenheit_to_kelvin(float fahrenheit) {
    //Converts fahrenheit to kelvin by first converting F to C, then C to K
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
float kelvin_to_celsius(float kelvin) {
    //Converts kelvin to celsius
    return (kelvin - 273.15);
}
float kelvin_to_fahrenheit(float kelvin) {
    //Converts kelvin to fahrenheit by first converting K to C, then C to F
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}
void temperature_catagory_evaluator(float celsius) {
    //Compares the celsius temp to various values to generate a weather report and temp catagory
    if (celsius >= 70) {
        printf("Temperature catagory: THE WORLD IS ON FIRE\nWeather Advisory: Probably stay indoors\n");
    }
    if (70 > celsius && celsius >= 35) {
        printf("Temperature catagory: Extreme Heat\nWeather Advisory: Apply lots of sunscreen\n");
    }
    if (35 > celsius && celsius >= 25) {
        printf("Temperature catagory: Hot\nWeather Advisory: Great day for the pool\n");
    }
    if (25 > celsius && celsius >= 10) {
        printf("Temperature catagory: Comfortable\nWeather Advisory: Good day for a walk\n");
    }
    if (10 > celsius && celsius >= 0) {
        printf("Temperature catagory: Cold\nWeather Advisory: Wear a coat\n");
    }
    if (0 > celsius && celsius >= -90) {
        printf("Temperature catagory: Freezing\nWeather Advisory: Frostbite Warning\n");
    }
    if (-90 > celsius) {
        printf("Temperature catagory: THE WORLD IS IN AN ICE AGE\nWeather Advisory: Probably stay indoors\n");
    }
}
int main() {
    //Main function that obtains user values and sends those values to other functions. Temp conversion is printed here
    float temp_val, temp_final, temp_cat;
    int temp_scale, temp_conv, TorF = 1;
    while (TorF == 1) {
        //This while loop ensures valid input and allows the user to try again
        printf("\nEnter the temperature: ");
        scanf("%f", &temp_val);
        printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &temp_scale);
        if (temp_scale == 1) {
            temp_cat = temp_val;
        }
        printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &temp_conv);
        printf("\n");
        if (temp_conv > 3 || temp_conv < 1){ 
            printf("Temperature conversion selection must be 1, 2, or 3");
        }
        else if (temp_scale > 3 || temp_scale < 1) {
            printf("Temperature scale selection must be 1, 2, or 3");  
        }
        else if (temp_scale == 3 && temp_val < 0) {
            printf("Kelvin must be larger than 0, try again");   
        }
        else if (temp_scale == temp_conv) {
            printf("Cannot convert to same scale, try again"); 
        }
        else {
            TorF = 0;
        }
    }
    //All if / else if statements determine what conversion the user wanted, and obtains the converted value
    if (temp_scale == 1 && temp_conv == 2) {
        temp_final = celsius_to_fahrenheit(temp_val);
        printf("Converted Temperature: %f*F\n", temp_final);
    }
    else if (temp_scale == 1 && temp_conv == 3) {
        temp_final = celsius_to_kelvin(temp_val);
        printf("Converted Temperature: %fK\n", temp_final);
    }
    else if (temp_scale == 2 && temp_conv == 1) {
        temp_final = fahrenheit_to_celsius(temp_val);
        temp_cat = temp_final;
        printf("Converted Temperature: %f*C\n", temp_final);
    }
    else if (temp_scale == 2 && temp_conv == 3) {
        temp_final = fahrenheit_to_kelvin(temp_val);
        temp_cat = fahrenheit_to_celsius(temp_val);
        printf("Converted Temperature: %fK\n", temp_final);
    }
    else if (temp_scale == 3 && temp_conv == 1) {
        temp_final = kelvin_to_celsius(temp_val);
        temp_cat = temp_final;
        printf("Converted Temperature: %f*C\n", temp_final);
    }
    else if (temp_scale == 3 && temp_conv == 2) {
        temp_final = kelvin_to_fahrenheit(temp_val);
        temp_cat = kelvin_to_celsius(temp_val);
        printf("Converted Temperature: %f*F\n", temp_final);
    }
temperature_catagory_evaluator(temp_cat);
return 0;
}