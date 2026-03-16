// CustomerSupport_Command.cpp
#include "CustomerSupport_Command.h"
#include "BackCommand.h"
#include <imgui.h>

CustomerSupport_Command::CustomerSupport_Command(std::shared_ptr<BackCommand> backCmd)
    : m_Details("Customer Support"),
      m_ContactName("William Halling"),
      m_ContactEmail("32233703@student.murdoch.edu.au"),
      m_BackCommand(backCmd)
{
    m_Availability.push_back({"Monday", "12:00 PM - 11:59 PM"});
    m_Availability.push_back({"Tuesday", "12:00 PM - 11:59 PM"});
    m_Availability.push_back({"Wednesday", "12:00 PM - 11:59 PM"});
    m_Availability.push_back({"Thursday", "12:00 PM - 11:59 PM"});
    m_Availability.push_back({"Friday", "12:00 PM - 11:59 PM"});
}



void CustomerSupport_Command::Execute()
{
    ShowWindow();
}


void CustomerSupport_Command::ShowWindow()
{
    ImGui::Begin("Customer Support");
    ImGui::Text("Details: %s", m_Details.c_str());
    ImGui::Text("Contact Name: %s", m_ContactName.c_str());
    ImGui::Text("Contact Email: %s", m_ContactEmail.c_str());
    ImGui::Text("Availability:");

	
	for (const auto& a : m_Availability)
    {
        ImGui::Text("%s: %s", a.day.c_str(), a.time.c_str());
    }
    
	
	if (ImGui::Button("Back") && m_BackCommand)
    {
        m_BackCommand->Execute();
    }
    ImGui::End();
}
