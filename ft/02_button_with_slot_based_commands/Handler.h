#include <QObject>
#include <QTestable.h>
#include <QPushButton>
#include <QApplication>
#include <QLabel>

using namespace QTestable;

class Handler : public QTestableClassHandler
{
  Q_OBJECT

  virtual QString handleInvalidRequest(QObject *object, const QTestableAutomationRequest &request) {}

  private slots:
    QString click(QObject *object, const QTestableAutomationRequest &request)
    {
      ((QPushButton *) object)->click();
      return "clicked";
    }

    QString quit(QObject *object, const QTestableAutomationRequest &request)
    {
      ((QApplication *) object)->quit();
      return "quit";
    }

    QString getText(QObject *object, const QTestableAutomationRequest &request)
    {
      return ((QLabel *) object)->text();
    }
};
