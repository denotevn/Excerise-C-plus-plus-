/**
 * Instrument.hpp by Olivia Stone for Code Clinic: C++
 **/

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#define UPDATE_PERIOD_MS 50 // update period in milliseconds
#define MIN_FREQ 100
#define MAX_FREQ 800

#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include <cmath>

#include <ao/ao.h> // Audio support https://xiph.org/ao/

class Instrument
{
public:
    Instrument();
    void play(int x, int y, int winWidth, int winHeight);
    void pause();
    void destroy();

private:
    ao_device *device_;
	ao_sample_format format_;
	char *buffer_ = NULL;
	int bufferSize_ = 0;
    bool instrumentActive_ = false;  // is the instrument "turned on"?
    bool instrumentPlaying_ = false; // is the instrument making sound?
    std::thread playerThread_;

    void playerLoop(); // run as thread to call ao_play() in a loop
};

#endif // INSTRUMENT_H_