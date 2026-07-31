#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class DocumentElement {
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement {
private:
    string text;

public: 
    TextElement(string text){
        this->text = text;
    }

    string render() override {
        return text + "\n";
    }
};

class ImageElement : public DocumentElement {
    private:
        string imagePath;

    public: 
        ImageElement(string imagepath){
            this->imagePath = imagepath;
        }

        string render() override {
            return "Image: " + imagePath + "\n";
        }
};

class NewLineElement : public DocumentElement {
    public:
        string render() override {
            return "\n";
        }
};

class TabSpaceElement : public DocumentElement {
    public:
        string render() override {
            return "\t";
        }
};

class Document {
    private:
        vector<DocumentElement*> documentElements;

    public:
        void addElement(DocumentElement* element) {
            documentElements.push_back(element);
        }

        string render(){
            string result;
            for (const auto& element : documentElements) {
                result += element->render();
            }
            return result;
        }
};

class Persistence {
    public:
        virtual void save(string data) = 0;
};

class SaveToFile : public Persistence {
    public:
        void save(string data) override {
            ofstream file("document.txt");
            if (file.is_open()) {
                file << data;
                file.close();
                cout << "Saved data to file successfully" << endl;
            } else {
                cout << "Something went wrong" << endl;
            }
        }
};

class SaveToDatabase : public Persistence {
    public:
        void save(string data) override {
            // Code to save data to a database
            cout << "Saved data to database successfully" << endl;
        }
};


class DocumentEditor {
    private:
        Document *doc;
        Persistence* db;

        public: 
            DocumentEditor(Persistence* db, Document *doc) {
                this->db = db;
                this->doc = doc;
            }

            void addText(string text) {
                doc->addElement(new TextElement(text));
            }

            void addImage(string imagePath) {
                doc->addElement(new ImageElement(imagePath));
            }

            void addNewLine() {
                doc->addElement(new NewLineElement());
            }

            void addTabSpace() {
                doc->addElement(new TabSpaceElement());
            }

            void saveDocument() {
                string renderedData = doc->render();
                db->save(renderedData);
            }

};

int main() {
    Document *doc = new Document();
    Persistence *db = new SaveToFile();
    DocumentEditor *editor = new DocumentEditor(db, doc);

    editor->addText("Hello, this is a sample document.");
    editor->addNewLine();
    editor->addText("This document contains text and images.");
    editor->addNewLine();
    editor->addImage("image1.png");
    editor->addNewLine();
    editor->addText("Thank you for using our document editor.");
    editor->saveDocument();
    return 0;
}