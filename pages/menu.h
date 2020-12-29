#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QApplication* application, QWidget *parent = nullptr);
    QApplication* application;
    QSize sizeHint() const override;
    ~Menu();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
