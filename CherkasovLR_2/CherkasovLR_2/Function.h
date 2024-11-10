#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include "Pipe_s.h"
#include "CS_s.h"

void AddPipe(std::map<int, Pipe>& pipes, int& idp);

void RedactPipe(std::map<int, Pipe>& pipes, int& idp);

void AddNPZ(std::map<int, NPZ>& CSs, int& idc);

void RedactNPZ(std::map<int, NPZ>& CSs, int& idc);

void start();

void ViewPipe(std::map<int, Pipe>& pipes, int& idp);

void ViewCSs(std::map<int, NPZ>& CSs, int& idc);

void Save(std::map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc);

void Load(std::map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc);

void Remove(std::map<int, Pipe>& pipes, std::map<int, NPZ>& CSs, int idp, int idc);

void Find(std::map<int, Pipe>& pipes, std::map<int, NPZ>& CSs, int idp, int idc);

template<typename T> T Input(const int mode,const int mi, const int ma, const int foi);

void log(std::string a);