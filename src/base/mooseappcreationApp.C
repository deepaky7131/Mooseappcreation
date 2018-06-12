#include "mooseappcreationApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<mooseappcreationApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

mooseappcreationApp::mooseappcreationApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  mooseappcreationApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  mooseappcreationApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  mooseappcreationApp::registerExecFlags(_factory);
}

mooseappcreationApp::~mooseappcreationApp() {}

void
mooseappcreationApp::registerApps()
{
  registerApp(mooseappcreationApp);
}

void
mooseappcreationApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"mooseappcreationApp"});
}

void
mooseappcreationApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"mooseappcreationApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
mooseappcreationApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
mooseappcreationApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
mooseappcreationApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
mooseappcreationApp__registerApps()
{
  mooseappcreationApp::registerApps();
}

extern "C" void
mooseappcreationApp__registerObjects(Factory & factory)
{
  mooseappcreationApp::registerObjects(factory);
}

extern "C" void
mooseappcreationApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  mooseappcreationApp::associateSyntax(syntax, action_factory);
}

extern "C" void
mooseappcreationApp__registerExecFlags(Factory & factory)
{
  mooseappcreationApp::registerExecFlags(factory);
}
