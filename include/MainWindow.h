#pragma once

#include <QtWidgets//QMainWindow>
#include <QMouseEvent>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    void setupStyle();

    void on_btn_close_clicked();
    void on_btn_minimize_clicked();
    void on_btn_maximize_clicked();

    ~MainWindow();

private:
    Ui::MainWindowClass ui;

protected:
    QPoint m_DragPosition;

    void mousePressEvent(QMouseEvent* event) override
    {
        m_DragPosition = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }

    void mouseMoveEvent(QMouseEvent* event) override
    {
        if (event->buttons() & Qt::LeftButton) {
            this->move(event->globalPos() - m_DragPosition);
            event->accept();
        }
    }
};
