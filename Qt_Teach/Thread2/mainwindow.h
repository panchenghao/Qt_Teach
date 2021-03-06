#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QThread>

class WorkThread : public QObject
{
	Q_OBJECT
public:
	WorkThread(QObject* parent = nullptr);
	~WorkThread();
public slots:
	void start1();
	void doWork();
signals:
	void workFinished();
	void workStart();
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

public slots:
	void ThreadStart();

private:
	Ui::MainWindow *ui;

	QThread* m_workerThread;
};
#endif // MAINWINDOW_H
