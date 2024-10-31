#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>

using namespace std;

string input;
int score = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_1->setText(getRandomWord());
    ui->label_2->setText(getRandomWord());
    ui->label_3->setText(getRandomWord());
    ui->score->setText(QString::number(score));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    if(ui->label_1->text() == input)
    {
        ui->label_1->setText(getRandomWord());
        scoreCount();
    }
    if(ui->label_2->text() == input)
    {
        ui->label_2->setText(getRandomWord());
        scoreCount();
    }
    if(ui->label_3->text() == input)
    {
        ui->label_3->setText(getRandomWord());
        scoreCount();
    }
    ui->lineEdit->setText("");

}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    input = arg1.toStdString();
}

QString MainWindow::getRandomWord()
{
    vector<string> words = {
        "a", "above", "after", "again", "all", "almost", "along", "always", "an", "and", "animal", "another", "answer", "any", "are", "around", "as", "ask", "at", "away", "back", "be", "because", "before", "began", "begin", "being", "below", "between", "big", "black", "book", "both", "boy", "but", "call", "came", "can", "car", "carry", "change", "children", "city", "close", "come", "could", "cut", "day", "did", "different", "do", "does", "each", "earth", "eat", "end", "enough", "even", "every", "example", "eye", "face", "family", "far", "father", "few", "find", "fire", "first", "follow", "food", "for", "form", "found", "from", "get", "girl", "give", "go", "got", "great", "group", "grow", "had", "hand", "hard", "has", "have", "he", "head", "hear", "help", "here", "home", "house", "how", "idea", "if", "important", "into", "is", "it", "its", "keep", "kind", "know", "land", "large", "last", "later", "learn", "left", "let", "letter", "life", "light", "like", "line", "list", "little", "long", "look", "make", "man", "many", "may", "me", "mean", "might", "mile", "miss", "more", "most", "mother", "move", "much", "my", "name", "near", "need", "never", "next", "night", "not", "now", "of", "often", "oil", "old", "on", "once", "one", "only", "or", "our", "out", "over", "own", "page", "paper", "part", "people", "place", "plant", "play", "point", "put", "read", "really", "right", "river", "said", "same", "saw", "say", "school", "sea", "second", "see", "seem", "set", "should", "side", "so", "some", "something", "sometimes", "song", "soon", "sound", "spell", "start", "state", "still", "stop", "story", "study", "such", "take", "talk", "tell", "than", "that", "the", "their", "them", "then", "there", "these", "they", "thing", "think", "this", "those", "thought", "time", "to", "together", "too", "took", "tree", "try", "turn", "two", "under", "until", "up", "upon", "use", "very", "walk", "want", "war", "was", "watch", "water", "we", "well", "went", "were", "when", "where", "which", "while", "white", "why", "will", "with", "without", "word", "work", "world", "would", "write", "year", "you", "your"
    };
    return QString::fromStdString(words[rand() % words.size()]);
}

void MainWindow::scoreCount()
{
    score++;
    ui->score->setText(QString::number(score));
}
