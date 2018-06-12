//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "mooseappcreationTestApp.h"
#include "mooseappcreationApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<mooseappcreationTestApp>()
{
  InputParameters params = validParams<mooseappcreationApp>();
  return params;
}

mooseappcreationTestApp::mooseappcreationTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  mooseappcreationApp::registerObjectDepends(_factory);
  mooseappcreationApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  mooseappcreationApp::associateSyntaxDepends(_syntax, _action_factory);
  mooseappcreationApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  mooseappcreationApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    mooseappcreationTestApp::registerObjects(_factory);
    mooseappcreationTestApp::associateSyntax(_syntax, _action_factory);
    mooseappcreationTestApp::registerExecFlags(_factory);
  }
}

mooseappcreationTestApp::~mooseappcreationTestApp() {}

void
mooseappcreationTestApp::registerApps()
{
  registerApp(mooseappcreationApp);
  registerApp(mooseappcreationTestApp);
}

void
mooseappcreationTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
mooseappcreationTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
mooseappcreationTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
mooseappcreationTestApp__registerApps()
{
  mooseappcreationTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
mooseappcreationTestApp__registerObjects(Factory & factory)
{
  mooseappcreationTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
mooseappcreationTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  mooseappcreationTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
mooseappcreationTestApp__registerExecFlags(Factory & factory)
{
  mooseappcreationTestApp::registerExecFlags(factory);
}
