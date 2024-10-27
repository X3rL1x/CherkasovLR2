#include <iostream>

#include "CherkasovLR_2.h"

#include <string>

#include <sstream>

#include <fstream>

using namespace std;

void start()
{
	Pipe pipe;
	pipe.namepipe = "Not specified";
	pipe.length = 0.;
	pipe.diametr = 0.;
	pipe.repair = true;
	NPZ npz;
	npz.countfactry = 0;
	npz.countfactrywork = 0;
	npz.namenpz = "Not specified";
	npz.productivity = 0;
	do
	{
		int c;
		string w;
		int f = 0;
		cout << "Choose number" << endl
			<< "1. Add pipe" << endl
			<< "2. Add NPZ" << endl
			<< "3. View all object" << endl
			<< "4. Edit pipe" << endl
			<< "5. Edit NPZ" << endl
			<< "6. Save" << endl
			<< "7. Load" << endl
			<< "0. Exit" << endl;

		while (true) {
			getline(cin, w);
			bool onlyDigits = true;
			for (char l : w) {
				if (!isdigit(l)) {
					onlyDigits = false;
					break;
				}
			}
			if (!onlyDigits) {
				cout << "Invalid input!" << endl;
			}
			else {
				stringstream ss(w);
				if (!(ss >> c) || c < 0 || c>7) {
					cout << "Invalid input!" << endl;
				}
				else {
					break;
				}
			}
		}

		switch (c)
		{
		case 1:
			cin.clear();
			AddPipe(pipe);
			break;
		case 2:
			cin.clear();
			AddNPZ(npz);
			break;
		case 3:
			cin.clear();
			ViewAll(pipe, npz);
			break;
		case 4:
			cin.clear();
			RedactPipe(pipe);
			break;
		case 5:
			cin.clear();
			RedactNPZ(npz);
			break;
		case 6:
			cin.clear();
			Save(pipe, npz);
			break;
		case 7:
			cin.clear();
			Load(pipe, npz);
			break;
		case 0:
			cin.clear();
			exit(1);
		default:
			cin.clear();
			cout << "Input error! Try again" << endl;
		}
	} while (true);
}

void AddPipe(Pipe& pipe)
{
	cout << "input name" << endl;

	getline(cin, pipe.namepipe);

	cout << "input length" << endl;

	string str;

	while (true) {
		getline(cin, str);
		bool onlyDigits = true;
		for (char c : str) {
			if (!isdigit(c) and c != '.') {
				onlyDigits = false;
				break;
			}
		}
		if (!onlyDigits) {
			cout << "Invalid input!" << endl;
		}
		else {
			stringstream ss(str);
			if (!(ss >> pipe.length) || pipe.length <= 0) {
				cout << "Invalid input!" << endl;
			}
			else {
				break;
			}
		}
	}

	cout << "input diametr" << endl;

	while (true) {
		getline(cin, str);
		bool onlyDigits = true;
		for (char c : str) {
			if (!isdigit(c) and c != '.') {
				onlyDigits = false;
				break;
			}
		}
		if (!onlyDigits) {
			cout << "Invalid input!" << endl;
		}
		else {
			stringstream ss(str);
			if (!(ss >> pipe.diametr) || pipe.diametr <= 0) {
				cout << "Invalid input!" << endl;
			}
			else {
				break;
			}
		}
	}

	cout << "Repair? (1 or 0)" << endl;

	while (true) {
		getline(cin, str);
		bool onlyDigits = true;
		for (char c : str) {
			if (!isdigit(c)) {
				onlyDigits = false;
				break;
			}
		}
		if (!onlyDigits) {
			cout << "Invalid input!" << endl;
		}
		else {
			stringstream ss(str);
			if (!(ss >> pipe.repair) || pipe.repair < 0 || pipe.repair >1) {
				cout << "Invalid input!" << endl;
			}
			else {
				break;
			}
		}
	}

	cin.clear();
}

void RedactPipe(Pipe& pipe)
{
	if (pipe.length > 0)
	{
		if (pipe.repair == 1)
		{
			pipe.repair = 0;
		}
		else
		{
			pipe.repair = 1;
		}
	}
	else
	{
		cout << "Pipe does not exist!" << endl;
	}
}

