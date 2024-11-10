#include <iostream>

#include "Function.h"

#include <string>

#include <sstream>

#include <fstream>

#include <map>

#include <vector>

#include <ctime>

#include <algorithm>

#include <cctype>

#include <limits>

#include <chrono>

using namespace std;

void log(string a) {
	auto now = chrono::system_clock::now();
	time_t end_time = chrono::system_clock::to_time_t(now);
	char buffer[26];
	if (ctime_s(buffer, sizeof(buffer), &end_time) == 0) {
		ofstream logi("log.txt", ios::app);
		logi << buffer << " " << a << endl;
		logi.close();
	}
	else {
		cerr << "Error getting the current time." << endl;
	}
}

template<typename T> T Input(int mode, int mi, int ma, int foi){
		string str;
		T r;
		if (mode == 1) {
			if (foi == 1){
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
						if (!(ss >> r) || r < mi || r > ma) {
							cout << "Invalid input!" << endl;
						}
						else {
							return r;
							break;
						}
					}
				}
			}
			else{
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
						if (!(ss >> r) || r < mi || r > ma) {
							cout << "Invalid input!" << endl;
						}
						else {
							return r;
							break;
						}
					}
				}
			}
		}
		if (mode == 2) {
			if (foi == 1) {
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
						if (!(ss >> r) || r < 0) {
							cout << "Invalid input!" << endl;
						}
						else {
							return r;
							break;
						}
					}
				}
			}
			else{
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
					if (!(ss >> r) || r < 0) {
						cout << "Invalid input!" << endl;
					}
					else {
						return r;
						break;
					}
				}
			}
		}
	}
}

void start()
{
	log("Programm start");
	map<int, Pipe> pipes;
	map<int, NPZ> CSs;
	int idp = 0;
	int idc = 0;
	do
	{
		int c = 1;
		int f = 0;
		cout << "Choose number" << endl
			<< "1. Add pipe" << endl
			<< "2. Add NPZ" << endl
			<< "3. View all object" << endl
			<< "4. Redact pipe" << endl
			<< "5. Redact NPZ" << endl
			<< "6. Save" << endl
			<< "7. Load" << endl
			<< "8. Delete" << endl
			<< "9. Find" << endl
			<< "0. Exit" << endl;

		c = Input<int>(1, 0, 9,0);

		switch (c)
		{
		case 1:
			cin.clear();
			log("User select case 1");
			AddPipe(pipes, idp);
			break;
		case 2:
			cin.clear();
			log("User select case 2");
			AddNPZ(CSs, idc);
			break;
		case 3:
			cin.clear();
			log("User select case 3");
			ViewPipe(pipes,idp);
			ViewCSs(CSs, idc);
			break;
		case 4:
			cin.clear();
			log("User select case 4");
			RedactPipe(pipes, idp);
			break;
		case 5:
			cin.clear();
			log("User select case 5");
			RedactNPZ(CSs, idc);
			break;
		case 6:
			cin.clear();
			log("User select case 6");
			Save(pipes, idp, CSs, idc);
			break;
		case 7:
			cin.clear();
			log("User select case 7");
			Load(pipes,idp, CSs, idc);
			break;
		case 8:
			cin.clear();
			log("User select case 8");
			Remove(pipes, CSs, idp, idc);
			break;
		case 9:
			cin.clear();
			log("User select case 9");
			Find(pipes, CSs, idp, idc);
			break;
		case 0:
			log("User select case 0");
			cin.clear();
			exit(0);
		default:
			cin.clear();
			cout << "Input error! Try again" << endl;
		}
	} while (true);
}
void Remove(map<int, Pipe>& pipes, map<int, NPZ>& CSs, int idp, int idc) {
	cout << endl << "Select the type of object you want to delete (1 - pipe, 2 - CS)" << endl;
	string str;
	int ch;
	int ch1;
	ch = Input<int>(1, 1, 2, 0);
	cout << "Select the index of object you want to delete" << endl;
	if (ch == 1) {
		ch1 = Input<int>(1, 1, idp,0);
		pipes.erase(ch1);
		log("User delete pipe " + to_string(ch1));
	}
	else {
		ch1 = Input<int>(1, 1, idc, 0);
		CSs.erase(ch1);
		log("User delete CS " + to_string(ch1));
	}

}

void AddPipe(map<int, Pipe>& pipes, int& idp)
{
	idp++;

	cout << "input name" << endl;

	getline(cin, pipes[idp].namepipe);

	cout << "input length" << endl;

	pipes[idp].length = Input<float>(2, 1, 0, 1);

	cout << "input diametr" << endl;

	pipes[idp].diametr = Input<float>(2, 1, 0, 1);

	cout << "Repair? (1 or 0)" << endl;

	pipes[idp].repair = Input<int>(1, 0, 1, 0);

	cin.clear();

	log("User add pipe with name: " + pipes[idp].namepipe + ", id: " + to_string(idp));
}

