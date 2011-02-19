#ifndef QTESTABLEAPPLICATION_H
#define QTESTABLEAPPLICATION_H

#include <QApplication>

class QTestableApplication : public QApplication
{
  public:
    QTestableApplication(int argc, char **argv);
};

#endif
