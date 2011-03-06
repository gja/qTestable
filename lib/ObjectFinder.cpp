#include "ObjectFinder.h"

namespace QTestable
{
  FindResults ObjectFinder::find(const QString &name)
  {
    QString errorMessage;
    
    QObject *result = objectMap[name];

    if(result == NULL)
      errorMessage = QString("Unable to find top level object \"%1\"").arg(name);

    return FindResults(errorMessage, result);
  }
}
