#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QLocalServer>
#include <QDialog>
#include <QSettings>
#include "zeallistmodel.h"
#include "zealsearchmodel.h"
#include "zealnativeeventfilter.h"

namespace Ui {
class MainWindow;
}

extern const QString serverName;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    void bringToFront(bool withHack);
    Ui::MainWindow *ui;
    QIcon icon;
    ZealListModel zealList;
    ZealSearchModel zealSearch;
    QLocalServer *localServer;
    QDialog hackDialog;
    void createTrayIcon();
    void setHotKey(const QKeySequence& hotKey);
    QKeySequence hotKey;
    QSettings settings;
    ZealNativeEventFilter nativeFilter;

protected:
    void closeEvent(QCloseEvent *event) {
        settings.setValue("geometry", saveGeometry());
        QMainWindow::closeEvent(event);
    }
};

#endif // MAINWINDOW_H
