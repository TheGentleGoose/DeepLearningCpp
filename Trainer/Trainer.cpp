// Trainer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ctime>

#include "projectclass.h"

using std::filesystem::current_path;

namespace fs = std::filesystem;



std::string* findProjects() {
    std::string* projectNames = new std::string[20];

    return projectNames;
}

std::string timerToString(std::time_t timer) {
    char str[26];
    ctime_s(str, sizeof str, &timer);
    return str;
}

std::string newProject() {
    std::cout << "Opening a new Project.\nWhat should it be called?\n";
    std::string folderStr = "";
    std::string name = "";
    std::cin >> name;
    std::cout << "Opening a new project called '"<< name <<"'\n";
    folderStr = current_path().u8string() + "\\projects\\" + name;
    std::cout << "Attempting to create folder at " << folderStr <<"\n";
    fs::create_directories(folderStr);
    std::cout << "Created a folder at " << folderStr << "\n";


    //creates a new project
    Project newproject;
    newproject.projectName = name;
    newproject.projectFolder = folderStr;
    newproject.lastEdited = time(0);

    createProjectJSON(newproject);

    return "";
}

int loadProject() {
    return 0;
}

int main()
{


    std::cout << "Welcome to TheGoose's Deep learning experiment\n";

    //TODO: detect projects

    std::string response = "";
    while ((response != "y") && (response != "n")) {
        response = "";
        std::cout << "Would you like to load a previous project?\n";
        std::cin >> response;

    }

    if (response == "y") {
        loadProject();
    }
    else {
        newProject();
    }

    
    system("pause");
}



/*
int loadParameters() {

    // Gets a profile string called "Preferred line" and converts it to an int.
    GetPrivateProfileString(
        "Preference",
        "Preferred Line",
        gszNULL,
        szBuffer,
        MAXBUFSIZE,
        gszINIfilename
    );
}
*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
