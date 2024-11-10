#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

class NPZ
{
public:

    std::string namenpz = "None";

    int countfactry = 0;

    int countfactrywork = 0;

    int productivity = 0;

    float percentage = 0;

    float operator/(NPZ& other)
    {
        if (other.countfactry == 0)
        {
            return 0;
        }

        float percent = ((float)(other.countfactry - other.countfactrywork) / other.countfactry) * 100;

        return round(percent);
    }

};