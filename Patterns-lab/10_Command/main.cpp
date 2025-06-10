#include "./Command.h"

class Application {
private:
    Document* document;
    Menu* mainMenu;
public:
    Application() {
        document = new Document();
        mainMenu = new Menu("Main Menu");

        mainMenu->Add(new MenuItem("Open", new OpenCommand(document)));
        mainMenu->Add(new MenuItem("Close", new CloseCommand(document)));
        mainMenu->Add(new MenuItem("Cut", new CutCommand(document)));
        mainMenu->Add(new MenuItem("Copy", new CopyCommand(document)));
        mainMenu->Add(new MenuItem("Paste", new PasteCommand(document)));
    }

    ~Application() {
        delete document;
        delete mainMenu;
    }

    void Add(Document* doc) {
        // В реальном приложении здесь была бы логика добавления документа
        document = doc;
    }

    void Run() {
        mainMenu->Show();

        // Симуляция выбора пунктов меню
        std::cout << "\nSimulating menu actions:\n";
        MenuItem* openItem = new MenuItem("Open", new OpenCommand(document));
        openItem->Clicked();
        delete openItem;

        MenuItem* cutItem = new MenuItem("Cut", new CutCommand(document));
        cutItem->Clicked();
        delete cutItem;

        MenuItem* pasteItem = new MenuItem("Paste", new PasteCommand(document));
        pasteItem->Clicked();
        delete pasteItem;
    }
};

int main() {
    Application app;
    app.Run();

    return 0;
}