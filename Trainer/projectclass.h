#pragma once



class Project {       // The class
public:             // Access specifier
    std::string projectName;        // Attribute (int variable)
    std::string projectFolder;
    std::time_t lastEdited;  // Attribute (string variable)
};

bool createProjectJSON(Project project) {

    std::string path = (project.projectFolder + "\\project.json");
    std::ofstream projectJSON( path);

    projectJSON << "fuck" << std::endl;
    return true;
}
