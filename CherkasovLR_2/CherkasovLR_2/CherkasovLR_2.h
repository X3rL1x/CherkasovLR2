#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

class Pipe
{
public:

    std::string namepipe = "None";

    float length = 0;

    float diametr = 0;

    bool repair = 0;

};

class NPZ
{
public:

    std::string namenpz = "None";

    int countfactry = 0;

    int countfactrywork = 0;

    int productivity = 0;
    
    float percentage = 0;

    void ChName (){

    }

};

void AddPipe(std::map<int,Pipe>& pipes, int& idp);

void RedactPipe(std::map<int, Pipe>& pipes, int& idp);

void AddNPZ(std::map<int, NPZ>& CSs, int& idc);

void RedactNPZ(std::map<int, NPZ>& CSs,int& idc);

void start();

void ViewPipe(std::map<int, Pipe>& pipes, int& idp);

void ViewCSs(std::map<int, NPZ>& CSs, int& idc);

void Save(std::map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc);

void Load(std::map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc);

void Remove(std::map<int, Pipe>& pipes, std::map<int, NPZ>& CSs, int idp, int idc);

void Find(std::map<int, Pipe>& pipes, std::map<int, NPZ>& CSs, int idp, int idc);

int Inputint(int mode, int mi, int ma);

float Inputfl(int mode, int mi, int ma);

void RedactFoundPipe(std::map<int, Pipe>& pipes,std::vector<int>);

void RedactFoundCS(std::map<int, NPZ>& CSs,std::vector<int>);

void log();