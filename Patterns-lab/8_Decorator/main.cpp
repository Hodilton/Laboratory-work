#include "./Decorator.h"

int main() {

    VisualComponent* textView = new TextView();
    std::cout << "Draw textView component:" << std::endl;
    textView->Draw();

    VisualComponent* scrollView = new ScrollDecorator(textView, 10);
    std::cout << "\nDraw with scrollView component:" << std::endl;
    scrollView->Draw();

    VisualComponent* borderView = new BorderDecorator(scrollView, 2);
    std::cout << "\nDraw with borderView component:" << std::endl;
    borderView->Draw();

    delete borderView;
    delete scrollView;
    delete textView;

    return 0;
}