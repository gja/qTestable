#include "ObjectFinder.h"

namespace QTestable
{
  void ParseTree(QStringList &tokens, FindResults &incrementalResults)
  {
    if(tokens.isEmpty())
      return;

    const QString &token = tokens.takeFirst();

    incrementalResults.targetObject = qFindChild<QObject *>(incrementalResults.targetObject, token);

    if(incrementalResults.targetObject == NULL)
      incrementalResults.errorMessage = QString("Unable to find object \"%1\"").arg(token);
    else
      ParseTree(tokens, incrementalResults);
  }


  FindResults ObjectFinder::find(const QString &name)
  {
    QStringList tokens = name.split('/');
    
    QObject *result = objectMap[tokens.takeFirst()];

    if(result == NULL)
      return FindResults(QString("Unable to find top level object \"%1\"").arg(name), NULL);

    FindResults r("", result);
    ParseTree(tokens, r);
    return r;
  }
}
