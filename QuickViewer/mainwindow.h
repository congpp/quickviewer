#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filevolume.h"
#include "imageview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
    void loadVolume(QString path);
    void makeHistoryMenu();

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
//    void paintEvent( QPaintEvent *event );
    void wheelEvent(QWheelEvent *e);
    void mousePressEvent(QMouseEvent *e);

public slots:
    void on_file_changed(QString path);
    void on_nextPage_triggered();
    void on_prevPage_triggered();
    void on_fullscreen_triggered();
    void on_pageChanged_triggered();
    void on_pageSlider_changed(int value);
    void on_appVersion_triggered();
    void on_autoloaded_triggered(bool autoreload);
    void on_historymenu_triggered(QAction *action);

private slots:
    void on_actionExit_triggered();
    void on_hover_anchor(Qt::AnchorPoint anchor);


private:
    Ui::MainWindow *ui;
//    QImage *m_img;
    IFileVolume* m_fileVolume;
    bool viewerWindowStateMaximized;
};

#endif // MAINWINDOW_H