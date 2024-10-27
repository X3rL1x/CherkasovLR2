#pragma once
#include <iostream>
#include <fstream>

struct Pipe
{
    std::string namepipe;

    float length;

    float diametr;

    bool repair;

};

struct NPZ
{
    std::string namenpz;

    int countfactry;

    int countfactrywork;

    int productivity;

};

void AddPipe(Pipe& pipe);

void RedactPipe(Pipe& pipe);

void AddNPZ(NPZ& npz);

void RedactNPZ(NPZ& npz);

void start();

void ViewAll(Pipe& pipe, NPZ& npz);

void Save(Pipe& pipe, NPZ& npz);

void Load(Pipe& pipe, NPZ& npz);