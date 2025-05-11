#include "./Composite.h"

int main() {
    Picture* root = new Picture();

    root->Add(new Line());
    root->Add(new Rectangle());

    Picture* subPicture = new Picture();
    subPicture->Add(new Text());
    subPicture->Add(new Line());

    root->Add(subPicture);
    root->Draw();

    delete root;

    return 0;
}