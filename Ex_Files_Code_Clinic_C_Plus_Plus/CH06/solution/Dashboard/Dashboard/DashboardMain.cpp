/**
 * DashboardApp.cpp by Olivia Stone for Code Clinic: C++
 **/

#include <Wt/WApplication.h>

#include "Dashboard.hpp"

int main(int argc, char **argv)
{
	return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) 
	{
		return Wt::cpp14::make_unique<Dashboard>(env);
	});
}