void AddNPZ(NPZ& npz)
{
	cout << "input name" << endl;

	getline(cin, npz.namenpz);

	cout << "input count factory" << endl;

	string str;

	while (true) {
		getline(cin, str);
		bool onlyDigits = true;
		for (char c : str) {
			if (!isdigit(c)) {
				onlyDigits = false;
				break;
			}
		}
		if (!onlyDigits) {
			cout << "Invalid input!" << endl;
		}
		else {
			stringstream ss(str);
			if (!(ss >> npz.countfactry) || npz.countfactry <= 0) {
				cout << "Invalid input!" << endl;
			}
			else {
				break;
			}
		}
	}

	cout << "input count factory work" << endl;

	while (true) {
		getline(cin, str);
		bool onlyDigits = true;
		for (char c : str) {
			if (!isdigit(c)) {
				onlyDigits = false;
				break;
			}
		}
		if (!onlyDigits) {
			cout << "Invalid input!" << endl;
		}
		else {
			stringstream ss(str);
			if (!(ss >> npz.countfactrywork) || npz.countfactrywork < 0 || npz.countfactrywork>npz.countfactry) {
				cout << "Invalid input!" << endl;
			}
			else {
				break;
			}
		}
	}

	cout << "input productivity" << endl;

	while (true) {
		getline(cin, str);
		bool onlyDigits = true;
		for (char c : str) {
			if (!isdigit(c)) {
				onlyDigits = false;
				break;
			}
		}
		if (!onlyDigits) {
			cout << "Invalid input!" << endl;
		}
		else {
			stringstream ss(str);
			if (!(ss >> npz.productivity) || npz.productivity <= 0) {
				cout << "Invalid input!" << endl;
			}
			else {
				break;
			}
		}
	}
}

void RedactNPZ(NPZ& npz)
{
	if (npz.countfactry > 0)
	{

		cout << "input count factory" << endl;

		string str;

		while (true) {
			getline(cin, str);
			bool onlyDigits = true;
			for (char c : str) {
				if (!isdigit(c)) {
					onlyDigits = false;
					break;
				}
			}
			if (!onlyDigits) {
				cout << "Invalid input!" << endl;
			}
			else {
				stringstream ss(str);
				if (!(ss >> npz.countfactrywork) || npz.countfactrywork < 0 || npz.countfactrywork>npz.countfactry) {
					cout << "Invalid input!" << endl;
				}
				else {
					break;
				}
			}
		}

	}

	else
	{
		cout << "NPZ does not exist!" << endl;
	}
}

void ViewAll(Pipe& pipe, NPZ& npz)
{
	if (pipe.length > 0)
	{
		cout << "Name pipe" << endl
			<< pipe.namepipe << endl
			<< "Pipe length" << endl
			<< pipe.length << endl
			<< "Pipe diametr" << endl
			<< pipe.diametr << endl
			<< "Need repair?" << endl
			<< pipe.repair << endl << endl;
	}
	if (npz.countfactry > 0)
	{
		cout << "Name NPZ" << endl
			<< npz.namenpz << endl
			<< "Count factory" << endl
			<< npz.countfactry << endl
			<< "Count factory active" << endl
			<< npz.countfactrywork << endl
			<< "Productivity" << endl
			<< npz.productivity << endl << endl;
	}
}

void Save(Pipe& pipe, NPZ& npz)
{
	ofstream SaveFile("savefile.txt");

	if (pipe.length != 0)

	{
		SaveFile << "np" << pipe.namepipe << endl;

		SaveFile << "lp" << pipe.length << endl;

		SaveFile << "dp" << pipe.diametr << endl;

		SaveFile << "rp" << pipe.repair << endl;

	}

	if (npz.countfactry != 0)

	{

		SaveFile << "nn" << npz.namenpz << endl;

		SaveFile << "cn" << npz.countfactry << endl;

		SaveFile << "wn" << npz.countfactrywork << endl;

		SaveFile << "pn" << npz.productivity << endl;

	}

	SaveFile.close();
}

void Load(Pipe& pipe, NPZ& npz) {

	ifstream fin("savefile.txt");

	string line;

	if (!fin)
	{
		cout << "File could not be created!" << endl;
	}
	else
	{
		while (getline(fin, line)) {
			if (line.find("np") == 0) {
				pipe.namepipe = line.substr(2);
			}

			if (line.find("lp") == 0) {
				pipe.length = stof(line.substr(2));
			}

			if (line.find("dp") == 0) {
				pipe.diametr = stof(line.substr(2));
			}

			if (line.find("rp") == 0) {
				pipe.repair = stoi(line.substr(2));
			}

			if (line.find("nn") == 0) {
				npz.namenpz = line.substr(2);
			}
			if (line.find("cn") == 0) {
				npz.countfactry = stoi(line.substr(2));
			}

			if (line.find("wn") == 0) {
				npz.countfactrywork = stoi(line.substr(2));;
			}

			if (line.find("pn") == 0) {
				npz.productivity = stoi(line.substr(2));
			}

		}
	}

	fin.close();
}

int main()
{
    start();
}