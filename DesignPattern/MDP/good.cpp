#include <iostream>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////
// Memento
/////////////////////////////////////////////////////////////

class TextMemento {
    string savedText;

public:
    TextMemento(string text)
        : savedText(text) {}

    string getText() const {
        return savedText;
    }
};

/////////////////////////////////////////////////////////////
// Originator
/////////////////////////////////////////////////////////////

class TextEditor {

    string text;

public:

    void write(string words) {
        text += words;
    }

    void show() const {
        cout << "Current Text : " << text << endl;
    }

    TextMemento save() {
        return TextMemento(text);
    }

    void restore(const TextMemento& memento) {
        text = memento.getText();
    }
};

/////////////////////////////////////////////////////////////
// Caretaker
/////////////////////////////////////////////////////////////

class History {

    vector<TextMemento> history;
    int currentIndex = -1;

public:

    void save(TextMemento memento) {

        // Remove future history if user edited after undo
        if(currentIndex + 1 < history.size()) {
            history.erase(history.begin() + currentIndex + 1,
                          history.end());
        }

        history.push_back(memento);
        currentIndex++;
    }

    TextMemento undo() {

        if(currentIndex <= 0)
            return history[0];

        currentIndex--;

        return history[currentIndex];
    }

    TextMemento redo() {

        if(currentIndex >= history.size()-1)
            return history[currentIndex];

        currentIndex++;

        return history[currentIndex];
    }
};

/////////////////////////////////////////////////////////////

int main() {

    TextEditor editor;
    History history;

    editor.write("Hello");
    history.save(editor.save());

    editor.write(" World");
    history.save(editor.save());

    editor.write(" !!!");
    history.save(editor.save());

    editor.write(" C++");
    history.save(editor.save());

    editor.show();

    // Hello , Hello World  , Hello World !!!  ,Hello World !!! C++

    cout << "\nUndo\n";
    editor.restore(history.undo());
    editor.show();

    cout << "\nUndo\n";
    editor.restore(history.undo());
    editor.show();

    cout << "\nUndo\n";
    editor.restore(history.undo());
    editor.show();

    cout << "\nRedo\n";
    editor.restore(history.redo());
    editor.show();

    cout << "\nRedo\n";
    editor.restore(history.redo());
    editor.show();
}