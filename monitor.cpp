#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
void DisplayAlert (const std::string& message)
{
    cout << message;
    for (int i = 0; i < 6; i++)
    {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}
int IsTempOk(float temperature)
  {
     if (temperature > 102 || temperature < 95)
     {
     DisplayAlert("Temperature is critical!\n");
    return 0;
     }
    return 1;
  }
int IsPulseOk(float pulseRate)
  {
    if (pulseRate < 60 || pulseRate > 100)
    {
    DisplayAlert("Pulse Rate is out of range!\n");
    return 0;
    }
    return 1;
  }

int IsSpoOk(float spo2)
  {
   if (spo2 < 90)
   {
    DisplayAlert("Oxygen Saturation out of range!\n");
    return 0;
   }
    return 1;
  }
int vitalsOk(float temperature, float pulseRate, float spo2) {
return IsTempOk(temperature) && IsPulseOk(pulseRate) && IsSpoOk(spo2);
}