void RedactPipe(map<int, Pipe>& pipes, int& idp)
{
	if (pipes[idp].length > 0)
	{
		if (pipes[idp].repair == 1)
		{
			pipes[idp].repair = 0;
		}
		else
		{
			pipes[idp].repair = 1;
		}
		log("User change pipe with id: " + to_string(idp));
	}
	else
	{
		cout << "Pipe does not exist!" << endl;

		log("User cant change pipe with id: " + to_string(idp));
	}
}

void AddNPZ(map<int, NPZ>& CSs, int& idc)
{
	idc++;

	cout << "input name" << endl;

	getline(cin, CSs[idc].namenpz);

	cout << "input count factory" << endl;

	CSs[idc].countfactry = Input<int>(2, 1, 0, 1);

	cout << "input count factory work" << endl;

	CSs[idc].countfactrywork = Input<int>(1, 1, CSs[idc].countfactry,0);

	cout << "input productivity" << endl;

	CSs[idc].productivity = Input<int>(2, 1, 0, 0);

	CSs[idc].percentage = (CSs[idc] / CSs[idc]);

	log("User add CS with name: " + CSs[idc].namenpz + ", id: " + to_string(idc));

	cin.clear();
}

void RedactNPZ(map<int, NPZ>& CSs, int& idc)
{

	if (CSs[idc].countfactry > 0)
	{

		cout << "input count factory" << endl;

		CSs[idc].countfactrywork = Input<int>(1, 1, CSs[idc].countfactry, 0);
		
		CSs[idc].percentage = round(((CSs[idc].countfactry - CSs[idc].countfactrywork) * 1.0 / CSs[idc].countfactry) * 100);

		log("User change pipe with id: " + to_string(idc));
	}

	else
	{
		cout << "CS does not exist!" << endl;

		log("User cant change CS with id: " + to_string(idc));
	}
}

void ViewPipe(map<int, Pipe>& pipes, int& idp)
{
	if (pipes.size() > 0) {
		int en = pipes.rbegin()->first;
		cout << endl << "ALL PIPES:" << endl << endl;
		for (int ch = 1; ch <= en; ch++)
		{
			if (pipes[ch].length > 0)
			{
				cout << "Name pipe" << endl
					<< pipes[ch].namepipe << endl
					<< "Pipe ID" << endl
					<< ch << endl
					<< "Pipe length" << endl
					<< pipes[ch].length << endl
					<< "Pipe diametr" << endl
					<< pipes[ch].diametr << endl
					<< "Need repair?" << endl
					<< pipes[ch].repair << endl << endl;
			}
			else {
				cout << "Not found(" << endl;
			}
		}
	}
	else {
		cout << endl << "Object pipes* empty(" << endl << endl;
	}
}

void ViewCSs(map<int, NPZ>&CSs, int& idc) {
	if (CSs.size() > 0) {
		int en = CSs.rbegin()->first;
		cout << endl << "ALL CS:" << endl << endl;
		for (int ch = 1; ch <= en; ch++)
		{
			if (CSs[ch].countfactry > 0)
			{
				cout << "Name CS" << endl
					<< CSs[ch].namenpz << endl
					<< "CS ID" << endl
					<< ch << endl
					<< "Count factory" << endl
					<< CSs[ch].countfactry << endl
					<< "Count Factory work" << endl
					<< CSs[ch].countfactrywork << endl
					<< "Productivity" << endl
					<< CSs[ch].productivity << endl
					<< "%" << endl
					<< CSs[ch].percentage << endl << endl;;
			}
			else {
				cout << "Not found(" << endl;
			}
		}
	}
	else {
		cout << endl << "Object CS* empty(" << endl << endl;
	}
}
void Save(map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc)
{
	ofstream SaveFile("savefile.txt");
	if (pipes.size() > 0) {
	int en = idp;
		for (int i=1; i <= en; i++) {
			if (pipes[i].length != 0)
			{
				string g = to_string(i);

				SaveFile << "np" << '-' << g << '/' << pipes[i].namepipe << endl;

				SaveFile << "lp" << '-' << g << '/' << pipes[i].length << endl;

				SaveFile << "dp" << '-' << g << '/' << pipes[i].diametr << endl;

				SaveFile << "rp" << '-' << g << '/' << pipes[i].repair << endl;

			}
		}
		cout << "pipes saves succesfully)" << endl << endl;
	}
	else {
		cout << "couldn't save because pipes* empty(" << endl << endl;
	}

	if (CSs.size() > 0) {
		int en = idc;
		for (int i=1; i <= en; i++) {
			if (CSs[i].countfactry != 0)
			{
				string g = to_string(i);

				SaveFile << "nn" << '-' << g << '/' << CSs[i].namenpz << endl;

				SaveFile << "cn" << '-' << g << '/' << CSs[i].countfactry << endl;

				SaveFile << "wn" << '-' << g << '/' << CSs[i].countfactrywork << endl;

				SaveFile << "pn" << '-' << g << '/' << CSs[i].productivity << endl;

			}
		}
		cout << "CSs saves succesfully)" << endl << endl;
	}
	else {
		cout << "couldn't save because CSs* empty(" << endl << endl;
	}
	SaveFile.close();
}

