#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include "Pipe_s.h"
#include "CS_s.h"
#include "Connect.h"

using namespace std;

void AddPipe(std::map<int, Pipe>& pipes, int& idp, vector<int>& pipeid);

void RedactPipe(std::map<int, Pipe>& pipes, int& idp);

void AddNPZ(std::map<int, NPZ>& CSs, int& idc, vector<int>& CSsid);

void RedactNPZ(std::map<int, NPZ>& CSs, int& idc);

void start();

void show_vector(vector<int>& a);

void Topolsort(map<int, Conn>& Conn, int& idc);

vector<vector<int>> createAdjacencyMatrix(const map<int, Conn>& edges, int numVertices);

vector<int> topologicalSort(const vector<vector<int>>& matrix);

void printAdjacencyMatrix(const vector<vector<int>>& matrix);

void addconn(map<int, Conn>& Conn, vector<int>& pipeid, vector<int>& CSsid);

void ViewPipe(std::map<int, Pipe>& pipes, int& idp);

void ViewCSs(std::map<int, NPZ>& CSs, int& idc);

void Save(std::map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc);

void Load(std::map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc);

void Remove(std::map<int, Pipe>& pipes, std::map<int, NPZ>& CSs, int idp, int idc);

void Find(std::map<int, Pipe>& pipes, std::map<int, NPZ>& CSs, int idp, int idc);

template<typename T> T Input(const int mode,const int mi, const int ma, const int foi);

void log(std::string a);