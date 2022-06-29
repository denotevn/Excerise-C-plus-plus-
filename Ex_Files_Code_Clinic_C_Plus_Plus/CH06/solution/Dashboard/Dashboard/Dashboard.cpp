/**
 * Dashboard.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "Dashboard.hpp"
#include "DashboardData.hpp"

using namespace std;
using namespace Wt;

Dashboard::Dashboard(const Wt::WEnvironment& env)
	: WApplication(env)
{
	setTitle("Code Clinic Dashboard");   // application title
	messageResourceBundle().use(appRoot() + "dashboard");
	instance()->useStyleSheet("resource/dashboard.css");

	// add widgets
	title_ = root()->addWidget(cpp14::make_unique<WText>("Manufacturing Process Status"));
	title_->setStyleClass("title");

	auto container = root()->addWidget(cpp14::make_unique<Wt::WContainerWidget>());
	auto vbox = container->setLayout(Wt::cpp14::make_unique<Wt::WVBoxLayout>());
	time_ = vbox->addWidget(cpp14::make_unique<Wt::WText>("Time: "));
	time_->setStyleClass("process");

	// meters
	pulsometer_ = vbox->addWidget(cpp14::make_unique<WText>("Pulsometer Readout: "));
	pulsometer_->setStyleClass("process");

	auto containerEngine = root()->addWidget(cpp14::make_unique<Wt::WContainerWidget>());
	auto hbox = containerEngine->setLayout(Wt::cpp14::make_unique<Wt::WHBoxLayout>());
	engineText_ = hbox->addWidget(cpp14::make_unique<Wt::WText>("Engine Efficiency:"));
	engine_ = hbox->addWidget(cpp14::make_unique<WProgressBar>());
	engine_->setStyleClass("Wt-progressbar");

	// color Status
	auto containerColor = root()->addWidget(cpp14::make_unique<Wt::WContainerWidget>());
	auto colorBox = containerColor->setLayout(Wt::cpp14::make_unique<Wt::WVBoxLayout>());

	red_ = colorBox->addWidget(cpp14::make_unique<Wt::WText>("Red"));
	red_->setStyleClass("red-box");

	blue_ = colorBox->addWidget(cpp14::make_unique<Wt::WText>("Blue"));
	blue_->setStyleClass("blue-box");

	green_ = colorBox->addWidget(cpp14::make_unique<WText>("Green"));
	green_->setStyleClass("green-box");

	auto button = root()->addWidget(Wt::cpp14::make_unique<Wt::WPushButton>("Update"));
	button->setMargin(5, Wt::Side::Left);

	root()->addWidget(Wt::cpp14::make_unique<Wt::WBreak>());    // insert a line break

	// load data
	dbData_.loadData();

	// populate board with data
	updateBoard();

	// connect user interaction with method
	button->clicked().connect(this, &Dashboard::updateBoard);
	button->clicked().connect([=]() {
		std::cerr << "Update " << std::endl;
	});

}

void Dashboard::updateBoard()
{
	dbData_.getData();

	time_->setText("Time: " + dbData_.getTime());
	pulsometer_->setText("Pulsometer Readout: " + to_string(dbData_.getPulsometer()));
	engine_->setValue(dbData_.getEngine());

	red_->setText("Red Value: " + to_string(dbData_.getRed()));
	blue_->setText("Blue Value: " + to_string(dbData_.getBlue()));
	green_->setText("Green Value: " + to_string(dbData_.getGreen()));
}