void Load(map<int, Pipe>& pipes, int& idp, std::map<int, NPZ>& CSs, int& idc) {

	ifstream fin("savefile.txt");

	string line;

	int maxidc = 0;

	int maxidp = 0;

	pipes.clear();

	CSs.clear();

	if (!fin)
	{
		cout << "File could not be created!" << endl;
	}
	else
	{
		int id;
		int pos;
		while (getline(fin, line)) {
			if (line.find("np") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3,pos-3));
				pipes[id].namepipe = line.substr(pos + 1);
				if (maxidp < id) { maxidp = id;}
			}

			if (line.find("lp") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3, pos - 3));
				pipes[id].length = stof(line.substr(pos + 1));
				if (maxidp < id) { maxidp = id; }
			}

			if (line.find("dp") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3, pos - 3));
				pipes[id].diametr = stof(line.substr(pos + 1));
				if (maxidp < id) { maxidp = id; }
			}

			if (line.find("rp") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3, pos - 3));
				pipes[id].repair = stoi(line.substr(pos + 1));
				if (maxidp < id) { maxidp = id; }
			}

			if (line.find("nn") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3, pos - 3));
				CSs[id].namenpz = line.substr(pos + 1);
				if (maxidc < id) { maxidc = id; }
			}

			if (line.find("cn") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3, pos - 3));
				CSs[id].countfactry = stoi(line.substr(pos + 1));
				if (maxidc < id) { maxidc = id; }
			}

			if (line.find("wn") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3, pos - 3));
				CSs[id].countfactrywork = stoi(line.substr(pos + 1));
				if (maxidc < id) { maxidc = id; }
			}

			if (line.find("pn") == 0) {
				pos = line.find('/');
				id = stoi(line.substr(3, pos - 3));
				CSs[id].productivity = stoi(line.substr(pos + 1));
				if (maxidc < id) { maxidc = id; }
			}

		}
	}
	if (idc < maxidc) { idc = maxidc; }
	if (idp < maxidp) { idp = maxidp; }
	fin.close();
}

