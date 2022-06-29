/**
 * Dashboard.hpp by Olivia Stone for Code Clinic: C++
 **/

#ifndef	DASHBOARD_H_
#define DASHBOARD_H_

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WProgressBar.h>
#include <Wt/WPushButton.h>

#include "DashboardData.hpp"

class Dashboard : public Wt::WApplication
{
public:
	Dashboard(const Wt::WEnvironment& env);

private:
	Wt::WText		     *title_;
	Wt::WText		     *time_;
	Wt::WText		     *pulsometer_;
	Wt::WText		     *engineText_;
	Wt::WProgressBar     *engine_;
	Wt::WText		     *green_;
	Wt::WText		     *red_;
	Wt::WText		     *blue_;
	DashboardData 		 dbData_;

	void updateBoard();
};

#endif // DASHBOARD_H_