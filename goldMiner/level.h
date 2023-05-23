#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QTimer>
#include <gameobject.h>
#include <vector>

namespace Ui {
class Level;
}

class Hook;

class Level : public QWidget
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();
    std::vector<GameObject*> gameObjects;
    int score;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void generateRandomObjects(int numStones,int numGolds);
    void paintGameObjects();
    void drawLine();
    void paintEvent(QPaintEvent* event) override;
    void updateTimer();
    void drawBombImage();

private:
    Ui::Level *ui;
    QPixmap minerPixmap;
    Hook* hook = NULL;
    int restTime;
};

#endif // LEVEL_H