void Find(map<int, Pipe>& pipes, std::map<int, NPZ>& CSs, int idp, int idc) {
	int ch1;
	int ch2;
	int ch3;
	int ch5;
	int i=1;
	string ch4;
	map<int, Pipe> findpipe;
	map<int, NPZ> findcs;
	vector<int>id;
	vector<int>allid;
	cout << "input type of object you find (1 - pipe, 2 - CS)" << endl;
	ch1 = Input<int>(1, 1, 2, 0);
	cout << "By what criteria should the program search for an object (if pipe: 1 - name, 2 - repair; if CS: 1 - name, 2 - by the percentage of unused workshops)" << endl;
	ch2 = Input<int>(1, 1, 2, 0);
	if (ch1 == 1 and ch2 == 1) {
		cout << "Input name" << endl<< endl;
		getline(cin, ch4);
		if (!pipes.empty()) {
			for (const auto& pipe : pipes) {
				if (pipe.second.namepipe.find(ch4) == 0) {
					findpipe.insert({ pipe.first, pipe.second });
				}
			}
			cout << "Id found pipes" << endl << endl;
			for (const auto& pipe : findpipe) {
				cout << pipe.first << " " << pipe.second.namepipe << endl<< endl;
				allid.push_back(pipe.first);
			}
			log("User find pipe with name" + ch4);
			cout << "Edit objects?" << endl;
			ch3 = Input<int>(1, 0, 1, 0);
			if (ch3 == 1) {
				cout << "Edit everything or selectively? (0 - everything, 1 - selectively)" << endl;
				ch5 = Input<int>(1, 0, 1, 0);
				if (ch5 == 1) {
					cout << "Enter the id through the entre. If all objects are entered, then enter 0" << endl;
					while (i != 0) {
						i = Input<int>(2, 0, 0, 0);
						if (i != 0) {
							id.push_back(i);
						}
					}
					for (int l : id) {
						RedactPipe(pipes, l);
					}
				}
				if(ch5 != 1) {
					for (int l : allid) {
						RedactPipe(pipes, l);
					}
				}
			}
		}
		else {
			cout << "The 'pipes' map is empty." << endl;
		}
	}
	if (ch1 == 1 and ch2 == 2) {
		cout << "Input repair count (1 - repair, 0 - no breakdowns)" << endl << endl;
		ch3 = Input<int>(1,0,1,0);
		if (!pipes.empty()) {
			for (const auto& pipe : pipes) {
				if (pipe.second.repair == ch3) {
					findpipe.insert({ pipe.first, pipe.second });
				}
			}
			cout << "Id found pipes:" << endl << endl;
			for (const auto& pipe : findpipe) {
				cout << pipe.first << " " << pipe.second.namepipe << endl<<endl;
				allid.push_back(pipe.first);
			}
			log("User find pipe with repair count" + to_string(ch3));
			cout << "Edit objects?" << endl;
			ch3 = Input<int>(1, 0, 1, 0);
			if (ch3 == 1) {
				cout << "Edit everything or selectively? (0 - everything, 1 - selectively)" << endl;
				ch5 = Input<int>(1, 0, 1, 0);
				if (ch5 == 1) {
					cout << "Enter the id through the entre. If all objects are entered, then enter 0" << endl;
					while (i != 0) {
						i = Input<int>(2, 0, 0, 0);
						if (i != 0) {
							id.push_back(i);
						}
					}
					for (int l : id) {
						RedactPipe(pipes, l);
					}
				}
				if (ch5 != 1) {
					for (int l : allid) {
						RedactPipe(pipes, l);
					}
				}
			}
		}
		else {
			cout << "The 'pipes' map is empty." << endl;
		}
	}
	if (ch1 == 2 and ch2 == 1) {
		cout << "Input name" << endl << endl;
		getline(cin, ch4);
		if (!CSs.empty()) {
			for (const auto& cs : CSs) {
				if (cs.second.namenpz.find(ch4) == 0) {
					findcs.insert({ cs.first, cs.second });
				}
			}
			cout << "cs's id found" << endl << endl;
			for (const auto& cs : findcs) {
				cout << cs.first << " " << cs.second.namenpz << endl << endl;
				allid.push_back(cs.first);
			}
			log("User find CS with name" + ch4);
			cout << "Edit objects?" << endl;
			ch3 = Input<int>(1, 0, 1, 0);
			if (ch3 == 1) {
				cout << "Edit everything or selectively? (0 - everything, 1 - selectively)" << endl;
				ch5 = Input<int>(1, 0, 1, 0);
				if (ch5 == 1) {
					cout << "Enter the id through the entre. If all objects are entered, then enter 0" << endl;
					while (i != 0) {
						i = Input<int>(2, 0, 0, 0);
						if (i != 0) {
							id.push_back(i);
						}
					}
					for (int l : id) {
						cout << "You redact CS - " << CSs[l].namenpz << " (Count factory - " << CSs[l].countfactry << ")" << endl;
						RedactNPZ(CSs, l);
					}
				}
				if (ch5 != 1) {
					for (int l : allid) {
						cout << "You redact CS - " << CSs[l].namenpz << " (Count factory - " << CSs[l].countfactry << ")" << endl;
						RedactNPZ(CSs, l);
					}
				}
			}
		}
		else {
			cout << "The 'CS' map is empty." << endl;
		}
	}
	if (ch1 == 2 and ch2 == 2) {
		cout << "Input precentage (integer value)" << endl << endl;
		ch3 = Input<int>(1, 0, 100, 0);
		if (!CSs.empty()) {
			for (const auto& cs : CSs) {
				if (cs.second.percentage == ch3) {
					findcs.insert({ cs.first, cs.second });
				}
			}
			cout << "CS id found" << endl << endl;
			for (const auto& cs : findcs) {
				cout << cs.first << " " << cs.second.namenpz << endl << endl;
				allid.push_back(cs.first);
			}
			log("User find CS with pecent" + to_string(ch3));
			cout << "Edit objects?" << endl;
			ch3 = Input<int>(1, 0, 1, 0);
			if (ch3 == 1) {
				cout << "Edit everything or selectively? (0 - everything, 1 - selectively)" << endl;
				ch5 = Input<int>(1, 0, 1, 0);
				if (ch5 == 1) {
					cout << "Enter the id through the entre. If all objects are entered, then enter 0" << endl;
					while (i != 0) {
						i = Input<int>(2, 0, 0, 0);
						if (i != 0) {
							id.push_back(i);
						}
					}
					for (int l : id) {
						cout << "You redact CS - " << CSs[l].namenpz << " (Count factory - " << CSs[l].countfactry << ")" << endl;
						RedactNPZ(CSs, l);
					}
				}
				if (ch5 != 1) {
					for (int l : allid) {
						cout << "You redact CS - " << CSs[l].namenpz << " (Count factory - " << CSs[l].countfactry << ")" << endl;
						RedactNPZ(CSs, l);
					}
				}
			}
		}
		else {
			cout << "The 'CS' map is empty." << endl;
		}
	}
}
















