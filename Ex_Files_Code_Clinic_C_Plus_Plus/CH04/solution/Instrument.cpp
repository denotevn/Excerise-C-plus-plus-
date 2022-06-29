/**
 * Instrument.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "Instrument.hpp"

using namespace std;

Instrument::Instrument()
{
    // configure audio settings
    memset(&format_, 0, sizeof(format_));
    format_.bits = 16; // store samples as int8_t
    format_.channels = 1;
    format_.rate = 44100;
    format_.byte_format = AO_FMT_LITTLE;

    // initialize and setup for default driver
    ao_initialize();
    int defaultDriver = ao_default_driver_id();
    device_ = ao_open_live(defaultDriver, &format_, NULL);
    if (device_ == NULL)
    {
        cerr << "ERROR: Failed to open audio device" << endl;
        exit(1);
    }

    // allocate buffer for audio samples
    bufferSize_ = format_.bits/8 * format_.channels * format_.rate * (float)UPDATE_PERIOD_MS/1000;
    buffer_ = (char *)calloc(bufferSize_, sizeof(char));
    if (buffer_ == NULL)
    {
        cerr << "ERROR: Could not allocated memory for buffer" << endl;
        exit(1);
    }

    instrumentActive_ = true;   // the instrument is "turned on"...
    instrumentPlaying_ = false; //   but it is not currently making sound
    playerThread_ = thread([this] { playerLoop(); }); // start a thread to call ao_play() repeatedly
}

void Instrument::play(int x, int y, int winWidth, int winHeight)
{
    float frequency = (float)(winHeight - y + 1) / (winHeight + 1) * (MAX_FREQ - MIN_FREQ) + MIN_FREQ;
    float volume = (float)x / winWidth;

    int sample;
    for (int i=0; i<bufferSize_/2; i++) 
    {
        sample = volume * 32768.0 * sin(2 * M_PI * frequency * ((float) i / format_.rate));
        buffer_[2*i] = sample & 0xff;
        buffer_[2*i+1] = (sample >> 8) & 0xff;
    }

    instrumentPlaying_ = true;
}

void Instrument::pause()
{
    instrumentPlaying_ = false;
}

void Instrument::destroy()
{
    instrumentActive_ = false;
    instrumentPlaying_ = false;
    playerThread_.join();
    ao_close(device_);
    ao_shutdown();
}

void Instrument::playerLoop()
{
    while (instrumentActive_) {
        while (instrumentPlaying_)
        {
            ao_play(device_, buffer_, bufferSize_);
           this_thread::sleep_for(chrono::milliseconds(UPDATE_PERIOD_MS));
        }
        this_thread::sleep_for(chrono::milliseconds(UPDATE_PERIOD_MS));
    }
}