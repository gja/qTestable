#ifndef QTESTABLEAPPLICATION_H
#define QTESTABLEAPPLICATION_H

#include <QApplication>

class QTestableApplication : public QApplication
{
  struct QTestableApplicationPrivate *d;

  public:
    QTestableApplication(int argc, char **argv);
    ~QTestableApplication();
};

#endif
