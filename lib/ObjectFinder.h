#ifndef OBJECTFINDER_H
#define OBJECTFINDER_H

#include "common.h"
#include <QHash>

namespace QTestable
{

  struct FindResults
  {
    FindResults (QString aErrorMessage, QObject *aTargetObject) : errorMessage(aErrorMessage), targetObject(aTargetObject) {}
    QString errorMessage;
    QObject *targetObject;
  };

  class ObjectFinder
  {
    QHash<QString, QObject *> objectMap;
    
    public:
      void insert(const QString &name, QObject *value)
      {
        objectMap.insert(name, value);
      }

      FindResults find(const QString &name);

      void remove(const QString &name)
      {
        objectMap.remove(name);
      }

      QList<QString> keys()
      {
        return objectMap.keys();
      }
  };
}

#endif
