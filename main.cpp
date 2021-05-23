#include <iostream>
#include <cassert>

const int CHANNELS_COUNT = 10; // important to be used as global. Defines the length of channels array.

void getChannelsList(float* channels)
{
    std::cout << "-----Reading the channels list\n";
    for (int i = 0; i < CHANNELS_COUNT; i++)
    {
        std::cout << "Channel " << i << ": " << channels[i] << " FM.\n";
    }
    std::cout << "-----End of Reading\n";
}

void setTheChannel(float* channels, int c)
{
    int i = c - 1;
    assert(i >= 0 && i < CHANNELS_COUNT);
    std::cout << "Channel " << c << " is set:\t" << channels[i] << "FM. \n";
}

int main() {

    float channels[CHANNELS_COUNT];
    for (int i = 0; i < CHANNELS_COUNT; i++)
    {
        channels[i] = 5.0f + (float) i * 14.5f; //5.0 and 14.5 are random number, just to make channels different and more like real FM.
    }
    std::cout << "-----Channels are set\n";

    getChannelsList(channels);

    int channel;
    while (true)
    {
        std::cout << "What channel you'd prefer? Enter the number from 1 to " << CHANNELS_COUNT << ": \n";
        std::cin >> channel;

        if (channel == 0) break;
        else if (channel < 0 || channel > CHANNELS_COUNT)
        {
            std::cerr << "Wrong channel number!\n";
            std::cout << "Please enter the channel from 1 to " << CHANNELS_COUNT << ".\n";
        }
        else
        {
            setTheChannel(channels, channel);
        }
    }

    std::cout << "-----Exit the radio.\n";
    return 0;
}
