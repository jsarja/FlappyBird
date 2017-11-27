#include "h-files/game.h"

using namespace std;

Game::Game() {
    unpaused = false;
    ended = false;
    // Asetetaan ikkunan koko
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,800);

    setBackgroundBrush(QBrush(QImage(":/images/Images/bg.png")));

    // Luodaan uusi scene ja asetetaa se näkyväksi.
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,800);
    setScene(scene);

    // Luodaan pelaaja ja asetataan se näyttöön.
    player = new Bird();
    scene->addItem(player);

    // Focus, että keyPressit toimii
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Luodaan uusi score ja asetetaan näyttöön.
    score = new Score();
    scene->addItem(score);

    // Haetaan highscore
    loadHighScore();

    // Lisätään ohje pelin aloitukseen.
    guideText = new QGraphicsTextItem();
    guideText->setPlainText("Press SPACE to start");
    guideText->setFont(QFont("Arial Black", 16));
    guideText->setPos(125,145);
    scene->addItem(guideText);

}

void Game::startNew() {
    unpaused = false;
    ended = false;

    // Luodaan uusi scene ja asetetaa se näkyväksi.
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,800);
    setScene(scene);

    // Luodaan pelaaja ja asetataan se näyttöön.
    player = new Bird();
    player->GameStarted = false;
    scene->addItem(player);

    // Focus, että keyPressit toimii
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Luodaan uusi score ja asetetaan näyttöön.
    score = new Score();
    scene->addItem(score);

    // Lisätään ohje pelin aloitukseen.
    scene->addItem(guideText);
}

void Game::loadHighScore() {
    ifstream scoreFile("highScore.txt");
    string oldScore;
    while(getline(scoreFile, oldScore)) {
        highScore = std::stoi (oldScore);
    }
}

void Game::updateHighScore() {
    ofstream scoreFile;
    scoreFile.open ("highScore.txt");
    scoreFile << std::to_string (highScore);
}

void Game::gameOver() {
    ended = true;
    // Pysäytetään liike ruudulla.
    player->spawn->ajastin->stop();
    player->ajastin->stop();

    // Lisätään GameOver-teksti
    QGraphicsPixmapItem* gameOver = new QGraphicsPixmapItem();
    gameOver->setPixmap(QPixmap(":/images/Images/Over"));
    gameOver->setPos(160,40);
    scene->addItem(gameOver);

    // Lisätään score board
    QGraphicsPixmapItem* scoreboard = new QGraphicsPixmapItem();
    scoreboard->setPixmap(QPixmap(":/images/Images/scoreBoard"));
    scoreboard->setPos(63,265);
    scene->addItem(scoreboard);

    // Lisätään score teksti
    QGraphicsTextItem* scoreText = new QGraphicsTextItem();
    scoreText->setPlainText("SCORE:");
    scoreText->setDefaultTextColor(Qt::white);
    scoreText->setFont(QFont("Arial Black", 25));
    scoreText->setZValue(1);
    scoreText->setPos(90,275);
    scene->addItem(scoreText);

    // Muutetaan scoren paikkaa.
    score->setFont(QFont("Arial Black", 25));
    score->setPos(140,325);

    // Lisätään Best teksti
    QGraphicsTextItem* bestText = new QGraphicsTextItem();
    bestText->setPlainText("BEST:");
    bestText->setDefaultTextColor(Qt::white);
    bestText->setFont(QFont("Arial Black", 25));
    bestText->setZValue(1);
    bestText->setPos(345,275);
    scene->addItem(bestText);

    // Lisätään highscore näytölle.
    if(score->getScore() > highScore) {
        highScore = score->getScore();
        updateHighScore();
    }

    QGraphicsTextItem* high = new QGraphicsTextItem();
    high->setPlainText(QString::number(highScore));
    high->setDefaultTextColor(Qt::white);
    high->setFont(QFont("Arial Black", 25));
    high->setZValue(1);
    high->setPos(380,325);
    scene->addItem(high);


    // Lisätään OK-painike
    QPushButton* OKbutton = new QPushButton();

    OKbutton->setFlat(true);
    OKbutton->setAutoFillBackground(true);

    OKbutton->setStyleSheet("background-image:url(:/images/Images/OK.png)");
    OKbutton->setGeometry(0,0,128,43);
    OKbutton->move(240,550);
    scene->addWidget(OKbutton);

    connect(OKbutton,SIGNAL(clicked(bool)),this,SLOT(startNew()));

}

