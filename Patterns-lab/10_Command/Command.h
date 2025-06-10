#pragma once
#include <iostream>
#include <vector>
#include <string>

class Command {
public:
    virtual void Execute() = 0;
};

// Класс Document (Receiver)
class Document {
public:
    void Open() { std::cout << "Document open" << "\n"; }
    void Close() { std::cout << "Document close" << "\n";; }
    void Cut() { std::cout << "Text cut" << "\n"; }
    void Copy() { std::cout << "Text copied" << "\n"; }
    void Paste() { std::cout << "Text pasted" << "\n"; }
};

class OpenCommand : public Command {
private:
    Document* document;
public:
    OpenCommand(Document* doc) : document(doc) {}
    void Execute() override { document->Open(); }
};

class CloseCommand : public Command {
private:
    Document* document;
public:
    CloseCommand(Document* doc) : document(doc) {}
    void Execute() override { document->Close(); }
};

class CutCommand : public Command {
private:
    Document* document;
public:
    CutCommand(Document* doc) : document(doc) {}
    void Execute() override { document->Cut(); }
};

class CopyCommand : public Command {
private:
    Document* document;
public:
    CopyCommand(Document* doc) : document(doc) {}
    void Execute() override { document->Copy(); }
};

class PasteCommand : public Command {
private:
    Document* document;
public:
    PasteCommand(Document* doc) : document(doc) {}
    void Execute() override { document->Paste(); }
};

// Класс MenuItem (Invoker)
class MenuItem {
private:
    Command* command;
    std::string name;
public:
    MenuItem(const std::string& name, Command* cmd) : name(name), command(cmd) {}
    ~MenuItem() { delete command; }

    void Clicked() {
        std::cout << "Menu item '" << name << "' clicked" << "\n";
        command->Execute();
    }

    std::string GetName() const { return name; }
};

class Menu {
private:
    std::vector<MenuItem*> items;
    std::string name;
public:
    Menu(const std::string& name) : name(name) {}
    ~Menu() {
        for (auto item : items) {
            delete item;
        }
    }

    void Add(MenuItem* item) {
        items.push_back(item);
    }

    void Show() {
        std::cout << "Menu: " << name << "\n";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << i + 1 << ". " << items[i]->GetName() << "\n";
        }
    }
};