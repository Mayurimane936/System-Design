#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentEditor {
private:
    vector<string> documentElement;
    string renderDocument;

public:
    void addText(string text) {
        documentElement.push_back(text);
    }

    void addImage(string imagePath) {
        documentElement.push_back(imagePath);
    }

    string renderElement() {
        if (renderDocument.empty()) {
            string result;
            for (const auto& ele : documentElement) {
                if (ele.size() > 4 &&
                    (ele.substr(ele.size() - 4) == ".png" || ele.substr(ele.size() - 4) == ".jpg")) {
                    result += "Image: " + ele + "\n";
                } else {
                    result += ele + "\n";
                }
            }
            renderDocument = result;
        }
        return renderDocument;
    }

    void saveToFile() {
        ofstream file("document.txt");
        if (file.is_open()) {
            file << renderElement();
            file.close();
            cout << "saved data to file successfully" << endl;
        } else {
            cout << "Something went wrong" << endl;
        }
    }
};

int main() {
    DocumentEditor doc;
    doc.addImage("picture.jpg");
    doc.addText("Hellooooo");
    doc.saveToFile();
    return 0;
}