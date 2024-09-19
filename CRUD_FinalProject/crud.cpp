#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

// Function to parse URL-encoded data (POST/GET request data)
std::map<std::string, std::string> parseData(const std::string& data) {
    std::map<std::string, std::string> result;
    std::string key, value;
    bool isKey = true;
    
    for (char ch : data) {
        if (ch == '=') {
            isKey = false;
        } else if (ch == '&') {
            result[key] = value;
            key.clear();
            value.clear();
            isKey = true;
        } else {
            if (isKey) key += ch;
            else value += ch;
        }
    }
    
    if (!key.empty() && !value.empty()) {
        result[key] = value;
    }
    
    return result;
}

// Function to add a record to the file
void addRecord(const std::string& name, const std::string& address, const std::string& phone) {
    std::ofstream file("C:/xampp/cgi-bin/records.txt", std::ios::app);
    file << name << "|" << address << "|" << phone << "\n";
    file.close();
}

// Function to update a record (rewrites the file)
void updateRecord(const std::string& name, const std::string& newAddress, const std::string& newPhone) {
    std::ifstream file("C:/xampp/cgi-bin/records.txt");
    std::ofstream tempFile("C:/xampp/cgi-bin/temp.txt");
    std::string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        if (pos1 != std::string::npos) {
            std::string currentName = line.substr(0, pos1);
            if (currentName == name) {
                // Update the record with the new data
                tempFile << name << "|" << newAddress << "|" << newPhone << "\n";
                found = true;
            } else {
                tempFile << line << "\n";
            }
        }
    }

    file.close();
    tempFile.close();
    
    remove("C:/xampp/cgi-bin/records.txt");
    rename("C:/xampp/cgi-bin/temp.txt", "C:/xampp/cgi-bin/records.txt");

    if (found) {
        std::cout << "<p>Record updated successfully!</p>";
    } else {
        std::cout << "<p>Record not found!</p>";
    }
}

// Function to delete a record
void deleteRecord(const std::string& name) {
    std::ifstream file("C:/xampp/cgi-bin/records.txt");
    std::ofstream tempFile("C:/xampp/cgi-bin/temp.txt");
    std::string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        if (pos1 != std::string::npos) {
            std::string currentName = line.substr(0, pos1);
            if (currentName == name) {
                found = true;  // Mark the record as found and skip writing it to the temp file
            } else {
                tempFile << line << "\n";  // Write all other records except the deleted one
            }
        }
    }

    file.close();
    tempFile.close();
    
    remove("C:/xampp/cgi-bin/records.txt");
    rename("C:/xampp/cgi-bin/temp.txt", "C:/xampp/cgi-bin/records.txt");

    if (found) {
        std::cout << "<p>Record deleted successfully!</p>";
    } else {
        std::cout << "<p>Record not found!</p>";
    }
}

int main() {
    std::cout << "Content-Type: text/html\n\n";
    std::cout << "<html><body>";
    
    std::string requestMethod = getenv("REQUEST_METHOD");
    std::string data;
    
    if (requestMethod == "POST") {
        char* contentLength = getenv("CONTENT_LENGTH");
        int len = contentLength ? atoi(contentLength) : 0;
        char ch;
        for (int i = 0; i < len; ++i) {
            std::cin.get(ch);
            data += ch;
        }
    } else if (requestMethod == "GET") {
        char* queryString = getenv("QUERY_STRING");
        if (queryString) data = queryString;
    }
    
    std::map<std::string, std::string> formData = parseData(data);
    
    if (formData["action"] == "Add") {
        addRecord(formData["name"], formData["address"], formData["phone"]);
        std::cout << "<p>Record added successfully!</p>";
    } else if (formData["action"] == "Update") {
        updateRecord(formData["name"], formData["address"], formData["phone"]);
    } else if (formData["action"] == "Delete") {
        deleteRecord(formData["name"]);
    }
    
    std::cout << "</body></html>";
    return 0;
}
