#include "StandardHandlers.h"
#include "IQTestableClassHandler.h"
#include "handlers/handler_for_button.h"
#include "handlers/handler_for_application.h"
#include "handlers/handler_for_label.h"
//NEXTINCLUDEHERE

using namespace QTestable;

IQTestableClassHandler *QTestable::StandardHandlers::buttonHandler()
{
  return new handler_for_button("button");
}

IQTestableClassHandler *QTestable::StandardHandlers::applicationHandler()
{
  return new handler_for_application("application");
}

IQTestableClassHandler *QTestable::StandardHandlers::labelHandler()
{
  return new handler_for_label("label");
}
